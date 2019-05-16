#ifndef PARTICULARS_H
#define PARTICULARS_H

//Headers(Particulars)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>


class Particulars: public wxDialog
{
	public:

		Particulars(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Particulars();

		//Declarations(Particulars)
		wxButton* OKButton;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		wxStaticText* StaticText10;
		wxStaticText* StaticText11;
		wxStaticText* StaticText12;
		wxStaticText* StaticText13;
		wxTextCtrl* BText;
		wxTextCtrl* DeckStrText;
		wxTextCtrl* HText;
		wxTextCtrl* LCGText;
		wxTextCtrl* LOAText;
		wxTextCtrl* LightShipText;
		wxTextCtrl* MaxDWTText;
		wxTextCtrl* MaxDrText;
		wxTextCtrl* MinDrText;
		wxTextCtrl* ShipNameText;
		wxTextCtrl* TCGText;
		wxTextCtrl* TankStrText;
		wxTextCtrl* VCGText;




		//Identifiers(Particulars)
		static const long ID_NAMELABEL;
		static const long ID_NAME;
		static const long ID_LSHIPLABEL;
		static const long ID_LIGHTSHIP;
		static const long ID_LOALABEL;
		static const long ID_LOA;
		static const long ID_BEAMLABEL;
		static const long ID_BEAM;
		static const long ID_HEIGHTLABEL;
		static const long ID_HEIGHT;
		static const long ID_LCGLABEL;
		static const long ID_LCG;
		static const long ID_TCGLABEL;
		static const long ID_TCG;
		static const long ID_VCGLABEL;
		static const long ID_VCG;
		static const long ID_COVERSTRENGTHLABEL;
		static const long ID_COVERSTRENGTH;
		static const long ID_TANKSTRENGTHLABEL;
		static const long ID_TANKSTRENGTH;
		static const long ID_MINDRAFTLABEL;
		static const long ID_MINDRAFT;
		static const long ID_MAXDEADWEIGHTLABEL;
		static const long ID_MAXDEADWEIGHT;
		static const long ID_MAXDRAFTLABEL;
		static const long ID_MAXDRAFT;
		static const long ID_OK;


	private:

		//Handlers(Particulars)
		void OnOKButtonClick(wxCommandEvent& event);


		DECLARE_EVENT_TABLE()
};
#endif
