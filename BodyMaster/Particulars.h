#ifndef PARTICULARS_H
#define PARTICULARS_H
#include "../Ship.h"


//(*Headers(Particulars)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Particulars: public wxDialog
{
	public:
        void load();
        void go(Ship&);
		Particulars(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Particulars();

		//(*Declarations(Particulars)
		wxButton* OK;
		wxStaticText* MaxDWTText;
		wxStaticText* StaticText10;
		wxStaticText* StaticText11;
		wxStaticText* StaticText12;
		wxStaticText* StaticText13;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		wxTextCtrl* BText;
		wxTextCtrl* DeckStrText;
		wxTextCtrl* HText;
		wxTextCtrl* LCGText;
		wxTextCtrl* LOAText;
		wxTextCtrl* LightShipText;
		wxTextCtrl* MaxDrText;
		wxTextCtrl* MinDrText;
		wxTextCtrl* ShipNameText;
		wxTextCtrl* TCGText;
		wxTextCtrl* TankStrText;
		wxTextCtrl* VCGText;
		//*)

	protected:

		//(*Identifiers(Particulars)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL6;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL7;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL8;
		static const long ID_STATICTEXT9;
		static const long ID_TEXTCTRL9;
		static const long ID_STATICTEXT10;
		static const long ID_TEXTCTRL10;
		static const long ID_STATICTEXT11;
		static const long ID_TEXTCTRL11;
		static const long ID_STATICTEXT12;
		static const long ID_TEXTCTRL12;
		static const long ID_STATICTEXT13;
		static const long ID_STATICTEXT14;
		static const long ID_OK;
		//*)

	private:
        Ship* ShipBody;
		//(*Handlers(Particulars)
		void OnOKClick(wxCommandEvent& event);
		void Change(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
