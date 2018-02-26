#include "stdafx.h"
#include "HoursDownloader.h"
#include <iostream>
double HoursDownloader::GetHoursPast2Weeks(std::string path)
{
	getSourceCode(path);
	std::string searchingFor = "hours past";

	size_t foundPosition = m_source.find(searchingFor);
	foundPosition -= 6;
	std::string hours;

	for (int i = 0; i < 6; i++)
	{
		if (m_source[foundPosition + i] == '2' && m_source[foundPosition + i + 1] == '>') continue;
		if(m_source[foundPosition + i] != '>')
		hours += m_source[foundPosition + i];
	}
	
	double hoursConverted = ::atof(hours.c_str());
	m_source.clear();
	return hoursConverted;
}

void HoursDownloader::getSourceCode(std::string path)
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, path);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &m_source);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}