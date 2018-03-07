#pragma once
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <iostream>

#include "Date.h"
#include "Player.h"

#define CURL_STATICLIB
#pragma comment(lib, "curl/libcurl_a.lib")
#include "curl/curl.h"

class HoursDownloader
{
private:
	std::map<int, Player> *m_players;
	std::string m_source;
	Date systemDate;

	double getHoursPast2Weeks(std::string path);\
	void getSourceCode(std::string path);
	void getSystemDate();
	void saveDate();
	
	static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
	{
		((std::string*)userp)->append((char*)contents, size * nmemb);
		return size * nmemb;
	}

public:
	HoursDownloader(std::map<int, Player> *m_players);
	void Do();
	
};

