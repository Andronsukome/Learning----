// Подсчитать количество бит установленных в 1 в байте. Используется таблица кеширования результатов,
// индексируется возможными значениями байта, со смешением отрицательных индексов. Можно изначально
// заполнить таблицу и увеличить быстродействие программы уменьшив количество проверок, но увеличив
// время запуска на время инициализации значений. Либо заполнять таблицу из изначально подготовленного
// файла и тогда также уменьшится количество проверок на заполненность.
// 21.09.2011

#include "stdafx.h"
#include <iostream>
using std::cout;
#include <conio.h>

int CountTrueBitsInByte(char chValue);

int _tmain(int argc, _TCHAR* argv[])
{
	const int SizeCache = 256,//размер таблицы для кеширования из расчета: 1 байт = (-127 - 128) = 256
		CacheShift = 127;//смещение индекса в положительное значение
	char ch = ' ';
	int iCount(0),
		Cache[ SizeCache ];//количество бит может принимать значения от 0 до 8

	for(int i = 0; i < SizeCache; ++i)
		Cache[ i ] = -1;//выставляем в неверные значения

	while(true)
	{
		cout << "Input the symbol \"0-exit\" :> ";
		ch = _getch();
		if(ch != '0')//если не выход
			_putch(ch);
		else
		{
			cout << "\n\n";
			break;		
		}

		if(Cache[ (int)ch + CacheShift ] != -1)//если в таблице есть ответ
			iCount = Cache[ (int)ch + CacheShift ];
		else
		{
			iCount = CountTrueBitsInByte(ch);
			Cache[ (int)ch + CacheShift ] = iCount;//заносим результат в таблицу
		}

		cout << "; True bits in this symbol is " << iCount << '\n';
	}

	return 0; 
}

int CountTrueBitsInByte(char chValue)
{
	const int BitsInBytes(8);
	int iMask(1),
		iCounter(0);

	for(int i = 0; i < BitsInBytes; ++i)
	{
		if(chValue & iMask)
			++iCounter;
		chValue >>= 1;
	}
	return iCounter;
}