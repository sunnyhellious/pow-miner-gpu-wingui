#pragma once

namespace tonpowminergpuwingui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public:
		SettingsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void Update(void) {

			if (this->AutoStartMinersFlag)
				this->comboBox1->SelectedIndex = 1;
			else
				this->comboBox1->SelectedIndex = 0;

			
			switch (this->DumpLogsMode) {
				case 0: 
				case 1:
				case 2: this->comboBox2->SelectedIndex = this->DumpLogsMode; break;
				default: break;
			}


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(304, 55);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(199, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Start miners right after GUI starts options:";
			this->label1->Click += gcnew System::EventHandler(this, &SettingsForm::label2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Do not start any miner", L"Start all miners" });
			this->comboBox1->Location = System::Drawing::Point(9, 25);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(284, 21);
			this->comboBox1->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(7, 115);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Apply";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SettingsForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(88, 115);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Cancel";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &SettingsForm::button3_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->comboBox2);
			this->groupBox2->Location = System::Drawing::Point(0, 61);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(304, 48);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Dump logs/errors to files";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Do not dump anything", L"Dump to files only ERRORS",
					L"Dump to files all LOGS"
			});
			this->comboBox2->Location = System::Drawing::Point(9, 19);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(284, 21);
			this->comboBox2->TabIndex = 4;
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(305, 149);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button2);
			this->Name = L"SettingsForm";
			this->Text = L"Settings";
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	

	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	public: bool NewSettingsApplied		= false;
	public: bool AutoStartMinersFlag	= false;
	public: int	 DumpLogsMode 			= false;

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		
		this->AutoStartMinersFlag = this->comboBox1->SelectedIndex == 1 ? true : false;
		this->DumpLogsMode = this->comboBox2->SelectedIndex;
				
		this->NewSettingsApplied = true;

		this->Close();

	}
	
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

		this->AutoStartMinersFlag = this->comboBox1->SelectedIndex == 1 ? true : false;

		this->NewSettingsApplied = false;
		
		this->Close();
		
	}

private: System::Void SettingsForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
