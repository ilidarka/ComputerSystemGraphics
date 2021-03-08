//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TButton *Button1;
	TEdit *Edit1;
	TTimer *Timer1;
	TLabel *Label2;
	TEdit *Edit2;
	TButton *Button2;
	TLabel *Label3;
	TEdit *Edit3;
	TButton *Button3;
	TPaintBox *PaintBox1;
	TPanel *Panel2;
	TButton *Button4;
	TButton *Button5;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall PaintBox1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);


private:	// User declarations
	void setStandartColor();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
