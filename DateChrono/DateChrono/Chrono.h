#pragma once

#include <iostream>

namespace Chrono
{
	class Date
	{
	public:
		enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec	};
		class Invalid {};// to throw as exception 

		Date(int y, Month m, int d);// check for valid date and initialize 
		Date(void);
		~Date(void);

		int year() const {return m_Year;}
		Month month() const {return m_Month;}
		int day() const {return m_Day;}

		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
	
	private:
		int m_Year;
		Month m_Month;
		int m_Day;
	};

	bool is_date(int y, Date::Month m, int d);// true for valid date 
	bool leapyear(int y);// true if y is a leap year 

	bool operator== (const Date& a, const Date& b);
	bool operator!= (const Date& a, const Date& b);

	std::ostream& operator<< (std::ostream& os, const Date& d);
	std::istream& operator>> (std::istream& is, Date& dd);

	enum Day { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

	Date next_Sunday(const Date& d);
	Day day_of_week(const Date& d);
	Date next_weekday(const Date& d);
	const Date& default_date();
}