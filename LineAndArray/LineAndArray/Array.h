// Описание класса Array
#ifndef ARRAYh53453453456_524534534153_54345345_001
#define ARRAYh53453453456_524534534153_54345345_001

class Array
{
	typedef int Element;
	
	Element * m_pArr;
	int m_Size;
	int m_Step;//Шаг увеличения массива
	int m_CurrIdx;//Текуший индекс
	int m_FirstIdx;//Индекс первого элемента, всегда == 0
	int m_LastIdx;//Индекс всегда указывает на элемент следующий за последним заполенным в массиве
	
	bool AllocMemory();//Увеличивает массив на размер заданный шагом
	bool IfSort;//Указывает отсортирован массив или нет
	

public:

	Array(int iSize, int iStep);//Создает массив заданного размера и устанавливает шаг прироста памяти
	Array(Element *Arr, int iSize);//Создает массив на основе принятого массива
	Array(const Array& Right);
	Array();
	~Array();

	inline int GetSize() const {return this->m_Size;};
	inline int GetLastIdx() const {return this->m_LastIdx;};
	inline int GetFirstIdx() const {return this->m_FirstIdx;};
	inline int GetCurrIdx() const {return this->m_CurrIdx;};
	inline int GetStep() const {return this->m_Step;};
	void Sort();//Сортирует массив
	int SearchKey(int Key);//Ищет элемент в массиве и возвращает его индекс или -1 если элемента нет
	void PushBack(Element NewElement);//Добавляет 1 элемент в конец
	void PushArrayBack(const Element* NewElements, int iSize);//Добавляет новый массив в конец
	void RemoveElementAtIndex(int Index);//Удаляет элемент из массива по индексу
	void InsertElementAtIndex(int Index, Element NewElement);//Добавляет элемент в массив по индексу
	void FreeArray();//освобождет память занятую массивом - НО НЕ УДАЛЯЕТ массив

	Array operator + (Array& Rigth);
	Array operator = (Array& Rigth);

	friend std::ostream& operator << (std::ostream& out, const Array& Right);
};

#endif
//void Show(const char* Name = "Array");//Печатает массив, принимает в качестве параметра имя печатаемого массива