#pragma once

#include <map>
#include <vector>
#include <fstream>
#include "Date.h"
#include "Player.h"

class Loader
{
public:
	static bool LoadDates(std::string path, std::vector<Date> *dates);
	static bool LoadPlayers(std::string path, std::map<int, Player> *players);
	static bool LoadPreviousRecords(std::string path, std::map<int, Player> *players);
};

