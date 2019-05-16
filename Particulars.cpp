#include "Particulars.h"
#include <iostream>

//InternalHeaders(Particulars)
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/validate.h>


//IdInit(Particulars)
const long Particulars::ID_NAMELABEL = wxNewId();
const long Particulars::ID_NAME = wxNewId();
const long Particulars::ID_LSHIPLABEL = wxNewId();
const long Particulars::ID_LIGHTSHIP = wxNewId();
const long Particulars::ID_LOALABEL = wxNewId();
const long Particulars::ID_LOA = wxNewId();
const long Particulars::ID_BEAMLABEL = wxNewId();
const long Particulars::ID_BEAM = wxNewId();
const long Particulars::ID_HEIGHTLABEL = wxNewId();
const long Particulars::ID_HEIGHT = wxNewId();
const long Particulars::ID_LCGLABEL = wxNewId();
const long Particulars::ID_LCG = wxNewId();
const long Particulars::ID_TCGLABEL = wxNewId();
const long Particulars::ID_TCG = wxNewId();
const long Particulars::ID_VCGLABEL = wxNewId();
const long Particulars::ID_VCG = wxNewId();
const long Particulars::ID_COVERSTRENGTHLABEL = wxNewId();
const long Particulars::ID_COVERSTRENGTH = wxNewId();
const long Particulars::ID_TANKSTRENGTHLABEL = wxNewId();
const long Particulars::ID_TANKSTRENGTH = wxNewId();
const long Particulars::ID_MINDRAFTLABEL = wxNewId();
const long Particulars::ID_MINDRAFT = wxNewId();
const long Particulars::ID_MAXDEADWEIGHTLABEL = wxNewId();
const long Particulars::ID_MAXDEADWEIGHT = wxNewId();
const long Particulars::ID_MAXDRAFTLABEL = wxNewId();
const long Particulars::ID_MAXDRAFT = wxNewId();
const long Particulars::ID_OK = wxNewId();

BEGIN_EVENT_TABLE(Particulars,wxDialog)
	//EventTable(Particulars)

END_EVENT_TABLE()

Particulars::Particulars(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//Initialize(Particulars)
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	FlexGridSizer1 = new wxFlexGridSizer(10, 4, 0, 0);
	StaticText1 = new wxStaticText(this, ID_NAMELABEL, _("Ships Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_NAMELABEL"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ShipNameText = new wxTextCtrl(this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	FlexGridSizer1->Add(ShipNameText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(this, ID_LSHIPLABEL, _("Light Ship"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LSHIPLABEL"));
	FlexGridSizer1->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LightShipText = new wxTextCtrl(this, ID_LIGHTSHIP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_LIGHTSHIP"));
	FlexGridSizer1->Add(LightShipText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_LOALABEL, _("LOA"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LOALABEL"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LOAText = new wxTextCtrl(this, ID_LOA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_LOA"));
	FlexGridSizer1->Add(LOAText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_BEAMLABEL, _("Beam"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_BEAMLABEL"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BText = new wxTextCtrl(this, ID_BEAM, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BEAM"));
	FlexGridSizer1->Add(BText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_HEIGHTLABEL, _("Height"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_HEIGHTLABEL"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	HText = new wxTextCtrl(this, ID_HEIGHT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_HEIGHT"));
	FlexGridSizer1->Add(HText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(this, ID_LCGLABEL, _("Ships LCG"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LCGLABEL"));
	FlexGridSizer1->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LCGText = new wxTextCtrl(this, ID_LCG, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_LCG"));
	FlexGridSizer1->Add(LCGText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_TCGLABEL, _("Ships TCG"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_TCGLABEL"));
	FlexGridSizer1->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TCGText = new wxTextCtrl(this, ID_TCG, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TCG"));
	FlexGridSizer1->Add(TCGText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_VCGLABEL, _("Ships VCG"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_VCGLABEL"));
	FlexGridSizer1->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VCGText = new wxTextCtrl(this, ID_VCG, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_VCG"));
	FlexGridSizer1->Add(VCGText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_COVERSTRENGTHLABEL, _("Hatch Cover Strength"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_COVERSTRENGTHLABEL"));
	FlexGridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DeckStrText = new wxTextCtrl(this, ID_COVERSTRENGTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COVERSTRENGTH"));
	FlexGridSizer1->Add(DeckStrText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText13 = new wxStaticText(this, ID_TANKSTRENGTHLABEL, _("Tank Surface Strength"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_TANKSTRENGTHLABEL"));
	FlexGridSizer1->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TankStrText = new wxTextCtrl(this, ID_TANKSTRENGTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TANKSTRENGTH"));
	FlexGridSizer1->Add(TankStrText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_MINDRAFTLABEL, _("Min Draft"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_MINDRAFTLABEL"));
	FlexGridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	MinDrText = new wxTextCtrl(this, ID_MINDRAFT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_MINDRAFT"));
	FlexGridSizer1->Add(MinDrText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(this, ID_MAXDEADWEIGHTLABEL, _("Max Dead weight"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_MAXDEADWEIGHTLABEL"));
	FlexGridSizer1->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	MaxDWTText = new wxTextCtrl(this, ID_MAXDEADWEIGHT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_MAXDEADWEIGHT"));
	FlexGridSizer1->Add(MaxDWTText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_MAXDRAFTLABEL, _("Max Draft"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_MAXDRAFTLABEL"));
	FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	MaxDrText = new wxTextCtrl(this, ID_MAXDRAFT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_MAXDRAFT"));
	FlexGridSizer1->Add(MaxDrText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	OKButton = new wxButton(this, ID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_OK"));
	FlexGridSizer1->Add(OKButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Particulars::OnOKButtonClick);
}

Particulars::~Particulars()
{
	//Destroy(Particulars)
}
void Particulars::OnOKButtonClick(wxCommandEvent& event)
{
    Close();
}
