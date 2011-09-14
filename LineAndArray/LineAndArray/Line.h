//описание класса Line
// Доделать:
//2. Вернуть прежнюю длину линии, которую сделали паралельной.
#include "Dot.h"

#ifndef LINEh14534321584645_8678913618649646_8641_001
#define LINEh14534321584645_8678913618649646_8641_001

class Line
{
	Dot A;//начальная точка
	Dot B;//конечная точка
	double LengthLine;

	double GetLingthLine();
	void ResizeLine();
public:
	Line(double AX, double AY, double BX, double BY);
	Line(Dot X, Dot Y);
	Line(const Line& Right);
	Line();

	double GetLength(){return this->LengthLine;};
	void SetLine(double AX, double AY, double BX, double BY);
	bool CheckParallel(const Line Second);//возвращает true если линии параллельны
	void SetParallel(const Line Second);//делает обьект вызывающий функцию параллельным обьекту принятому в параметрах
	void Show(char* Name);
};

#endif
