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
	//B.PushBack(21);
	//B.PushBack(22);
	//B.PushBack(23);
	//B.PushBack(24);
	//C.PushBack(31);
	//C.PushBack(32);
	//C.PushBack(33);
	//C.PushBack(34);
	//C.PushBack(35);
	//D.PushBack(41);
	//D.PushBack(42); 
	//D.PushBack(43);
	//D.PushBack(44);
	//D.PushBack(45);
	//D.PushBack(46);
	//E = A + B + C + D;
	//std::cout << E;
	std::cout << "Array A: " << A <<'\n';
	std::cout << "\nadd to idx -1 - ";
	A.InsertElementAtIndex(-1, 10);
	std::cout << "Array A: " << A <<'\n';
	std::cout << "\nadd to idx 0 - ";
	A.InsertElementAtIndex(0, 10);
	std::cout << "Array A: " << A <<'\n';
	std::cout << "\nadd to idx 2 - ";
	A.InsertElementAtIndex(2, 10);
	std::cout << "Array A: " << A <<'\n';
	std::cout << "\nadd to idx 5 - ";
	A.InsertElementAtIndex(5, 10);
	std::cout << "Array A: " << A <<'\n';
	std::cout << "\nadd to idx 8 - ";
	A.InsertElementAtIndex(8, 10);
	std::cout << "Array A: " << A <<'\n';

	std::cout << "Array A: " << A <<'\n';
	std::cout << "\nrem idx -1 - ";
	A.RemoveElementAtIndex(-1);
	std::cout << "Array A: " << A <<'\n';
	std::cout << "\nrem idx 0 - ";
	A.RemoveElementAtIndex(0);
	std::cout << "Array A: " << A <<'\n';
	std::cout << "\nrem idx 2 - ";
	A.RemoveElementAtIndex(2);
	std::cout << "Array A: " << A <<'\n';
	std::cout << "\nrem idx 3 - ";
	A.RemoveElementAtIndex(3);
	std::cout << "Array A: " << A <<'\n';
	std::cout << "\nrem idx 3 - ";
	A.RemoveElementAtIndex(3);
	std::cout << "Array A: " << A <<'\n';

	//if(_CrtDumpMemoryLeaks() == true)
	//	std::cerr << "\n\n\tERROR MEMORY!!! - (_CrtDumpMemoryLeaks() == true)\n\n";
	//else
	//	std::cerr << "\n\n\tMemory remove correctly!!!\n\n";
	return 0;
}
