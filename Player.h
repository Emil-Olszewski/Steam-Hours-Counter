#pragma once
#include <string>

class Player
{
private:
	std::string m_discordMention;
	std::string m_steamProfileLink;
	double m_hoursPast2Weeks;

public:
	Player();
	Player(std::string discord, std::string steam);
	double& HoursPast2Weeks();
	std::string GetDiscordMention();
	std::string GetSteamProfileLink();
	void operator=(Player &p);
};

