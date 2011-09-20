// DateChrono.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Chrono.h"

int _tmain(int argc, _TCHAR* argv[])
	try
{
	Chrono::Date holiday(1978, Chrono::Date::jul, 4); // initialization 
	Chrono::Date d2 = Chrono::next_Sunday(holiday);
	d2.add_day(40);
    Chrono::Day  d  = day_of_week(d2);
    std::cout << "holiday is " << holiday << " d2 is " << d2 << std::endl;
    return holiday != d2;
}

catch (Chrono::Date::Invalid&) {
    std::cerr << "error: Invalid date\n"; 
    return 1;
}
catch (...) {
    std::cerr << "Oops: unknown exception!\n"; 
    return 2;
}