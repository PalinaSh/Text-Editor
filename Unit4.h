//---------------------------------------------------------------------------
//создание словаря на основе хэш-таблицы
//хэш-таблица на основе массива стеков
#ifndef Unit4H
#define Unit4H
#include <vcl.h>

struct element
{
	AnsiString word;
	element *next;
};

class Dictionary
{
protected:
	element *Head[30];
public:
	Dictionary();
	~Dictionary(){};
	void CloseDict(TMemo *Memo, AnsiString filename);
	void Dictionary :: PrintDict(TMemo *Memo);
	void AddWord(char Key, AnsiString Word);
	void CreateDict(AnsiString filename, TMemo *Memo);
	void FindWord(AnsiString Word, TRichEdit *RichEdit);
	void PrintHash(TMemo *Memo);
	void AddNewWordInDictionary(AnsiString Word);
	void CheckAllText(TRichEdit *RE);
};
//---------------------------------------------------------------------------
#endif
