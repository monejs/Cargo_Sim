#ifndef PARTICULARS_H
#define PARTICULARS_H

//(*Headers(Particulars)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class Particulars: public wxDialog
{
	public:

		Particulars(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~Particulars();

		//(*Declarations(Particulars)
		wxStaticLine* StaticLine1;
		wxStaticText* LCGText;
		wxStaticText* LOAText;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		wxStaticText* TCGText;
		wxStaticText* VCGText;
		wxStaticText* beamText;
		wxStaticText* heightText;
		wxStaticText* lightShipText;
		wxStaticText* nameText;
		//*)

	protected:

		//(*Identifiers(Particulars)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT11;
		static const long ID_STATICTEXT10;
		static const long ID_STATICTEXT13;
		static const long ID_STATICTEXT12;
		static const long ID_STATICTEXT14;
		static const long ID_STATICTEXT15;
		static const long ID_STATICTEXT16;
		static const long ID_STATICTEXT17;
		//*)

	private:

		//(*Handlers(Particulars)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
