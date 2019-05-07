/***************************************************************
 * Name:      BodyMasterMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Vilis Erglis (vilis@erglis.org)
 * Created:   2019-05-07
 * Copyright: Vilis Erglis ()
 * License:
 **************************************************************/

#include "BodyMasterMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(BodyMasterFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
Ship ShipBody;

//(*IdInit(BodyMasterFrame)
const long BodyMasterFrame::ID_GRID1 = wxNewId();
const long BodyMasterFrame::ID_BUTTON4 = wxNewId();
const long BodyMasterFrame::ID_BUTTON3 = wxNewId();
const long BodyMasterFrame::ID_BUTTON2 = wxNewId();
const long BodyMasterFrame::ID_BUTTON1 = wxNewId();
const long BodyMasterFrame::idMenuQuit = wxNewId();
const long BodyMasterFrame::idMenuAbout = wxNewId();
const long BodyMasterFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(BodyMasterFrame,wxFrame)
    //(*EventTable(BodyMasterFrame)
    //*)
END_EVENT_TABLE()

BodyMasterFrame::BodyMasterFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(BodyMasterFrame)
    wxBoxSizer* BoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
    Grid = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
    Grid->CreateGrid(0,8);
    Grid->SetMinSize(wxSize(1200,500));
    Grid->EnableEditing(true);
    Grid->EnableGridLines(true);
    Grid->SetDefaultColSize(150, true);
    Grid->SetDefaultCellFont( Grid->GetFont() );
    Grid->SetDefaultCellTextColour( Grid->GetForegroundColour() );
    FlexGridSizer1->Add(Grid, 1, wxALL|wxEXPAND, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    AddButton = new wxButton(this, ID_BUTTON4, _("Add Unit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer1->Add(AddButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DeleteButton = new wxButton(this, ID_BUTTON3, _("Delete Unit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer1->Add(DeleteButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ParticularsButton = new wxButton(this, ID_BUTTON2, _("Particulars"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer1->Add(ParticularsButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CalculateButton = new wxButton(this, ID_BUTTON1, _("Calculate"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(CalculateButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BodyMasterFrame::OnAddButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BodyMasterFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BodyMasterFrame::OnAbout);
    //*)
}

BodyMasterFrame::~BodyMasterFrame()
{
    //(*Destroy(BodyMasterFrame)
    //*)
}

void BodyMasterFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void BodyMasterFrame::OnAbout(wxCommandEvent& event)
{
}

void BodyMasterFrame::OnAddButtonClick(wxCommandEvent& event)
{
    wxArrayString choices;
    for (unsigned int i=0; i<sizeof(ShipBody.u_type_strings)/sizeof(ShipBody.u_type_strings[0]); i++)
    {
        choices.Add(ShipBody.u_type_strings[i]);
    }
    Grid->InsertRows();
    Grid->SetCellEditor(0,1, new wxGridCellChoiceEditor(choices, false));
    Grid->SetCellValue(0,1, choices[0]);
    ShipBody.new_unit(ShipBody.u_types::Ballast);
}
