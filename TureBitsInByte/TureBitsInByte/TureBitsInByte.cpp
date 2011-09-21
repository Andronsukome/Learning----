// ���������� ���������� ��� ������������� � 1 � �����. ������������ ������� ����������� �����������,
// ������������� ���������� ���������� �����, �� ��������� ������������� ��������. ����� ����������
// ��������� ������� � ��������� �������������� ��������� �������� ���������� ��������, �� ��������
// ����� ������� �� ����� ������������� ��������. ���� ��������� ������� �� ���������� ���������������
// ����� � ����� ����� ���������� ���������� �������� �� �������������.
// 21.09.2011

#include "stdafx.h"
#include <iostream>
using std::cout;
#include <conio.h>

int CountTrueBitsInByte(char chValue);

int _tmain(int argc, _TCHAR* argv[])
{
	const int SizeCache = 256,//������ ������� ��� ����������� �� �������: 1 ���� = (-127 - 128) = 256
		CacheShift = 127;//�������� ������� � ������������� ��������
	char ch = ' ';
	int iCount(0),
		Cache[ SizeCache ];//���������� ��� ����� ��������� �������� �� 0 �� 8

	for(int i = 0; i < SizeCache; ++i)
		Cache[ i ] = -1;//���������� � �������� ��������

	while(true)
	{
		cout << "Input the symbol \"0-exit\" :> ";
		ch = _getch();
		if(ch != '0')//���� �� �����
			_putch(ch);
		else
		{
			cout << "\n\n";
			break;		
		}

		if(Cache[ (int)ch + CacheShift ] != -1)//���� � ������� ���� �����
			iCount = Cache[ (int)ch + CacheShift ];
		else
		{
			iCount = CountTrueBitsInByte(ch);
			Cache[ (int)ch + CacheShift ] = iCount;//������� ��������� � �������
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