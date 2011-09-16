#include "stdafx.h"
#include "Array.h"
#include <algorithm>
#include <iomanip>

std::ostream& operator << (std::ostream& out, const Array& Right)
{
	for(int i = 0; i < Right.m_LastIdx; ++i)
	{
		if(!(i % 20))
			std::cout << std::endl;
		std::cout << std::setw(3) << Right.m_pArr[ i ];
	}
	return out;
}

Array Array::operator = (Array& Rigth)
{
	delete [] this->m_pArr;
	this->m_pArr = new Element [ Rigth.m_Size ];
	this->IfSort = Rigth.IfSort;
	this->m_CurrIdx = Rigth.m_CurrIdx;
	this->m_FirstIdx = Rigth.m_FirstIdx;
	this->m_LastIdx = Rigth.m_LastIdx;
	this->m_Size = Rigth.m_Size;
	this->m_Step = Rigth.m_Step;
	memcpy_s(this->m_pArr, sizeof(Element) * this->m_Size, Rigth.m_pArr, sizeof(Element) * Rigth.m_Size);
	return *this;
}

Array Array::operator + (Array& Rigth)
{
	Array tmp;

	tmp.PushArrayBack(this->m_pArr, this->m_Size);
	tmp.PushArrayBack(Rigth.m_pArr, Rigth.m_Size);

	return tmp;
}

void Array::FreeArray()
{
	this->m_Size = 1;
	this->m_Step = 1;
	this->m_CurrIdx = 0;
	this->m_FirstIdx = 0;
	this->m_LastIdx = 1;
	this->IfSort = false;

	Element* Arr = new Element [ this->m_Size ];
	delete [] m_pArr;
	m_pArr = Arr;
}

void Array::Sort()
{
	if(IfSort)
		return;

	std::sort(&m_pArr[ m_FirstIdx ], &m_pArr[ m_LastIdx ]);

	IfSort = true;
}

int Array::SearchKey(int Key)
{
	for(m_CurrIdx = 0; m_CurrIdx < m_LastIdx; ++m_CurrIdx)
		if(Key == m_pArr[ m_CurrIdx ])
			return m_CurrIdx;

	return -1;
}

void Array::RemoveElementAtIndex(int Index)
{
	if(Index < 0 || Index >= m_Size)
	{
		std::cerr << "\n\nWrong Index!!! - (Index < 0 || Index >= m_Size)\n\n";
		return;
	}
	
	Element* Arr = new Element [ m_LastIdx - 1 ];
	
	int i = 0;//используется как индекс нового массива

	for(m_CurrIdx = 0; m_CurrIdx < m_LastIdx; ++m_CurrIdx)
	{

		if(Index == m_CurrIdx)
			continue;
		else
		{
			Arr[ i ] = m_pArr[ m_CurrIdx ];
			++i;
		}
	}

	delete [] m_pArr;

	--m_LastIdx;
	m_Size = m_LastIdx;
	m_pArr = Arr;
}

void Array::InsertElementAtIndex(int Index, Element NewElement)
{
	if(Index < 0 || Index >= m_Size)
	{
		std::cerr << "\n\nWrong Index!!! - (Index < 0 || Index >= m_Size)\n\n";
		return;
	}
	
	Element* Arr = new Element [ m_LastIdx + 1 ];
	
	++m_LastIdx;

	int i = 0;//используется как индекс старого массива

	for(m_CurrIdx = 0; m_CurrIdx < m_LastIdx; ++m_CurrIdx)
	{

		if(Index == m_CurrIdx)
		{
			Arr[ m_CurrIdx ] = NewElement;
		}
		else
		{
			Arr[ m_CurrIdx ] = m_pArr[ i ];
			++i;
		}
	}

	delete [] m_pArr;

	m_Size = m_LastIdx;
	m_pArr = Arr;
}

void Array::Show(const char* Name)
{
	std::cout << Name << ":\n";

	for(m_CurrIdx = 0; m_CurrIdx < m_LastIdx; ++m_CurrIdx)
	{
		if(!(m_CurrIdx % 20))
			std::cout << std::endl;
		std::cout << std::setw(3) << m_pArr[ m_CurrIdx ];
	}

	std::cout << "\nFirst Index = " << m_FirstIdx << "; Last Index = " << m_LastIdx
		<< "; Current Index = " << m_CurrIdx << "; Size = " << m_Size << "; Step = " << m_Step << ";\n\n";
}

void Array::PushArrayBack(const Element* NewElements, int iSize)
{
	bool AddMem = true;

	m_Step = iSize;
	
	if(m_Size <= m_LastIdx + m_Step)
		AddMem = AllocMemory();
	
	if(AddMem)
	{
		for(m_CurrIdx = 0; m_CurrIdx < iSize; ++m_CurrIdx, ++m_LastIdx)
			m_pArr[ m_LastIdx ] = NewElements[ m_CurrIdx ];

		IfSort = false;
	}	
}

void Array::PushBack(Element NewElement)
{
	bool AddMem = true;

	if(m_Size == m_LastIdx)
		AddMem = AllocMemory();

	if(AddMem)
	{
		m_pArr[ m_LastIdx ] = NewElement;
		++m_LastIdx;
		m_CurrIdx = m_Size - 1;
	}
	IfSort = false;
}

bool Array::AllocMemory()
{
	int TempSize = m_Size + m_Step;
	
	if(TempSize > 100000)
	{
		std::cerr << "Can not add memory, you array is full!";
		return false;
	}

	Element* Arr = new Element [ TempSize ];
	
	memcpy_s(Arr, sizeof(Element) * TempSize, m_pArr, sizeof(Element) * m_Size);
	
	delete [] m_pArr;
	
	m_Size = TempSize;
	m_pArr = Arr;
	return true;
}

Array::Array(Element *Arr, int iSize)
	:m_pArr(0), m_Size(iSize), m_Step(iSize),
	m_CurrIdx(0), m_FirstIdx(0), m_LastIdx(iSize),
	IfSort(false)
{
	if(iSize <= 0 || Arr == 0)
	{
		std::cerr << "\nConstructor error!!! - ( iSize <= 0 || Arr == 0 )\n";
		m_Size = 1;
		m_Step = 1;
		m_pArr = new Element [ m_Size ];
		return;
	}
	m_pArr = new Element [ m_Size ];
	memcpy_s(m_pArr, sizeof(Element) * m_Size, Arr, sizeof(Element) * iSize);
}

Array::Array(int iSize, int iStep)
	:m_pArr(0), m_Size(iSize), m_Step(iStep),
	m_CurrIdx(0), m_FirstIdx(0), m_LastIdx(0),
	IfSort(false)
{
	iSize <= 0 ? m_Size = 0 : m_Size;
	iStep <= 0 ? m_Step = 1 : m_Step;

	m_pArr = new Element [ m_Size ];
}

Array::Array(const Array& Right)
	:m_pArr(0), m_Size(Right.m_Size), m_Step(Right.m_Step),
	m_CurrIdx(Right.m_CurrIdx), m_FirstIdx(Right.m_FirstIdx), m_LastIdx(Right.m_LastIdx),
	IfSort(Right.IfSort)
{
	if(Right.m_pArr != 0)
	{
		m_pArr = new Element [ m_Size ];
		memcpy_s(m_pArr, sizeof(Element) * m_Size, Right.m_pArr, sizeof(Element) * Right.m_Size);
	}
}

Array::Array()
	:m_pArr(0), m_Size(1), m_Step(1),
	m_CurrIdx(0), m_FirstIdx(0), m_LastIdx(0),
	IfSort(false)
{
	m_pArr = new Element [ m_Size ];
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

Array::~Array()
{
	delete [] m_pArr;
	m_pArr = 0;
}

//void Array::SetLastIdx(int Idx){
//	if(Idx < 0 || Idx > m_LastIdx)
//		return;
//	m_LastIdx = Idx;}

//void Array::SetAllToZero(){
//	for(m_CurrIdx = 0; m_CurrIdx < m_Size; ++m_CurrIdx)
//		m_pArr[ m_CurrIdx ] = 0;}
