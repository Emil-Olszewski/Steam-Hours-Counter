#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}

Player::Player(int id, std::string discord, std::string steam)
{
	m_id = id;
	m_discordMention = discord;
	m_steamProfileLink = steam;
}

int Player::GetID()
{
	return m_id;
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
	previousHoursRecords = p.previousHoursRecords;
}

void Player::operator+=(Player &p)
{
	m_hoursPast2Weeks += p.HoursPast2Weeks();
	p.HoursPast2Weeks() = 0;
}

bool Player::operator==(Player &p)
{
	if (m_discordMention == p.m_discordMention) return true;
	else return false;
}
