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

			DevicesListBox->AutoSize = true;
			
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
	private: System::Windows::Forms::GroupBox^  DevicesSearchEngineGroupBox;


	private: System::Windows::Forms::ListBox^  DevicesListBox;
	private: System::Windows::Forms::Button^  SearchOpenCLDevicesButton;
	private: System::Windows::Forms::Button^  SearchCUDADevicesButton;

	private: System::Windows::Forms::Button^  UseDeviceButton;


	private: System::Windows::Forms::TabControl^  DevicesTabControl;
	private: System::Windows::Forms::TabPage^  DeviceTabPage;
	private: System::Windows::Forms::GroupBox^  GiverGroupBox;

	private: System::Windows::Forms::CheckBox^  GiverAdrAutoCheckBox;
	private: System::Windows::Forms::TextBox^  GiverAddrTextBox;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  MinerExecCtrlGroupBox;

	private: System::Windows::Forms::CheckBox^  MinerAutoRstCheckBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  MinerStartButton;

	private: System::Windows::Forms::ToolStripMenuItem^  importSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  updateToolsToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  TestMinerLogsGroupBox;


	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::GroupBox^  DeviceTestGroupBox;



	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  BoostFactorTextBox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckBox^  LogsAutoScrollDownCheckBox;


	private: System::Windows::Forms::GroupBox^  WalletGroupBox;
	private: System::Windows::Forms::TextBox^  WalletAddrTextBox;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  LogsSettingsGroupBox;

	private: System::Windows::Forms::TextBox^  LogsMaxLinesTextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  DevInfoGroupBox;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  DevPidTextBox;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  DevDidTextBox;

	private: System::Windows::Forms::ComboBox^  DevTypeComboBox;

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
			this->importSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->updateToolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->DevicesSearchEngineGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->UseDeviceButton = (gcnew System::Windows::Forms::Button());
			this->SearchCUDADevicesButton = (gcnew System::Windows::Forms::Button());
			this->DevicesListBox = (gcnew System::Windows::Forms::ListBox());
			this->SearchOpenCLDevicesButton = (gcnew System::Windows::Forms::Button());
			this->DevicesTabControl = (gcnew System::Windows::Forms::TabControl());
			this->DeviceTabPage = (gcnew System::Windows::Forms::TabPage());
			this->DevInfoGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->DevTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->DevPidTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->DevDidTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LogsSettingsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->LogsMaxLinesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LogsAutoScrollDownCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->WalletGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->WalletAddrTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->DeviceTestGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->BoostFactorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->TestMinerLogsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->MinerExecCtrlGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->MinerAutoRstCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->MinerStartButton = (gcnew System::Windows::Forms::Button());
			this->GiverGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->GiverAdrAutoCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->GiverAddrTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->DevicesSearchEngineGroupBox->SuspendLayout();
			this->DevicesTabControl->SuspendLayout();
			this->DeviceTabPage->SuspendLayout();
			this->DevInfoGroupBox->SuspendLayout();
			this->LogsSettingsGroupBox->SuspendLayout();
			this->WalletGroupBox->SuspendLayout();
			this->DeviceTestGroupBox->SuspendLayout();
			this->TestMinerLogsGroupBox->SuspendLayout();
			this->MinerExecCtrlGroupBox->SuspendLayout();
			this->GiverGroupBox->SuspendLayout();
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
			this->menuStrip1->Size = System::Drawing::Size(1466, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->importSettingsToolStripMenuItem,
					this->exportSettingsToolStripMenuItem, this->updateToolsToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// importSettingsToolStripMenuItem
			// 
			this->importSettingsToolStripMenuItem->Name = L"importSettingsToolStripMenuItem";
			this->importSettingsToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->importSettingsToolStripMenuItem->Text = L"Import settings";
			// 
			// exportSettingsToolStripMenuItem
			// 
			this->exportSettingsToolStripMenuItem->Name = L"exportSettingsToolStripMenuItem";
			this->exportSettingsToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->exportSettingsToolStripMenuItem->Text = L"Export settings";
			// 
			// updateToolsToolStripMenuItem
			// 
			this->updateToolsToolStripMenuItem->Name = L"updateToolsToolStripMenuItem";
			this->updateToolsToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->updateToolsToolStripMenuItem->Text = L"Update tools";
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
			// DevicesSearchEngineGroupBox
			// 
			this->DevicesSearchEngineGroupBox->Controls->Add(this->UseDeviceButton);
			this->DevicesSearchEngineGroupBox->Controls->Add(this->SearchCUDADevicesButton);
			this->DevicesSearchEngineGroupBox->Controls->Add(this->DevicesListBox);
			this->DevicesSearchEngineGroupBox->Controls->Add(this->SearchOpenCLDevicesButton);
			this->DevicesSearchEngineGroupBox->Location = System::Drawing::Point(12, 24);
			this->DevicesSearchEngineGroupBox->Name = L"DevicesSearchEngineGroupBox";
			this->DevicesSearchEngineGroupBox->Size = System::Drawing::Size(315, 522);
			this->DevicesSearchEngineGroupBox->TabIndex = 3;
			this->DevicesSearchEngineGroupBox->TabStop = false;
			this->DevicesSearchEngineGroupBox->Text = L"Devices search engine";
			// 
			// UseDeviceButton
			// 
			this->UseDeviceButton->Location = System::Drawing::Point(5, 490);
			this->UseDeviceButton->Name = L"UseDeviceButton";
			this->UseDeviceButton->Size = System::Drawing::Size(304, 23);
			this->UseDeviceButton->TabIndex = 3;
			this->UseDeviceButton->Text = L"Use device";
			this->UseDeviceButton->UseVisualStyleBackColor = true;
			this->UseDeviceButton->Click += gcnew System::EventHandler(this, &MainForm::UseDeviceButton_Click);
			// 
			// SearchCUDADevicesButton
			// 
			this->SearchCUDADevicesButton->Location = System::Drawing::Point(6, 48);
			this->SearchCUDADevicesButton->Name = L"SearchCUDADevicesButton";
			this->SearchCUDADevicesButton->Size = System::Drawing::Size(304, 23);
			this->SearchCUDADevicesButton->TabIndex = 2;
			this->SearchCUDADevicesButton->Text = L"Search CUDA devices";
			this->SearchCUDADevicesButton->UseVisualStyleBackColor = true;
			this->SearchCUDADevicesButton->Click += gcnew System::EventHandler(this, &MainForm::SearchCUDADevicesButton_Click);
			// 
			// DevicesListBox
			// 
			this->DevicesListBox->FormattingEnabled = true;
			this->DevicesListBox->Location = System::Drawing::Point(6, 77);
			this->DevicesListBox->Name = L"DevicesListBox";
			this->DevicesListBox->Size = System::Drawing::Size(304, 407);
			this->DevicesListBox->TabIndex = 1;
			// 
			// SearchOpenCLDevicesButton
			// 
			this->SearchOpenCLDevicesButton->Location = System::Drawing::Point(6, 19);
			this->SearchOpenCLDevicesButton->Name = L"SearchOpenCLDevicesButton";
			this->SearchOpenCLDevicesButton->Size = System::Drawing::Size(304, 23);
			this->SearchOpenCLDevicesButton->TabIndex = 0;
			this->SearchOpenCLDevicesButton->Text = L"Search OpenCL devices";
			this->SearchOpenCLDevicesButton->UseVisualStyleBackColor = true;
			this->SearchOpenCLDevicesButton->Click += gcnew System::EventHandler(this, &MainForm::SearchDevicesButton_Click);
			// 
			// DevicesTabControl
			// 
			this->DevicesTabControl->Controls->Add(this->DeviceTabPage);
			this->DevicesTabControl->Location = System::Drawing::Point(333, 27);
			this->DevicesTabControl->Name = L"DevicesTabControl";
			this->DevicesTabControl->SelectedIndex = 0;
			this->DevicesTabControl->Size = System::Drawing::Size(1129, 529);
			this->DevicesTabControl->TabIndex = 4;
			this->DevicesTabControl->Tag = L"";
			// 
			// DeviceTabPage
			// 
			this->DeviceTabPage->Controls->Add(this->DevInfoGroupBox);
			this->DeviceTabPage->Controls->Add(this->LogsSettingsGroupBox);
			this->DeviceTabPage->Controls->Add(this->WalletGroupBox);
			this->DeviceTabPage->Controls->Add(this->DeviceTestGroupBox);
			this->DeviceTabPage->Controls->Add(this->TestMinerLogsGroupBox);
			this->DeviceTabPage->Controls->Add(this->MinerExecCtrlGroupBox);
			this->DeviceTabPage->Controls->Add(this->GiverGroupBox);
			this->DeviceTabPage->Location = System::Drawing::Point(4, 22);
			this->DeviceTabPage->Name = L"DeviceTabPage";
			this->DeviceTabPage->Padding = System::Windows::Forms::Padding(3);
			this->DeviceTabPage->Size = System::Drawing::Size(1121, 503);
			this->DeviceTabPage->TabIndex = 0;
			this->DeviceTabPage->Tag = L"";
			this->DeviceTabPage->Text = L"Device tab";
			this->DeviceTabPage->UseVisualStyleBackColor = true;
			// 
			// DevInfoGroupBox
			// 
			this->DevInfoGroupBox->Controls->Add(this->DevTypeComboBox);
			this->DevInfoGroupBox->Controls->Add(this->label5);
			this->DevInfoGroupBox->Controls->Add(this->DevPidTextBox);
			this->DevInfoGroupBox->Controls->Add(this->label6);
			this->DevInfoGroupBox->Controls->Add(this->DevDidTextBox);
			this->DevInfoGroupBox->Location = System::Drawing::Point(12, 6);
			this->DevInfoGroupBox->Name = L"DevInfoGroupBox";
			this->DevInfoGroupBox->Size = System::Drawing::Size(161, 77);
			this->DevInfoGroupBox->TabIndex = 7;
			this->DevInfoGroupBox->TabStop = false;
			this->DevInfoGroupBox->Text = L"Device information";
			// 
			// DevTypeComboBox
			// 
			this->DevTypeComboBox->FormattingEnabled = true;
			this->DevTypeComboBox->Location = System::Drawing::Point(9, 19);
			this->DevTypeComboBox->Name = L"DevTypeComboBox";
			this->DevTypeComboBox->Size = System::Drawing::Size(146, 21);
			this->DevTypeComboBox->TabIndex = 11;
			this->DevTypeComboBox->Text = L"Type";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(11, 51);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(28, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"PID:";
			// 
			// DevPidTextBox
			// 
			this->DevPidTextBox->Location = System::Drawing::Point(41, 48);
			this->DevPidTextBox->Name = L"DevPidTextBox";
			this->DevPidTextBox->Size = System::Drawing::Size(39, 20);
			this->DevPidTextBox->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(86, 51);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(29, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"DID:";
			// 
			// DevDidTextBox
			// 
			this->DevDidTextBox->Location = System::Drawing::Point(116, 48);
			this->DevDidTextBox->Name = L"DevDidTextBox";
			this->DevDidTextBox->Size = System::Drawing::Size(39, 20);
			this->DevDidTextBox->TabIndex = 7;
			// 
			// LogsSettingsGroupBox
			// 
			this->LogsSettingsGroupBox->Controls->Add(this->label3);
			this->LogsSettingsGroupBox->Controls->Add(this->LogsMaxLinesTextBox);
			this->LogsSettingsGroupBox->Controls->Add(this->LogsAutoScrollDownCheckBox);
			this->LogsSettingsGroupBox->Location = System::Drawing::Point(12, 82);
			this->LogsSettingsGroupBox->Name = L"LogsSettingsGroupBox";
			this->LogsSettingsGroupBox->Size = System::Drawing::Size(161, 77);
			this->LogsSettingsGroupBox->TabIndex = 6;
			this->LogsSettingsGroupBox->TabStop = false;
			this->LogsSettingsGroupBox->Text = L"Logs settings";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Max lines:";
			// 
			// LogsMaxLinesTextBox
			// 
			this->LogsMaxLinesTextBox->Location = System::Drawing::Point(63, 18);
			this->LogsMaxLinesTextBox->Name = L"LogsMaxLinesTextBox";
			this->LogsMaxLinesTextBox->Size = System::Drawing::Size(93, 20);
			this->LogsMaxLinesTextBox->TabIndex = 5;
			// 
			// LogsAutoScrollDownCheckBox
			// 
			this->LogsAutoScrollDownCheckBox->AutoSize = true;
			this->LogsAutoScrollDownCheckBox->Location = System::Drawing::Point(9, 45);
			this->LogsAutoScrollDownCheckBox->Name = L"LogsAutoScrollDownCheckBox";
			this->LogsAutoScrollDownCheckBox->Size = System::Drawing::Size(104, 17);
			this->LogsAutoScrollDownCheckBox->TabIndex = 3;
			this->LogsAutoScrollDownCheckBox->Text = L"Auto scroll down";
			this->LogsAutoScrollDownCheckBox->UseVisualStyleBackColor = true;
			// 
			// WalletGroupBox
			// 
			this->WalletGroupBox->Controls->Add(this->WalletAddrTextBox);
			this->WalletGroupBox->Controls->Add(this->label4);
			this->WalletGroupBox->Location = System::Drawing::Point(354, 82);
			this->WalletGroupBox->Name = L"WalletGroupBox";
			this->WalletGroupBox->Size = System::Drawing::Size(753, 77);
			this->WalletGroupBox->TabIndex = 3;
			this->WalletGroupBox->TabStop = false;
			this->WalletGroupBox->Text = L"Wallet settings";
			// 
			// WalletAddrTextBox
			// 
			this->WalletAddrTextBox->Location = System::Drawing::Point(57, 19);
			this->WalletAddrTextBox->Name = L"WalletAddrTextBox";
			this->WalletAddrTextBox->Size = System::Drawing::Size(690, 20);
			this->WalletAddrTextBox->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Address:";
			// 
			// DeviceTestGroupBox
			// 
			this->DeviceTestGroupBox->Controls->Add(this->label2);
			this->DeviceTestGroupBox->Controls->Add(this->BoostFactorTextBox);
			this->DeviceTestGroupBox->Controls->Add(this->button3);
			this->DeviceTestGroupBox->Location = System::Drawing::Point(179, 6);
			this->DeviceTestGroupBox->Name = L"DeviceTestGroupBox";
			this->DeviceTestGroupBox->Size = System::Drawing::Size(169, 77);
			this->DeviceTestGroupBox->TabIndex = 5;
			this->DeviceTestGroupBox->TabStop = false;
			this->DeviceTestGroupBox->Text = L"Test execution control";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Boost factor:";
			// 
			// BoostFactorTextBox
			// 
			this->BoostFactorTextBox->Location = System::Drawing::Point(76, 48);
			this->BoostFactorTextBox->Name = L"BoostFactorTextBox";
			this->BoostFactorTextBox->Size = System::Drawing::Size(86, 20);
			this->BoostFactorTextBox->TabIndex = 4;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 17);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Start";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// TestMinerLogsGroupBox
			// 
			this->TestMinerLogsGroupBox->Controls->Add(this->textBox1);
			this->TestMinerLogsGroupBox->Location = System::Drawing::Point(12, 165);
			this->TestMinerLogsGroupBox->Name = L"TestMinerLogsGroupBox";
			this->TestMinerLogsGroupBox->Size = System::Drawing::Size(1095, 332);
			this->TestMinerLogsGroupBox->TabIndex = 3;
			this->TestMinerLogsGroupBox->TabStop = false;
			this->TestMinerLogsGroupBox->Text = L"Test/miner logs";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 19);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(1080, 304);
			this->textBox1->TabIndex = 0;
			// 
			// MinerExecCtrlGroupBox
			// 
			this->MinerExecCtrlGroupBox->Controls->Add(this->MinerAutoRstCheckBox);
			this->MinerExecCtrlGroupBox->Controls->Add(this->button1);
			this->MinerExecCtrlGroupBox->Controls->Add(this->MinerStartButton);
			this->MinerExecCtrlGroupBox->Location = System::Drawing::Point(179, 82);
			this->MinerExecCtrlGroupBox->Name = L"MinerExecCtrlGroupBox";
			this->MinerExecCtrlGroupBox->Size = System::Drawing::Size(169, 77);
			this->MinerExecCtrlGroupBox->TabIndex = 2;
			this->MinerExecCtrlGroupBox->TabStop = false;
			this->MinerExecCtrlGroupBox->Text = L"Miner execution control";
			// 
			// MinerAutoRstCheckBox
			// 
			this->MinerAutoRstCheckBox->AutoSize = true;
			this->MinerAutoRstCheckBox->Location = System::Drawing::Point(6, 45);
			this->MinerAutoRstCheckBox->Name = L"MinerAutoRstCheckBox";
			this->MinerAutoRstCheckBox->Size = System::Drawing::Size(80, 17);
			this->MinerAutoRstCheckBox->TabIndex = 3;
			this->MinerAutoRstCheckBox->Text = L"Auto restart";
			this->MinerAutoRstCheckBox->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(87, 17);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Stop";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// MinerStartButton
			// 
			this->MinerStartButton->Location = System::Drawing::Point(6, 17);
			this->MinerStartButton->Name = L"MinerStartButton";
			this->MinerStartButton->Size = System::Drawing::Size(75, 23);
			this->MinerStartButton->TabIndex = 3;
			this->MinerStartButton->Text = L"Start";
			this->MinerStartButton->UseVisualStyleBackColor = true;
			// 
			// GiverGroupBox
			// 
			this->GiverGroupBox->Controls->Add(this->GiverAdrAutoCheckBox);
			this->GiverGroupBox->Controls->Add(this->GiverAddrTextBox);
			this->GiverGroupBox->Controls->Add(this->label1);
			this->GiverGroupBox->Location = System::Drawing::Point(354, 6);
			this->GiverGroupBox->Name = L"GiverGroupBox";
			this->GiverGroupBox->Size = System::Drawing::Size(753, 77);
			this->GiverGroupBox->TabIndex = 1;
			this->GiverGroupBox->TabStop = false;
			this->GiverGroupBox->Text = L"Giver settings";
			// 
			// GiverAdrAutoCheckBox
			// 
			this->GiverAdrAutoCheckBox->AutoSize = true;
			this->GiverAdrAutoCheckBox->Location = System::Drawing::Point(9, 45);
			this->GiverAdrAutoCheckBox->Name = L"GiverAdrAutoCheckBox";
			this->GiverAdrAutoCheckBox->Size = System::Drawing::Size(65, 17);
			this->GiverAdrAutoCheckBox->TabIndex = 2;
			this->GiverAdrAutoCheckBox->Text = L"Auto set";
			this->GiverAdrAutoCheckBox->UseVisualStyleBackColor = true;
			// 
			// GiverAddrTextBox
			// 
			this->GiverAddrTextBox->Location = System::Drawing::Point(57, 19);
			this->GiverAddrTextBox->Name = L"GiverAddrTextBox";
			this->GiverAddrTextBox->Size = System::Drawing::Size(690, 20);
			this->GiverAddrTextBox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Address:";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1466, 567);
			this->Controls->Add(this->DevicesTabControl);
			this->Controls->Add(this->DevicesSearchEngineGroupBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"pow-miner-gpu-wingui";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->DevicesSearchEngineGroupBox->ResumeLayout(false);
			this->DevicesTabControl->ResumeLayout(false);
			this->DeviceTabPage->ResumeLayout(false);
			this->DevInfoGroupBox->ResumeLayout(false);
			this->DevInfoGroupBox->PerformLayout();
			this->LogsSettingsGroupBox->ResumeLayout(false);
			this->LogsSettingsGroupBox->PerformLayout();
			this->WalletGroupBox->ResumeLayout(false);
			this->WalletGroupBox->PerformLayout();
			this->DeviceTestGroupBox->ResumeLayout(false);
			this->DeviceTestGroupBox->PerformLayout();
			this->TestMinerLogsGroupBox->ResumeLayout(false);
			this->TestMinerLogsGroupBox->PerformLayout();
			this->MinerExecCtrlGroupBox->ResumeLayout(false);
			this->MinerExecCtrlGroupBox->PerformLayout();
			this->GiverGroupBox->ResumeLayout(false);
			this->GiverGroupBox->PerformLayout();
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
	
	AppSysSubProcess AppSysSubProcess_0;

	AppSysSubProcess_0.Run("\"D:\\Program Files (other)\\pow-miner-gpu\\minertools-opencl-windows-x86-64\\pow-miner-opencl.exe\"", "2>&1", true);

	DevicesListBox->BeginUpdate();

	DevicesListBox->Items->Clear();

	for (int i = 0; i < AppSysSubProcess_0.stdoutData.size(); i++) {
		DevicesListBox->Items->Add(gcnew String(AppSysSubProcess_0.stdoutData.at(i).c_str()));
		OutputDebugStringA(AppSysSubProcess_0.stdoutData.at(i).c_str());
	}

	DevicesListBox->EndUpdate();

}

private: System::Void SearchCUDADevicesButton_Click(System::Object^  sender, System::EventArgs^  e) {

	AppSysSubProcess AppSysSubProcess_0;

	AppSysSubProcess_0.Run("\"D:\\Program Files (other)\\pow-miner-gpu\\minertools-cuda-windows-x86-64\\pow-miner-cuda.exe\"", "2>&1", true);

	DevicesListBox->BeginUpdate();

	DevicesListBox->Items->Clear();

	for (int i = 0; i < AppSysSubProcess_0.stdoutData.size(); i++) {
		DevicesListBox->Items->Add(gcnew String(AppSysSubProcess_0.stdoutData.at(i).c_str()));
		OutputDebugStringA(AppSysSubProcess_0.stdoutData.at(i).c_str());
	}

	DevicesListBox->EndUpdate();

}
private: System::Void UseDeviceButton_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (DevicesListBox->SelectedItem) {
	
		DevicesTabControl->Controls->Add(this->DeviceTabPage);

	}

}

};
}
