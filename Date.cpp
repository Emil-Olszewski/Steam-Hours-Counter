#include "stdafx.h"
#include "Date.h"

Date::Date()
{
}

Date::Date(int y, int m, int d, int h, int min)
{
	Set(y, m, d, h, min);
	m_code = GenerateCode();
}

void Date::Set(int y, int m, int d, int h, int min)
{
	m_year = y;
	m_month = m;
	m_day = d;
	m_hour = h;
	m_minute = min;
}

int Date::GenerateCode()
{
	int code = (m_year + m_month + m_day) * m_hour - m_minute;
	return code;
}

int Date::GetCode()
{
	return m_code;
}

std::string Date::GetAsString()
{
	std::string temp;
	temp = std::to_string(GetY()) + " " + std::to_string(GetM()) + " " + 
	std::to_string(GetD()) + " " + std::to_string(GetHr()) + " " + std::to_string(GetMin());

	return temp;
}

int Date::GetY()
{
	return m_year;
}

int Date::GetM()
{
	return m_month;
}

int Date::GetD()
{
	return m_day;
}

int Date::GetHr()
{
	return m_hour;
}

int Date::GetMin()
{
	return m_minute;
}

bool Date::operator==(Date &d)
{
	if (m_year == d.m_year && m_month == d.m_month && m_day == d.m_day &&
		m_hour == d.m_hour && m_minute == d.m_minute) return true;
	else return false;
}
