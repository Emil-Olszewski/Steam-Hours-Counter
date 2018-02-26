#include "stdafx.h"
#include "RaportCreator.h"
#include <iostream>
#include <cmath>

RaportCreator::RaportCreator(std::vector<Player> *base)
{
	m_base = base;
}

void RaportCreator::Do()
{
	sort();
	double average;
	for (int i = 0; i < m_base->size(); i++)
	{
		double average = round((m_base->operator[](i).HoursPast2Weeks() / 14) * 10) / 10;
		std::cout << "**" << i+1 << " " << m_base->operator[](i).GetDiscordMention() << " z wynikiem " <<
		m_base->operator[](i).HoursPast2Weeks() << "h [srednio " << average << "h dziennie]**" << std::endl;

		if (i + 1 < m_base->size())
		{
			double difference = m_base->operator[](i).HoursPast2Weeks() - m_base->operator[](i+1).HoursPast2Weeks();
			double percentage = round((difference / m_base->operator[](i).HoursPast2Weeks() * 100) * 10) / 10;

			std::cout << std::endl << "[" << difference << "h do kolejnego miejsca / "<< percentage << "%]"
			<< std::endl << std::endl;
		}
	}
}

void RaportCreator::sort()
{
	int swaps;
	do
	{
		swaps = 0;
		Player temp("a","b");
		for (int i = 0; i < m_base->size()-1; i++)
		{
			if (m_base->operator[](i).HoursPast2Weeks() < m_base->operator[](i+1).HoursPast2Weeks())
			{
				temp = m_base->operator[](i+1);
				m_base->operator[](i + 1) = m_base->operator[](i);
				m_base->operator[](i) = temp;
				swaps++;
			}
		}
	} while (swaps != 0);
}
