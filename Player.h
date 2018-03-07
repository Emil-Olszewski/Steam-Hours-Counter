#pragma once

#include <string>
#include <vector>
#include <map>

#include "Date.h"

class Player
{
	int m_id;
	double m_hoursPast2Weeks;
	std::string m_discordMention;
	std::string m_steamProfileLink;
	
public:
	std::map<int, double> previousHoursRecords;

	Player();
	Player(int id, std::string discord, std::string steam);
	int GetID();
	double& HoursPast2Weeks();
	std::string GetDiscordMention();
	std::string GetSteamProfileLink();
	void operator=(Player &p);
	void operator+=(Player &p);
	bool operator==(Player &p);
};

