#include "stdafx.h"
#include "Loader.h"

bool Loader::LoadDates(std::string path, std::vector<Date> *dates)
{
	std::ifstream file;
	file.open(path.c_str());
	if (!file.good()) return false;

	int year, month, day, hour, minute;
	std::string discord, steam;
	while (!file.eof())
	{
		file >> year >> month >> day >> hour >> minute;
		dates->push_back(Date(year, month, day, hour, minute));
	}
	
	file.close();
	return true;
}

bool Loader::LoadPlayers(std::string path, std::map<int, Player> *players)
{
	std::ifstream file;
	file.open(path.c_str());
	if (!file.good()) return false;

	int id;
	std::string discord, steam;
	while (!file.eof())
	{
		file >> id >> discord >> steam;
		players->insert(std::pair<int, Player>(id,(Player(id, discord, steam))));
	}

	file.close();
	return true;
}

bool Loader::LoadPreviousRecords(std::string path, std::map<int, Player> *players)
{
	std::ifstream file;
	file.open(path.c_str());
	if (!file.good()) return false;

	int id, year, month, day, hour, minute;
	double hours;
	std::string discord, steam;
	while (!file.eof())
	{
		file >> id >> hours >> year >> month >> day >> hour >> minute;
		Date date(year, month, day, hour, minute);
		players->operator[](id).previousHoursRecords.insert(std::pair<int, double>(date.GenerateCode(), hours));
	}

	file.close();
	return true;
}