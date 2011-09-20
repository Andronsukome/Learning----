#include "StdAfx.h"
#include "Chrono.h"

namespace Chrono
{
	Date::Date(int y, Month m, int d)
		:m_Year(y), m_Month(m), m_Day(d)
	{
		if(!is_date(y, m, d)) throw Invalid();
	}

	const Date& default_date()
	{
		static const Date dd(2001, Date::jan, 1);// start of 21st century
		return dd;
	}

	Date::Date(void)
		:m_Year(default_date().year()),
		m_Month(default_date().month()),
		m_Day(default_date().day())
	{
	}
	
	Date::~Date(void){}

	void Date::add_day(int n)
	{
		//...this->m_Day += n;
	}

	void Date::add_month(int n)
	{
		//...
	}

	void Date::add_year(int n)
	{
		if(m_Month == feb && m_Day == 29 && !leapyear(n + m_Year))
		{// beware of leap years!
			m_Month = mar;// use March 1 instead of February 29 
			m_Day = 1;
		}
		m_Year += n;
	}

	bool is_date(int y, Date::Month m, int d)
	{
		if(0 >= d)
			return false;

		int day_in_month = 31;

		switch(m)
		{
		case Date::feb:
			day_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Date::apr:
		case Date::jun:
		case Date::sep:
		case Date::nov:
			day_in_month = 30;
			break;
		}
		
		if(day_in_month < d)
			return false;
		
		return true;
	}

	bool leapyear(int y)
	{
		if((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0))
			return true;
		return false;
	}

	bool operator== (const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}

	bool operator!= (const Date& a, const Date& b)
	{
		return !(a == b);
	}

	std::ostream& operator<< (std::ostream& os, const Date& d)
	{
		return os << '(' << d.year()
			<< ',' << d.month()
			<< ',' << d.day()
			<< ')';
	}

	std::istream& operator>> (std::istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;

		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;

		if(!is)
			return is;

		if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')// oops: format error 
		{
			is.clear(std::ios_base::failbit);// set the fail bit 
			return is;
		}

		dd = Date(y, Date::Month(m), d);// update dd
		return is;
	}

	Day day_of_week(const Date& d)
	{
		//...
		return sunday;
	}

	Date next_Sunday(const Date& d)
	{
		//...
		return d;
	}

	Date next_weekday(const Date& d)
	{
		//...
		return d;
	}
}