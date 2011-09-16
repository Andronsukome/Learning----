// LineAndArray.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Array.h"
#include "Dot.h"
#include "Line.h"
//#include <crtdbg.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Array A, B, C, D, E;

	A.PushBack(11);
	A.PushBack(12);
	A.PushBack(13);
	B.PushBack(21);
	B.PushBack(22);
	B.PushBack(23);
	B.PushBack(24);
	C.PushBack(31);
	C.PushBack(32);
	C.PushBack(33);
	C.PushBack(34);
	C.PushBack(35);
	D.PushBack(41);
	D.PushBack(42); 
	D.PushBack(43);
	D.PushBack(44);
	D.PushBack(45);
	D.PushBack(46);
	E = A + B + C + D;
	std::cout << E;
	//if(_CrtDumpMemoryLeaks() == true)
	//	std::cerr << "\n\n\tERROR MEMORY!!! - (_CrtDumpMemoryLeaks() == true)\n\n";
	//else
	//	std::cerr << "\n\n\tMemory remove correctly!!!\n\n";
	return 0;
}
