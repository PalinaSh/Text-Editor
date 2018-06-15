//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <ExtActns.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <OleCtnrs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *RichEdit1;
	TActionList *ActionList1;
	TImageList *ImageList1;
	TEditCut *EditCut1;
	TEditCopy *EditCopy1;
	TEditPaste *EditPaste1;
	TEditSelectAll *EditSelectAll1;
	TEditUndo *EditUndo1;
	TRichEditBold *RichEditBold1;
	TRichEditItalic *RichEditItalic1;
	TRichEditUnderline *RichEditUnderline1;
	TRichEditStrikeOut *RichEditStrikeOut1;
	TRichEditBullets *RichEditBullets1;
	TRichEditAlignLeft *RichEditAlignLeft1;
	TRichEditAlignRight *RichEditAlignRight1;
	TRichEditAlignCenter *RichEditAlignCenter1;
	TFileExit *FileExit1;
	TFileOpen *FileOpen1;
	TFileSaveAs *FileSaveAs1;
	TSearchFind *SearchFind1;
	TSearchReplace *SearchReplace1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N29;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TToolButton *ToolButton15;
	TToolButton *ToolButton16;
	TToolButton *ToolButton17;
	TToolButton *ToolButton18;
	TToolButton *ToolButton19;
	TSearchFindNext *SearchFindNext1;
	TSearchFindFirst *SearchFindFirst1;
	TOpenPicture *OpenPicture1;
	TSavePicture *SavePicture1;
	TStatusBar *StatusBar1;
	TEditDelete *EditDelete1;
	TToolButton *ToolButton20;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TPopupMenu *PopupMenu1;
	TFontDialog *FontDialog1;
	TMenuItem *N25;
	TColorDialog *ColorDialog1;
	TMenuItem *N26;
	TMenuItem *N27;
	TMenuItem *N28;
	TMenuItem *N30;
	TMenuItem *N31;
	TMenuItem *N32;
	TMenuItem *N33;
	TToolButton *ToolButton5;
	TToolButton *ToolButton21;
	TToolButton *ToolButton22;
	TToolButton *ToolButton23;
	TToolButton *ToolButton24;
	TToolButton *ToolButton25;
	TMenuItem *N5;
	TMenuItem *N14;
	TMemo *Memo1;
	TFindDialog *FindDialog1;
	TButton *Button1;
	TToolButton *ToolButton14;
	TMenuItem *N20;
	TMenuItem *N21;
	TMenuItem *N22;
	void __fastcall N3Click(TObject *Sender);
	void __fastcall ToolButton16Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall ToolButton17Click(TObject *Sender);
	void __fastcall FontDialog1Apply(TObject *Sender, HWND Wnd);
	void __fastcall N15Click(TObject *Sender);
	void __fastcall N29Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N26Click(TObject *Sender);
	void __fastcall N27Click(TObject *Sender);
	void __fastcall N25Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall N14Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall RichEdit1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall N22Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall N21Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
