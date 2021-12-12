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

#pragma comment(lib, "Urlmon.lib")


ref class MinerConfig
{

public:

	MinerConfig(void) {

	}

	int type = 0;

	int platform_id = 0;
	int device_id = 0;
	int boost_factor = 16;

	int giver_strategy = 0;

	System::String^ custom_giver_address = "";

	int logs_max_lines = 1000;
	int logs_verbosity = 3;

	bool auto_restart = true;

	System::String^ wallet_address = "";

	int import_json_string( std::string json_string );

	std::string export_json_string( void );
	
};

