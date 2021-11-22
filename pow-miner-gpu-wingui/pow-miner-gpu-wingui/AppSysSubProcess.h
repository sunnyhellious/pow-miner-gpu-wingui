#pragma once

#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


class AppSysSubProcess {

public:

	AppSysSubProcess(void) {
		
	}

	HANDLE SubSys_StdOut_RD			= NULL;
	HANDLE SubSys_StdOut_WR			= NULL;
	HANDLE SubSys_ReadData_Thread	= NULL;

	std::vector<std::string> data;
		
	static DWORD __stdcall GetStdOut(void * argh)
	{
		DWORD dwRead = 0;
		CHAR chBuf[128];
		BOOL bSuccess = FALSE;

		AppSysSubProcess *p_AppSysSubProcess = (AppSysSubProcess *) argh;

		HANDLE File = p_AppSysSubProcess->SubSys_StdOut_RD;

		for (;;)
		{

			if (dwRead > 0) {
				p_AppSysSubProcess->data.push_back(std::string(chBuf));
			}

			bSuccess = ReadFile(File, chBuf, 128, &dwRead, NULL);
			
			if (!bSuccess)
				break;
					
		}

		return 0;
	}

	HRESULT Run(std::string command, std::string arguments) {
		
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		SECURITY_ATTRIBUTES saAttr;

		ZeroMemory(&saAttr, sizeof(saAttr));
		saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
		saAttr.bInheritHandle = TRUE;
		saAttr.lpSecurityDescriptor = NULL;

		if (!CreatePipe(&SubSys_StdOut_RD, &SubSys_StdOut_WR, &saAttr, 0)) {
			return HRESULT_FROM_WIN32(GetLastError());
		}

		/*
		if (!SetHandleInformation(SubSys_StdOut_RD, HANDLE_FLAG_INHERIT, 0)) {
			return HRESULT_FROM_WIN32(GetLastError());
		}
		*/
			

		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		si.hStdError = SubSys_StdOut_WR;
		si.hStdOutput = SubSys_StdOut_WR;
		si.dwFlags |= STARTF_USESTDHANDLES;
		si.dwFlags |= STARTF_USESHOWWINDOW;
		
		ZeroMemory(&pi, sizeof(pi));

		std::string commandLine = command + " " + arguments;

		// Start the child process. 
		if (!CreateProcessA(NULL,           // No module name (use command line)
			(LPSTR) commandLine.c_str(),	// Command line
			NULL,                           // Process handle not inheritable
			NULL,                           // Thread handle not inheritable
			TRUE,                           // Set handle inheritance
			0,                              // No creation flags
			NULL,                           // Use parent's environment block
			NULL,                           // Use parent's starting directory 
			(LPSTARTUPINFOA) &si,           // Pointer to STARTUPINFO structure
			(LPPROCESS_INFORMATION) &pi)	// Pointer to PROCESS_INFORMATION structure
			)
		{
			return HRESULT_FROM_WIN32(GetLastError());
		}
		else
		{
			
			CloseHandle(SubSys_StdOut_WR);	

			SubSys_ReadData_Thread = CreateThread(0, 0, AppSysSubProcess::GetStdOut, (void *)this, 0, NULL);

		}

		WaitForSingleObject(SubSys_ReadData_Thread, INFINITE);
				
		return S_OK;
	}




};