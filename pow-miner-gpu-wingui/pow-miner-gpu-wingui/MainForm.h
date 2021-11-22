#pragma once

#include "AboutForm.h"

#include <windows.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>
#include <comdef.h>
#include <io.h>
#include <fcntl.h>

#include "AppSysSubProcess.h"

namespace powminergpuwingui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::GroupBox^  DevicesGroupBox;

	private: System::Windows::Forms::ListBox^  Devices;
	private: System::Windows::Forms::Button^  SearchDevicesButton;





	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->DevicesGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->Devices = (gcnew System::Windows::Forms::ListBox());
			this->SearchDevicesButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->DevicesGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1269, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ExitCallback);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::AboutCallback);
			// 
			// DevicesGroupBox
			// 
			this->DevicesGroupBox->Controls->Add(this->Devices);
			this->DevicesGroupBox->Controls->Add(this->SearchDevicesButton);
			this->DevicesGroupBox->Location = System::Drawing::Point(12, 27);
			this->DevicesGroupBox->Name = L"DevicesGroupBox";
			this->DevicesGroupBox->Size = System::Drawing::Size(1245, 524);
			this->DevicesGroupBox->TabIndex = 3;
			this->DevicesGroupBox->TabStop = false;
			// 
			// Devices
			// 
			this->Devices->FormattingEnabled = true;
			this->Devices->Location = System::Drawing::Point(6, 48);
			this->Devices->Name = L"Devices";
			this->Devices->Size = System::Drawing::Size(1233, 108);
			this->Devices->TabIndex = 1;
			// 
			// SearchDevicesButton
			// 
			this->SearchDevicesButton->Location = System::Drawing::Point(6, 19);
			this->SearchDevicesButton->Name = L"SearchDevicesButton";
			this->SearchDevicesButton->Size = System::Drawing::Size(304, 23);
			this->SearchDevicesButton->TabIndex = 0;
			this->SearchDevicesButton->Text = L"Search devices";
			this->SearchDevicesButton->UseVisualStyleBackColor = true;
			this->SearchDevicesButton->Click += gcnew System::EventHandler(this, &MainForm::SearchDevicesButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1269, 563);
			this->Controls->Add(this->DevicesGroupBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->DevicesGroupBox->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void ExitCallback(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}

private: System::Void AboutCallback(System::Object^  sender, System::EventArgs^  e) {
	// this->Hide();
	powminergpuwingui::AboutForm AboutFormObject;
	AboutFormObject.ShowDialog();
	// this->Show();
}
private: System::Void SearchDevicesButton_Click(System::Object^  sender, System::EventArgs^  e) {
	
/*

	char	psBuffer[128];
	FILE   *pPipe;

	// std::vector<std::string> devices_vect;
	std::vector<std::string> devices_vect;

	if ((pPipe = _popen("\"D:\\Program Files (other)\\pow-miner-gpu\\minertools-cuda-windows-x86-64\\pow-miner-cuda.exe\" 2>&1", "rt")) == NULL)
		return;

	devices_vect.push_back(std::string("\"D:\\Program Files (other)\\pow-miner-gpu\\minertools-cuda-windows-x86-64\\pow-miner-cuda.exe\" 2>&1"));
		
	while (fgets(psBuffer, 128, pPipe))
	{	
		OutputDebugStringA(psBuffer);
		devices_vect.push_back(std::string(psBuffer));
	}
	
	if (feof(pPipe))
	{
		sprintf(psBuffer, "\nProcess returned %d\n", _pclose(pPipe));
		devices_vect.push_back(std::string(psBuffer));
	}
	else
	{
		sprintf(psBuffer, "Error: Failed to read the pipe to the end.\n");
		devices_vect.push_back(std::string(psBuffer));
	}

	Devices->BeginUpdate();

	Devices->Items->Clear();

	for (int i = 0; i < devices_vect.size(); i++){
		Devices->Items->Add(gcnew String(devices_vect.at(i).c_str()));
		OutputDebugStringA(devices_vect.at(i).c_str());
	}

	Devices->EndUpdate();

*/
	AppSysSubProcess AppSysSubProcess_0;

	AppSysSubProcess_0.Run("\"D:\\Program Files (other)\\pow-miner-gpu\\minertools-opencl-windows-x86-64\\pow-miner-opencl.exe\"", "2>&1"); // 

	Devices->BeginUpdate();

	Devices->Items->Clear();

	for (int i = 0; i < AppSysSubProcess_0.data.size(); i++) {
		Devices->Items->Add(gcnew String(AppSysSubProcess_0.data.at(i).c_str()));
		OutputDebugStringA(AppSysSubProcess_0.data.at(i).c_str());
	}

	Devices->EndUpdate();

}
};
}
