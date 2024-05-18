#pragma once

namespace app {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AboutForm : public System::Windows::Forms::Form
	{
	public:
		AboutForm(void)
		{
			InitializeComponent();
		}

	protected:
		~AboutForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ appDescription;
	private: System::Windows::Forms::PictureBox^ appIcon;

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::GroupBox^ gbInfo;
			System::Windows::Forms::Label^ lblRights;
			System::Windows::Forms::Label^ lblAuthor;
			System::Windows::Forms::Label^ lblVersion;
			System::Windows::Forms::Label^ lblName;
			System::Windows::Forms::Button^ btnClose;
			this->appDescription = (gcnew System::Windows::Forms::Label());
			this->appIcon = (gcnew System::Windows::Forms::PictureBox());
			gbInfo = (gcnew System::Windows::Forms::GroupBox());
			lblRights = (gcnew System::Windows::Forms::Label());
			lblAuthor = (gcnew System::Windows::Forms::Label());
			lblVersion = (gcnew System::Windows::Forms::Label());
			lblName = (gcnew System::Windows::Forms::Label());
			btnClose = (gcnew System::Windows::Forms::Button());
			gbInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->appIcon))->BeginInit();
			this->SuspendLayout();
			// 
			// gbInfo
			// 
			gbInfo->Controls->Add(this->appDescription);
			gbInfo->Location = System::Drawing::Point(14, 172);
			gbInfo->Name = L"gbInfo";
			gbInfo->Size = System::Drawing::Size(411, 149);
			gbInfo->TabIndex = 14;
			gbInfo->TabStop = false;
			// 
			// appDescription
			// 
			this->appDescription->AutoSize = true;
			this->appDescription->Location = System::Drawing::Point(11, 22);
			this->appDescription->Name = L"appDescription";
			this->appDescription->Size = System::Drawing::Size(0, 13);
			this->appDescription->TabIndex = 7;
			// 
			// lblRights
			// 
			lblRights->AutoSize = true;
			lblRights->Location = System::Drawing::Point(167, 125);
			lblRights->Name = L"lblRights";
			lblRights->Size = System::Drawing::Size(104, 13);
			lblRights->TabIndex = 13;
			lblRights->Text = L"Всі права захищені";
			// 
			// lblAuthor
			// 
			lblAuthor->AutoSize = true;
			lblAuthor->Location = System::Drawing::Point(167, 97);
			lblAuthor->Name = L"lblAuthor";
			lblAuthor->Size = System::Drawing::Size(155, 13);
			lblAuthor->TabIndex = 12;
			lblAuthor->Text = L"Розробник: ст. гр. ПІ-21б ПІБ";
			// 
			// lblVersion
			// 
			lblVersion->AutoSize = true;
			lblVersion->Location = System::Drawing::Point(167, 67);
			lblVersion->Name = L"lblVersion";
			lblVersion->Size = System::Drawing::Size(70, 13);
			lblVersion->TabIndex = 11;
			lblVersion->Text = L"Версія: 1.0.0";
			// 
			// lblName
			// 
			lblName->AutoSize = true;
			lblName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			lblName->Location = System::Drawing::Point(167, 38);
			lblName->Name = L"lblName";
			lblName->Size = System::Drawing::Size(29, 13);
			lblName->TabIndex = 10;
			lblName->Text = L"Yoo";
			// 
			// btnClose
			// 
			btnClose->DialogResult = System::Windows::Forms::DialogResult::OK;
			btnClose->Location = System::Drawing::Point(187, 350);
			btnClose->Name = L"btnClose";
			btnClose->Size = System::Drawing::Size(75, 23);
			btnClose->TabIndex = 8;
			btnClose->Text = L"Закрити";
			btnClose->UseVisualStyleBackColor = true;
			btnClose->Click += gcnew System::EventHandler(this, &AboutForm::btnClose_Click);
			// 
			// appIcon
			// 
			this->appIcon->Location = System::Drawing::Point(28, 27);
			this->appIcon->Name = L"appIcon";
			this->appIcon->Size = System::Drawing::Size(128, 128);
			this->appIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->appIcon->TabIndex = 9;
			this->appIcon->TabStop = false;
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(438, 405);
			this->Controls->Add(gbInfo);
			this->Controls->Add(lblRights);
			this->Controls->Add(lblAuthor);
			this->Controls->Add(lblVersion);
			this->Controls->Add(lblName);
			this->Controls->Add(this->appIcon);
			this->Controls->Add(btnClose);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"AboutForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Про застосунок";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AboutForm::AboutForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AboutForm::AboutForm_Load);
			gbInfo->ResumeLayout(false);
			gbInfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->appIcon))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Hide();
		}

		private: System::Void AboutForm_Load(System::Object^ sender, System::EventArgs^ e) {
			 appIcon->Image = Image::FromFile("icon.png");

			appDescription->Text =
				L"Тема роботи ''\n"
				L"Застосунок виконано відповідно до індивідуального завдання\n"
				L"Застосунок дозволяє\n"
				L"1. бла бла\n"
				L"2. бла бла\n"
				L"3. бла бла\n"
				L"4. бла бла\n"
				L"5. бла бла";
		}

		private: System::Void AboutForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			e->Cancel = true;
			this->Hide();
		}
	};
}
