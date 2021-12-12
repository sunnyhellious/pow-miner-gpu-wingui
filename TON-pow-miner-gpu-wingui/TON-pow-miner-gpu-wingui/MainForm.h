#pragma once

#include "AboutForm.h"
#include <msclr\marshal_cppstd.h>

#include <windows.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>
#include <comdef.h>
#include <io.h>
#include <fcntl.h>

#include "AppSysSubProcess.h"
#include "MinerConfig.h"

#include "DeviceTab.h"

#include "UpdateToolsForm.h"

#include "MapVoid.h"

#include <msclr\marshal.h>

#include "SettingsForm.h"

#include "mjson.h"

using namespace System;
using namespace msclr::interop;

void stopall_thread(void);

namespace tonpowminergpuwingui {

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

	public: static MainForm^ MainForm_0;

	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора

			MainForm_0 = this;

			CreateDirectoryA((AppSysSubProcess::ExePath() + "\\config\\autosave_dumps").c_str(), NULL);
			CreateDirectoryA((AppSysSubProcess::ExePath() + "\\miners").c_str(), NULL);
			CreateDirectoryA((AppSysSubProcess::ExePath() + "\\logs_dumps").c_str(), NULL);

			AppSysSubProcess AppSysSubProcess_Dl_Config;

			AppSysSubProcess_Dl_Config.Run("\"" + AppSysSubProcess::ExePath() + "\\tools\\wget\\wget.exe\"" + " --timeout=1 --tries=5 -N https://newton-blockchain.github.io/global.config.json", "",
				AppSysSubProcess::ExePath() + "\\config", true);



			DeviceTabsMap = new MapVoid();

			LoadConfig();

			if (this->sets_startm_ragui) {
				this->StartAll();
			}

			timer1->Interval = 100;
			timer1->Start();

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
	private: System::Windows::Forms::ToolStripMenuItem^  importSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  updateToolsToolStripMenuItem;
	private: System::Windows::Forms::ListBox^  DevicesListBox;
	private: System::Windows::Forms::Button^  SearchCUDADevicesButton;
	private: System::Windows::Forms::Button^  UseDeviceButton;
	private: System::Windows::Forms::Button^  SearchOpenCLDevicesButton;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;

	public: System::Windows::Forms::TabControl^  DevicesTabControl;

	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  StartAllButton;
	private: System::Windows::Forms::Button^  StopAllButton;
	private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  RigHashTextBox;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->updateToolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->DevicesListBox = (gcnew System::Windows::Forms::ListBox());
			this->SearchCUDADevicesButton = (gcnew System::Windows::Forms::Button());
			this->UseDeviceButton = (gcnew System::Windows::Forms::Button());
			this->SearchOpenCLDevicesButton = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->StartAllButton = (gcnew System::Windows::Forms::Button());
			this->StopAllButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->RigHashTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DevicesTabControl = (gcnew System::Windows::Forms::TabControl());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
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
			this->menuStrip1->Size = System::Drawing::Size(1444, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->settingsToolStripMenuItem,
					this->importSettingsToolStripMenuItem, this->exportSettingsToolStripMenuItem, this->updateToolsToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->settingsToolStripMenuItem->Text = L"Settings";
			this->settingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::settingsToolStripMenuItem_Click);
			// 
			// importSettingsToolStripMenuItem
			// 
			this->importSettingsToolStripMenuItem->Name = L"importSettingsToolStripMenuItem";
			this->importSettingsToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->importSettingsToolStripMenuItem->Text = L"Import settings";
			this->importSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::importSettingsToolStripMenuItem_Click);
			// 
			// exportSettingsToolStripMenuItem
			// 
			this->exportSettingsToolStripMenuItem->Name = L"exportSettingsToolStripMenuItem";
			this->exportSettingsToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->exportSettingsToolStripMenuItem->Text = L"Export settings";
			this->exportSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exportSettingsToolStripMenuItem_Click);
			// 
			// updateToolsToolStripMenuItem
			// 
			this->updateToolsToolStripMenuItem->Name = L"updateToolsToolStripMenuItem";
			this->updateToolsToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->updateToolsToolStripMenuItem->Text = L"Update tools";
			this->updateToolsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::updateToolsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(154, 22);
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
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// DevicesListBox
			// 
			this->DevicesListBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->DevicesListBox->FormattingEnabled = true;
			this->DevicesListBox->HorizontalScrollbar = true;
			this->DevicesListBox->Location = System::Drawing::Point(3, 32);
			this->DevicesListBox->MaximumSize = System::Drawing::Size(310, 375);
			this->DevicesListBox->MinimumSize = System::Drawing::Size(310, 375);
			this->DevicesListBox->Name = L"DevicesListBox";
			this->DevicesListBox->Size = System::Drawing::Size(310, 368);
			this->DevicesListBox->TabIndex = 3;
			// 
			// SearchCUDADevicesButton
			// 
			this->SearchCUDADevicesButton->Dock = System::Windows::Forms::DockStyle::Top;
			this->SearchCUDADevicesButton->Location = System::Drawing::Point(3, 3);
			this->SearchCUDADevicesButton->Name = L"SearchCUDADevicesButton";
			this->SearchCUDADevicesButton->Size = System::Drawing::Size(152, 23);
			this->SearchCUDADevicesButton->TabIndex = 1;
			this->SearchCUDADevicesButton->Text = L"Search CUDA devices";
			this->SearchCUDADevicesButton->UseVisualStyleBackColor = true;
			this->SearchCUDADevicesButton->Click += gcnew System::EventHandler(this, &MainForm::SearchCUDADevicesButton_Click);
			// 
			// UseDeviceButton
			// 
			this->UseDeviceButton->Dock = System::Windows::Forms::DockStyle::Top;
			this->UseDeviceButton->Location = System::Drawing::Point(3, 413);
			this->UseDeviceButton->Name = L"UseDeviceButton";
			this->UseDeviceButton->Size = System::Drawing::Size(310, 23);
			this->UseDeviceButton->TabIndex = 4;
			this->UseDeviceButton->Text = L"Use device";
			this->UseDeviceButton->UseVisualStyleBackColor = true;
			this->UseDeviceButton->Click += gcnew System::EventHandler(this, &MainForm::UseDeviceButton_Click);
			// 
			// SearchOpenCLDevicesButton
			// 
			this->SearchOpenCLDevicesButton->Dock = System::Windows::Forms::DockStyle::Top;
			this->SearchOpenCLDevicesButton->Location = System::Drawing::Point(161, 3);
			this->SearchOpenCLDevicesButton->Name = L"SearchOpenCLDevicesButton";
			this->SearchOpenCLDevicesButton->Size = System::Drawing::Size(152, 23);
			this->SearchOpenCLDevicesButton->TabIndex = 2;
			this->SearchOpenCLDevicesButton->Text = L"Search OpenCL devices";
			this->SearchOpenCLDevicesButton->UseVisualStyleBackColor = true;
			this->SearchOpenCLDevicesButton->Click += gcnew System::EventHandler(this, &MainForm::SearchOpenCLDevicesButton_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->SearchCUDADevicesButton);
			this->flowLayoutPanel1->Controls->Add(this->SearchOpenCLDevicesButton);
			this->flowLayoutPanel1->Controls->Add(this->DevicesListBox);
			this->flowLayoutPanel1->Controls->Add(this->UseDeviceButton);
			this->flowLayoutPanel1->Controls->Add(this->StartAllButton);
			this->flowLayoutPanel1->Controls->Add(this->StopAllButton);
			this->flowLayoutPanel1->Controls->Add(this->label1);
			this->flowLayoutPanel1->Controls->Add(this->RigHashTextBox);
			this->flowLayoutPanel1->Location = System::Drawing::Point(4, 24);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(316, 498);
			this->flowLayoutPanel1->TabIndex = 5;
			// 
			// StartAllButton
			// 
			this->StartAllButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->StartAllButton->Location = System::Drawing::Point(3, 442);
			this->StartAllButton->Name = L"StartAllButton";
			this->StartAllButton->Size = System::Drawing::Size(152, 23);
			this->StartAllButton->TabIndex = 5;
			this->StartAllButton->Text = L"Start all";
			this->StartAllButton->UseVisualStyleBackColor = false;
			this->StartAllButton->Click += gcnew System::EventHandler(this, &MainForm::StartAllButton_Click);
			// 
			// StopAllButton
			// 
			this->StopAllButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->StopAllButton->Location = System::Drawing::Point(161, 442);
			this->StopAllButton->Name = L"StopAllButton";
			this->StopAllButton->Size = System::Drawing::Size(152, 23);
			this->StopAllButton->TabIndex = 6;
			this->StopAllButton->Text = L"Stop all";
			this->StopAllButton->UseVisualStyleBackColor = false;
			this->StopAllButton->Click += gcnew System::EventHandler(this, &MainForm::StopAllButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(7, 474);
			this->label1->Margin = System::Windows::Forms::Padding(7, 6, 3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"RIG TOTAL HASHRATE:";
			// 
			// RigHashTextBox
			// 
			this->RigHashTextBox->Location = System::Drawing::Point(162, 471);
			this->RigHashTextBox->Margin = System::Windows::Forms::Padding(4, 3, 3, 3);
			this->RigHashTextBox->Name = L"RigHashTextBox";
			this->RigHashTextBox->Size = System::Drawing::Size(149, 20);
			this->RigHashTextBox->TabIndex = 7;
			// 
			// DevicesTabControl
			// 
			this->DevicesTabControl->Location = System::Drawing::Point(323, 24);
			this->DevicesTabControl->Name = L"DevicesTabControl";
			this->DevicesTabControl->SelectedIndex = 0;
			this->DevicesTabControl->Size = System::Drawing::Size(1118, 498);
			this->DevicesTabControl->TabIndex = 4;
			this->DevicesTabControl->Tag = L"";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1444, 525);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->DevicesTabControl);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1460, 564);
			this->MinimumSize = System::Drawing::Size(1460, 564);
			this->Name = L"MainForm";
			this->Text = L"TON-pow-miner-gpu-wingui";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void ExitCallback(System::Object^  sender, System::EventArgs^  e) {
	
	StopAll();
	SaveConfig(false);

	this->Close();
}

private: System::Void AboutCallback(System::Object^  sender, System::EventArgs^  e) {
	// this->Hide();
	tonpowminergpuwingui::AboutForm AboutFormObject;
	AboutFormObject.ShowDialog();
	// this->Show();
}

private: System::Void SearchOpenCLDevicesButton_Click(System::Object^  sender, System::EventArgs^  e) {
	
	AppSysSubProcess AppSysSubProcess_0;

	AppSysSubProcess_0.Run("\"" + AppSysSubProcess::ExePath() + "\\tools\\minertools\\pow-miner-opencl.exe\"", "2>&1", AppSysSubProcess::ExePath(), true);

	DevicesListBox->BeginUpdate();

	DevicesListBox->Items->Clear();

	std::string full_str = "";

	for (int i = 0; i < AppSysSubProcess_0.stdoutData.size(); i++) {

		// System::String^ Line = gcnew String(AppSysSubProcess_0.stdoutData.at(i).c_str());

		// if (Line->StartsWith("[ OpenCL: platform #"))
		//	DevicesListBox->Items->Add(Line);

		full_str += AppSysSubProcess_0.stdoutData.at(i).c_str();
		
	}

	System::String^ full_sstr = gcnew String(full_str.c_str());

	array<wchar_t> ^id = { '[', ']' };
	array<String^> ^StringArray_TMP = full_sstr->Split(id);

	bool found = false;

	for each(String^ temp in StringArray_TMP) {

		if (temp->Contains("OpenCL: platform #"))
			DevicesListBox->Items->Add("[" + temp + "]");
		
	}


	DevicesListBox->EndUpdate();
	   	
}

private: System::Void SearchCUDADevicesButton_Click(System::Object^  sender, System::EventArgs^  e) {

	AppSysSubProcess AppSysSubProcess_0;

	AppSysSubProcess_0.Run("\"" + AppSysSubProcess::ExePath() + "\\tools\\minertools\\pow-miner-cuda.exe\"", "2>&1", AppSysSubProcess::ExePath(), true);

	DevicesListBox->BeginUpdate();

	DevicesListBox->Items->Clear();

	std::string full_str = "";

	for (int i = 0; i < AppSysSubProcess_0.stdoutData.size(); i++) {

		// System::String^ Line = gcnew String(AppSysSubProcess_0.stdoutData.at(i).c_str());

		// if (Line->StartsWith("[ OpenCL: platform #"))
		//	DevicesListBox->Items->Add(Line);

		full_str += AppSysSubProcess_0.stdoutData.at(i).c_str();

	}

	// full_str = "[ GPU #1 ][ GPU #2 ]";

	System::String^ full_sstr = gcnew String(full_str.c_str());

	array<wchar_t> ^id = { '[', ']' };
	array<String^> ^StringArray_TMP = full_sstr->Split(id);

	bool found = false;

	for each(String^ temp in StringArray_TMP) {

		if (temp->Contains("GPU #"))
			DevicesListBox->Items->Add("[" + temp + "]");

	}


	DevicesListBox->EndUpdate();

}

private: tonpowminergpuwingui::DeviceTab ^DeviceTab_0;
private: int tabs_id_cnt = 0;

public: MapVoid *DeviceTabsMap;

private: System::Void UseDeviceButton_Click(System::Object^  sender, System::EventArgs^  e) {
	
	int type = 0;
	int pid	 = 0;
	int did	 = 0;

	if (DevicesListBox->SelectedItem) {
	
		System::String^ dev_sstr = DevicesListBox->GetItemText(DevicesListBox->SelectedItem);
		std::string dev_str = msclr::interop::marshal_as<std::string>(dev_sstr);

		if (dev_sstr->StartsWith("[ OpenCL: platform #")) {
			type = 1;
			if (sscanf(dev_str.c_str(), "[ OpenCL: platform #%d device #%d ", &pid, &did) != 2)
				return;
		} else if (dev_sstr->StartsWith("[ GPU #")) {
			type = 0;
			if (sscanf(dev_str.c_str(), "[ GPU #%d ", &did) != 1)
				return;
		} else {
			return;
		}

		DeviceTab_0 = (gcnew tonpowminergpuwingui::DeviceTab());

		DeviceTab_0->DevicesTabControl_Parent = this->DevicesTabControl;
		DeviceTab_0->GetTabPage()->Name = "miner" + "_" + System::Convert::ToString(this->tabs_id_cnt);
		DeviceTab_0->GetDevTypeComboBox()->SelectedIndex = type;
		DeviceTab_0->GetDevPidTextBox()->Text = gcnew String(std::to_string(pid).c_str());
		DeviceTab_0->GetDevDidTextBox()->Text = gcnew String(std::to_string(did).c_str());
		
		if (type == 0)
			DeviceTab_0->GetTabPage()->Text = gcnew String(("CUDA [" + std::to_string(pid) + ":" + std::to_string(did) + "]").c_str());
		else if (type == 1)
			DeviceTab_0->GetTabPage()->Text = gcnew String(("OCL [" + std::to_string(pid) + ":" + std::to_string(did) + "]").c_str());

		DevicesTabControl->TabPages->Add(DeviceTab_0->GetTabPage());

		DevicesTabControl->SelectedTab = DeviceTab_0->GetTabPage();

		DeviceTab_0->GetTabPage()->Show();

		std::string m_key = "miner_" + std::to_string(this->tabs_id_cnt);
		
		DeviceTabsMap->add_void(m_key, (void *) (void *)GCHandle::ToIntPtr(GCHandle::Alloc(DeviceTab_0)));

		tabs_id_cnt += 1;

			
	}

}

private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
}

public: delegate void DeviceTab_LogsTextBoxAddLine_Delagate(DeviceTab^ DeviceTab, System::String^ line);

public: void DeviceTab_LogsTextBoxAddLine(DeviceTab^ DeviceTab, System::String^ line) {

	if (DeviceTab->GetLogsTextBox()->InvokeRequired)
	{

		DeviceTab_LogsTextBoxAddLine_Delagate ^DLG = gcnew DeviceTab_LogsTextBoxAddLine_Delagate(this, &MainForm::DeviceTab_LogsTextBoxAddLine);

		if (this->IsHandleCreated)
			this->Invoke(DLG, DeviceTab, line);

	}
	else
	{

		// System::String^ dt_line = gcnew String(AppSysSubProcess::GetDateTime().c_str()) + gcnew String(": ") + line;		
		System::String^ dt_line = line;

		if (dt_line->Contains("FOUND")) {
			DeviceTab->GetLogsFoundsTextBox()->Text = dt_line;
			DeviceTab->AppSysSubProcess_0->DataVector.push_back(msclr::interop::marshal_as<std::string>(dt_line));
		}
		
		// best boost factor: 128

		if (dt_line->Contains("best boost factor:")) {

			char *p_char = NULL;

			if ((p_char = (char *) strstr(msclr::interop::marshal_as<std::string>(dt_line).c_str(), "best boost factor:")) != NULL) {

				int tmp_i;

				if (sscanf(p_char, "best boost factor: %d", &tmp_i) == 1) {

					DeviceTab->GetBoostFactorTextBox()->Text = gcnew System::String(std::to_string(tmp_i).c_str());

				}


				

			}

		}

		//

		if (dt_line->Contains("average speed:")) {
			
			array<wchar_t> ^id = { ':' ,',', '[', ']' };
			array<String^> ^StringArray_TMP = dt_line->Split(id);

			bool found = false;

			for each(String^ temp in StringArray_TMP) {

				if (found == true) {
					DeviceTab->GetHashSpeedTextBox()->Text = temp;
					break;
				}

				if (temp->Contains("average speed"))
					found = true;
				
					

			}
				
		}
						
		DeviceTab->GetLogsTextBox()->AppendText(dt_line);		

		int max_lines_qnt = int::Parse( DeviceTab->GetLogsMaxLinesTextBox()->Text );
				
		array <String^>^ string_array_temp = DeviceTab->GetLogsTextBox()->Text->Split('\n');

		int lines_qnt = string_array_temp->Length;
		
		// OutputDebugStringA((std::string("max_lines_qnt: ") + std::to_string(max_lines_qnt) + std::string("\n\r")).c_str());
		// OutputDebugStringA((std::string("lines_qnt: ") + std::to_string(lines_qnt) + std::string("\n\r")).c_str());
	
		if (lines_qnt > max_lines_qnt) {

			DeviceTab->GetLogsTextBox()->Text = "";

			// TODO make normal rotation
			/*
			if (string_array_temp->Length == lines_qnt) {

				DeviceTab->GetLogsTextBox()->Text = "";

				for (int i = (lines_qnt - max_lines_qnt); i < (lines_qnt); i++) {

					DeviceTab->GetLogsTextBox()->AppendText(string_array_temp[i]);
					DeviceTab->GetLogsTextBox()->AppendText("\n");

				}

			}
			*/

		}

		if (this->sets_dump_logs_mode == 2) {

			std::string dt_str = DeviceTab->AppSysSubProcess_0->time_stamp;
			std::string dest_file_str = AppSysSubProcess::ExePath() + "\\logs_dumps\\" + "logs_%s_%s_" + "%s" + ".txt";
			char dest_file_char[2048] = { "" };

			char text[128];
			strcpy(text, msclr::interop::marshal_as<std::string>(DeviceTab->GetTabPage()->Text).c_str());

			for (int i = 0; i < strlen(text); i++) {
				switch (text[i]) {
				case ' ':
				case '[':
				case ']':
				case ':': text[i] = '_'; break;
				default: break;
				}
			}

			sprintf(dest_file_char, dest_file_str.c_str(), DeviceTab->GetTabPage()->Name, text, dt_str.c_str());

			AppSysSubProcess::AppendLineToFile(dest_file_char, &msclr::interop::marshal_as<std::string>(dt_line));

		}

		//

		if (dt_line->Contains("ERR") || dt_line->Contains("err") || dt_line->Contains("Err") ) {

			DeviceTab->GetErrorsTextBox()->AppendText(dt_line);			

			if (this->sets_dump_logs_mode == 1) {
				
				std::string dt_str = DeviceTab->AppSysSubProcess_0->time_stamp;
				std::string dest_file_str = AppSysSubProcess::ExePath() + "\\logs_dumps\\" + "errors_%s_%s_" + "%s" + ".txt";
				char dest_file_char[2048] = { "" };

				char text[128];
				strcpy(text, msclr::interop::marshal_as<std::string>(DeviceTab->GetTabPage()->Text).c_str());

				for (int i = 0; i < strlen(text); i++) {
					switch (text[i]) {
						case ' ':
						case '[':
						case ']':
						case ':': text[i] = '_'; break;
						default: break;
					}
				}

				sprintf(dest_file_char, dest_file_str.c_str(), DeviceTab->GetTabPage()->Name, text, dt_str.c_str());

				AppSysSubProcess::AppendLineToFile(dest_file_char, &msclr::interop::marshal_as<std::string>(dt_line));

			}	

			int max_lines_qnt = int::Parse(DeviceTab->GetLogsMaxLinesTextBox()->Text);

			array <String^>^ string_array_temp = DeviceTab->GetErrorsTextBox()->Text->Split('\n');

			int lines_qnt = string_array_temp->Length;

			if (lines_qnt > max_lines_qnt) {

				DeviceTab->GetErrorsTextBox()->Text = "";

			}

		}
		
	}

}


private: System::Void updateToolsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	tonpowminergpuwingui::UpdateToolsForm UpdateToolsFormObject;
	UpdateToolsFormObject.ShowDialog();

}

public: std::string MarshalString(String ^ s) {
	using namespace Runtime::InteropServices;
	std::string str;

	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	str = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return str;
}

private: System::Void exportSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	this->saveFileDialog1->Filter = "JSON file|*.json";
	this->saveFileDialog1->Title = "Export settings to file";
	this->saveFileDialog1->ShowDialog();

	if (this->saveFileDialog1->FileName != "")
	{
		// System::IO::FileStream^ fs = (System::IO::FileStream^) this->saveFileDialog1->OpenFile();

		marshal_context context;

		std::string file_name_str = MarshalString(this->saveFileDialog1->FileName);
		// std::string file_name_str = AppSysSubProcess::ExePath() + "\\config\\autosave.config.json";

		// OutputDebugStringA(file_name_str.c_str());

		SaveConfig_ToFile(file_name_str);
		
		// fs->Close();

	}

}

private: System::Void importSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		
	this->openFileDialog1->Filter = "JSON file|*.json";
	this->openFileDialog1->Title = "Import settings from file";
	this->openFileDialog1->ShowDialog();

	if (this->openFileDialog1->FileName != "")
	{
		// System::IO::FileStream^ fs = (System::IO::FileStream^) this->openFileDialog1->OpenFile();

		marshal_context context;

		std::string file_name_str = MarshalString(this->openFileDialog1->FileName);
		// std::string file_name_str = AppSysSubProcess::ExePath() + "\\config\\autosave.config.json";

		// OutputDebugStringA(file_name_str.c_str());

		if (LoadConfig_FromFile(file_name_str, true) != 0 )
			return;

		SaveConfig(true);

		DeleteAll();

		this->tabs_id_cnt = 0;

		if (LoadConfig_FromFile(file_name_str, false) != 0)
			return;

		// fs->Close();
	}

}
private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		
	StopAll();

	SaveConfig(false);

}

private: void LoadConfig() {

	if (AppSysSubProcess::FileExists(AppSysSubProcess::ExePath() + "\\config\\autosave.config.json")) {

		std::vector<std::string> miners_json_strings;

		miners_json_strings = AppSysSubProcess::ReadLinesFromFile(AppSysSubProcess::ExePath() + "\\config\\autosave.config.json");
			
		MinerConfig^ MinerConfig_tmp;

		MinerConfig_tmp = gcnew MinerConfig();

		for (int i = 0; i < miners_json_strings.size()-1; i++) {
						
			if (MinerConfig_tmp->import_json_string(miners_json_strings.at(i)) == 0) {

				DeviceTab_0 = (gcnew tonpowminergpuwingui::DeviceTab());

				DeviceTab_0->DevicesTabControl_Parent = this->DevicesTabControl;

				DeviceTab_0->GetTabPage()->Name = "miner" + "_" + System::Convert::ToString(tabs_id_cnt);

				DeviceTab_0->ImportConfig(MinerConfig_tmp);

				DevicesTabControl->TabPages->Add(DeviceTab_0->GetTabPage());

				std::string m_key = "miner_" + std::to_string(this->tabs_id_cnt);

				DeviceTabsMap->add_void(m_key, (void *)(void *)GCHandle::ToIntPtr(GCHandle::Alloc(DeviceTab_0)));
				
				tabs_id_cnt = tabs_id_cnt + 1;

				// DevicesTabControl->SelectedTab = DeviceTab_0->GetTabPage();

				// DeviceTab_0->GetTabPage()->Show();

			}

		}

		char json_chars[4096];
		double double_tmp;
		strcpy(json_chars, miners_json_strings.at(miners_json_strings.size() - 1).c_str());
		if (!mjson_get_number(json_chars, strlen(json_chars), "$.startm_ragui", &double_tmp))
			return;
		this->sets_startm_ragui = double_tmp;


		// char json_chars[4096];
		// double double_tmp;
		strcpy(json_chars, miners_json_strings.at(miners_json_strings.size() - 1).c_str());
		if (!mjson_get_number(json_chars, strlen(json_chars), "$.dump_logs_mode", &double_tmp))
			return;
		this->sets_dump_logs_mode = double_tmp;
	

	}


}

public: void DeleteAll(void) {

	for (std::map<std::string, void *>::iterator it = DeviceTabsMap->map_void.begin(); it != DeviceTabsMap->map_void.end(); it++) {

		GCHandle h = GCHandle::FromIntPtr(IntPtr(it->second));
		DeviceTab^ P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);

		P_DeviceTab_TMP->MinerStop();

		P_DeviceTab_TMP->Delete();

	}

}

public: void StartAll(void) {

	for (std::map<std::string, void *>::iterator it = DeviceTabsMap->map_void.begin(); it != DeviceTabsMap->map_void.end(); it++) {

		GCHandle h = GCHandle::FromIntPtr(IntPtr(it->second));
		DeviceTab^ P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);

		P_DeviceTab_TMP->MinerStart();

	}

}

private: System::Void StartAllButton_Click(System::Object^  sender, System::EventArgs^  e) {

	StartAll();

}

public: void StopAll(void) {

	if (!DeviceTabsMap->map_void.empty()) {
	
		TabPage^ TMP_TabPage = DevicesTabControl->SelectedTab;

		GCHandle h = GCHandle::FromIntPtr(IntPtr((--DeviceTabsMap->map_void.end())->second));
		DeviceTab^ P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);
		
		DevicesTabControl->SelectedTab = P_DeviceTab_TMP->GetTabPage();
		// P_DeviceTab_TMP->GetTabPage()->Show();

		for (std::map<std::string, void *>::iterator it = DeviceTabsMap->map_void.begin(); it != DeviceTabsMap->map_void.end(); it++) {
			
			GCHandle h = GCHandle::FromIntPtr(IntPtr(it->second));
			DeviceTab^ P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);

			// DevicesTabControl->SelectedTab = P_DeviceTab_TMP->GetTabPage();
			// P_DeviceTab_TMP->GetTabPage()->Show();

			// this->Refresh();
			// this->DevicesTabControl->Refresh();
			// P_DeviceTab_TMP->Refresh();

			P_DeviceTab_TMP->MinerStop();
			P_DeviceTab_TMP->TestStop();
			
			// this->Refresh();
			// this->DevicesTabControl->Refresh();
			// P_DeviceTab_TMP->Refresh();

		}

		DevicesTabControl->SelectedTab = TMP_TabPage;
	
	}

}

private: System::Void StopAllButton_Click(System::Object^  sender, System::EventArgs^  e) {

	StopAll();

}

public: void SaveConfig(bool force) {

	std::vector<std::string> vect_string_old;
	std::vector<std::string> vect_string;

	MinerConfig^ MinerConfig_tmp;

	MinerConfig_tmp = gcnew MinerConfig();

	std::map<std::string, void *>::iterator it = DeviceTabsMap->map_void.begin();

	for (; it != DeviceTabsMap->map_void.end(); it++) {

		GCHandle h = GCHandle::FromIntPtr(IntPtr(it->second));
		DeviceTab^ P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);

		P_DeviceTab_TMP->ExportConfig(MinerConfig_tmp);

		vect_string.push_back( MinerConfig_tmp->export_json_string() + "\n" );

	}

	char *json_chars = mjson_aprintf("{%Q:%d, %Q:%d}",
		"startm_ragui", this->sets_startm_ragui, "dump_logs_mode", this->sets_dump_logs_mode);
	
	vect_string.push_back(std::string(json_chars) + "\n");

	free(json_chars);

	vect_string_old = AppSysSubProcess::ReadLinesFromFile(AppSysSubProcess::ExePath() + "\\config\\autosave.config.json");

	if ( (vect_string != vect_string_old) || (force == true) ) {

		std::string dt_str = AppSysSubProcess::GetDateTime();
		std::string dest_file_str = AppSysSubProcess::ExePath() + "\\config\\autosave_dumps\\" + "dump_" + "%s" + "_autosave.config.json";
		char dest_file_char[2048] = { "" };

		sprintf(dest_file_char, dest_file_str.c_str(), dt_str.c_str());

		if (CopyFileA(
			(AppSysSubProcess::ExePath() + "\\config\\autosave.config.json").c_str(),
			dest_file_char,
			false
		) == 0)
			printf("error on config dump creation\n");

		AppSysSubProcess::WriteLinesToFile(AppSysSubProcess::ExePath() + "\\config\\autosave.config.json", &vect_string);

	}

}

public: void SaveConfig_ToFile( std::string filename ) {

	std::vector<std::string> vect_string_old;
	std::vector<std::string> vect_string;

	MinerConfig^ MinerConfig_tmp;

	MinerConfig_tmp = gcnew MinerConfig();

	std::map<std::string, void *>::iterator it = DeviceTabsMap->map_void.begin();

	for (; it != DeviceTabsMap->map_void.end(); it++) {

		GCHandle h = GCHandle::FromIntPtr(IntPtr(it->second));
		DeviceTab^ P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);

		P_DeviceTab_TMP->ExportConfig(MinerConfig_tmp);

		vect_string.push_back(MinerConfig_tmp->export_json_string() + "\n");

	}

	char *json_chars = mjson_aprintf("{%Q:%d, %Q:%d}",
		"startm_ragui", this->sets_startm_ragui, "dump_logs_mode", this->sets_dump_logs_mode);

	vect_string.push_back( std::string(json_chars) + "\n");

	free(json_chars);	

	AppSysSubProcess::WriteLinesToFile(filename, &vect_string);

}

public: int LoadConfig_FromFile(std::string filename, bool only_test) {

	if (AppSysSubProcess::FileExists(filename)) {

		std::vector<std::string> miners_json_strings;

		miners_json_strings = AppSysSubProcess::ReadLinesFromFile(filename);
		
		MinerConfig^ MinerConfig_tmp;

		MinerConfig_tmp = gcnew MinerConfig();

		if (miners_json_strings.size() <= 0)
			return 1;

		for (int i = 0; i < miners_json_strings.size()-1; i++) {
			
			if (MinerConfig_tmp->import_json_string(miners_json_strings.at(i)) != 0) {

				return 1;

			}


		}

		char json_chars[4096];
		double double_tmp;
		strcpy(json_chars, miners_json_strings.at(miners_json_strings.size() - 1).c_str());
		if (!mjson_get_number(json_chars, strlen(json_chars), "$.startm_ragui", &double_tmp))
			return 1;
		// this->sets_startm_ragui = double_tmp;

		strcpy(json_chars, miners_json_strings.at(miners_json_strings.size() - 1).c_str());
		if (!mjson_get_number(json_chars, strlen(json_chars), "$.dump_logs_mode", &double_tmp))
			return 1;
		// this->sets_dump_logs_mode = double_tmp;

		if (only_test == true)
			return 0;


		for (int i = 0; i < miners_json_strings.size()-1; i++) {

			if (MinerConfig_tmp->import_json_string(miners_json_strings.at(i)) == 0) {

				DeviceTab_0 = (gcnew tonpowminergpuwingui::DeviceTab());

				DeviceTab_0->DevicesTabControl_Parent = this->DevicesTabControl;

				DeviceTab_0->GetTabPage()->Name = "miner" + "_" + System::Convert::ToString(tabs_id_cnt);

				DeviceTab_0->ImportConfig(MinerConfig_tmp);

				DevicesTabControl->TabPages->Add(DeviceTab_0->GetTabPage());

				std::string m_key = "miner_" + std::to_string(this->tabs_id_cnt);

				DeviceTabsMap->add_void(m_key, (void *)(void *)GCHandle::ToIntPtr(GCHandle::Alloc(DeviceTab_0)));

				this->tabs_id_cnt++;

				// DevicesTabControl->SelectedTab = DeviceTab_0->GetTabPage();

				// DeviceTab_0->GetTabPage()->Show();




			}


		}

		strcpy(json_chars, miners_json_strings.at(miners_json_strings.size() - 1).c_str());
		if (!mjson_get_number(json_chars, strlen(json_chars), "$.startm_ragui", &double_tmp))
			return 1;
		this->sets_startm_ragui = double_tmp;

		strcpy(json_chars, miners_json_strings.at(miners_json_strings.size() - 1).c_str());
		if (!mjson_get_number(json_chars, strlen(json_chars), "$.dump_logs_mode", &double_tmp))
			return 1;
		this->sets_dump_logs_mode = double_tmp;

		return 0;


	}
	else {

		return 1;
	}

}

public: bool sets_startm_ragui = 0;
public: int sets_dump_logs_mode = 0;

private: System::Void settingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	tonpowminergpuwingui::SettingsForm SettingsFormObject;

	if (sets_startm_ragui == true) {
		SettingsFormObject.AutoStartMinersFlag = true;
	}

	SettingsFormObject.DumpLogsMode = sets_dump_logs_mode;

	SettingsFormObject.Update();
		
	SettingsFormObject.ShowDialog();

	if (SettingsFormObject.NewSettingsApplied) {
		this->sets_startm_ragui = SettingsFormObject.AutoStartMinersFlag;
		this->sets_dump_logs_mode = SettingsFormObject.DumpLogsMode;
	}


}

private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

}

private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {

}

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	float float_tmp = 0;
	float float_total = 0;

	GCHandle h;
	DeviceTab^ P_DeviceTab_TMP;

	if (DeviceTabsMap->map_void.empty())
		return;

	for (std::map<std::string, void *>::iterator it = DeviceTabsMap->map_void.begin(); it != DeviceTabsMap->map_void.end(); it++) {

		h = GCHandle::FromIntPtr(IntPtr(it->second));
		P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);

		if (!P_DeviceTab_TMP->AppSysSubProcess_0->run_status) {
			// P_DeviceTab_TMP->GetHashSpeedTextBox()->Text = "";
			continue;
		}


		if (sscanf(msclr::interop::marshal_as<std::string>(P_DeviceTab_TMP->GetHashSpeedTextBox()->Text).c_str(), " %f Mhash/s ", &float_tmp) == 1)
			float_total += float_tmp;

	}

	char tmp_str[256] = { "" };

	sprintf(tmp_str, "%.3f Mhash/s", float_total);

	this->RigHashTextBox->Text = gcnew String(tmp_str);
	// this->RigHashTextBox->Refresh();

}
};
}


