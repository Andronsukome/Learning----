// Посчитать каким количеством уникальных способов в квадратной матрице N на N за K шагов можно ходом коня дойти от левого нижнего
// до правого верхнего угла. Матрица не больше 30 клеток.
// 15.07.2011
// 21.09.2011 (подправлены коментарии и удалены ненужные функции)

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <conio.h>//подключил _getch()

const int FieldSIZE(8);// размер шахматного поля (N)

bool IfRange(const int x,const int y,const int FieldSIZE);// проверяет возможен ли ход, true если не вышел за поле
int Version(const int Step[], const int StepSIZE, int Field[][FieldSIZE], const int FieldSIZE,
	int StartPosition_X, int StartPosition_Y, int FinalPosition_X, int FinalPosition_Y, const int NumberOfStep);// проверяет количество вариантов прохождения поля за К шагов

int _tmain(int argc, _TCHAR* argv[])
{
	const int StepSIZE(16);// размер массива для определения хода
	int Step[StepSIZE] = {-2,-2,-1, 1, 2, 2, 1, -1, -1, 1, 2, 2, 1, -1, -2, -2};// массив ходов коня
	int Field[FieldSIZE][FieldSIZE] = {NULL};// шахматное поле
	unsigned int Counter(NULL);// счетчик уникальных ходов
	int Key(10);// количество ходов (К)
	while(Key != 48)// пока не нажат 0
	{
		system("Cls");
		cout << "\nPlease, enter the number of steps\nfor which You want to take the field: ";
		cin >> Key;
		if(!cin)// если мусор чистим и пропускаем эту итерацию
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
	unsigned int Counter(NULL);// счетчик уникальных ходов
	int * StartPosition = &Field[StartPosition_X][StartPosition_Y];
	int * FinalPosition = &Field[FinalPosition_X][FinalPosition_Y];
	if(NumberOfStep >= NULL && StartPosition == FinalPosition)// если это последний ходи и финальное поле - посчитать и вернуть
		return ++Counter;	
	// если финальное поле и не конечная позиция - не считать и закончить рекурсию
	else if(NumberOfStep == NULL)
		return NULL;

	for(int i = NULL; i < StepSIZE / 2; ++i)
	{
		if(IfRange(StartPosition_X + Step[i], StartPosition_Y + Step[i + 8], FieldSIZE))// если этот ход возможен
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
	if((x < FieldSIZE && x >= NULL) && (y < FieldSIZE && y >= NULL))// Если не вышли за диапазон поля
		return true;
	else
		return false;
}