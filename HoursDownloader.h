#pragma once
#include <string>

#define CURL_STATICLIB
#pragma comment(lib, "curl/libcurl_a.lib")
#include "curl/curl.h"

class HoursDownloader
{
private:
	std::string m_source;
	void getSourceCode(std::string path);

	static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
	{
		((std::string*)userp)->append((char*)contents, size * nmemb);
		return size * nmemb;
	}

public:
	double GetHoursPast2Weeks(std::string path);
};

