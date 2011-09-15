//�������� ������ Line
// ��������:
//2. ������� ������� ����� �����, ������� ������� �����������.
#ifndef LINEh14534321584645_8678913618649646_8641_001
#define LINEh14534321584645_8678913618649646_8641_001

#include "Dot.h"

class Line
{
	Dot A;//��������� �����
	Dot B;//�������� �����
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
	bool CheckParallel(const Line Second);//���������� true ���� ����� �����������
	void SetParallel(const Line Second);//������ ������ ���������� ������� ������������ ������� ��������� � ����������
	void Show(char* Name = "Line");

	bool operator == (Line& Rigth);
};

#endif
