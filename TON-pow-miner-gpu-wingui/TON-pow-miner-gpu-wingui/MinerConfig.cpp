#include "MinerConfig.h"
#include "mjson.h"

using namespace System;



int MinerConfig::import_json_string(std::string json_string) {
	
	char json_chars[4096];
	strcpy(json_chars, json_string.c_str());
	
	double double_tmp;
	char char_arr_tmp[1024];

	if (!mjson_get_number(json_chars, strlen(json_chars), "$.type", &double_tmp))
		return 1;
	this->type = double_tmp;
	
	if (!mjson_get_number(json_chars, strlen(json_chars), "$.pid", &double_tmp))
		return 1;
	this->platform_id = double_tmp;

	if (!mjson_get_number(json_chars, strlen(json_chars), "$.did", &double_tmp))
		return 1;
	this->device_id = double_tmp;

	if (!mjson_get_number(json_chars, strlen(json_chars), "$.bf", &double_tmp))
		return 1;
	this->boost_factor = double_tmp;

	if (!mjson_get_number(json_chars, strlen(json_chars), "$.gs", &double_tmp))
		return 1;
	this->giver_strategy = double_tmp;

	if (!mjson_get_string(json_chars, strlen(json_chars), "$.cga", char_arr_tmp, 1024))
		return 1;
	this->custom_giver_address = gcnew System::String(char_arr_tmp);

	if (!mjson_get_number(json_chars, strlen(json_chars), "$.lml", &double_tmp))
		return 1;
	this->logs_max_lines = double_tmp;

	if (!mjson_get_number(json_chars, strlen(json_chars), "$.lv", &double_tmp))
		return 1;
	this->logs_verbosity = double_tmp;

	if (!mjson_get_number(json_chars, strlen(json_chars), "$.arst", &double_tmp))
		return 1;
	this->auto_restart = double_tmp;

	if (!mjson_get_string(json_chars, strlen(json_chars), "$.wa", char_arr_tmp, 1024))
		return 1;
	this->wallet_address = gcnew System::String(char_arr_tmp);

	return 0;
}

std::string MarshalString(String ^ s) {
	using namespace Runtime::InteropServices;
	std::string str;

	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	str = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return str;
}


std::string MinerConfig::export_json_string(void) {

	std::string json_string;	

	if (this->custom_giver_address->Length == 0)
		this->custom_giver_address = " ";

	if (this->wallet_address->Length == 0)
		this->wallet_address = " ";

	char *json_chars = mjson_aprintf("{%Q:%d, %Q:%d, %Q:%d, %Q:%d, %Q:%d, %Q:%s, %Q:%d, %Q:%d, %Q:%d, %Q:%s }",
		"type", this->type,
		"pid", this->platform_id,
		"did", this->device_id,
		"bf", this->boost_factor,
		"gs", this->giver_strategy,
		"cga", ( "\"" + MarshalString(this->custom_giver_address) + "\"" ).c_str(),
		"lml", this->logs_max_lines,
		"lv", this->logs_verbosity,
		"arst", this->auto_restart,
		"wa", ( "\"" + MarshalString(this->wallet_address) + "\"" ).c_str());

	json_string = json_chars;

	free(json_chars);

	return json_string;
}