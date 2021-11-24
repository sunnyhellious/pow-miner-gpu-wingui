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

	std::vector<std::string>	stdoutData;

	PROCESS_INFORMATION			processInfo;
	STARTUPINFOA				startupInfo;
	SECURITY_ATTRIBUTES			saAttr;

	HANDLE						stdoutReadHandle	= NULL;
	HANDLE						stdoutWriteHandle	= NULL;

	HANDLE						stdoutReadThread	= NULL;
		
	static DWORD __stdcall stdoutReadThreadProcedure(void * argh)
	{

		DWORD		bytes_read;
		char		tBuf[257];
		char		outbuf[32768];
		int			outbuf_len = 0;

		char *p_nl = "NULL";

		AppSysSubProcess *p_this = NULL;
		
		if (argh == NULL)
			return 1;

		p_this = (AppSysSubProcess *) argh;

		for (;;) {

			if (!ReadFile( p_this->stdoutReadHandle, tBuf, 256, &bytes_read, NULL))
			{
				
				if( strlen( outbuf ) > 0 )
					p_this->stdoutData.push_back(std::string(outbuf));
				
				return GetLastError();
			}

			if (bytes_read > 0)
			{
				tBuf[bytes_read] = '\0';
				
				if ((p_nl = strchr(tBuf, '\n')) != NULL) {

					*p_nl = '\0';

					strcat_s(outbuf, sizeof(outbuf), tBuf);

					p_this->stdoutData.push_back(std::string(outbuf));

					p_nl = p_nl + 1;

					outbuf[0] = '\0';

					strcat_s(outbuf, sizeof(outbuf), p_nl);
									   					 
				}
				else {

					strcat_s(outbuf, sizeof(outbuf), tBuf);

				}
				

												
			}
		}
		
		return 0;

	}

	HRESULT Run(std::string command, std::string arguments, bool wait_end_flag) 
	{
		
		char cmdline[256];
		
		DWORD exitcode;

		std::string cmdline_in = command + " " + arguments;

		strcpy_s(cmdline, sizeof(cmdline), cmdline_in.c_str());

		memset(&saAttr, 0, sizeof(saAttr));
		saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
		saAttr.bInheritHandle = TRUE;
		saAttr.lpSecurityDescriptor = NULL;

		// Create a pipe for the child process's STDOUT. 
		if (!CreatePipe(&stdoutReadHandle, &stdoutWriteHandle, &saAttr, 5000))
		{
			return HRESULT_FROM_WIN32(GetLastError());
		}

		// Ensure the read handle to the pipe for STDOUT is not inherited.
		if (!SetHandleInformation(stdoutReadHandle, HANDLE_FLAG_INHERIT, 0))
		{
			return HRESULT_FROM_WIN32(GetLastError());
		}

		memset(&startupInfo, 0, sizeof(startupInfo));
		startupInfo.cb = sizeof(startupInfo);
		startupInfo.hStdError = stdoutWriteHandle;
		startupInfo.hStdOutput = stdoutWriteHandle;
		startupInfo.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
		startupInfo.dwFlags |= STARTF_USESTDHANDLES;

		// memset(&processInfo, 0, sizeof(processInfo));  // Not actually necessary
	
		if (!CreateProcessA(NULL, cmdline, NULL, NULL, TRUE,
			CREATE_NO_WINDOW | CREATE_UNICODE_ENVIRONMENT, NULL, 0, &startupInfo, &processInfo))
		{
			return HRESULT_FROM_WIN32(GetLastError());
		}

		CloseHandle(stdoutWriteHandle);

		// Create thread for grabbing stdout of child process
		stdoutReadThread = CreateThread(0, 0, AppSysSubProcess::stdoutReadThreadProcedure, (void *)this, 0, NULL);
		
		if (wait_end_flag) {

			WaitForSingleObject(stdoutReadThread, INFINITE);


			if (WaitForSingleObject(processInfo.hProcess, INFINITE) != WAIT_OBJECT_0)
			{
				return HRESULT_FROM_WIN32(GetLastError());
			}

			if (!GetExitCodeProcess(processInfo.hProcess, &exitcode))
			{
				return HRESULT_FROM_WIN32(GetLastError());
			}

			CloseHandle(processInfo.hProcess);
			CloseHandle(processInfo.hThread);

		}

		
		return exitcode;

	}

};

/*

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

		if (!SetHandleInformation(SubSys_StdOut_RD, HANDLE_FLAG_INHERIT, 0)) {
			return HRESULT_FROM_WIN32(GetLastError());
		}


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

	*/