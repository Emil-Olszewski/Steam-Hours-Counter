#pragma once

#include <map>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <iostream>
#include "Player.h"

class RaportCreator
{
	int m_dateCode;
	std::map<int, Player> *m_players;
	std::vector<int> m_playersIDs;
	void sort();
	void fillPlayersIDs();
	std::string showPlus(double number);

public:
	RaportCreator(std::map<int, Player>* players, int dateCode);
	void Do();
};

