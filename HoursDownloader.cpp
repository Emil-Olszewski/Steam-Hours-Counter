#include "stdafx.h"
#include "HoursDownloader.h"

HoursDownloader::HoursDownloader(std::map<int, Player> *players)
{
	m_players = players;
}

void HoursDownloader::Do()
{
	getSystemDate();
	saveDate();

	std::fstream file;
	file.open("records.txt", std::ios::app);
	if (file.good())
	{
		int i = 1;
		for(auto &element : *m_players)
		{
			element.second.HoursPast2Weeks() = getHoursPast2Weeks(element.second.GetSteamProfileLink());
			file << std::endl << element.second.GetID() << " " << element.second.HoursPast2Weeks() <<
				" " << systemDate.GetAsString();

			system("cls");
			std::cout << "[" << i << "/" << m_players->size() << "]" << std::endl;
			i++;
		}
	}

	file.close();
}

double HoursDownloader::getHoursPast2Weeks(std::string path)
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

void HoursDownloader::getSystemDate()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	systemDate.Set(st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute);
}

void HoursDownloader::saveDate()
{
	std::fstream file;
	file.open("dates.txt", std::ios::app);
	if (file.good())
	{
		file << std::endl << systemDate.GetAsString();
	}

	file.close();
}
