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

	inline int GetSize() const {return this->m_Size;};
	inline int GetLastIdx() const {return this->m_LastIdx;};
	inline int GetFirstIdx() const {return this->m_FirstIdx;};
	inline int GetCurrIdx() const {return this->m_CurrIdx;};
	inline int GetStep() const {return this->m_Step;};
	void Sort();//��������� ������
	int SearchKey(int Key);//���� ������� � ������� � ���������� ��� ������ ��� -1 ���� �������� ���
	void PushBack(Element NewElement);//��������� 1 ������� � �����
	void PushArrayBack(const Element* NewElements, int iSize);//��������� ����� ������ � �����
	void RemoveElementAtIndex(int Index);//������� ������� �� ������� �� �������
	void InsertElementAtIndex(int Index, Element NewElement);//��������� ������� � ������ �� �������
	void FreeArray();//���������� ������ ������� �������� - �� �� ������� ������

	Array operator + (Array& Rigth);
	Array operator = (Array& Rigth);

	friend std::ostream& operator << (std::ostream& out, const Array& Right);
};

#endif
//void Show(const char* Name = "Array");//�������� ������, ��������� � �������� ��������� ��� ����������� �������