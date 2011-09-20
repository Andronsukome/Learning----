// перевернуть строку не использу€ дополнительный Ѕ”‘≈–!!!
// как € пон€л нельз€ использовать ни временную переменную, ни дополнительную линию

#include "stdafx.h"
#include <iostream>
using namespace std;

void reverse(char *String);

int _tmain(int argc, _TCHAR* argv[])
{
	char String[] = "This line should be rotated";

	cout << "Befor: " << String << endl;
	reverse(String);
	cout << "After: " << String << endl;

	return 0;
}

void reverse(char *String)
{
	int len = strlen(String) - 1;

	for(int i = 0; i < len; ++i, --len)
	{
		String[ len ] ^= String[ i ];
		String[ i ] ^= String[ len ];
		String[ len ] ^= String[ i ];
	}
}