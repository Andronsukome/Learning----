// �������� ������ Array
#ifndef ARRAYh53453453456_524534534153_54345345_001
#define ARRAYh53453453456_524534534153_54345345_001

class Array
{
	typedef int Element;
	
	Element * m_pArr;
	int m_Size;
	int m_Step;//��� ���������� �������
	int m_CurrIdx;//������� ������
	int m_FirstIdx;//������ ������� ��������, ������ == 0
	int m_LastIdx;//������ ������ ��������� �� ������� ��������� �� ��������� ���������� � �������
	
	bool AllocMemory();//����������� ������ �� ������ �������� �����
	bool IfSort;//��������� ������������ ������ ��� ���
	

public:

	Array(int iSize, int iStep);//������� ������ ��������� ������� � ������������� ��� �������� ������
	Array(Element *Arr, int iSize);//������� ������ �� ������ ��������� �������
	Array(const Array& Right);
	Array();
	~Array();

	int GetSize(){return this->m_Size;};
	int GetLastIdx(){return this->m_LastIdx;};
	int GetFirstIdx(){return this->m_FirstIdx;};
	int GetCurrIdx(){return this->m_CurrIdx;};
	int GetStep(){return this->m_Step;};
	void Show(const char* Name = "Array");//�������� ������, ��������� � �������� ��������� ��� ����������� �������
	void Sort();//��������� ������
	int SearchKey(int Key);//���� ������� � ������� � ���������� ��� ������ ��� -1 ���� �������� ���
	void PushBack(Element NewElement);//��������� 1 ������� � �����
	void PushArrayBack(const Element* NewElements, int iSize);//��������� ����� ������ � �����
	void RemoveElementAtIndex(int Index);//������� ������� �� ������� �� �������
	void InsertElementAtIndex(int Index, Element NewElement);//��������� ������� � ������ �� �������
	void FreeArray();//���������� ������ ������� �������� - �� �� ������� ������
//������� �� �������� ������	void SetLastIdx(int Idx);
//������� �� �����������	void SetAllToZero();//�������� ���� ������
};

#endif
