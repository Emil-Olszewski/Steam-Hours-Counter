#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>

#include "Date.h"
#include "Player.h"
#include "Loader.h"
#include "HoursDownloader.h"
#include "RaportCreator.h"

int main(void)
{
	std::vector<Date> dates;
	Loader::LoadDates("dates.txt", &dates);

	std::map<int, Player> players;
	Loader::LoadPlayers("players.txt", &players);
	Loader::LoadPreviousRecords("records.txt", &players);

	for (int i = 0; i < dates.size(); i++)
		std::cout << i << " " << dates[i].GetAsString() << std::endl;

	std::cout << "wpisz numer: ";
	int choice;
	std::cin >> choice;

	HoursDownloader hDownloader(&players);
	hDownloader.Do();

	RaportCreator creator(&players, dates[choice].GetCode());
	creator.Do();

	std::cout << "porównane z " << dates[choice].GetAsString() << std::endl;

	getchar(); getchar();
	return 0;
}
