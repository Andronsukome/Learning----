// ��������� ����� ����������� ���������� �������� � ���������� ������� N �� N �� K ����� ����� ����� ���� ����� �� ������ �������
// �� ������� �������� ����. ������� �� ������ 30 ������.
// 15.07.2011
// 21.09.2011 (����������� ���������� � ������� �������� �������)

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <conio.h>//��������� _getch()

const int FieldSIZE(8);// ������ ���������� ���� (N)

bool IfRange(const int x,const int y,const int FieldSIZE);// ��������� �������� �� ���, true ���� �� ����� �� ����
int Version(const int Step[], const int StepSIZE, int Field[][FieldSIZE], const int FieldSIZE,
	int StartPosition_X, int StartPosition_Y, int FinalPosition_X, int FinalPosition_Y, const int NumberOfStep);// ��������� ���������� ��������� ����������� ���� �� � �����

int _tmain(int argc, _TCHAR* argv[])
{
	const int StepSIZE(16);// ������ ������� ��� ����������� ����
	int Step[StepSIZE] = {-2,-2,-1, 1, 2, 2, 1, -1, -1, 1, 2, 2, 1, -1, -2, -2};// ������ ����� ����
	int Field[FieldSIZE][FieldSIZE] = {NULL};// ��������� ����
	unsigned int Counter(NULL);// ������� ���������� �����
	int Key(10);// ���������� ����� (�)
	while(Key != 48)// ���� �� ����� 0
	{
		system("Cls");
		cout << "\nPlease, enter the number of steps\nfor which You want to take the field: ";
		cin >> Key;
		if(!cin)// ���� ����� ������ � ���������� ��� ��������
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		system("Cls");
		cout << "\n\nPlease wait. Processing.\n\n";
		Counter = Version(Step, StepSIZE, Field, FieldSIZE, FieldSIZE - 1, FieldSIZE - FieldSIZE, FieldSIZE - FieldSIZE, FieldSIZE - 1, Key);
		system("Cls");
		cout << "\n\n   The number of unique ways\nin a square matrix of "
			<< FieldSIZE << " by " << FieldSIZE << "\nfor " << Key 
			<< " steps == " << Counter << endl << endl
			<< "Press any key if you want to continue,\n or exit press - \'0\'\n";
		Key = _getch();
	}

	return NULL;
}

int Version(const int Step[], const int StepSIZE, int Field[][FieldSIZE], const int FieldSIZE,
	int StartPosition_X, int StartPosition_Y, int FinalPosition_X, int FinalPosition_Y, const int NumberOfStep)
{
	unsigned int Counter(NULL);// ������� ���������� �����
	int * StartPosition = &Field[StartPosition_X][StartPosition_Y];
	int * FinalPosition = &Field[FinalPosition_X][FinalPosition_Y];
	if(NumberOfStep >= NULL && StartPosition == FinalPosition)// ���� ��� ��������� ���� � ��������� ���� - ��������� � �������
		return ++Counter;	
	// ���� ��������� ���� � �� �������� ������� - �� ������� � ��������� ��������
	else if(NumberOfStep == NULL)
		return NULL;

	for(int i = NULL; i < StepSIZE / 2; ++i)
	{
		if(IfRange(StartPosition_X + Step[i], StartPosition_Y + Step[i + 8], FieldSIZE))// ���� ���� ��� ��������
		{
			Counter += Version(Step, StepSIZE, Field, FieldSIZE, StartPosition_X + Step[i], StartPosition_Y + Step[i + 8], FinalPosition_X, FinalPosition_Y, NumberOfStep - 1);
		}
		else
			continue;
	}
	return Counter;
}

bool IfRange(const int x, const int y, const int FieldSIZE)
{
	if((x < FieldSIZE && x >= NULL) && (y < FieldSIZE && y >= NULL))// ���� �� ����� �� �������� ����
		return true;
	else
		return false;
}