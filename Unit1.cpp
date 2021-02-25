//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//����� �������
int a = 50;
//���� �������� ������
float alfa = 0;
//�������� �������� ����
float alfaSpeed = 0.01;
//�������� �����������
int speed = 100;
//���������� ������ ������
int x;
int y;
//������ ��������� �������� ��������
TPoint outerRectangle[4];
//������ ��������� ����������� ��������
TPoint innerRectangle[4];
//������ ��������� ���������� ������
TPoint innerFigure[12];

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

	outerRectangle[0] = Point(x + ((x - (a / Sqrt(2))) - x) * cos(alfa) - sin(alfa),
							  y + ((x - (a / Sqrt(2))) - x) * sin(alfa) + cos(alfa));
	outerRectangle[1] = Point(x + cos(alfa) - ((y - (a / Sqrt(2))) - y) * sin(alfa),
							  y + sin(alfa) + ((y - (a / Sqrt(2))) - y) * cos(alfa));
	outerRectangle[2] = Point(x + ((x + (a / Sqrt(2))) - x) * cos(alfa) - sin(alfa),
							  y + ((x + (a / Sqrt(2))) - x) * sin(alfa) + cos(alfa));
	outerRectangle[3] = Point(x + cos(alfa) - ((y + (a / Sqrt(2))) - y) * sin(alfa),
							  y + sin(alfa) + ((y + (a / Sqrt(2))) - y) * cos(alfa));
	Image1->Canvas->Polygon(outerRectangle, 3);

	innerRectangle[0] = Point(x + ((x - (a / 2)) - x) * cos(alfa) - ((y + (a / 2)) - y) * sin(alfa),
							  y + ((x - (a / 2)) - x) * sin(alfa) + ((y + (a / 2)) - y) * cos(alfa));
	innerRectangle[1] = Point(x + ((x - (a / 2)) - x) * cos(alfa) - ((y - (a / 2)) - y) * sin(alfa),
							  y + ((x - (a / 2)) - x) * sin(alfa) + ((y - (a / 2)) - y) * cos(alfa));
	innerRectangle[2] = Point(x + ((x + (a / 2)) - x) * cos(alfa) - ((y - (a / 2)) - y) * sin(alfa),
						      y + ((x + (a / 2)) - x) * sin(alfa) + ((y - (a / 2)) - y) * cos(alfa));
	innerRectangle[3] = Point(x + ((x + (a / 2)) - x) * cos(alfa) - ((y + (a / 2)) - y) * sin(alfa),
						      y + ((x + (a / 2)) - x) * sin(alfa) + ((y + (a / 2)) - y) * cos(alfa));
	Image1->Canvas->Polygon(innerRectangle, 3);

	innerFigure[0] = Point(x + ((x - (a / 2)) - x) * cos(alfa) - sin(alfa),
						   y + ((x - (a / 2)) - x) * sin(alfa) + cos(alfa));
	innerFigure[1] = Point(x + ((x - ((Sqrt(2) * a) - a)) - x) * cos(alfa) - ((y - ((Sqrt(2) * a) - a)) - y) * sin(alfa),
						   y + ((x - ((Sqrt(2) * a) - a)) - x) * sin(alfa) + ((y - ((Sqrt(2) * a) - a)) - y) * cos(alfa));
	innerFigure[2] = Point(x, y);

	innerFigure[3] = Point(x + cos(alfa) - ((y - (a / 2)) - y) * sin(alfa),
						   y + sin(alfa) + ((y - (a / 2)) - y) * cos(alfa));
	innerFigure[4] = Point(x + ((x + ((Sqrt(2) * a) - a)) - x) * cos(alfa) - ((y - ((Sqrt(2) * a) - a)) - y) * sin(alfa),
						   y + ((x + ((Sqrt(2) * a) - a)) - x) * sin(alfa) + ((y - ((Sqrt(2) * a) - a)) - y) * cos(alfa));
	innerFigure[5] = Point(x, y);

	innerFigure[6] = Point(x + ((x + (a / 2)) - x) * cos(alfa) - sin(alfa),
						   y + ((x + (a / 2)) - x) * sin(alfa) + cos(alfa));
	innerFigure[7] = Point(x + ((x + ((Sqrt(2) * a) - a)) - x) * cos(alfa) - ((y + ((Sqrt(2) * a) - a)) - y) * sin(alfa),
						   y + ((x + ((Sqrt(2) * a) - a)) - x) * sin(alfa) + ((y + ((Sqrt(2) * a) - a)) - y) * cos(alfa));
	innerFigure[8] = Point(x, y);

	innerFigure[9] = Point(x + cos(alfa) - ((y + (a / 2)) - y) * sin(alfa),
						   y + sin(alfa) + ((y + (a / 2)) - y) * cos(alfa));
	innerFigure[10] = Point(x + ((x - ((Sqrt(2) * a) - a)) - x) * cos(alfa) - ((y + ((Sqrt(2) * a) - a)) - y) * sin(alfa),
							y + ((x - ((Sqrt(2) * a) - a)) - x) * sin(alfa) + ((y + ((Sqrt(2) * a) - a)) - y) * cos(alfa));
	innerFigure[11] = Point(x, y);
	Image1->Canvas->Polygon(innerFigure, 11);

	alfa += alfaSpeed;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    alfaSpeed = StrToFloat(Edit3->Text);
}
//---------------------------------------------------------------------------

