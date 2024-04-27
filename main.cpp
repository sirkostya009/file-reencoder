#include <AppCore/AppCore.h>
#include <iostream>
#include <functional>
#include <shobjidl.h>
#include <fstream>

namespace ul = ultralight;

class About : public ul::WindowListener, public ul::LoadListener, public ul::ViewListener {
    ul::RefPtr<ul::Window> window;
    ul::RefPtr<ul::Overlay> overlay;
    std::function<void()> closeCallback;

public:
    About(const ul::RefPtr<ul::App>& app, std::function<void()> onClose)
    : closeCallback{std::move(onClose)}
    , window{ ul::Window::Create(app->main_monitor(), 560, 600, false, ul::kWindowFlags_Resizable) }
    , overlay{ ul::Overlay::Create(window, 1, 1, 0, 0) }
    {
        window->set_listener(this);
        overlay->view()->set_load_listener(this);
        overlay->view()->set_view_listener(this);

        window->MoveToCenter();
        overlay->view()->LoadURL("file:///about.html");
        overlay->Focus();
    }

    void OnClose(ul::Window*) override {
        window->Close();
        closeCallback();
    }

    void OnResize(ul::Window*, uint32_t width, uint32_t height) override {
        overlay->Resize(width, height);
    }

    void OnChangeTitle(ul::View *caller, const ul::String &title) override {
        window->SetTitle(title.utf8().data());
    }

    bool OnKeyEvent(const ul::KeyEvent &evt) override {
        constexpr auto Escape = 27;

        switch (evt.virtual_key_code) {
        case Escape:
            OnClose(window.get());
        }
        return true;
    }
};

class App : public ul::AppListener, public ul::WindowListener, public ul::LoadListener, public ul::ViewListener {
    ul::RefPtr<ul::App> app;
    ul::RefPtr<ul::Window> window;
    ul::RefPtr<ul::Overlay> overlay;

    About* pAbout = nullptr;
    bool closeAbout = false;
public:
    App()
    : app{ ul::App::Create() }
    , window{ ul::Window::Create(app->main_monitor(), 720, 640, false, ul::kWindowFlags_Resizable | ul::kWindowFlags_Maximizable) }
    , overlay{ ul::Overlay::Create(window, 1, 1, 0, 0) }
    {
        app->set_listener(this);
        window->set_listener(this);
        overlay->view()->set_load_listener(this);
        overlay->view()->set_view_listener(this);

        window->MoveToCenter();
        overlay->Resize(window->width(), window->height());
        overlay->view()->LoadURL("file:///app.html");
        overlay->Focus();
    }

    inline void run() {
        app->Run();
    }

    void OnUpdate() override {
        if (closeAbout) {
            delete pAbout;
            pAbout = nullptr;
            closeAbout = false;
            ul::SetJSContext(overlay->view()->LockJSContext()->ctx());
        }
    }

    void OnClose(ul::Window*) override {
        std::exit(0);
    }

    void OnResize(ul::Window*, uint32_t width, uint32_t height) override {
        overlay->Resize(width, height);
        overlay->view()->Resize(width, height);
    }

    void OnDOMReady(ul::View *caller, uint64_t frame_id, bool is_main_frame, const ul::String &url) override {
        using ul::JSCallback, ul::JSCallbackWithRetval;
        ul::SetJSContext(caller->LockJSContext()->ctx());
        auto global = ul::JSGlobalObject();

        global["nuke"] = BindJSCallback(&App::Nuke);
        global["openInfo"] = BindJSCallback(&App::OpenInfo);
        global["openFile"] = BindJSCallbackWithRetval(&App::OpenFile);
        global["saveAsFile"] = BindJSCallback(&App::SaveAsFile);
    }

    void OnChangeCursor(ul::View *caller, ul::Cursor cursor) override {
        window->SetCursor(cursor);
    }

    void OnChangeTitle(ul::View *caller, const ul::String &title) override {
        window->SetTitle(title.utf8().data());
    }

    void OnAddConsoleMessage(ul::View*, ul::MessageSource, ul::MessageLevel lvl, const ul::String &message,
                             uint32_t line, uint32_t col, const ul::String &) override {
        (lvl == ul::kMessageLevel_Error ? std::cerr : std::cout)
            << "Console: " << message.utf8().data() << " at line: " << line << ", column: " << col << std::endl;
    }

    void OpenInfo(const ul::JSObject&, const ul::JSArgs&) {
        if (pAbout) {
            return;
        }

        pAbout = new About(app, [this] { closeAbout = true; });
    }

    ul::JSValue OpenFile(const ul::JSObject&, const ul::JSArgs&) {
        IFileOpenDialog *dialog;
        CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<LPVOID*>(&dialog));
        dialog->Show((HWND) window->native_handle());

        if (IShellItem *item; SUCCEEDED(dialog->GetResult(&item))) {
            LPWSTR filePath;
            item->GetDisplayName(SIGDN_FILESYSPATH, &filePath);
            item->Release();
            dialog->Release();

            auto file = std::ifstream(filePath);

            return {std::string(std::istreambuf_iterator<char>(file), {}).c_str()};
        }

        return {};
    }

    void writeFile(std::ofstream fs, const std::string& encoding, const ul::String& data) {
        if (encoding == "bin") {
            auto u8 = data.utf8();

            for (int i{}; i < u8.length(); ++i) {
                auto ch = u8[i];

                if (ch == '\n') {
                    fs << '\n';
                    continue;
                }

                fs << !!(ch & 0b00000001);
                fs << !!(ch & 0b00000010);
                fs << !!(ch & 0b00000100);
                fs << !!(ch & 0b00001000);
                fs << !!(ch & 0b00010000);
                fs << !!(ch & 0b00100000);
                fs << !!(ch & 0b01000000);
                fs << !!(ch & 0b10000000);
            }
        } else if (encoding == "utf8") {
            fs << data.utf8().data();
        } else if (encoding == "utf16") {
            fs << '\xFE' << '\xFF';
            auto s16 = data.utf16();

            for (int i{}; i < s16.length(); ++i)  {
                auto c = s16[i];
                if (c == '\n') {
                    fs << '\x24' << '\x24';
                    continue;
                }
                auto bytes = (char*) &c;
                fs << bytes[1] << bytes[0];
            }
        } else if (encoding == "utf32") {
            fs << '\xFF' << '\xFE' << '\x00' << '\x00';
            auto s32 = data.utf32();

            for (int i{}; i < s32.length(); ++i)  {
                auto c = s32[i];
                if (c == '\n') {
                    fs << '\x00' << '\x00' << '\x24' << '\x24';
                    continue;
                }
                auto bytes = (char*) &c;
                fs << bytes[3] << bytes[2] << bytes[1] << bytes[0];
            }
        }
    }

    void SaveAsFile(const ul::JSObject&, const ul::JSArgs& args) {
        auto encoding = (ul::String) args[0];
        auto contents = (ul::String) args[1];

        IFileSaveDialog *pFileSave;
        CoCreateInstance(CLSID_FileSaveDialog, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pFileSave));
        pFileSave->SetOptions(FOS_FORCEFILESYSTEM | FOS_OVERWRITEPROMPT);
        pFileSave->SetDefaultExtension(encoding.utf16().data());
        pFileSave->SetFileName(encoding.utf16().data());

        if (SUCCEEDED(pFileSave->Show(nullptr))) {
            IShellItem *pItem;
            pFileSave->GetResult(&pItem);
            PWSTR pszFilePath;
            pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
            auto wfilepath = std::wstring(pszFilePath);
            auto filepath = std::string(wfilepath.begin(), wfilepath.end());
            writeFile(std::move(std::ofstream(filepath)), encoding.utf8().data(), contents);
            CoTaskMemFree(pszFilePath);
            pItem->Release();
        }
        pFileSave->Release();
    }

    void Nuke(const ul::JSObject&, const ul::JSArgs&) {
        std::exit(0);
    }
};

auto main() -> int {
    CoInitialize(nullptr);
    App().run();
}
