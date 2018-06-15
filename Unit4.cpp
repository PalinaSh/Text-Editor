//---------------------------------------------------------------------------
//создание словаря на основе хэш-таблицы
//хэш-таблица на основе массива стеков

#pragma hdrstop

#include "Unit4.h"
#include <vcl.h>
//#include <math.h>

Dictionary :: Dictionary()
{
	for (int i = 0; i < 30; i++) {
		Head[i] = NULL;
	}
}

void Dictionary :: PrintDict(TMemo *Memo)
{
	Memo->Clear();
	for (int hash = 0; hash < 30; hash++) {
		if (Head[hash]) {
			element *temp = Head[hash];
			while (temp){
				Memo->Lines->Add(temp->word);
				temp = temp->next;
			}
		}
	}
}

void Dictionary :: CloseDict(TMemo *Memo, AnsiString filename)
{
	PrintDict(Memo);
	if(FileExists(filename))
		DeleteFile(filename);
	TFileStream *Stream = new TFileStream (filename, fmCreate);
	delete Stream;
	Memo->Lines->SaveToFile(filename);
	for (int hash = 0; hash < 30; hash++) {
		while (Head[hash]){
		element *temp = Head[hash];
		Head[hash] = Head[hash]->next;
		delete temp;
		}
	}
}

int WhichHash(char Key)
{
	int hash;
	if ((int)Key == -72)
		hash = 6;
	else if ((int)Key < -26)
		hash = (int)Key + 32;
	else if ((int)Key >= -3)
		hash = (int)Key + 30;
	else
		hash = (int)Key + 33;
	return hash;
}

void Dictionary :: AddWord(char Key, AnsiString Word)
{
	int hash = WhichHash(Key);

	element *temp = new element;
	temp->next = Head[hash];
	temp->word = Word;
	Head[hash] = temp;

}

void Dictionary :: CreateDict(AnsiString filename, TMemo *Memo)
{
	Memo->Lines->Clear();
	Memo->Lines->LoadFromFile(filename);
	for (int i = 0; i < Memo->Lines->Count; i++) {
		AnsiString Word = Memo->Lines->Strings[i];
		char Key = Word.c_str()[0];
		AddWord(Key, Word);
	}
}

void Dictionary :: FindWord(AnsiString Word, TRichEdit *RichEdit)
{
	char Key = Word.c_str()[0];
	int hash = WhichHash(Key);
	int x, y;
	if (Head[hash]) {
		element *item = Head[hash];
		while (item){
			if (item->word == Word) {
                if (RichEdit->SelStart - Word.Length()) {
					x = RichEdit->SelStart - Word.Length() - 1;
				}
				else
					x = RichEdit->SelStart - Word.Length();
				y = RichEdit->SelStart;
				RichEdit->SelStart = x;
				RichEdit->SelLength = Word.Length() + 1;
				RichEdit->SelAttributes->Color = clBlack;  //атрибуты верного текста
				RichEdit->SelStart = y;
				return;
			}
			else
				item = item->next;
		}
	}
	if (RichEdit->SelStart - Word.Length()) {
		x = RichEdit->SelStart - Word.Length() - 1;
	}
	else
		x = RichEdit->SelStart - Word.Length();
	y = RichEdit->SelStart;
	RichEdit->SelStart = x;
	RichEdit->SelLength = Word.Length() + 1;
	RichEdit->SelAttributes->Color = clRed;  //атрибуты неверного текста
	RichEdit->SelStart = y;
	RichEdit->SelAttributes->Color = clBlack;
	/*int x = RichEdit->SelStart - Word.Length(); //начало поиска
	int y = RichEdit->Text.Length() - x; // длина текста, от начала поиска
	TSearchTypes Option;
	Option << stWholeWord; // слово целиком
	Option >> stMatchCase; // без учёта регистра
	FD->FindTextW = Word;
	FD->Execute();

	int FoundAt = RichEdit->FindText(FD->FindText, x, y, Option);
	FD->CloseDialog();
	if (FoundAt != -1) {   // если найдено
		RichEdit->SelStart = FoundAt;
		RichEdit->SelLength = Word.Length();
		RichEdit->SelAttributes->Color = clRed;  //атрибуты неверного текста
		RichEdit->SelStart = RichEdit->Text.Length();
		RichEdit->SelAttributes->Color = clBlack;
	}                   */
}

void Dictionary :: AddNewWordInDictionary(AnsiString Word)
{
	if (Word != "") {
		char Key = Word.c_str()[0];
		AddWord(Key, Word);
	}
}

void Dictionary :: CheckAllText(TRichEdit *RE)
{
	RE->SelStart = 0;
	bool separator = true;
	int words[30];
	int k = 0;
	AnsiString Text = RE->Text;
	for (int i = 0; i < RE->Text.Length(); i++) {
		RE->SelStart = i;
		char Key = Text.c_str()[i];
		if ((Key == ' ' || Key == ',' || Key == '.' || Key == ';' || Key == '?'
		|| Key == '!' || Key == '\r' || Key == ')' || Key == '(' || Key == '"') && separator) {
			AnsiString Word = "";
			bool b = true;
			for (int j = 0; j < k; j++) {
				if (words[j] >= -72 && words[j] <= 0)
					Word = Word + (char)words[j];
				else
					b = false;
			}
			if (b)
				FindWord(Word, RE);
			k = 0;
			separator = false;
		}
		else {
			if (Key != ' ' && Key != ',' && Key != '.' && Key != ';' && Key != '?'
			&& Key != '!' && Key != '\r' && Key != ')' && Key != '(' && Key != '"') {
				words[k] = (int)Key;
				k++;
				separator = true;
			}
		}
	}
}



//---------------------------------------------------------------------------

#pragma package(smart_init)
