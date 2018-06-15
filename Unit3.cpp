//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BitBtn1Click(TObject *Sender)
{
	if (Form1->SaveDialog1->Execute()){
		Form3->Close();
		Form1->RichEdit1->Lines->SaveToFile(Form1->SaveDialog1->FileName);
	}
	Form1->RichEdit1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BitBtn2Click(TObject *Sender)
{
	Form1->RichEdit1->Clear();
	Form3->Close();
}
//---------------------------------------------------------------------------
