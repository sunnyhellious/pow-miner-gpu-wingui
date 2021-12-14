#pragma once

#include "AppSysSubProcess.h"

namespace tonpowminergpuwingui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UpdateToolsForm
	/// </summary>
	public ref class UpdateToolsForm : public System::Windows::Forms::Form
	{
	public:
		UpdateToolsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			// Run();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UpdateToolsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  UpdateToolsTextBox;
	private: System::Windows::Forms::Button^  UpdOkButton;
	private: System::Windows::Forms::Timer^  timer1;



	private: System::ComponentModel::IContainer^  components;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UpdateToolsForm::typeid));
			this->UpdateToolsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->UpdOkButton = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// UpdateToolsTextBox
			// 
			this->UpdateToolsTextBox->Location = System::Drawing::Point(12, 12);
			this->UpdateToolsTextBox->Multiline = true;
			this->UpdateToolsTextBox->Name = L"UpdateToolsTextBox";
			this->UpdateToolsTextBox->ReadOnly = true;
			this->UpdateToolsTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->UpdateToolsTextBox->Size = System::Drawing::Size(626, 381);
			this->UpdateToolsTextBox->TabIndex = 34;
			// 
			// UpdOkButton
			// 
			this->UpdOkButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UpdOkButton.BackgroundImage")));
			this->UpdOkButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->UpdOkButton->Location = System::Drawing::Point(588, 399);
			this->UpdOkButton->Name = L"UpdOkButton";
			this->UpdOkButton->Size = System::Drawing::Size(50, 50);
			this->UpdOkButton->TabIndex = 35;
			this->UpdOkButton->UseVisualStyleBackColor = true;
			this->UpdOkButton->Click += gcnew System::EventHandler(this, &UpdateToolsForm::UpdOkButton_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &UpdateToolsForm::timer1_Tick);
			// 
			// UpdateToolsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(650, 461);
			this->Controls->Add(this->UpdOkButton);
			this->Controls->Add(this->UpdateToolsTextBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(666, 500);
			this->MinimumSize = System::Drawing::Size(666, 500);
			this->Name = L"UpdateToolsForm";
			this->Text = L"Update tools";
			this->Load += gcnew System::EventHandler(this, &UpdateToolsForm::UpdateToolsForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: void Run(void)
		{

			this->UpdateToolsTextBox->WordWrap = false;

			std::string gl_conf_url = "https://newton-blockchain.github.io/global.config.json";
			std::string opencl_url	= "https://github.com/tontechio/pow-miner-gpu/releases/latest/download/minertools-opencl-windows-x86-64.zip";
			std::string cuda_url	= "https://github.com/tontechio/pow-miner-gpu/releases/latest/download/minertools-cuda-windows-x86-64.zip";
			
			AppSysSubProcess AppSysSubProcess_Dl;

			bool errors_exists = false;

			//////////////////////// NET CONFIG

			this->UpdateToolsTextBox->AppendText("1. Trying to download \"global.config.json\" from \"" + gcnew String(gl_conf_url.c_str()) + "\"\r\n\r\n" );
			
			AppSysSubProcess_Dl.Run("\"" + AppSysSubProcess::ExePath() + "\\tools\\wget\\wget.exe\"" + " --timeout=1 --tries=5 -N " + gl_conf_url, "", AppSysSubProcess::ExePath() + "\\config", true);
			for( int i = 0; i < AppSysSubProcess_Dl.stdoutData.size(); i++ )
				this->UpdateToolsTextBox->AppendText(gcnew System::String(("\t"+AppSysSubProcess_Dl.stdoutData.at(i)+"\r\n").c_str()));
			AppSysSubProcess_Dl.stdoutData.clear();
			// if(AppSysSubProcess::DownloadFileFromUrl(gl_conf_url, AppSysSubProcess::ExePath() + "\\config\\global.config.json"))
			if(AppSysSubProcess_Dl.exitcode != 0) {
				this->UpdateToolsTextBox->AppendText("\r\n\tFAILED\r\n");
				errors_exists = true;
			}
			else
				this->UpdateToolsTextBox->AppendText("\r\n\tSUCCESS\r\n");

			//////////////////////// OPENCL 

			this->UpdateToolsTextBox->AppendText("\r\n2.0. Trying to download \"minertools-opencl-windows-x86-64.zip\" from \"" + gcnew String(opencl_url.c_str()) + "\"\r\n\r\n");

			AppSysSubProcess_Dl.Run("\"" + AppSysSubProcess::ExePath() + "\\tools\\wget\\wget.exe\"" + " --timeout=1 --tries=5 -N " + opencl_url, "", AppSysSubProcess::ExePath() + "\\tools", true);
			for (int i = 0; i < AppSysSubProcess_Dl.stdoutData.size(); i++)
				this->UpdateToolsTextBox->AppendText(gcnew System::String(("\t" + AppSysSubProcess_Dl.stdoutData.at(i) + "\r\n").c_str()));
			AppSysSubProcess_Dl.stdoutData.clear();
			// if (AppSysSubProcess::DownloadFileFromUrl(opencl_url, AppSysSubProcess::ExePath() + "\\tools\\minertools-opencl-windows-x86-64.zip"))
			if (AppSysSubProcess_Dl.exitcode != 0) {
				this->UpdateToolsTextBox->AppendText("\r\n\tFAILED\r\n");
				errors_exists = true;
			}
			else
				this->UpdateToolsTextBox->AppendText("\r\n\tSUCCESS\r\n");

			//////////////////////// OPENCL UNZIP

			this->UpdateToolsTextBox->AppendText("\r\n2.1. Trying to unzip \"minertools-opencl-windows-x86-64.zip\"\r\n");
			if (AppSysSubProcess::UnzipToFolder(AppSysSubProcess::ExePath() + "\\tools\\minertools-opencl-windows-x86-64.zip", AppSysSubProcess::ExePath() + "\\tools\\minertools")) {
				this->UpdateToolsTextBox->AppendText("\r\n\tFAILED\r\n");
				errors_exists = true;
			}				
			else
				this->UpdateToolsTextBox->AppendText("\r\n\tSUCCESS\r\n");

			//////////////////////// CUDA
			
			this->UpdateToolsTextBox->AppendText("\r\n3.0. Trying to download \"minertools-cuda-windows-x86-64.zip\" from \"" + gcnew String(cuda_url.c_str()) + "\"\r\n\r\n");

			AppSysSubProcess_Dl.Run("\"" + AppSysSubProcess::ExePath() + "\\tools\\wget\\wget.exe\"" + " --timeout=1 --tries=5 -N " + cuda_url, "", AppSysSubProcess::ExePath() + "\\tools", true);
			for (int i = 0; i < AppSysSubProcess_Dl.stdoutData.size(); i++)
				this->UpdateToolsTextBox->AppendText(gcnew System::String(("\t" + AppSysSubProcess_Dl.stdoutData.at(i) + "\r\n").c_str()));
			AppSysSubProcess_Dl.stdoutData.clear();
			// if (AppSysSubProcess::DownloadFileFromUrl(cuda_url, AppSysSubProcess::ExePath() + "\\tools\\minertools-cuda-windows-x86-64.zip"))
			if (AppSysSubProcess_Dl.exitcode != 0){
				this->UpdateToolsTextBox->AppendText("\r\n\tFAILED\r\n");
				errors_exists = true;
			}
			else
				this->UpdateToolsTextBox->AppendText("\r\n\tSUCCESS\r\n");

			//////////////////////// CUDA UNZIP

			this->UpdateToolsTextBox->AppendText("\r\n3.1. Trying to unzip \"minertools-cuda-windows-x86-64.zip\"\r\n");
			if (AppSysSubProcess::UnzipToFolder(AppSysSubProcess::ExePath() + "\\tools\\minertools-cuda-windows-x86-64.zip", AppSysSubProcess::ExePath() + "\\tools\\minertools")) {
				this->UpdateToolsTextBox->AppendText("\r\n\tFAILED\r\n");
				errors_exists = true;
			}
			else
				this->UpdateToolsTextBox->AppendText("\r\n\tSUCCESS\r\n");

			//////////////////////// 

			this->UpdateToolsTextBox->AppendText("\r\n\///////////////////////////////////////////////\r\n");

			if(errors_exists)
				this->UpdateToolsTextBox->AppendText("\r\n\tWE HAD PROBLEMS, PLEASE REVIEW THIS LOG AND CHECK THE INTERNET\r\n");
			else
				this->UpdateToolsTextBox->AppendText("\r\n\tEVERYTHING SEEMS TO BE FINE\r\n");

			
			
		}

	private: System::Void UpdateToolsForm_Load(System::Object^  sender, System::EventArgs^  e) {

		// this->Run();

		UpdOkButton->Enabled = false();

		timer1->Interval = 100;

		timer1->Start();
	
	}


private: System::Void UpdOkButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}



private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	timer1->Stop();
	
	this->Run();

	UpdOkButton->Enabled = true;

}
};
}
