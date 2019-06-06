#include "Particulars.h"

//(*InternalHeaders(Particulars)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Particulars)
const long Particulars::ID_STATICTEXT1 = wxNewId();
const long Particulars::ID_TEXTCTRL3 = wxNewId();
const long Particulars::ID_STATICTEXT2 = wxNewId();
const long Particulars::ID_TEXTCTRL2 = wxNewId();
const long Particulars::ID_STATICTEXT3 = wxNewId();
const long Particulars::ID_TEXTCTRL4 = wxNewId();
const long Particulars::ID_STATICTEXT4 = wxNewId();
const long Particulars::ID_TEXTCTRL1 = wxNewId();
const long Particulars::ID_STATICTEXT5 = wxNewId();
const long Particulars::ID_TEXTCTRL5 = wxNewId();
const long Particulars::ID_STATICTEXT6 = wxNewId();
const long Particulars::ID_TEXTCTRL6 = wxNewId();
const long Particulars::ID_STATICTEXT7 = wxNewId();
const long Particulars::ID_TEXTCTRL7 = wxNewId();
const long Particulars::ID_STATICTEXT8 = wxNewId();
const long Particulars::ID_TEXTCTRL8 = wxNewId();
const long Particulars::ID_STATICTEXT9 = wxNewId();
const long Particulars::ID_TEXTCTRL9 = wxNewId();
const long Particulars::ID_STATICTEXT10 = wxNewId();
const long Particulars::ID_TEXTCTRL10 = wxNewId();
const long Particulars::ID_STATICTEXT11 = wxNewId();
const long Particulars::ID_TEXTCTRL11 = wxNewId();
const long Particulars::ID_STATICTEXT12 = wxNewId();
const long Particulars::ID_TEXTCTRL12 = wxNewId();
const long Particulars::ID_STATICTEXT13 = wxNewId();
const long Particulars::ID_STATICTEXT14 = wxNewId();
const long Particulars::ID_OK = wxNewId();
//*)

BEGIN_EVENT_TABLE(Particulars,wxDialog)
	//(*EventTable(Particulars)
	//*)
END_EVENT_TABLE()

Particulars::Particulars(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Particulars)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Particulars"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(10, 4, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Ship Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	ShipNameText = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer1->Add(ShipNameText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Light Ship, t"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LightShipText = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer1->Add(LightShipText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("LOA, m"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LOAText = new wxTextCtrl(this, ID_TEXTCTRL4, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer1->Add(LOAText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Beam, m"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BText = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(BText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Height, m"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	HText = new wxTextCtrl(this, ID_TEXTCTRL5, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	FlexGridSizer1->Add(HText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("LCG, m"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LCGText = new wxTextCtrl(this, ID_TEXTCTRL6, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	FlexGridSizer1->Add(LCGText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("VCG, m"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	VCGText = new wxTextCtrl(this, ID_TEXTCTRL7, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	FlexGridSizer1->Add(VCGText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("TCG, m"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer1->Add(StaticText8, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	TCGText = new wxTextCtrl(this, ID_TEXTCTRL8, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	FlexGridSizer1->Add(TCGText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Hatch Cover Strength t/m2"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer1->Add(StaticText9, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	DeckStrText = new wxTextCtrl(this, ID_TEXTCTRL9, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	FlexGridSizer1->Add(DeckStrText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Tank Survace Strength, t/m2"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer1->Add(StaticText10, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	TankStrText = new wxTextCtrl(this, ID_TEXTCTRL10, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	FlexGridSizer1->Add(TankStrText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Minimal Draft, m"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	FlexGridSizer1->Add(StaticText11, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	MinDrText = new wxTextCtrl(this, ID_TEXTCTRL11, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
	FlexGridSizer1->Add(MinDrText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Maximal Draft, m"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	FlexGridSizer1->Add(StaticText12, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	MaxDrText = new wxTextCtrl(this, ID_TEXTCTRL12, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
	FlexGridSizer1->Add(MaxDrText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Maximal Displacement, t"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	FlexGridSizer1->Add(StaticText13, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	MaxDWTText = new wxStaticText(this, ID_STATICTEXT14, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	FlexGridSizer1->Add(MaxDWTText, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	OK = new wxButton(this, ID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_OK"));
	FlexGridSizer1->Add(OK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Particulars::Change);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Particulars::Change);
	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Particulars::Change);
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Particulars::Change);
	Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Particulars::Change);
	Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Particulars::Change);
	Connect(ID_TEXTCTRL7,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Particulars::Change);
	Connect(ID_TEXTCTRL8,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Particulars::Change);
	Connect(ID_TEXTCTRL9,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Particulars::Change);
	Connect(ID_TEXTCTRL10,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Particulars::Change);
	Connect(ID_TEXTCTRL11,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Particulars::Change);
	Connect(ID_TEXTCTRL12,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Particulars::Change);
	Connect(ID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Particulars::OnOKClick);
	//*)
}

Particulars::~Particulars()
{
	//(*Destroy(Particulars)
	//*)
}

void Particulars::go(Ship& ptr)
{
    ShipBody = &ptr;
    load();
    ShowModal();
}

void Particulars::load()
{

    ShipNameText->SetValue(wxString::Format(wxT("%s"),ShipBody->read_s_name()));
    LOAText->SetValue(wxString::Format(wxT("%.2f"),ShipBody->read_s_LOA()));
    HText->SetValue(wxString::Format(wxT("%.2f"),ShipBody->read_s_height()));
    BText->SetValue(wxString::Format(wxT("%.2f"),ShipBody->read_s_beam()));
    LCGText->SetValue(wxString::Format(wxT("%.2f"),ShipBody->read_s_LCGLight()));
    VCGText->SetValue(wxString::Format(wxT("%.2f"),ShipBody->read_s_VCGLight()));
    TCGText->SetValue(wxString::Format(wxT("%.2f"),ShipBody->read_s_TCGLight()));
    LightShipText->SetValue(wxString::Format(wxT("%i"),ShipBody->read_s_lightShip()));
    MaxDrText->SetValue(wxString::Format(wxT("%.2f"),ShipBody->read_s_maxDraft()));
    MinDrText->SetValue(wxString::Format(wxT("%.2f"),ShipBody->read_s_minDraft()));
    MaxDWTText->SetLabel(wxString::Format(wxT("%.0f"),ShipBody->read_s_maxDWT()));
    DeckStrText->SetValue(wxString::Format(wxT("%.2f"),ShipBody->read_s_strengthCover()));
    TankStrText->SetValue(wxString::Format(wxT("%.2f"),ShipBody->read_s_strengthTank()));
}

void Particulars::OnOKClick(wxCommandEvent& event)
{
    Close();
}

void Particulars::Change(wxCommandEvent& event)
{
     ShipBody->set_s_name(ShipNameText->GetValue().ToStdString());
    ShipBody->set_s_LOA(LOAText->GetValue().ToStdString());
    ShipBody->set_s_beam(BText->GetValue().ToStdString());
    ShipBody->set_s_height(HText->GetValue().ToStdString());
    ShipBody->set_s_LCGLight(LCGText->GetValue().ToStdString());
    ShipBody->set_s_VCGLight(VCGText->GetValue().ToStdString());
    ShipBody->set_s_TCGLight(TCGText->GetValue().ToStdString());
    ShipBody->set_s_lightShip(LightShipText->GetValue().ToStdString());
    ShipBody->set_s_maxDraft(MaxDrText->GetValue().ToStdString());
    ShipBody->set_s_minDraft(MinDrText->GetValue().ToStdString());
    ShipBody->set_s_strengthCover(DeckStrText->GetValue().ToStdString());
    ShipBody->set_s_strengthTank(TankStrText->GetValue().ToStdString());
    ShipBody->calculate();
    ShipBody->set_s_maxDWT();
    MaxDWTText->SetLabel(wxString::Format(wxT("%.0f"), ShipBody->read_s_maxDWT()));
}
