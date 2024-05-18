#pragma once

#include "Converter.h"
#include "AboutForm.h"

namespace app {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form {
		app::Converter^ converter;
		app::AboutForm^ aboutForm;

	public:
		MainForm(void)
		{
			InitializeComponent();
			converter = gcnew app::Converter();
			aboutForm = gcnew app::AboutForm();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::RichTextBox^ editor;
	private: System::Windows::Forms::ToolStripComboBox^ fileEncodings;
	private: System::Windows::Forms::ToolStripStatusLabel^ filenameLabel;
	private: System::Windows::Forms::ToolStripButton^ openButton;
	private: System::Windows::Forms::ToolStripButton^ saveButton;
	private: System::Windows::Forms::ToolStripButton^ clearButton;
	private: System::ComponentModel::Container ^components;
	private: System::Windows::Forms::ToolStripProgressBar^ saveProgress;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::MenuStrip^ menuStrip1;
			System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ відкритиToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ зберегтиToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
			System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
			System::Windows::Forms::ToolStripMenuItem^ вийтиToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ проПрограмуToolStripMenuItem;
			System::Windows::Forms::ToolStrip^ toolStrip1;
			System::Windows::Forms::StatusStrip^ statusStrip1;
			this->openButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->saveButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->clearButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->fileEncodings = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->saveProgress = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->filenameLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->editor = (gcnew System::Windows::Forms::RichTextBox());
			menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			відкритиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			зберегтиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			вийтиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			проПрограмуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			menuStrip1->SuspendLayout();
			toolStrip1->SuspendLayout();
			statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { файлToolStripMenuItem, проПрограмуToolStripMenuItem });
			menuStrip1->Location = System::Drawing::Point(0, 0);
			menuStrip1->Name = L"menuStrip1";
			menuStrip1->Size = System::Drawing::Size(704, 24);
			menuStrip1->TabIndex = 0;
			menuStrip1->Text = L"menuStrip";
			// 
			// файлToolStripMenuItem
			// 
			файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				відкритиToolStripMenuItem,
					зберегтиToolStripMenuItem, toolStripMenuItem1, toolStripSeparator1, вийтиToolStripMenuItem
			});
			файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			файлToolStripMenuItem->Text = L"Файл";
			// 
			// відкритиToolStripMenuItem
			// 
			відкритиToolStripMenuItem->Name = L"відкритиToolStripMenuItem";
			відкритиToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			відкритиToolStripMenuItem->Text = L"Відкрити";
			відкритиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openFileDialog);
			// 
			// зберегтиToolStripMenuItem
			// 
			зберегтиToolStripMenuItem->Name = L"зберегтиToolStripMenuItem";
			зберегтиToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			зберегтиToolStripMenuItem->Text = L"Зберегти";
			зберегтиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveFileDialog);
			// 
			// toolStripMenuItem1
			// 
			toolStripMenuItem1->Name = L"toolStripMenuItem1";
			toolStripMenuItem1->Size = System::Drawing::Size(127, 22);
			toolStripMenuItem1->Text = L"Очистити";
			toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::clear);
			// 
			// toolStripSeparator1
			// 
			toolStripSeparator1->Name = L"toolStripSeparator1";
			toolStripSeparator1->Size = System::Drawing::Size(124, 6);
			// 
			// вийтиToolStripMenuItem
			// 
			вийтиToolStripMenuItem->Name = L"вийтиToolStripMenuItem";
			вийтиToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			вийтиToolStripMenuItem->Text = L"Вийти";
			вийтиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::вийтиToolStripMenuItem_Click);
			// 
			// проПрограмуToolStripMenuItem
			// 
			проПрограмуToolStripMenuItem->Name = L"проПрограмуToolStripMenuItem";
			проПрограмуToolStripMenuItem->Size = System::Drawing::Size(99, 20);
			проПрограмуToolStripMenuItem->Text = L"Про програму";
			проПрограмуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::проПрограмуToolStripMenuItem_Click);
			// 
			// toolStrip1
			// 
			toolStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->openButton, this->saveButton,
					this->clearButton, this->fileEncodings, this->saveProgress
			});
			toolStrip1->Location = System::Drawing::Point(0, 24);
			toolStrip1->Name = L"toolStrip1";
			toolStrip1->Size = System::Drawing::Size(704, 25);
			toolStrip1->TabIndex = 1;
			toolStrip1->Text = L"toolStrip";
			// 
			// openButton
			// 
			this->openButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->openButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->openButton->Name = L"openButton";
			this->openButton->Size = System::Drawing::Size(23, 22);
			this->openButton->Text = L"toolStripButton1";
			this->openButton->ToolTipText = L"Open";
			this->openButton->Click += gcnew System::EventHandler(this, &MainForm::openFileDialog);
			// 
			// saveButton
			// 
			this->saveButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->saveButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(23, 22);
			this->saveButton->Text = L"toolStripButton2";
			this->saveButton->ToolTipText = L"Save";
			this->saveButton->Click += gcnew System::EventHandler(this, &MainForm::saveFileDialog);
			// 
			// clearButton
			// 
			this->clearButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->clearButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(23, 22);
			this->clearButton->Text = L"toolStripButton3";
			this->clearButton->ToolTipText = L"Clear";
			this->clearButton->Click += gcnew System::EventHandler(this, &MainForm::clear);
			// 
			// fileEncodings
			// 
			this->fileEncodings->Name = L"fileEncodings";
			this->fileEncodings->Size = System::Drawing::Size(121, 25);
			// 
			// saveProgress
			// 
			this->saveProgress->Name = L"saveProgress";
			this->saveProgress->Size = System::Drawing::Size(100, 22);
			// 
			// statusStrip1
			// 
			statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->filenameLabel });
			statusStrip1->Location = System::Drawing::Point(0, 579);
			statusStrip1->Name = L"statusStrip1";
			statusStrip1->Size = System::Drawing::Size(704, 22);
			statusStrip1->TabIndex = 3;
			statusStrip1->Text = L"statusStrip1";
			// 
			// filenameLabel
			// 
			this->filenameLabel->Name = L"filenameLabel";
			this->filenameLabel->Size = System::Drawing::Size(102, 17);
			this->filenameLabel->Text = L"Файл не відкрито";
			// 
			// editor
			// 
			this->editor->Location = System::Drawing::Point(150, 63);
			this->editor->Name = L"editor";
			this->editor->Size = System::Drawing::Size(400, 513);
			this->editor->TabIndex = 2;
			this->editor->Text = L"";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(704, 601);
			this->Controls->Add(statusStrip1);
			this->Controls->Add(this->editor);
			this->Controls->Add(toolStrip1);
			this->Controls->Add(menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"File Reencoder";
			this->Load += gcnew System::EventHandler(this, &MainForm::Main_Load);
			menuStrip1->ResumeLayout(false);
			menuStrip1->PerformLayout();
			toolStrip1->ResumeLayout(false);
			toolStrip1->PerformLayout();
			statusStrip1->ResumeLayout(false);
			statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: void openFileDialog(System::Object^ sender, System::EventArgs^ e) {
			auto dialog = gcnew OpenFileDialog();
			dialog->Filter = "Text Files|*.txt";
			dialog->Title = "Select a Text File";

			if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				auto sr = gcnew System::IO::StreamReader(dialog->FileName);
				this->editor->Text = sr->ReadToEnd();
				sr->Close();
				filenameLabel->Text = dialog->FileName;
			}
		}

		private: void saveFileDialog(System::Object^ sender, System::EventArgs^ e) {
			auto dialog = gcnew SaveFileDialog();
			dialog->Filter = "Text Files|*.txt";
			dialog->Title = "Save a Text File";

			if (dialog->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
				return;
			}

			saveProgress->Value = 0;
			auto sw = gcnew System::IO::StreamWriter(dialog->FileName);
			if (fileEncodings->Text == "UTF-8") {
				sw->Write(converter->toUtf8(this->editor->Text));
				saveProgress->Value = 100;
			} else if (fileEncodings->Text == "UTF-16") {
				auto chars = converter->toUtf16(this->editor->Text);

				for (int i = 0; i < chars->Length; i++) {
					sw->Write(chars[i] >> 8);
					sw->Write((unsigned char) chars[i]);
					saveProgress->Value = (i + 1) * (100.0 / chars->Length);
				}
			} else if (fileEncodings->Text == "UTF-32") {
				auto chars = converter->toUtf32(this->editor->Text);

				for (int i = 0; i < chars->Length; i++) {
					sw->Write(chars[i]);
					saveProgress->Value = (i + 1) * (100.0 / chars->Length);
				}
			} else if (fileEncodings->Text == "Binary") {
				sw->Write(converter->toBinary(this->editor->Text));
			}
			filenameLabel->Text = dialog->FileName;
			sw->Close();
		}

		private: System::Void вийтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}

		private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
			fileEncodings->Items->Add("UTF-8");
			fileEncodings->Items->Add("UTF-16");
			fileEncodings->Items->Add("UTF-32");
			fileEncodings->Items->Add("Binary");

			fileEncodings->SelectedIndex = 0;

			openButton->Image = Image::FromFile("open.png");
			saveButton->Image = Image::FromFile("save.png");
			clearButton->Image = Image::FromFile("clear.png");
		}

		private: System::Void проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			aboutForm->ShowDialog();
		}

		private: System::Void clear(System::Object^ sender, System::EventArgs^ e) {
			this->editor->Clear();
			filenameLabel->Text = L"Файл закрито";
		}
	};
}
