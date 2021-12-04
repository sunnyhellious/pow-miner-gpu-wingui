#pragma once

#include "AppSysSubProcess.h"

#include "FoundsAllForm.h"

#include <msclr\marshal_cppstd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "MinerConfig.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;

void DeviceTab_MinerProc_stdoutNLCallBack(void* handle);
void DeviceTab_MinerProc_stdoutNLCallBack_1(void* handle);

void DeviceTab_MinerProc_processFinishCallBack(void* handle);

namespace powminergpuwingui {
		 
	/// <summary>
	/// Summary for DeviceTab
	/// </summary>
	public ref class DeviceTab : public System::Windows::Forms::UserControl
	{
	public:
		DeviceTab(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			InitializeComponent_USER();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DeviceTab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	protected:
	private: System::Windows::Forms::GroupBox^  DevInfoGroupBox;
	private: System::Windows::Forms::ComboBox^  DevTypeComboBox;
	private: System::Windows::Forms::Label^  PIDLabel;
	private: System::Windows::Forms::TextBox^  DevPidTextBox;
	private: System::Windows::Forms::Label^  DIDLabel;
	private: System::Windows::Forms::TextBox^  DevDidTextBox;
	private: System::Windows::Forms::GroupBox^  DeviceTestGroupBox;
	private: System::Windows::Forms::Label^  BFLabel;
	private: System::Windows::Forms::TextBox^  BoostFactorTextBox;
	private: System::Windows::Forms::Button^  TestStartButton;
	private: System::Windows::Forms::GroupBox^  GiverGroupBox;
	private: System::Windows::Forms::TextBox^  GiverCustomAddrTextBox;
	private: System::Windows::Forms::Label^  GiverAddressLabel;
	private: System::Windows::Forms::GroupBox^  LogsSettingsGroupBox;
	private: System::Windows::Forms::Label^  LogMaxLinesLabel;
	private: System::Windows::Forms::TextBox^  LogsMaxLinesTextBox;
	private: System::Windows::Forms::GroupBox^  MinerExecCtrlGroupBox;
	private: System::Windows::Forms::Button^  MinerStopButton;
	private: System::Windows::Forms::CheckBox^  MinerAutoRstCheckBox;
	private: System::Windows::Forms::Button^  MinerStartButton;
	private: System::Windows::Forms::GroupBox^  WalletGroupBox;
	private: System::Windows::Forms::TextBox^  WalletAddrTextBox;
	private: System::Windows::Forms::Label^  WalletAddressLabel;
	private: System::Windows::Forms::GroupBox^  DeviceControlGroupBox;
	private: System::Windows::Forms::Button^  DeleteDeviceButton;
	private: System::Windows::Forms::GroupBox^  FoundsGroupBox;
	private: System::Windows::Forms::Button^  FoundsShowAllButton;
	private: System::Windows::Forms::TextBox^  FoundsTextBox;
	private: System::Windows::Forms::GroupBox^  LogsGroupBox;
	private: System::Windows::Forms::TextBox^  LogsTextBox;
	private: System::Windows::Forms::Label^  LogsVerbosityLabel;
	private: System::Windows::Forms::TextBox^  LogsVerbosityTextBox;
	private: System::Windows::Forms::Label^  GiverStrategyLabel;
	private: System::Windows::Forms::ComboBox^  GiverStrategyComboBox;
	private: System::Windows::Forms::Button^  TestStopButton;
	private: System::Windows::Forms::GroupBox^  HashSpeedGroupBox;
	private: System::Windows::Forms::TextBox^  HashSpeedTextBox;


	protected:

	protected:

	protected:

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
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->DevInfoGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->DevTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->PIDLabel = (gcnew System::Windows::Forms::Label());
			this->DevPidTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DIDLabel = (gcnew System::Windows::Forms::Label());
			this->DevDidTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DeviceTestGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->TestStopButton = (gcnew System::Windows::Forms::Button());
			this->BFLabel = (gcnew System::Windows::Forms::Label());
			this->BoostFactorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TestStartButton = (gcnew System::Windows::Forms::Button());
			this->GiverGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->GiverStrategyLabel = (gcnew System::Windows::Forms::Label());
			this->GiverStrategyComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->GiverCustomAddrTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GiverAddressLabel = (gcnew System::Windows::Forms::Label());
			this->LogsSettingsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->LogsVerbosityLabel = (gcnew System::Windows::Forms::Label());
			this->LogsVerbosityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LogMaxLinesLabel = (gcnew System::Windows::Forms::Label());
			this->LogsMaxLinesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MinerExecCtrlGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->MinerStopButton = (gcnew System::Windows::Forms::Button());
			this->MinerAutoRstCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->MinerStartButton = (gcnew System::Windows::Forms::Button());
			this->WalletGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->WalletAddrTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WalletAddressLabel = (gcnew System::Windows::Forms::Label());
			this->DeviceControlGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->DeleteDeviceButton = (gcnew System::Windows::Forms::Button());
			this->FoundsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->FoundsShowAllButton = (gcnew System::Windows::Forms::Button());
			this->FoundsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->HashSpeedGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->HashSpeedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LogsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->LogsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel2->SuspendLayout();
			this->DevInfoGroupBox->SuspendLayout();
			this->DeviceTestGroupBox->SuspendLayout();
			this->GiverGroupBox->SuspendLayout();
			this->LogsSettingsGroupBox->SuspendLayout();
			this->MinerExecCtrlGroupBox->SuspendLayout();
			this->WalletGroupBox->SuspendLayout();
			this->DeviceControlGroupBox->SuspendLayout();
			this->FoundsGroupBox->SuspendLayout();
			this->HashSpeedGroupBox->SuspendLayout();
			this->LogsGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->DevInfoGroupBox);
			this->flowLayoutPanel2->Controls->Add(this->DeviceTestGroupBox);
			this->flowLayoutPanel2->Controls->Add(this->GiverGroupBox);
			this->flowLayoutPanel2->Controls->Add(this->LogsSettingsGroupBox);
			this->flowLayoutPanel2->Controls->Add(this->MinerExecCtrlGroupBox);
			this->flowLayoutPanel2->Controls->Add(this->WalletGroupBox);
			this->flowLayoutPanel2->Controls->Add(this->DeviceControlGroupBox);
			this->flowLayoutPanel2->Controls->Add(this->FoundsGroupBox);
			this->flowLayoutPanel2->Controls->Add(this->HashSpeedGroupBox);
			this->flowLayoutPanel2->Controls->Add(this->LogsGroupBox);
			this->flowLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(1104, 466);
			this->flowLayoutPanel2->TabIndex = 7;
			// 
			// DevInfoGroupBox
			// 
			this->DevInfoGroupBox->Controls->Add(this->DevTypeComboBox);
			this->DevInfoGroupBox->Controls->Add(this->PIDLabel);
			this->DevInfoGroupBox->Controls->Add(this->DevPidTextBox);
			this->DevInfoGroupBox->Controls->Add(this->DIDLabel);
			this->DevInfoGroupBox->Controls->Add(this->DevDidTextBox);
			this->DevInfoGroupBox->Location = System::Drawing::Point(3, 3);
			this->DevInfoGroupBox->Name = L"DevInfoGroupBox";
			this->DevInfoGroupBox->Size = System::Drawing::Size(161, 77);
			this->DevInfoGroupBox->TabIndex = 6;
			this->DevInfoGroupBox->TabStop = false;
			this->DevInfoGroupBox->Text = L"Device information";
			// 
			// DevTypeComboBox
			// 
			this->DevTypeComboBox->FormattingEnabled = true;
			this->DevTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Cuda", L"OpenCL" });
			this->DevTypeComboBox->Location = System::Drawing::Point(9, 19);
			this->DevTypeComboBox->Name = L"DevTypeComboBox";
			this->DevTypeComboBox->Size = System::Drawing::Size(146, 21);
			this->DevTypeComboBox->TabIndex = 7;
			this->DevTypeComboBox->Text = L"Type";
			this->DevTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &DeviceTab::DevTypeComboBox_SelectedIndexChanged);
			// 
			// PIDLabel
			// 
			this->PIDLabel->AutoSize = true;
			this->PIDLabel->Location = System::Drawing::Point(11, 51);
			this->PIDLabel->Name = L"PIDLabel";
			this->PIDLabel->Size = System::Drawing::Size(28, 13);
			this->PIDLabel->TabIndex = 8;
			this->PIDLabel->Text = L"PID:";
			// 
			// DevPidTextBox
			// 
			this->DevPidTextBox->Location = System::Drawing::Point(41, 48);
			this->DevPidTextBox->Name = L"DevPidTextBox";
			this->DevPidTextBox->Size = System::Drawing::Size(39, 20);
			this->DevPidTextBox->TabIndex = 9;
			this->DevPidTextBox->TextChanged += gcnew System::EventHandler(this, &DeviceTab::DevPidTextBox_TextChanged);
			// 
			// DIDLabel
			// 
			this->DIDLabel->AutoSize = true;
			this->DIDLabel->Location = System::Drawing::Point(86, 51);
			this->DIDLabel->Name = L"DIDLabel";
			this->DIDLabel->Size = System::Drawing::Size(29, 13);
			this->DIDLabel->TabIndex = 10;
			this->DIDLabel->Text = L"DID:";
			// 
			// DevDidTextBox
			// 
			this->DevDidTextBox->Location = System::Drawing::Point(116, 48);
			this->DevDidTextBox->Name = L"DevDidTextBox";
			this->DevDidTextBox->Size = System::Drawing::Size(39, 20);
			this->DevDidTextBox->TabIndex = 11;
			this->DevDidTextBox->TextChanged += gcnew System::EventHandler(this, &DeviceTab::DevDidTextBox_TextChanged);
			// 
			// DeviceTestGroupBox
			// 
			this->DeviceTestGroupBox->Controls->Add(this->TestStopButton);
			this->DeviceTestGroupBox->Controls->Add(this->BFLabel);
			this->DeviceTestGroupBox->Controls->Add(this->BoostFactorTextBox);
			this->DeviceTestGroupBox->Controls->Add(this->TestStartButton);
			this->DeviceTestGroupBox->Location = System::Drawing::Point(170, 3);
			this->DeviceTestGroupBox->Name = L"DeviceTestGroupBox";
			this->DeviceTestGroupBox->Size = System::Drawing::Size(169, 77);
			this->DeviceTestGroupBox->TabIndex = 12;
			this->DeviceTestGroupBox->TabStop = false;
			this->DeviceTestGroupBox->Text = L"Test execution control";
			// 
			// TestStopButton
			// 
			this->TestStopButton->Location = System::Drawing::Point(87, 17);
			this->TestStopButton->Name = L"TestStopButton";
			this->TestStopButton->Size = System::Drawing::Size(75, 23);
			this->TestStopButton->TabIndex = 16;
			this->TestStopButton->Text = L"Stop";
			this->TestStopButton->UseVisualStyleBackColor = true;
			this->TestStopButton->Click += gcnew System::EventHandler(this, &DeviceTab::TestStopButton_Click);
			// 
			// BFLabel
			// 
			this->BFLabel->AutoSize = true;
			this->BFLabel->Location = System::Drawing::Point(6, 51);
			this->BFLabel->Name = L"BFLabel";
			this->BFLabel->Size = System::Drawing::Size(67, 13);
			this->BFLabel->TabIndex = 14;
			this->BFLabel->Text = L"Boost factor:";
			// 
			// BoostFactorTextBox
			// 
			this->BoostFactorTextBox->Location = System::Drawing::Point(76, 48);
			this->BoostFactorTextBox->Name = L"BoostFactorTextBox";
			this->BoostFactorTextBox->Size = System::Drawing::Size(86, 20);
			this->BoostFactorTextBox->TabIndex = 15;
			// 
			// TestStartButton
			// 
			this->TestStartButton->Location = System::Drawing::Point(6, 17);
			this->TestStartButton->Name = L"TestStartButton";
			this->TestStartButton->Size = System::Drawing::Size(75, 23);
			this->TestStartButton->TabIndex = 13;
			this->TestStartButton->Text = L"Start";
			this->TestStartButton->UseVisualStyleBackColor = true;
			this->TestStartButton->Click += gcnew System::EventHandler(this, &DeviceTab::TestStartButton_Click);
			// 
			// GiverGroupBox
			// 
			this->GiverGroupBox->Controls->Add(this->GiverStrategyLabel);
			this->GiverGroupBox->Controls->Add(this->GiverStrategyComboBox);
			this->GiverGroupBox->Controls->Add(this->GiverCustomAddrTextBox);
			this->GiverGroupBox->Controls->Add(this->GiverAddressLabel);
			this->GiverGroupBox->Location = System::Drawing::Point(345, 3);
			this->GiverGroupBox->Name = L"GiverGroupBox";
			this->GiverGroupBox->Size = System::Drawing::Size(753, 77);
			this->GiverGroupBox->TabIndex = 16;
			this->GiverGroupBox->TabStop = false;
			this->GiverGroupBox->Text = L"Giver settings";
			// 
			// GiverStrategyLabel
			// 
			this->GiverStrategyLabel->AutoSize = true;
			this->GiverStrategyLabel->Location = System::Drawing::Point(6, 22);
			this->GiverStrategyLabel->Name = L"GiverStrategyLabel";
			this->GiverStrategyLabel->Size = System::Drawing::Size(49, 13);
			this->GiverStrategyLabel->TabIndex = 19;
			this->GiverStrategyLabel->Text = L"Strategy:";
			this->GiverStrategyLabel->Click += gcnew System::EventHandler(this, &DeviceTab::label1_Click_1);
			// 
			// GiverStrategyComboBox
			// 
			this->GiverStrategyComboBox->FormattingEnabled = true;
			this->GiverStrategyComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"auto", L"random", L"custom" });
			this->GiverStrategyComboBox->Location = System::Drawing::Point(57, 19);
			this->GiverStrategyComboBox->Name = L"GiverStrategyComboBox";
			this->GiverStrategyComboBox->Size = System::Drawing::Size(690, 21);
			this->GiverStrategyComboBox->TabIndex = 12;
			this->GiverStrategyComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &DeviceTab::GiverStrategyComboBox_SelectedIndexChanged);
			// 
			// GiverCustomAddrTextBox
			// 
			this->GiverCustomAddrTextBox->Location = System::Drawing::Point(57, 48);
			this->GiverCustomAddrTextBox->Name = L"GiverCustomAddrTextBox";
			this->GiverCustomAddrTextBox->Size = System::Drawing::Size(690, 20);
			this->GiverCustomAddrTextBox->TabIndex = 18;
			// 
			// GiverAddressLabel
			// 
			this->GiverAddressLabel->AutoSize = true;
			this->GiverAddressLabel->Location = System::Drawing::Point(9, 51);
			this->GiverAddressLabel->Name = L"GiverAddressLabel";
			this->GiverAddressLabel->Size = System::Drawing::Size(45, 13);
			this->GiverAddressLabel->TabIndex = 17;
			this->GiverAddressLabel->Text = L"Custom:";
			this->GiverAddressLabel->Click += gcnew System::EventHandler(this, &DeviceTab::GiverAddressLabel_Click);
			// 
			// LogsSettingsGroupBox
			// 
			this->LogsSettingsGroupBox->Controls->Add(this->LogsVerbosityLabel);
			this->LogsSettingsGroupBox->Controls->Add(this->LogsVerbosityTextBox);
			this->LogsSettingsGroupBox->Controls->Add(this->LogMaxLinesLabel);
			this->LogsSettingsGroupBox->Controls->Add(this->LogsMaxLinesTextBox);
			this->LogsSettingsGroupBox->Location = System::Drawing::Point(3, 86);
			this->LogsSettingsGroupBox->Name = L"LogsSettingsGroupBox";
			this->LogsSettingsGroupBox->Size = System::Drawing::Size(161, 77);
			this->LogsSettingsGroupBox->TabIndex = 20;
			this->LogsSettingsGroupBox->TabStop = false;
			this->LogsSettingsGroupBox->Text = L"Logs settings";
			// 
			// LogsVerbosityLabel
			// 
			this->LogsVerbosityLabel->AutoSize = true;
			this->LogsVerbosityLabel->Location = System::Drawing::Point(6, 45);
			this->LogsVerbosityLabel->Name = L"LogsVerbosityLabel";
			this->LogsVerbosityLabel->Size = System::Drawing::Size(53, 13);
			this->LogsVerbosityLabel->TabIndex = 23;
			this->LogsVerbosityLabel->Text = L"Verbosity:";
			this->LogsVerbosityLabel->Click += gcnew System::EventHandler(this, &DeviceTab::label1_Click);
			// 
			// LogsVerbosityTextBox
			// 
			this->LogsVerbosityTextBox->Location = System::Drawing::Point(63, 42);
			this->LogsVerbosityTextBox->Name = L"LogsVerbosityTextBox";
			this->LogsVerbosityTextBox->Size = System::Drawing::Size(93, 20);
			this->LogsVerbosityTextBox->TabIndex = 24;
			this->LogsVerbosityTextBox->TextChanged += gcnew System::EventHandler(this, &DeviceTab::textBox1_TextChanged);
			// 
			// LogMaxLinesLabel
			// 
			this->LogMaxLinesLabel->AutoSize = true;
			this->LogMaxLinesLabel->Location = System::Drawing::Point(6, 21);
			this->LogMaxLinesLabel->Name = L"LogMaxLinesLabel";
			this->LogMaxLinesLabel->Size = System::Drawing::Size(54, 13);
			this->LogMaxLinesLabel->TabIndex = 21;
			this->LogMaxLinesLabel->Text = L"Max lines:";
			// 
			// LogsMaxLinesTextBox
			// 
			this->LogsMaxLinesTextBox->Location = System::Drawing::Point(63, 18);
			this->LogsMaxLinesTextBox->Name = L"LogsMaxLinesTextBox";
			this->LogsMaxLinesTextBox->Size = System::Drawing::Size(93, 20);
			this->LogsMaxLinesTextBox->TabIndex = 22;
			// 
			// MinerExecCtrlGroupBox
			// 
			this->MinerExecCtrlGroupBox->Controls->Add(this->MinerStopButton);
			this->MinerExecCtrlGroupBox->Controls->Add(this->MinerAutoRstCheckBox);
			this->MinerExecCtrlGroupBox->Controls->Add(this->MinerStartButton);
			this->MinerExecCtrlGroupBox->Location = System::Drawing::Point(170, 86);
			this->MinerExecCtrlGroupBox->Name = L"MinerExecCtrlGroupBox";
			this->MinerExecCtrlGroupBox->Size = System::Drawing::Size(169, 77);
			this->MinerExecCtrlGroupBox->TabIndex = 24;
			this->MinerExecCtrlGroupBox->TabStop = false;
			this->MinerExecCtrlGroupBox->Text = L"Miner execution control";
			// 
			// MinerStopButton
			// 
			this->MinerStopButton->Location = System::Drawing::Point(87, 17);
			this->MinerStopButton->Name = L"MinerStopButton";
			this->MinerStopButton->Size = System::Drawing::Size(75, 23);
			this->MinerStopButton->TabIndex = 28;
			this->MinerStopButton->Text = L"Stop";
			this->MinerStopButton->UseVisualStyleBackColor = true;
			this->MinerStopButton->Click += gcnew System::EventHandler(this, &DeviceTab::MinerStopButton_Click);
			// 
			// MinerAutoRstCheckBox
			// 
			this->MinerAutoRstCheckBox->AutoSize = true;
			this->MinerAutoRstCheckBox->Location = System::Drawing::Point(6, 45);
			this->MinerAutoRstCheckBox->Name = L"MinerAutoRstCheckBox";
			this->MinerAutoRstCheckBox->Size = System::Drawing::Size(80, 17);
			this->MinerAutoRstCheckBox->TabIndex = 27;
			this->MinerAutoRstCheckBox->Text = L"Auto restart";
			this->MinerAutoRstCheckBox->UseVisualStyleBackColor = true;
			// 
			// MinerStartButton
			// 
			this->MinerStartButton->Location = System::Drawing::Point(6, 17);
			this->MinerStartButton->Name = L"MinerStartButton";
			this->MinerStartButton->Size = System::Drawing::Size(75, 23);
			this->MinerStartButton->TabIndex = 25;
			this->MinerStartButton->Text = L"Start";
			this->MinerStartButton->UseVisualStyleBackColor = true;
			this->MinerStartButton->Click += gcnew System::EventHandler(this, &DeviceTab::MinerStartButton_Click);
			// 
			// WalletGroupBox
			// 
			this->WalletGroupBox->Controls->Add(this->WalletAddrTextBox);
			this->WalletGroupBox->Controls->Add(this->WalletAddressLabel);
			this->WalletGroupBox->Location = System::Drawing::Point(345, 86);
			this->WalletGroupBox->Name = L"WalletGroupBox";
			this->WalletGroupBox->Size = System::Drawing::Size(753, 77);
			this->WalletGroupBox->TabIndex = 28;
			this->WalletGroupBox->TabStop = false;
			this->WalletGroupBox->Text = L"Wallet settings";
			// 
			// WalletAddrTextBox
			// 
			this->WalletAddrTextBox->Location = System::Drawing::Point(57, 19);
			this->WalletAddrTextBox->Name = L"WalletAddrTextBox";
			this->WalletAddrTextBox->Size = System::Drawing::Size(690, 20);
			this->WalletAddrTextBox->TabIndex = 30;
			// 
			// WalletAddressLabel
			// 
			this->WalletAddressLabel->AutoSize = true;
			this->WalletAddressLabel->Location = System::Drawing::Point(6, 22);
			this->WalletAddressLabel->Name = L"WalletAddressLabel";
			this->WalletAddressLabel->Size = System::Drawing::Size(48, 13);
			this->WalletAddressLabel->TabIndex = 29;
			this->WalletAddressLabel->Text = L"Address:";
			// 
			// DeviceControlGroupBox
			// 
			this->DeviceControlGroupBox->Controls->Add(this->DeleteDeviceButton);
			this->DeviceControlGroupBox->Location = System::Drawing::Point(3, 169);
			this->DeviceControlGroupBox->Name = L"DeviceControlGroupBox";
			this->DeviceControlGroupBox->Size = System::Drawing::Size(101, 48);
			this->DeviceControlGroupBox->TabIndex = 34;
			this->DeviceControlGroupBox->TabStop = false;
			this->DeviceControlGroupBox->Text = L"Device control";
			// 
			// DeleteDeviceButton
			// 
			this->DeleteDeviceButton->BackColor = System::Drawing::Color::Transparent;
			this->DeleteDeviceButton->Location = System::Drawing::Point(6, 19);
			this->DeleteDeviceButton->Name = L"DeleteDeviceButton";
			this->DeleteDeviceButton->Size = System::Drawing::Size(90, 23);
			this->DeleteDeviceButton->TabIndex = 16;
			this->DeleteDeviceButton->Text = L"Delete";
			this->DeleteDeviceButton->UseVisualStyleBackColor = false;
			this->DeleteDeviceButton->Click += gcnew System::EventHandler(this, &DeviceTab::DeleteDeviceButton_Click);
			// 
			// FoundsGroupBox
			// 
			this->FoundsGroupBox->Controls->Add(this->FoundsShowAllButton);
			this->FoundsGroupBox->Controls->Add(this->FoundsTextBox);
			this->FoundsGroupBox->Location = System::Drawing::Point(110, 169);
			this->FoundsGroupBox->Name = L"FoundsGroupBox";
			this->FoundsGroupBox->Size = System::Drawing::Size(844, 48);
			this->FoundsGroupBox->TabIndex = 35;
			this->FoundsGroupBox->TabStop = false;
			this->FoundsGroupBox->Text = L"Founds";
			// 
			// FoundsShowAllButton
			// 
			this->FoundsShowAllButton->BackColor = System::Drawing::Color::Transparent;
			this->FoundsShowAllButton->Location = System::Drawing::Point(742, 17);
			this->FoundsShowAllButton->Name = L"FoundsShowAllButton";
			this->FoundsShowAllButton->Size = System::Drawing::Size(90, 23);
			this->FoundsShowAllButton->TabIndex = 17;
			this->FoundsShowAllButton->Text = L"Show all";
			this->FoundsShowAllButton->UseVisualStyleBackColor = false;
			this->FoundsShowAllButton->Click += gcnew System::EventHandler(this, &DeviceTab::FoundsShowAllButton_Click);
			// 
			// FoundsTextBox
			// 
			this->FoundsTextBox->Location = System::Drawing::Point(6, 19);
			this->FoundsTextBox->Name = L"FoundsTextBox";
			this->FoundsTextBox->Size = System::Drawing::Size(730, 20);
			this->FoundsTextBox->TabIndex = 0;
			// 
			// HashSpeedGroupBox
			// 
			this->HashSpeedGroupBox->Controls->Add(this->HashSpeedTextBox);
			this->HashSpeedGroupBox->Location = System::Drawing::Point(960, 169);
			this->HashSpeedGroupBox->Name = L"HashSpeedGroupBox";
			this->HashSpeedGroupBox->Size = System::Drawing::Size(138, 48);
			this->HashSpeedGroupBox->TabIndex = 36;
			this->HashSpeedGroupBox->TabStop = false;
			this->HashSpeedGroupBox->Text = L"Hash speed";
			// 
			// HashSpeedTextBox
			// 
			this->HashSpeedTextBox->Location = System::Drawing::Point(6, 19);
			this->HashSpeedTextBox->Name = L"HashSpeedTextBox";
			this->HashSpeedTextBox->Size = System::Drawing::Size(126, 20);
			this->HashSpeedTextBox->TabIndex = 0;
			// 
			// LogsGroupBox
			// 
			this->LogsGroupBox->Controls->Add(this->LogsTextBox);
			this->LogsGroupBox->Location = System::Drawing::Point(3, 223);
			this->LogsGroupBox->Name = L"LogsGroupBox";
			this->LogsGroupBox->Size = System::Drawing::Size(1101, 240);
			this->LogsGroupBox->TabIndex = 33;
			this->LogsGroupBox->TabStop = false;
			this->LogsGroupBox->Text = L"Logs";
			// 
			// LogsTextBox
			// 
			this->LogsTextBox->Location = System::Drawing::Point(6, 19);
			this->LogsTextBox->Multiline = true;
			this->LogsTextBox->Name = L"LogsTextBox";
			this->LogsTextBox->ReadOnly = true;
			this->LogsTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->LogsTextBox->Size = System::Drawing::Size(1089, 218);
			this->LogsTextBox->TabIndex = 32;
			// 
			// DeviceTab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->flowLayoutPanel2);
			this->Name = L"DeviceTab";
			this->Size = System::Drawing::Size(1104, 466);
			this->flowLayoutPanel2->ResumeLayout(false);
			this->DevInfoGroupBox->ResumeLayout(false);
			this->DevInfoGroupBox->PerformLayout();
			this->DeviceTestGroupBox->ResumeLayout(false);
			this->DeviceTestGroupBox->PerformLayout();
			this->GiverGroupBox->ResumeLayout(false);
			this->GiverGroupBox->PerformLayout();
			this->LogsSettingsGroupBox->ResumeLayout(false);
			this->LogsSettingsGroupBox->PerformLayout();
			this->MinerExecCtrlGroupBox->ResumeLayout(false);
			this->MinerExecCtrlGroupBox->PerformLayout();
			this->WalletGroupBox->ResumeLayout(false);
			this->WalletGroupBox->PerformLayout();
			this->DeviceControlGroupBox->ResumeLayout(false);
			this->FoundsGroupBox->ResumeLayout(false);
			this->FoundsGroupBox->PerformLayout();
			this->HashSpeedGroupBox->ResumeLayout(false);
			this->HashSpeedGroupBox->PerformLayout();
			this->LogsGroupBox->ResumeLayout(false);
			this->LogsGroupBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Windows::Forms::TabPage^  DeviceTabPage;
	
	public: static DeviceTab^ LastDeviceTab;

	private: void InitializeComponent_USER(void)
	{

		AppSysSubProcess_0 = new AppSysSubProcess();
		AppSysSubProcess_1 = new AppSysSubProcess();

		this->LogsVerbosityTextBox->Text = "3";
		
		this->DevTypeComboBox->SelectedIndex = 0;

		std::vector<std::string> givers = this->GetGivers();

		for(int i = 0; i < givers.size(); i++ )
			this->GiverStrategyComboBox->Items->Add( gcnew String(givers.at(i).c_str()) );
		
		this->GiverStrategyComboBox->SelectedIndex = 0;
		this->GiverStrategyComboBox_SelectedIndexChanged_Proc();
			   
		this->DevPidTextBox->Text = "0";
		this->DevDidTextBox->Text = "0";

		this->LogsMaxLinesTextBox->Text = "1000";
		
		this->BoostFactorTextBox->Text = "16";

		this->MinerAutoRstCheckBox->Checked = true;

		this->MinerStopButton->Enabled = false;

		// 

		this->DeviceTabPage = (gcnew System::Windows::Forms::TabPage());

		this->DeviceTabPage->SuspendLayout();

		this->DeviceTabPage->Controls->Add(this->GetFlowLayoutPanel());
		this->DeviceTabPage->Location = System::Drawing::Point(4, 22);
		this->DeviceTabPage->Name = L"DeviceTabPage";
		this->DeviceTabPage->Padding = System::Windows::Forms::Padding(3);
		this->DeviceTabPage->Size = System::Drawing::Size(1110, 472);
		this->DeviceTabPage->TabIndex = 0;
		this->DeviceTabPage->Tag = L"";
		this->DeviceTabPage->Text = L"Device tab";
		this->DeviceTabPage->UseVisualStyleBackColor = true;

		this->DeviceTabPage->ResumeLayout(false);

		LastDeviceTab = this;

	}

	public: System::Windows::Forms::FlowLayoutPanel^ GetFlowLayoutPanel(void) {
		return this->flowLayoutPanel2;
	}

	public: System::Windows::Forms::TabPage^ GetTabPage(void) {
		return this->DeviceTabPage;
	}

	public: System::Windows::Forms::ComboBox^ GetDevTypeComboBox(void) {
		return this->DevTypeComboBox;
	}

	public: System::Windows::Forms::TextBox^ GetDevPidTextBox(void) {
		return this->DevPidTextBox;
	}

	public: System::Windows::Forms::TextBox^ GetDevDidTextBox(void) {
		return this->DevDidTextBox;
	}

public: System::Windows::Forms::TabControl^ DevicesTabControl_Parent;

private: System::Void DeleteDeviceButton_Click(System::Object^  sender, System::EventArgs^  e);

public: AppSysSubProcess* AppSysSubProcess_0 = NULL;

public: void MinerStart(void);

public: void MinerRestart(void) {
	
	if (!AppSysSubProcess::DirectoryExists(AppSysSubProcess_0->last_working_dir)) {

		if (CreateDirectoryA(AppSysSubProcess_0->last_working_dir.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError())
		{
			// CopyFile(...)
		}
		else
		{
			this->LogsTextBox->AppendText(gcnew String("Failed to create directory: "));
			this->LogsTextBox->AppendText(gcnew String(AppSysSubProcess_0->last_working_dir.c_str()));
			this->LogsTextBox->AppendText(gcnew String("\r\n"));
		}

	}
		

	if(this->AppSysSubProcess_0 != NULL)
		AppSysSubProcess_0->ReRun(false);

}

private: std::vector<std::string> GetGivers(void) {

	std::string pow_givers = AppSysSubProcess::ReadTxtToString(AppSysSubProcess::ExePath() + "\\config\\pow-givers.txt");

	std::vector<std::string> strings;
	std::istringstream f(pow_givers);
	std::string s;
	while (getline(f, s, '\n')) {
		strings.push_back(s);
	}

	return strings;

}

private: static int srand_exec_flag = 0;

private: std::string GetRandomGiver(void) {

	std::vector<std::string> strings = this->GetGivers();

	int qnt = strings.size();

	if (powminergpuwingui::DeviceTab::srand_exec_flag == 0) {
		srand(time(NULL));
		powminergpuwingui::DeviceTab::srand_exec_flag = 1;
	}

	int rand_num = rand() % qnt;

	return strings.at(rand_num);

}

private: System::Void MinerStartButton_Click(System::Object^ sender, System::EventArgs^  e);

public: TextBox^ GetLogsTextBox(void) {
	return this->LogsTextBox;
}

public: CheckBox^ GetMinerAutoRstCheckBox(void) {
	return this->MinerAutoRstCheckBox;
}

public: TextBox^ GetLogsMaxLinesTextBox(void) {
	return this->LogsMaxLinesTextBox;
}

public: TextBox^ GetLogsFoundsTextBox(void) {
	return this->FoundsTextBox;
}

public: TextBox^ GetHashSpeedTextBox(void) {
	return this->HashSpeedTextBox;
}

private: void UpdateTabPage_Name(void) {

	if (this->DeviceTabPage != nullptr) {

		if (this->DevTypeComboBox->SelectedIndex == 0)
			this->DeviceTabPage->Text = gcnew String(("CUDA [" + msclr::interop::marshal_as<std::string>(this->DevPidTextBox->Text) + ":" + msclr::interop::marshal_as<std::string>(this->DevDidTextBox->Text) + "]").c_str());
		else if (this->DevTypeComboBox->SelectedIndex == 1)
			this->DeviceTabPage->Text = gcnew String(("OCL [" + msclr::interop::marshal_as<std::string>(this->DevPidTextBox->Text) + ":" + msclr::interop::marshal_as<std::string>(this->DevDidTextBox->Text) + "]").c_str());

	}
	
}

private: System::Void DevTypeComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	UpdateTabPage_Name();
}

public: void MinerStop(void) {

	AppSysSubProcess_0->Stop();

	this->DevInfoGroupBox->Enabled = true;
	this->DeviceControlGroupBox->Enabled = true;
	this->DeviceTestGroupBox->Enabled = true;
	this->GiverGroupBox->Enabled = true;
	this->WalletGroupBox->Enabled = true;

	this->LogsSettingsGroupBox->Enabled = true;

	this->MinerAutoRstCheckBox->Enabled = true;

	this->MinerStartButton->Enabled = true;
	this->MinerStopButton->Enabled = false;

}

public: System::Void MinerStopButton_Click(System::Object^  sender, System::EventArgs^  e) {

	MinerStop();
		
}

private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void FoundsShowAllButton_Click(System::Object^  sender, System::EventArgs^  e) {

	powminergpuwingui::FoundsAllForm FoundsAllForm_0;

	FoundsAllForm_0.GetFoundsAllTextBox()->Text = "";

	for (int i = 0; i < this->AppSysSubProcess_0->DataVector.size(); i++) {
		FoundsAllForm_0.GetFoundsAllTextBox()->AppendText(gcnew String(this->AppSysSubProcess_0->DataVector.at(i).c_str()));
	}
		
	FoundsAllForm_0.ShowDialog();

}
private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void GiverAddressLabel_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void GiverStrategyComboBox_SelectedIndexChanged_Proc(void) {

	if (this->GiverStrategyComboBox->SelectedIndex == 2) {
		this->GiverCustomAddrTextBox->Enabled = true;
		this->GiverCustomAddrTextBox->Visible = true;
		this->GiverAddressLabel->Visible = true;
	}
	else {
		this->GiverCustomAddrTextBox->Enabled = false;
		this->GiverCustomAddrTextBox->Visible = false;
		this->GiverAddressLabel->Visible = false;
	}

}

private: System::Void GiverStrategyComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	this->GiverStrategyComboBox_SelectedIndexChanged_Proc();

}

public: AppSysSubProcess* AppSysSubProcess_1 = NULL;

private: System::Void TestStartButton_Click(System::Object^  sender, System::EventArgs^  e) {

	this->DevInfoGroupBox->Enabled = false;
	this->DeviceControlGroupBox->Enabled = false;
	this->MinerExecCtrlGroupBox->Enabled = false;
	this->GiverGroupBox->Enabled = false;
	this->WalletGroupBox->Enabled = false;

	this->BoostFactorTextBox->Enabled = false;

	this->LogsSettingsGroupBox->Enabled = false;

	this->MinerAutoRstCheckBox->Enabled = false;

	this->TestStartButton->Enabled = false;
	this->TestStopButton->Enabled = true;	

	std::string test_cuda_cmd = "\"" + AppSysSubProcess::ExePath() + "\\tools\\minertools\\pow-miner-cuda.exe \" -vv -B -g " + msclr::interop::marshal_as<std::string>(this->DevDidTextBox->Text) + " -t 10 kQBWkNKqzCAwA9vjMwRmg7aY75Rf8lByPA9zKXoqGkHi8SM7 229760179690128740373110445116482216837 5391989333430127958933403017403926134727428884508114496220722049840 10000000000 ";
	std::string test_opencl_cmd = "\"" + AppSysSubProcess::ExePath() + "\\tools\\minertools\\pow-miner-opencl.exe \" -vv -B -g " + msclr::interop::marshal_as<std::string>(this->DevDidTextBox->Text) + " -p " + msclr::interop::marshal_as<std::string>(this->DevPidTextBox->Text) + " -t 10 kQBWkNKqzCAwA9vjMwRmg7aY75Rf8lByPA9zKXoqGkHi8SM7 229760179690128740373110445116482216837 5391989333430127958933403017403926134727428884508114496220722049840 10000000000 ";

	AppSysSubProcess_1->CallBacksOwnerHandle = (void *)GCHandle::ToIntPtr(GCHandle::Alloc(this)); // .ToPointer();
	AppSysSubProcess_1->stdoutNLCallBack = DeviceTab_MinerProc_stdoutNLCallBack_1;
	AppSysSubProcess_1->processFinishCallBack = NULL;
	AppSysSubProcess_1->last_working_dir_delete_on_finish = 1;

	std::string wd = AppSysSubProcess::ExePath() + "\\miners\\" + msclr::interop::marshal_as<std::string>(this->DeviceTabPage->Name);

	if (CreateDirectoryA(wd.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError())
	{
		// CopyFile(...)
	}
	else
	{
		this->LogsTextBox->AppendText(gcnew String("Failed to create directory: "));
		this->LogsTextBox->AppendText(gcnew String(wd.c_str()));
		this->LogsTextBox->AppendText(gcnew String("\r\n"));
	}

	this->LogsTextBox->AppendText(gcnew String(test_cuda_cmd.c_str()));
	this->LogsTextBox->AppendText(gcnew String("\r\n"));

	this->LogsTextBox->AppendText(gcnew String(test_opencl_cmd.c_str()));
	this->LogsTextBox->AppendText(gcnew String("\r\n"));

	if (this->DevTypeComboBox->SelectedIndex == 0)
		AppSysSubProcess_1->Run(test_cuda_cmd, "", wd, false); // 2>&1
	else if (this->DevTypeComboBox->SelectedIndex == 1)
		AppSysSubProcess_1->Run(test_opencl_cmd, "", wd, false); // 2>&1
	
}
		 
public: void TestStop(void) {

	AppSysSubProcess_1->Stop();

	this->DevInfoGroupBox->Enabled = true;
	this->DeviceControlGroupBox->Enabled = true;
	this->MinerExecCtrlGroupBox->Enabled = true;
	this->GiverGroupBox->Enabled = true;
	this->WalletGroupBox->Enabled = true;

	this->BoostFactorTextBox->Enabled = true;

	this->LogsSettingsGroupBox->Enabled = true;

	this->MinerAutoRstCheckBox->Enabled = true;

	this->TestStartButton->Enabled = true;
	this->TestStopButton->Enabled = false;

}

private: System::Void TestStopButton_Click(System::Object^  sender, System::EventArgs^  e) {

	TestStop();

}

public: System::Void ImportConfig(MinerConfig^ miner_config) {

	this->DevTypeComboBox->SelectedIndex = miner_config->type; // 1

	this->DevPidTextBox->Text = gcnew String(std::to_string(miner_config->platform_id).c_str()); // 2
	this->DevDidTextBox->Text = gcnew String(std::to_string(miner_config->device_id).c_str()); // 3

	if (miner_config->type)
		this->DeviceTabPage->Text = gcnew String(("CUDA [" + std::to_string(miner_config->platform_id) + ":" + std::to_string(miner_config->device_id) + "]").c_str());
	else if (miner_config->type)
		this->DeviceTabPage->Text = gcnew String(("OCL [" + std::to_string(miner_config->platform_id) + ":" + std::to_string(miner_config->device_id) + "]").c_str());

	this->LogsMaxLinesTextBox->Text = gcnew String(std::to_string(miner_config->logs_max_lines).c_str()); // 4

	this->LogsVerbosityTextBox->Text = gcnew String(std::to_string(miner_config->logs_verbosity).c_str()); // 5

	this->GiverStrategyComboBox->SelectedIndex = miner_config->giver_strategy; // 6

	this->GiverCustomAddrTextBox->Text = miner_config->custom_giver_address; // 7

	this->MinerAutoRstCheckBox->Checked = miner_config->auto_restart; // 8

	this->BoostFactorTextBox->Text = gcnew String(std::to_string(miner_config->boost_factor).c_str()); // 9

	this->WalletAddrTextBox->Text = miner_config->wallet_address; // 10

	if (this->DevTypeComboBox->SelectedIndex == 0)
		this->DeviceTabPage->Text = gcnew String(("CUDA [" + std::to_string(miner_config->platform_id) + ":" + std::to_string(miner_config->device_id) + "]").c_str());
	else if (this->DevTypeComboBox->SelectedIndex == 1)
		this->DeviceTabPage->Text = gcnew String(("OCL [" + std::to_string(miner_config->platform_id) + ":" + std::to_string(miner_config->device_id) + "]").c_str());

}

public: int ExportConfig(MinerConfig^ miner_config) {

	int int_tmp;

	miner_config->type = this->DevTypeComboBox->SelectedIndex; // 1

	if( sscanf(msclr::interop::marshal_as<std::string>(this->DevPidTextBox->Text).c_str(), "%d", &int_tmp) != 1 ) return 1;
	miner_config->platform_id = int_tmp;  // 2

	if (sscanf(msclr::interop::marshal_as<std::string>(this->DevDidTextBox->Text).c_str(), "%d", &int_tmp) != 1) return 1;
	miner_config->device_id = int_tmp;  // 3

	if (sscanf(msclr::interop::marshal_as<std::string>(this->LogsMaxLinesTextBox->Text).c_str(), "%d", &int_tmp) != 1) return 1;
	miner_config->logs_max_lines = int_tmp; // 4

	if (sscanf(msclr::interop::marshal_as<std::string>(this->LogsVerbosityTextBox->Text).c_str(), "%d", &int_tmp) != 1) return 1;
	miner_config->logs_verbosity = int_tmp; // 5

	miner_config->giver_strategy = this->GiverStrategyComboBox->SelectedIndex; // 6

	miner_config->custom_giver_address = this->GiverCustomAddrTextBox->Text; // 7

	miner_config->auto_restart = this->MinerAutoRstCheckBox->Checked; // 8

	if (sscanf(msclr::interop::marshal_as<std::string>(this->BoostFactorTextBox->Text).c_str(), "%d", &int_tmp) != 1) return 1;
	miner_config->boost_factor = int_tmp; // 9

	miner_config->wallet_address = this->WalletAddrTextBox->Text; // 10

}

public: void Delete(void);

private: System::Void DevPidTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	UpdateTabPage_Name();
}
private: System::Void DevDidTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	UpdateTabPage_Name();
}
};
}
