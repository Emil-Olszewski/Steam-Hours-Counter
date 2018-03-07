#pragma once

#include <string>

class Date
{
	int m_code;
	int m_year;
	int m_month;
	int m_day;
	int m_hour;
	int m_minute;

public:
	Date();
	Date(int y, int m, int d, int h, int min);
	void Set(int y, int m, int d, int h, int min);
	int GenerateCode();
	int GetCode();
	std::string GetAsString();
	int GetY();
	int GetM();	
	int GetD();
	int GetHr();
	int GetMin();
	bool operator==(Date &d);
};

