#pragma once

#include <fstream>
#include <vector>
#include "Player.h"

class PlayersLoader
{
private:
	std::string m_baseOfPlayersPath;
	std::vector<Player> *m_base;

public:
	PlayersLoader(std::string path, std::vector<Player> *base);
	bool Load();
};

