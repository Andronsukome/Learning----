// Посчитать каким количеством уникальных способов в квадратной матрице N на N за K шагов можно ходом коня дойти от левого нижнего
// до правого верхнего угла. Матрица не больше 30 клеток.
// 15.07.2011

/* Вопрос:
Даны два массива : А[n] и B[m]. Необходимо создать третий массив, в котором нужно собрать: 
Элементы обоих массивов; 
Общие элементы двух массивов; 
Элементы массива A, которые не включаются в B; 
Элементы массива B, которые не включаются в A; 
Элементы массивов A и B, коотрые не являются общими дял них (то есть объединение результатов двух предыдущих вариантов). 
*/

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

const int  FieldSIZE = 8;			// Размер шахматного поля

void ProgressHorse(int [][FieldSIZE]);								// Ходит конем пока не дойдет до правого верхнего угла
void ShowField(int [][FieldSIZE]);									// Показывает шахматную доску (для тестирования)
void ShowVersion(int **, int *);									// Показывает массив указателей на лог-журнал ходов (для тестирования)
bool RangeOfFields(int, int);										// Проверяет не выйдет ли ход за диапазон поля
void Init(int [][FieldSIZE]);										// Обнуляет массив (шахматное поле)
int ** CopyField(int **, int [][FieldSIZE], int *, int *);			// Копирует путь коня с поля в лог-журнал ходов
int ** Add(int **, int *);											// Если лог-журнал закончился, добавляем место
int ** Compare(int **, int[][FieldSIZE], int *, int *, int *);		// Проверяет чтобы в лог-журнал записывалить только уникальные записи

int _tmain(int argc, _TCHAR* argv[])
{
	int iVersionSIZE = 10;											// Стартовый размер лог-журнала
	int Field[FieldSIZE][FieldSIZE] = {0};							// Шахматное поле
	int iCounter = 0;												// Счетчих уникальных ходов
	int iEnough(0);													// Ограничитель сколько подрят повторяющихся ходов игнорируем
	int * pEnough = &iEnough;										// Указатель на ограничитель
	int * pCounter = &iCounter;										// Указатель на счетчик
	int *pVersionSIZE = &iVersionSIZE;								// Указатель на размер лог-журнала
	int ** Version = new int * [iVersionSIZE];						// Выделяем память для лог-журнала
	for(int i = 0; i < iVersionSIZE; ++i)
		Version[i] = new int [FieldSIZE * FieldSIZE];

	srand(time(NULL));

	while(iEnough != 100)											// Если 100 раз не добавляется в лог уникальный ход, прекратить
	{
		ProgressHorse(Field);													// Просчитываем варианд прохождения конем
		Version = Compare(Version, Field, pCounter, pVersionSIZE, pEnough);		// Сверяем его на уникальность
	}

	cout << "Number of unic progress is " << iCounter << endl;					// Выводим результат

	for(int i = 0; i < iVersionSIZE; ++i)										// Удаляем память выделенную для лог-журнала
		delete Version[i];
	delete [] Version;

	system("Pause");
	system("Cls");

	if(_CrtDumpMemoryLeaks())													// Проверяем всю ли выделенную память удалили
		cout << "Not all of the allocated memory is removed." << endl;
	else
		cout << "Memory is removed correctly." << endl;


	return 0;
}

// Проверяет чтобы в лог-журнал записывалить только уникальные записи
int ** Compare(int ** Version, int Field[][FieldSIZE], int * pCounter, int * pVersionSIZE, int * pEnough)
{
	int iCounter;													// Счетчик для прохождения по массиву (вместо еще 1 цикла)
	bool bState = true;												// Перемення для сравнения ходов

	for(int i_Vers = 0; i_Vers < *pVersionSIZE; ++i_Vers)
	{
		iCounter = 0;											
		for(int i = 0; i < FieldSIZE; ++i)
		{
			for(int j = 0; j < FieldSIZE; ++j)
			{
				if(Version[i_Vers][iCounter++] == Field[i][j])		// Если находит в журнале точно такую последовательность устанавливает переменную в true 
					bState = true;
				else												// Если находит отличие прерывает проверку и устанавливает переменную в false
				{
					bState = false;
					break;
				}
			}
			if(bState == false)										
				break;
		}
		if(bState == true)
			break;
	}

	if(bState == false)													// Если переменная показывает, что в журнале нет такой записи
	{
		*pEnough = 0;													// Сбрасывает ограничитель
		Version = CopyField(Version, Field, pCounter, pVersionSIZE);	// Копирует уникальную запись в лог
	}
	else																// Если такая запись есть в логе
		++*pEnough;														// Увеличивает ограничитель

	return Version;	
}

// Показывает массив указателей на лог-журнал ходов (для тестирования)
void ShowVersion(int ** Version, int * pVersionSIZE)
{
	for(int i = 0; i < *pVersionSIZE; ++i)
	{
		cout << "\"" << i << "\" - ";
		for(int j = 0; j < FieldSIZE * FieldSIZE; ++j)
			 cout << Version[i][j] << " ";
		cout << endl;
	}
}

// Если лог-журнал закончился, добавляем место
int ** Add(int ** Version, int * pVersionSIZE)
{
	int ** Temp = new int * [*pVersionSIZE+10];						// Создаем временный журнал на 10 страниц больше
	for(int i = 0; i < *pVersionSIZE+10; ++i)
		Temp[i] = new int [FieldSIZE * FieldSIZE];

	for(int i = 0; i < *pVersionSIZE; ++i)							// Копируем в него старый
		memcpy_s(Temp[i],sizeof(int)*(FieldSIZE * FieldSIZE),Version[i],sizeof(int)*(FieldSIZE * FieldSIZE));

	for(int i = 0; i < *pVersionSIZE; ++i)							// Удаляем старый
		delete Version[i];
	delete [] Version;

	*pVersionSIZE += 10;											// Увеличиваем переменную определяющую размер журнала

	return Temp;													// Возвращаем новый журнал
}

// Копирует путь коня с поля в лог-журнал ходов
int ** CopyField(int ** Version, int Field[][FieldSIZE], int * pCounter, int * pVersionSIZE)
{
	int iCounter(0);											// Счетчик вместо еще 1 цикла

	if(*pCounter == *pVersionSIZE - 1)							// Если журнал заполнен
		Version = Add(Version, pVersionSIZE);					// добавляем в него страницы

	for(int i = 0; i < FieldSIZE; ++i)
		for(int j = 0; j < FieldSIZE; ++j)
			Version[*pCounter][iCounter++] = Field[i][j];		// Записываем путь коня в лог-журнал

	++*pCounter;												// Увеличиваем счетчик на 1 уникальный ход

	return Version;
}

// Обнуляет массив (шахматное поле)
void Init(int Field[][FieldSIZE])
{
	for(int i = 0; i < FieldSIZE; ++i)
		for(int j = 0; j < FieldSIZE; ++j)
			Field[i][j] = 0;
}

// Показывает шахматную доску (для тестирования)
void ShowField(int Field[][FieldSIZE])
{
	for(int i = 0; i < FieldSIZE; ++i)
	{
		for(int j = 0; j < FieldSIZE; ++j)
			cout << Field[i][j] << "\t";
		cout << endl;
	}
}

// Ходит конем пока не дойдет до правого верхнего угла
void ProgressHorse(int Field[][FieldSIZE])
{
	int i = FieldSIZE - 1, j = FieldSIZE - FieldSIZE;		// Координаты хода
	int iStep(0);											// Ход
	int * Position =  &Field[i][j];							// Указатель на ход по координатам
	bool IfRange = true;									// Определяет диапазон доски

	Init(Field);											// Обнуляем поле

	*Position += 1;											// Добавляем 1 в стартовую позицию коня

	while(Position != &Field[FieldSIZE - FieldSIZE][FieldSIZE - 1])				// Пока не добрались до верхнего правого угла
	{
		iStep = rand() % 8 +1;													// Случайным образом выбираем 1 из 8 ходов

		switch(iStep)															// Ходим конем если это возможно и добавляем 1 в новое местоположения
		{
		case 1:
			{
				IfRange = RangeOfFields(i - 2, j - 1);
				if(IfRange)
				{
					i -= 2;
					j -= 1;
					Position =  &Field[i][j];
					*Position += 1;
				}
				break;
			}
		case 2:
			{
				IfRange = RangeOfFields(i - 2, j +1);
				if(IfRange)
				{
					i -= 2;
					j += 1;
					Position =  &Field[i][j];
					*Position += 1;
				}
				break;
			}
		case 3:
			{
				IfRange = RangeOfFields(i + 2, j - 1);
				if(IfRange)
				{
					i += 2;
					j -= 1;
					Position =  &Field[i][j];
					*Position += 1;
				}
				break;
			}
		case 4:
			{
				IfRange = RangeOfFields(i + 2, j + 1);
				if(IfRange)
				{
					i += 2;
					j += 1;
					Position =  &Field[i][j];
					*Position += 1;
				}
				break;
			}
		case 5:
			{
				IfRange = RangeOfFields(i - 1, j - 2);
				if(IfRange)
				{
					i -= 1;
					j -= 2;
					Position =  &Field[i][j];
					*Position += 1;
				}
				break;
			}
		case 6:
			{
				IfRange = RangeOfFields(i + 1, j - 2);
				if(IfRange)
				{
					i += 1;
					j -= 2;
					Position =  &Field[i][j];
					*Position += 1;
				}
				break;
			}
		case 7:
			{
				IfRange = RangeOfFields(i - 1, j + 2);
				if(IfRange)
				{
					i -= 1;
					j += 2;
					Position =  &Field[i][j];
					*Position += 1;
				}
				break;
			}
		case 8:
			{
				IfRange = RangeOfFields(i + 1, j + 2);
				if(IfRange)
				{
					i += 1;
					j += 2;
					Position =  &Field[i][j];
					*Position += 1;
				}
				break;
			}
		}
	}
}

// Проверяет не выйдет ли ход за диапазон поля
bool RangeOfFields(int i, int j)
{
	if((i < FieldSIZE && i >= 0) && (j < FieldSIZE && j >= 0))	// Если вышли за диапазон поля
		return true;											// вернуть true
	else
		return false;											//если нет - false
}