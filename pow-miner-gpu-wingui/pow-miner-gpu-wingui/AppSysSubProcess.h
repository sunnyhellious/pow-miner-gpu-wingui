#pragma once

#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include <experimental/filesystem>
#include <cstdio>
#include <Shldisp.h>
#include <fstream>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

#pragma comment(lib, "Urlmon.lib")

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

	DWORD						exitcode;

	std::string					last_command;
	std::string					last_arguments;
	std::string					last_working_dir;
	int							last_working_dir_delete_on_finish = 0;

	std::vector<std::string>	DataVector;
	
	void *CallBacksOwnerHandle;
	void (*stdoutNLCallBack)		(void *handle)  = NULL;
	void (*processFinishCallBack)	(void *handle)  = NULL;

	bool run_status = false;

	std::string time_stamp;

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


			if (!ReadFile( p_this->stdoutReadHandle, tBuf, 256, &bytes_read, NULL) )
			{
				
				if( strlen( outbuf ) > 0 )
					p_this->stdoutData.push_back(std::string(outbuf));

				if (p_this->stdoutNLCallBack != NULL) {
					p_this->stdoutNLCallBack(p_this->CallBacksOwnerHandle);
				}

				//

				if (WaitForSingleObject(p_this->processInfo.hProcess, INFINITE) != WAIT_OBJECT_0)
				{
					return HRESULT_FROM_WIN32(GetLastError());
				}

				if (!GetExitCodeProcess(p_this->processInfo.hProcess, &p_this->exitcode))
				{
					return HRESULT_FROM_WIN32(GetLastError());
				}

				try
				{
					CloseHandle(p_this->processInfo.hProcess);
				}
				catch (...)
				{
					
				}

				try
				{
					CloseHandle(p_this->processInfo.hThread);
				}
				catch (...)
				{

				}

				//

				p_this->run_status = false;

				//

				if (p_this->last_working_dir_delete_on_finish) {
					if (AppSysSubProcess::DirectoryExists(p_this->last_working_dir))
						AppSysSubProcess::DeleteDirectoryAndAllSubfolders(p_this->last_working_dir);
				}

				if (p_this->processFinishCallBack != NULL) {
					p_this->processFinishCallBack(p_this->CallBacksOwnerHandle);
				}
								
				//
				
				return GetLastError();
			}

			if (bytes_read > 0)
			{
				tBuf[bytes_read] = '\0';
				
				if ((p_nl = strchr(tBuf, '\n')) != NULL) {

					*p_nl = '\0';

					strcat_s(outbuf, sizeof(outbuf), tBuf);

					p_this->stdoutData.push_back(std::string(outbuf));
					
					if (p_this->stdoutNLCallBack != NULL) {
						p_this->stdoutNLCallBack(p_this->CallBacksOwnerHandle);
					}					

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

	public: HRESULT Run(std::string command, std::string arguments, std::string working_dir, bool wait_flag)
	{


		/*

		#define BUFSIZE 4096

		TCHAR chNewEnv[BUFSIZE];
		LPTSTR lpszCurrentVariable;

		// Copy environment strings into an environment block.

		lpszCurrentVariable = (LPTSTR)chNewEnv;
		if (FAILED(StringCchCopy(lpszCurrentVariable, BUFSIZE, TEXT("LANG=en_US"))))
		{
			printf("String copy failed\n");
			return FALSE;
		}


		lpszCurrentVariable += lstrlen(lpszCurrentVariable) + 1;
		if (FAILED(StringCchCopy(lpszCurrentVariable, BUFSIZE, TEXT("lang=en"))))
		{
			printf("String copy failed\n");
			return FALSE;
		}


		// Terminate the block with a NULL byte.

		lpszCurrentVariable += lstrlen(lpszCurrentVariable) + 1;
		*lpszCurrentVariable = (TCHAR)0;

		*/

		//

		char cmdline[4096];

		this->last_command = command;
		this->last_arguments = arguments;
		this->last_working_dir = working_dir;

		DWORD dwFlags = 0;

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

		// memset(&startupInfo, 0, sizeof(startupInfo));

		ZeroMemory(&startupInfo, sizeof(STARTUPINFOA));
		startupInfo.cb = sizeof(startupInfo);
		startupInfo.hStdError = stdoutWriteHandle;
		startupInfo.hStdOutput = stdoutWriteHandle;
		startupInfo.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
		startupInfo.dwFlags |= STARTF_USESTDHANDLES;

		ZeroMemory(&processInfo, sizeof(PROCESS_INFORMATION));


		// memset(&processInfo, 0, sizeof(processInfo));  // Not actually necessary

		this->exitcode = 0;

		dwFlags = CREATE_UNICODE_ENVIRONMENT | CREATE_NO_WINDOW; // CREATE_NO_WINDOW | CREATE_UNICODE_ENVIRONMENT | DETACHED_PROCESS
	
		// AllocConsole();

		if (!CreateProcessA(NULL, cmdline, NULL, NULL, TRUE, dwFlags, NULL, working_dir.c_str(), &startupInfo, &processInfo)) // (LPVOID)chNewEnv
		{
			return HRESULT_FROM_WIN32(GetLastError());
		}

		CloseHandle(stdoutWriteHandle);

		time_stamp = AppSysSubProcess::GetDateTime();
		
		// Create thread for grabbing stdout of child process
		stdoutReadThread = CreateThread(0, 0, AppSysSubProcess::stdoutReadThreadProcedure, (void *)this, 0, NULL);
		
		this->run_status = true;
		
		if (wait_flag) {

			WaitForSingleObject(stdoutReadThread, INFINITE);
			
		}
		
		return this->exitcode;

	}

	public: HRESULT ReRun(bool wait_flag)
	{

		return this->Run(this->last_command, this->last_arguments, this->last_working_dir, wait_flag);

	}

	public: HRESULT Stop()
	{

		this->run_status = false;

		this->stdoutNLCallBack = NULL;
		this->processFinishCallBack = NULL;
		this->CallBacksOwnerHandle = NULL;


		if (!TerminateProcess(this->processInfo.hProcess, 0)) {
			DWORD err = GetLastError();
			std::string err_str = "ERR:Stop: code = " + std::to_string(HRESULT_FROM_WIN32(err)) + "\n";
			OutputDebugStringA(err_str.c_str());
		}
		
		// GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT, this->processInfo.dwProcessId);
		// GenerateConsoleCtrlEvent(CTRL_C_EVENT, this->processInfo.dwProcessId);
		// GenerateConsoleCtrlEvent(CTRL_CLOSE_EVENT, this->processInfo.dwProcessId);

		// this->tmp_flag = true;

		WaitForSingleObject(stdoutReadThread, INFINITE);
				
		return this->exitcode;

	}

	public: static std::string WS2S(const std::wstring& wstr)
	{
		std::string str(wstr.begin(), wstr.end());
		return str;
	}
	
	public: static std::wstring S2WS(const std::string& s)
	{
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
		std::wstring r(buf);
		delete[] buf;
		return r;
	}

	public: static std::string ExePath() {

		TCHAR buffer[MAX_PATH] = { 0 };
		GetModuleFileName(NULL, buffer, MAX_PATH);
		std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");		

		return WS2S(std::wstring(buffer).substr(0, pos));
	}

	public: static void DeleteDirectoryAndAllSubfolders(std::string dir)
	{		
		std::experimental::filesystem::remove_all(dir.c_str());
	}

	public: static std::string GetDateTime() {

		std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::string s(30, '\0');
		std::strftime(&s[0], s.size(), "%Y-%m-%d_%H-%M-%S", std::localtime(&now));

		return s;

	}

	public: static int DownloadFileFromUrl( std::string source_url, std::string destination_file ) {

		if (S_OK == URLDownloadToFileA(NULL, source_url.c_str(), destination_file.c_str(), 0, NULL)) {
			printf("Saved to 'myfile.txt'");
			return 0;
		}
		else {
			return 1;
		}		

	}

	public: static int UnzipToFolder(std::string zip_file, std::string destination_folder) {
		
		AppSysSubProcess AppSysSubProcess_0 = AppSysSubProcess();

		zip_file = "\"" + zip_file + "\"";
		
		AppSysSubProcess_0.Run("\"" + AppSysSubProcess::ExePath() + "\\tools\\unzip.exe" + "\" -o -j ", zip_file, destination_folder, true);

		if (AppSysSubProcess_0.exitcode != 0)
			return 1;

		return 0;

	}

	public: static int DownloadUrlPage(std::string url, std::string destination_file) {
		
		HRESULT hr = URLDownloadToFileA(0, url.c_str(), destination_file.c_str(), 0, NULL);
		if (hr == S_OK) {
			return 0;
		}
		else {
			return 1;
		}

		return 0;

	}

	public: static std::string ReadTxtToString(std::string file) {

		std::ifstream ifs(file);
		std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

		return content;

	}

	public: static BOOL DirectoryExists(std::string dir)
	{
		DWORD dwAttrib = GetFileAttributesA(dir.c_str());

		return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
			(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
	}

	public: static BOOL FileExists(std::string file_name)
	{
		/*
		LPWIN32_FIND_DATAA FindFileData;
		HANDLE handle = FindFirstFileA(file_name.c_str(), FindFileData);
		
		int found = handle != INVALID_HANDLE_VALUE;
		
		if (found)
		{
			//FindClose(&handle); this will crash
			FindClose(handle);
		}

		return found;
		*/

		if (FILE *file = fopen(file_name.c_str(), "r")) {
			fclose(file);
			return true;
		}
		else {
			return false;
		}

	}

	public: static std::vector<std::string> ReadLinesFromFile(std::string file) {

		std::vector<std::string> vect_string;
		FILE *stream;
		char line[4096];

		if (fopen_s(&stream, file.c_str(), "r") == 0)
		{

			while(1) {

				if (fgets(line, 4096, stream) == NULL)
					break;
				else
					vect_string.push_back(line);
			
			}

			fclose(stream);

		}
		
		return vect_string;

	}

	public: static int WriteLinesToFile(std::string file, std::vector<std::string> *p_vect_string) {

		FILE *stream;
		int err = 0;

		if (fopen_s(&stream, file.c_str(), "w") == 0)
		{

			for (int i = 0; i < p_vect_string->size(); i++) {

				if (fputs(p_vect_string->at(i).c_str(), stream) < 0) {
					err = 1;
					break;
				}

			}
			
			fclose(stream);

		}
		else {
			
			err = 1;

		}


		return err;

	}

	public: static int AppendLineToFile(std::string file, std::string *p_string) {

		FILE *stream;
		int err = 0;

		if (fopen_s(&stream, file.c_str(), "a") == 0)
		{

			if (fputs(p_string->c_str(), stream) < 0)
				err = 1;
			
			fclose(stream);

		}
		else {

			err = 1;

		}


		return err;

	}


};