#include "stdafx.h"
#include <iostream>
#include <vector>

#include "Player.h"
#include "PlayersLoader.h"
#include "HoursDownloader.h"
#include "RaportCreator.h"

int main(void)
{
	std::vector<Player> players;
	PlayersLoader loader("players.txt", &players);
	loader.Load();

	HoursDownloader hDownloader;
	for (int i = 0; i < players.size(); i++)
	{
		players[i].HoursPast2Weeks() = hDownloader.GetHoursPast2Weeks(players[i].GetSteamProfileLink());
	}

	RaportCreator creator(&players);
	creator.Do();

	getchar();
	return 0;
}