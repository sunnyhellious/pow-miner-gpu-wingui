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
#include <map>

#pragma comment(lib, "Urlmon.lib")

class MapVoid
{

public:

	MapVoid(void) {

	}

	std::map<std::string, void *> map_void;

	void add_void(std::string key, void* val) {
		this->map_void.insert(std::pair<std::string, void*>(key, val));
	}

	void delete_void(std::string key) {
		this->map_void.erase(key);
	}

	void* get_void(std::string key) {

		if (this->map_void.find(key) == this->map_void.end()) return NULL;

		return this->map_void.at(key);

	}

};

