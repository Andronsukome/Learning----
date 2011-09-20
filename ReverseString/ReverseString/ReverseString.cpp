// перевернуть строку не используя дополнительный буфер!!!
// вообще я думал над задачей и скорее всего имелось ввиду
// не использовать именно временную переменную для обмена,
// потому он и решал побитово...

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char string[] = "This line should be rotated";
	int len = strlen(string);

	cout << "Befor: " << string << endl;
	for(int i = 0; i < len; ++i)
	{
		if(i == len || i > len - i - 1)
			break;
		string[ len ] = string[ i ];
		string[ i ] = string[ len - i - 1 ];
		string[ len - i - 1 ] = string[ len ];
	}
	string[ len ] = 0;

	cout << "After: " << string << endl;

	return 0;
}

