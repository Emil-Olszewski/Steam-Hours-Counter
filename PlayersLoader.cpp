#include "stdafx.h"
#include "PlayersLoader.h"

PlayersLoader::PlayersLoader(std::string path, std::vector<Player> *base)
{
	m_baseOfPlayersPath = path;
	m_base = base;
}

bool PlayersLoader::Load()
{
	std::ifstream file;
	file.open(m_baseOfPlayersPath.c_str());
	if (!file.good()) return false;
		
	int howMany;
	file >> howMany;

	std::string discord, steam;
	for (int i = 0; i < howMany; i++)
	{
		file >> discord >> steam;
		m_base->push_back(Player(discord, steam));
	}
	
	return true;
}