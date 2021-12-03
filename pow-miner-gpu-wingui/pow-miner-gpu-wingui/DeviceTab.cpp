
#include "MainForm.h"
#include "DeviceTab.h"

using namespace powminergpuwingui;

void DeviceTab_MinerProc_stdoutNLCallBack(void* handle) {

	GCHandle h = GCHandle::FromIntPtr(IntPtr(handle));
	DeviceTab^ p_this = reinterpret_cast<DeviceTab^>(h.Target);

	for (int i = 0; i < p_this->AppSysSubProcess_0->stdoutData.size(); i++) {		
			
		MainForm::MainForm_0->DeviceTab_LogsTextBoxAddLine(p_this, gcnew String(p_this->AppSysSubProcess_0->stdoutData.at(i).c_str()) + "\r\n");
		
	}
		
	p_this->AppSysSubProcess_0->stdoutData.clear();

	// h.Free();
		
}


void DeviceTab_MinerProc_stdoutNLCallBack_1(void* handle) {

	GCHandle h = GCHandle::FromIntPtr(IntPtr(handle));
	DeviceTab^ p_this = reinterpret_cast<DeviceTab^>(h.Target);

	for (int i = 0; i < p_this->AppSysSubProcess_1->stdoutData.size(); i++) {

		MainForm::MainForm_0->DeviceTab_LogsTextBoxAddLine(p_this, gcnew String(p_this->AppSysSubProcess_1->stdoutData.at(i).c_str()) + "\r\n");

	}

	p_this->AppSysSubProcess_1->stdoutData.clear();

	// h.Free();

}

void DeviceTab_MinerProc_processFinishCallBack(void* handle) {

	GCHandle h = GCHandle::FromIntPtr(IntPtr(handle));
	DeviceTab^ p_this = reinterpret_cast<DeviceTab^>(h.Target);	

	if ( p_this->GetMinerAutoRstCheckBox()->Checked ) {

		MainForm::MainForm_0->DeviceTab_LogsTextBoxAddLine(p_this, "RESTARTING MINER IN 5 SECONDS" + "\r\n");

		// TODO FOUND IMITATION
		// MainForm::MainForm_0->DeviceTab_LogsTextBoxAddLine(p_this, "FOUND: " + gcnew String(std::to_string(rand()).c_str()) + "\r\n");

		Sleep(5000);

		p_this->MinerRestart();

	}

	// h.Free();

}

void DeviceTab::Delete(void) {

	this->DevicesTabControl_Parent->TabPages->RemoveByKey(this->DeviceTabPage->Name);

	MainForm::MainForm_0->DeviceTabsMap->delete_void(msclr::interop::marshal_as<std::string>(this->DeviceTabPage->Name));

}


System::Void DeviceTab::DeleteDeviceButton_Click(System::Object^  sender, System::EventArgs^  e) {

	this->Delete();

}

System::Void DeviceTab::MinerStartButton_Click(System::Object^ sender, System::EventArgs^  e) {

	MinerStart();

}

void DeviceTab::MinerStart(void) {

	MainForm::MainForm_0->SaveConfig(false);

	this->DevInfoGroupBox->Enabled = false;
	this->DeviceControlGroupBox->Enabled = false;
	this->DeviceTestGroupBox->Enabled = false;
	this->GiverGroupBox->Enabled = false;
	this->WalletGroupBox->Enabled = false;

	this->LogsSettingsGroupBox->Enabled = false;

	this->MinerAutoRstCheckBox->Enabled = false;

	this->MinerStartButton->Enabled = false;
	this->MinerStopButton->Enabled = true;

	AppSysSubProcess_0->CallBacksOwnerHandle = (void *)GCHandle::ToIntPtr(GCHandle::Alloc(this)); // .ToPointer();
	AppSysSubProcess_0->stdoutNLCallBack = DeviceTab_MinerProc_stdoutNLCallBack;
	AppSysSubProcess_0->processFinishCallBack = DeviceTab_MinerProc_processFinishCallBack;
	AppSysSubProcess_0->last_working_dir_delete_on_finish = 1;

	System::String^ giver_strategy_sstr;

	if (this->GiverStrategyComboBox->SelectedIndex == 2)
		giver_strategy_sstr = this->GiverCustomAddrTextBox->Text;
	else
		giver_strategy_sstr = this->GiverStrategyComboBox->GetItemText(this->GiverStrategyComboBox->SelectedItem);

	std::string vl_str = " -v " + msclr::interop::marshal_as<std::string>(this->LogsVerbosityTextBox->Text) + " ";
	std::string glc_str = " -C \"" + AppSysSubProcess::ExePath() + "\\config\\global.config.json" + "\" ";
	std::string cmd_str = " -e \"pminer start " +
		msclr::interop::marshal_as<std::string>(giver_strategy_sstr) + " " +
		msclr::interop::marshal_as<std::string>(this->WalletAddrTextBox->Text) + " " +
		msclr::interop::marshal_as<std::string>(this->DevDidTextBox->Text) + " " +
		msclr::interop::marshal_as<std::string>(this->BoostFactorTextBox->Text) + " " +
		msclr::interop::marshal_as<std::string>(this->DevPidTextBox->Text) + "\" ";

	std::string wd = AppSysSubProcess::ExePath() + "\\miners\\" + msclr::interop::marshal_as<std::string>(this->DeviceTabPage->Name); // "\"" + + "\""

	std::string cuda_miner_str = "\"" + AppSysSubProcess::ExePath() + "\\tools\\minertools-cuda-windows-x86-64\\tonlib-cuda-cli.exe" + "\"" + vl_str + glc_str + cmd_str;
	std::string opencl_miner_str = "\"" + AppSysSubProcess::ExePath() + "\\tools\\minertools-opencl-windows-x86-64\\tonlib-opencl-cli.exe" + "\"" + vl_str + glc_str + cmd_str;

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

	if (this->DevTypeComboBox->SelectedIndex == 0)
		AppSysSubProcess_0->Run(cuda_miner_str, "2>&1", wd, false);
	else if (this->DevTypeComboBox->SelectedIndex == 1)
		AppSysSubProcess_0->Run(opencl_miner_str, "2>&1", wd, false);

}
