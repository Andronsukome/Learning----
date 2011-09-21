// ��������� ����� ����������� ���������� �������� � ���������� ������� N �� N �� K ����� ����� ����� ���� ����� �� ������ �������
// �� ������� �������� ����. ������� �� ������ 30 ������.
// 15.07.2011

/* ������:
���� ��� ������� : �[n] � B[m]. ���������� ������� ������ ������, � ������� ����� �������: 
�������� ����� ��������; 
����� �������� ���� ��������; 
�������� ������� A, ������� �� ���������� � B; 
�������� ������� B, ������� �� ���������� � A; 
�������� �������� A � B, ������� �� �������� ������ ��� ��� (�� ���� ����������� ����������� ���� ���������� ���������). 
*/

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

const int  FieldSIZE = 8;			// ������ ���������� ����

void ProgressHorse(int [][FieldSIZE]);								// ����� ����� ���� �� ������ �� ������� �������� ����
void ShowField(int [][FieldSIZE]);									// ���������� ��������� ����� (��� ������������)
void ShowVersion(int **, int *);									// ���������� ������ ���������� �� ���-������ ����� (��� ������������)
bool RangeOfFields(int, int);										// ��������� �� ������ �� ��� �� �������� ����
void Init(int [][FieldSIZE]);										// �������� ������ (��������� ����)
int ** CopyField(int **, int [][FieldSIZE], int *, int *);			// �������� ���� ���� � ���� � ���-������ �����
int ** Add(int **, int *);											// ���� ���-������ ����������, ��������� �����
int ** Compare(int **, int[][FieldSIZE], int *, int *, int *);		// ��������� ����� � ���-������ ������������ ������ ���������� ������

int _tmain(int argc, _TCHAR* argv[])
{
	int iVersionSIZE = 10;											// ��������� ������ ���-�������
	int Field[FieldSIZE][FieldSIZE] = {0};							// ��������� ����
	int iCounter = 0;												// ������� ���������� �����
	int iEnough(0);													// ������������ ������� ������ ������������� ����� ����������
	int * pEnough = &iEnough;										// ��������� �� ������������
	int * pCounter = &iCounter;										// ��������� �� �������
	int *pVersionSIZE = &iVersionSIZE;								// ��������� �� ������ ���-�������
	int ** Version = new int * [iVersionSIZE];						// �������� ������ ��� ���-�������
	for(int i = 0; i < iVersionSIZE; ++i)
		Version[i] = new int [FieldSIZE * FieldSIZE];

	srand(time(NULL));

	while(iEnough != 100)											// ���� 100 ��� �� ����������� � ��� ���������� ���, ����������
	{
		ProgressHorse(Field);													// ������������ ������� ����������� �����
		Version = Compare(Version, Field, pCounter, pVersionSIZE, pEnough);		// ������� ��� �� ������������
	}

	cout << "Number of unic progress is " << iCounter << endl;					// ������� ���������

	for(int i = 0; i < iVersionSIZE; ++i)										// ������� ������ ���������� ��� ���-�������
		delete Version[i];
	delete [] Version;

	system("Pause");
	system("Cls");

	if(_CrtDumpMemoryLeaks())													// ��������� ��� �� ���������� ������ �������
		cout << "Not all of the allocated memory is removed." << endl;
	else
		cout << "Memory is removed correctly." << endl;


	return 0;
}

// ��������� ����� � ���-������ ������������ ������ ���������� ������
int ** Compare(int ** Version, int Field[][FieldSIZE], int * pCounter, int * pVersionSIZE, int * pEnough)
{
	int iCounter;													// ������� ��� ����������� �� ������� (������ ��� 1 �����)
	bool bState = true;												// ��������� ��� ��������� �����

	for(int i_Vers = 0; i_Vers < *pVersionSIZE; ++i_Vers)
	{
		iCounter = 0;											
		for(int i = 0; i < FieldSIZE; ++i)
		{
			for(int j = 0; j < FieldSIZE; ++j)
			{
				if(Version[i_Vers][iCounter++] == Field[i][j])		// ���� ������� � ������� ����� ����� ������������������ ������������� ���������� � true 
					bState = true;
				else												// ���� ������� ������� ��������� �������� � ������������� ���������� � false
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

	if(bState == false)													// ���� ���������� ����������, ��� � ������� ��� ����� ������
	{
		*pEnough = 0;													// ���������� ������������
		Version = CopyField(Version, Field, pCounter, pVersionSIZE);	// �������� ���������� ������ � ���
	}
	else																// ���� ����� ������ ���� � ����
		++*pEnough;														// ����������� ������������

	return Version;	
}

// ���������� ������ ���������� �� ���-������ ����� (��� ������������)
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

// ���� ���-������ ����������, ��������� �����
int ** Add(int ** Version, int * pVersionSIZE)
{
	int ** Temp = new int * [*pVersionSIZE+10];						// ������� ��������� ������ �� 10 ������� ������
	for(int i = 0; i < *pVersionSIZE+10; ++i)
		Temp[i] = new int [FieldSIZE * FieldSIZE];

	for(int i = 0; i < *pVersionSIZE; ++i)							// �������� � ���� ������
		memcpy_s(Temp[i],sizeof(int)*(FieldSIZE * FieldSIZE),Version[i],sizeof(int)*(FieldSIZE * FieldSIZE));

	for(int i = 0; i < *pVersionSIZE; ++i)							// ������� ������
		delete Version[i];
	delete [] Version;

	*pVersionSIZE += 10;											// ����������� ���������� ������������ ������ �������

	return Temp;													// ���������� ����� ������
}

// �������� ���� ���� � ���� � ���-������ �����
int ** CopyField(int ** Version, int Field[][FieldSIZE], int * pCounter, int * pVersionSIZE)
{
	int iCounter(0);											// ������� ������ ��� 1 �����

	if(*pCounter == *pVersionSIZE - 1)							// ���� ������ ��������
		Version = Add(Version, pVersionSIZE);					// ��������� � ���� ��������

	for(int i = 0; i < FieldSIZE; ++i)
		for(int j = 0; j < FieldSIZE; ++j)
			Version[*pCounter][iCounter++] = Field[i][j];		// ���������� ���� ���� � ���-������

	++*pCounter;												// ����������� ������� �� 1 ���������� ���

	return Version;
}

// �������� ������ (��������� ����)
void Init(int Field[][FieldSIZE])
{
	for(int i = 0; i < FieldSIZE; ++i)
		for(int j = 0; j < FieldSIZE; ++j)
			Field[i][j] = 0;
}

// ���������� ��������� ����� (��� ������������)
void ShowField(int Field[][FieldSIZE])
{
	for(int i = 0; i < FieldSIZE; ++i)
	{
		for(int j = 0; j < FieldSIZE; ++j)
			cout << Field[i][j] << "\t";
		cout << endl;
	}
}

// ����� ����� ���� �� ������ �� ������� �������� ����
void ProgressHorse(int Field[][FieldSIZE])
{
	int i = FieldSIZE - 1, j = FieldSIZE - FieldSIZE;		// ���������� ����
	int iStep(0);											// ���
	int * Position =  &Field[i][j];							// ��������� �� ��� �� �����������
	bool IfRange = true;									// ���������� �������� �����

	Init(Field);											// �������� ����

	*Position += 1;											// ��������� 1 � ��������� ������� ����

	while(Position != &Field[FieldSIZE - FieldSIZE][FieldSIZE - 1])				// ���� �� ��������� �� �������� ������� ����
	{
		iStep = rand() % 8 +1;													// ��������� ������� �������� 1 �� 8 �����

		switch(iStep)															// ����� ����� ���� ��� �������� � ��������� 1 � ����� ��������������
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

// ��������� �� ������ �� ��� �� �������� ����
bool RangeOfFields(int i, int j)
{
	if((i < FieldSIZE && i >= 0) && (j < FieldSIZE && j >= 0))	// ���� ����� �� �������� ����
		return true;											// ������� true
	else
		return false;											//���� ��� - false
}