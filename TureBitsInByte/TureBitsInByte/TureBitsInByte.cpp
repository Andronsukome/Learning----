// Подсчитать количество бит установленных в 1 в байте
// 21.09.2011

#include "stdafx.h"
#include <iostream>
using std::cout;
#include <conio.h>

int CountTrueBitsInByte(char chValue);

int _tmain(int argc, _TCHAR* argv[])
{
	char ch = ' ';
	int iCount(0);

	while(true)
	{
		cout << "Input the symbol \"0-exit\" :> ";
		ch = _getch();
		if(ch != '0')
			_putch(ch);
		else
		{
			cout << "\n\n";
			break;		
		}
		iCount = CountTrueBitsInByte(ch);
		cout << "; True bits in this symbol is " << iCount << '\n';
	}

	return 0; 
}

int CountTrueBitsInByte(char chValue)
{
	const int BitsInBytes(8);
	int iMask(1);
	int iCounter(0);

	for(int i = 0; i < BitsInBytes; ++i)
	{
		if(chValue & iMask)
			++iCounter;
		chValue >>= 1;
	}
	return iCounter;
}