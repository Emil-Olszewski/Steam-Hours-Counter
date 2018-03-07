#include "stdafx.h"
#include "RaportCreator.h"

RaportCreator::RaportCreator(std::map<int, Player>* players, int dateCode)
{
	m_dateCode = dateCode;
	m_players = players;
}

void RaportCreator::Do()
{
	sort();
	double average;
	for (int i = 0; i < m_playersIDs.size(); i++)
	{
		auto p1 = m_players->operator[](m_playersIDs[i]);
		auto p2 = m_players->operator[](m_playersIDs[i + 1]);

		average = round((p1.HoursPast2Weeks() / 14) * 10) / 10;
		if (average == 0) continue;

		std::cout << "**" << i + 1 << " " << p1.GetDiscordMention() << "**" << std::endl << std::endl;
		std::cout << "wynik: " << p1.HoursPast2Weeks() << "h [srednio " << average << "h dziennie]" << std::endl;

		double difference = p1.HoursPast2Weeks() - p1.previousHoursRecords[m_dateCode];
		double percentage = round((difference / p1.HoursPast2Weeks() * 100) * 10) / 10;

		std::cout << "od ostatniego pomiaru: " <<  showPlus(difference) << difference <<
		"h  / " << showPlus(difference) << percentage << "%]" << std::endl << std::endl;

		if (i + 1 < m_playersIDs.size())
		{
			difference = p1.HoursPast2Weeks() - p2.HoursPast2Weeks();
			percentage = round((difference / p1.HoursPast2Weeks() * 100) * 10) / 10;

			std::cout << std::endl << "---[" << difference << "h do kolejnego miejsca / "<< percentage << "%]---"
			<< std::endl << std::endl;
		}
	}
}

void RaportCreator::sort()
{
	fillPlayersIDs();
	int swaps;
	do
	{
		swaps = 0;
		int temp;
		for (int i = 0; i < m_players->size()-1; i++)
		{
			if (m_players->operator[](m_playersIDs[i]).HoursPast2Weeks() <
				m_players->operator[](m_playersIDs[i+1]).HoursPast2Weeks())
			{
				temp = m_playersIDs[i+1];
				m_playersIDs[i+1] = m_playersIDs[i];
				m_playersIDs[i] = temp;
				swaps++;
			}
		}
	} while (swaps != 0);
}

void RaportCreator::fillPlayersIDs()
{
	for (auto &it : *m_players)
	{
		m_playersIDs.push_back(it.first);
	}
}

std::string RaportCreator::showPlus(double number)
{
	if (number >= 0) return "+";
	else return "";
}