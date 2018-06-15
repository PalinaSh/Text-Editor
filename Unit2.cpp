//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
	ComboBox1Click(Sender);
	Edit1Change(Sender);
	Edit2Change(Sender);
	Edit3Change(Sender);
	Form2->Close() ;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ComboBox1Click(TObject *Sender)
{
	if (ComboBox1->ItemIndex == 0)
		Form1->RichEdit1->Paragraph->Alignment = taLeftJustify;
	else if (ComboBox1->ItemIndex == 1)
		Form1->RichEdit1->Paragraph->Alignment = taCenter;
	else if (ComboBox1->ItemIndex == 2)
		Form1->RichEdit1->Paragraph->Alignment = taRightJustify;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1Change(TObject *Sender)
{
	if (StrToInt(Edit1->Text) != 0) {
		Form1->RichEdit1->Paragraph->FirstIndent = StrToInt(Edit1->Text);
		Form1->RichEdit1->Paragraph->LeftIndent = StrToInt(Edit2->Text) - StrToInt(Edit1->Text);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit2Change(TObject *Sender)
{
	Form1->RichEdit1->Paragraph->LeftIndent = StrToInt(Edit2->Text) - StrToInt(Edit1->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit3Change(TObject *Sender)
{
	Form1->RichEdit1->Paragraph->RightIndent = StrToInt(Edit3->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BitBtn2Click(TObject *Sender)
{
	Form1->RichEdit1->Undo();
	Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
	if (Form1->RichEdit1->Paragraph->Alignment == taLeftJustify)
		ComboBox1->ItemIndex = 0;
	else if (Form1->RichEdit1->Paragraph->Alignment == taCenter)
		ComboBox1->ItemIndex = 1;
	else if (Form1->RichEdit1->Paragraph->Alignment == taRightJustify)
		ComboBox1->ItemIndex = 2;
	Edit1->Text = Form1->RichEdit1->Paragraph->FirstIndent;
	Edit2->Text = Form1->RichEdit1->Paragraph->LeftIndent + Form1->RichEdit1->Paragraph->FirstIndent;
	Edit3->Text = Form1->RichEdit1->Paragraph->RightIndent;
}
//---------------------------------------------------------------------------
