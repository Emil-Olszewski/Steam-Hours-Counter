#pragma once

#include <vector>
#include "Player.h"

class RaportCreator
{
	std::vector<Player> *m_base;
	void sort();

public:
	RaportCreator(std::vector<Player> *base);
	void Do();
};

