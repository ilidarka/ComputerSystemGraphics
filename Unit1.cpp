//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//Длина стороны
int a = 20;
//угол поворота фигуры
float alfa = 0;
//скорость поворота угла
float alfaSpeed = 0.01;
//Скорость перемещения
int speed = 100;
//Координаты центра фигуры
int x;
int y;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    a = StrToInt(Edit1->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    speed = StrToInt(Edit2->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
    alfa = 0;
	x = X;
	y = Y;
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Image1->Canvas->FillRect(Canvas->ClipRect);
	Timer1->Enabled = false;
	Timer1->Interval = speed;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	Timer1->Interval = speed;
	Image1->Canvas->FillRect(Canvas->ClipRect);
	//AB
	Image1->Canvas->MoveTo(x + ((x - (a / 2)) - x) * cos(alfa) - ((y + (a / 2)) - y) * sin(alfa),
						   y + ((x - (a / 2)) - x) * sin(alfa) + ((y + (a / 2)) - y) * cos(alfa));
	Image1->Canvas->LineTo(x + ((x - (a / 2)) - x) * cos(alfa) - ((y - (a / 2)) - y) * sin(alfa),
						   y + ((x - (a / 2)) - x) * sin(alfa) + ((y - (a / 2)) - y) * cos(alfa));
	//BC
	Image1->Canvas->MoveTo(x + ((x - (a / 2)) - x) * cos(alfa) - ((y - (a / 2)) - y) * sin(alfa),
						   y + ((x - (a / 2)) - x) * sin(alfa) + ((y - (a / 2)) - y) * cos(alfa));
	Image1->Canvas->LineTo(x + ((x + (a / 2)) - x) * cos(alfa) - ((y - (a / 2)) - y) * sin(alfa),
						   y + ((x + (a / 2)) - x) * sin(alfa) + ((y - (a / 2)) - y) * cos(alfa));
	//CD
	Image1->Canvas->MoveTo(x + ((x + (a / 2)) - x) * cos(alfa) - ((y - (a / 2)) - y) * sin(alfa),
						   y + ((x + (a / 2)) - x) * sin(alfa) + ((y - (a / 2)) - y) * cos(alfa));
	Image1->Canvas->LineTo(x + ((x + (a / 2)) - x) * cos(alfa) - ((y + (a / 2)) - y) * sin(alfa),
						   y + ((x + (a / 2)) - x) * sin(alfa) + ((y + (a / 2)) - y) * cos(alfa));
	//DA
	Image1->Canvas->MoveTo(x + ((x + (a / 2)) - x) * cos(alfa) - ((y + (a / 2)) - y) * sin(alfa),
						   y + ((x + (a / 2)) - x) * sin(alfa) + ((y + (a / 2)) - y) * cos(alfa));
	Image1->Canvas->LineTo(x + ((x - (a / 2)) - x) * cos(alfa) - ((y + (a / 2)) - y) * sin(alfa),
						   y + ((x - (a / 2)) - x) * sin(alfa) + ((y + (a / 2)) - y) * cos(alfa));
	//MN
	Image1->Canvas->MoveTo(x + ((x - (a / 2)) - x) * cos(alfa) - sin(alfa),
						   y + ((x - (a / 2)) - x) * sin(alfa) + cos(alfa));
	Image1->Canvas->LineTo(x + ((x + (a / 2)) - x) * cos(alfa) - sin(alfa),
						   y + ((x + (a / 2)) - x) * sin(alfa) + cos(alfa));
	//PT
	Image1->Canvas->MoveTo(x + cos(alfa) - ((y - (a / 2)) - y) * sin(alfa),
						   y + sin(alfa) + ((y - (a / 2)) - y) * cos(alfa));
	Image1->Canvas->LineTo(x + cos(alfa) - ((y + (a / 2)) - y) * sin(alfa),
						   y + sin(alfa) + ((y + (a / 2)) - y) * cos(alfa));
	alfa += alfaSpeed;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    alfaSpeed = StrToFloat(Edit3->Text);
}
//---------------------------------------------------------------------------

