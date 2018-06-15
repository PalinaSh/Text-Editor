//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TFileStream *file;
AnsiString filename;
Dictionary dict;
int words[30];
int i = 0;
bool separator = true;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
	if (OpenDialog1->Execute()) {
		RichEdit1->Lines->LoadFromFile(OpenDialog1->FileName);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ToolButton16Click(TObject *Sender)
{
	OpenDialog1->Filter = "Текстовый файл|*.txt;|RTF-документ|*.rtf;";
	N3Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
	if (SaveDialog1->Execute()){
		RichEdit1->Lines->SaveToFile(SaveDialog1->FileName);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ToolButton17Click(TObject *Sender)
{
	SaveDialog1->Filter = "Текстовый файл|*.txt;|RTF-документ|*.rtf;";
	N4Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FontDialog1Apply(TObject *Sender, HWND Wnd)
{
	RichEdit1->SelAttributes->Assign(FontDialog1->Font);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N15Click(TObject *Sender)
{
	if (FontDialog1->Execute()) {
		RichEdit1->SelAttributes->Assign(FontDialog1->Font);
	}
	else return;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N29Click(TObject *Sender)
{
	if (ColorDialog1->Execute()) {
		RichEdit1->Color = ColorDialog1->Color;
	}
	else return;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	//dict.CreateDict("Dictionary.txt", Memo1);
	dict.CreateDict("result.txt", Memo1);
	RichEdit1->PopupMenu = PopupMenu1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N26Click(TObject *Sender)
{
	N15Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N27Click(TObject *Sender)
{
	N29Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N25Click(TObject *Sender)
{
	Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
	Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
	Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N14Click(TObject *Sender)
{
	RichEdit1->SelStart = 0;
	int len = RichEdit1->Text.Length();
	RichEdit1->SelLength = len;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
	Application->Title = "Справка";
	ShowMessage("Программа предназначена для работы с текстом.\n\nВерсия программы: 1.0\nРазработчик: Шимановская П.Н.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RichEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
	if ((int)Key == 8) {
		if (i > 0)
			i--;
	}
	else if ((Key == ' ' || Key == ',' || Key == '.' || Key == ';' || Key == '?' || Key == '!'
			   || Key == '\r' || Key == ')' || Key == '(' || Key == '"') && separator) {
		AnsiString Word = "";
		bool b = true;
		if (i > 0) {
			for (int j = 0; j < i; j++) {
				if (words[j] >= 1072 && words[j] <= 1103)
					Word = Word + (char)(words[j] - 1104);
				else if (words[j] == 1105)
					Word = Word + char(words[j] - 1177);
				else
					b = false;
			}
		}
		if (b)
			dict.FindWord(Word, RichEdit1);
		i = 0;
		separator = false;
	}
	else {
		if (Key != ' ' && Key != ',' && Key != '.' && Key != ';' && Key != '?' &&
		Key != '!' && Key != '\r' && Key != ')' && Key != '(' && Key != '"') {
			words[i] = (int)Key;
			i++;
			separator = true;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N22Click(TObject *Sender)
{
	dict.CheckAllText(RichEdit1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	AnsiString Word = RichEdit1->SelText;
	dict.AddNewWordInDictionary(Word);
	N22Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N21Click(TObject *Sender)
{
	N22Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	dict.CloseDict(Memo1, "result.txt");
}
//---------------------------------------------------------------------------

