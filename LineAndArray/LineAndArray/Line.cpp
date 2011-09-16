#include "stdafx.h"
#include "Line.h"

void ResizeLine()
{
	//раздвинуть линию
}

std::ostream& operator << (std::ostream& out, const Line& Right)
{
	out << "Line: A(" << Right.A.x << ", " << Right.A.y 
		<< "), B(" << Right.B.x << ", " << Right.B.y << ")\n";
	return out;
}

bool Line::operator== (Line& Rigth)
{
	return (this->A.x == Rigth.A.x && this->B.x == Rigth.B.x
		&& this->A.y == Rigth.A.y && this->B.y == Rigth.B.y);
}

double Line::GetLingthLine()
{
	//смещаем первую точку исходной линии в 0, а вторую сдвигаем на столько - сколько сметили 1ю
	double tmpSecondDotX = this->B.x - this->A.x;
	double tmpSecondDotY = this->B.y - this->A.y;
	//вычисляем длину гипотенузы
	double Hypotenuse = std::sqrt(std::pow(tmpSecondDotX, 2) + std::pow(tmpSecondDotY, 2));
	return Hypotenuse;
}

bool Line::CheckParallel(const Line Second)
{
	//смещаем первую точку Линии 1 в 0, а вторую сдвигаем на столько - сколько сметили 1ю
	double TempDotFirstLineX = this->B.x - this->A.x;
	double TempDotFirstLineY = this->B.y - this->A.y;
	//находим значения для таблицы брадиса 1й линии относительно оси Х (угол)
	double AngleFirstTriangle = TempDotFirstLineY / TempDotFirstLineX;

	//смещаем первую точку Линии 2 в 0, а вторую сдвигаем на столько - сколько сметили 1ю
	double TempDotSecondLineX = Second.B.x - Second.A.x;
	double TempDotSecondLineY = Second.B.y - Second.A.y;
	//находим значения для таблицы брадиса 2й линии относительно оси Х (угол)
	double AngleSecondTriangle = TempDotSecondLineY / TempDotSecondLineX;
	
	//проверяем полученные значения на равенство1

	if((float)AngleFirstTriangle == (float)AngleSecondTriangle)
		return true;
	return false;
}

void Line::SetParallel(const Line Second)
{
	if(this->CheckParallel(Second))
		return;
	//смещаем первую точку исходной линии в 0, а вторую сдвигаем на столько - сколько сметили 1ю
	double tmpSecondDotFirstLineX = this->B.x - this->A.x;
	double tmpSecondDotFirstLineY = this->B.y - this->A.y;
	//находим значения для таблицы брадиса исходной линии относительно оси Х (угол)
	double AngleFirstTriangle = tmpSecondDotFirstLineY / tmpSecondDotFirstLineX;

	//смещаем первую точку переданной линии в 0, а вторую сдвигаем на столько - сколько сметили 1ю
	double tmpSecondDotSecondLineX = Second.B.x - Second.A.x;
	double tmpSecondDotSecondLineY = Second.B.y - Second.A.y;

	//получаем новые координаты 2й точки для исходной линии и возвращаем ее на место
	this->B.x = tmpSecondDotSecondLineX + this->A.x;
	this->B.y = tmpSecondDotSecondLineY + this->A.y;
}

void Line::Show(char* Name)
{
	std::cout << Name << " Line == Dot A(" << this->A.x << ", " << this->A.y
		<< ") and Dot B(" << this->B.x << ", " << this->B.y << ")\n";
}

void Line::SetLine(double AX, double AY, double BX, double BY)
{
	this->A.x = AX;
	this->A.y = AY;
	this->B.x = BX;
	this->B.y = BY;
}

Line::Line(const Line& Right)
	:A(Right.A), B(Right.B), LengthLine(Right.LengthLine)
{
}

Line::Line(Dot X, Dot Y)
	:A(X), B(Y), LengthLine(0)
{
	this->LengthLine = this->GetLingthLine();
}

Line::Line(double AX, double AY, double BX, double BY)
	:A(AX, AY), B(BX, BY), LengthLine(0)
{
	this->LengthLine = this->GetLingthLine();
}

Line::Line()
	:A(0, 0), B(0, 0), LengthLine(0)
{
}