#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//WinformCDemo is your project name
	tonpowminergpuwingui::MainForm form;	
	Application::Run(%form);
}