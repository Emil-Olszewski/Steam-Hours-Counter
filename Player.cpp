#include "stdafx.h"
#include "Player.h"

Player::Player(std::string discord, std::string steam)
{
	m_discordMention = discord;
	m_steamProfileLink = steam;
}

double& Player::HoursPast2Weeks()
{
	return m_hoursPast2Weeks;
}

std::string Player::GetDiscordMention()
{
	return m_discordMention;
}

std::string Player::GetSteamProfileLink()
{
	return m_steamProfileLink;
}

void Player::operator=(Player &p)
{
	m_discordMention = p.GetDiscordMention();
	m_steamProfileLink = p.GetSteamProfileLink();
	m_hoursPast2Weeks = p.HoursPast2Weeks();
}