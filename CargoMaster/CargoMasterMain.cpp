/***************************************************************
 * Name:      CargoMasterMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Vilis Erglis (vilis@erglis.org)
 * Created:   2019-05-07
 * Copyright: Vilis Erglis ()
 * License:   GNU General Public License v3.0
 **************************************************************/

#include "CargoMasterMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(CargoMasterFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
Ship ShipBody;  //Defining the class Ship with its all attributes

//Automatically generated code

//(*IdInit(CargoMasterFrame)
const long CargoMasterFrame::ID_GRID1 = wxNewId();
const long CargoMasterFrame::ID_PANEL1 = wxNewId();
const long CargoMasterFrame::ID_GRID2 = wxNewId();
const long CargoMasterFrame::ID_PANEL2 = wxNewId();
const long CargoMasterFrame::ID_GRID4 = wxNewId();
const long CargoMasterFrame::ID_PANEL8 = wxNewId();
const long CargoMasterFrame::ID_GRID3 = wxNewId();
const long CargoMasterFrame::ID_PANEL3 = wxNewId();
const long CargoMasterFrame::ID_GRID5 = wxNewId();
const long CargoMasterFrame::ID_PANEL4 = wxNewId();
const long CargoMasterFrame::ID_PANEL5 = wxNewId();
const long CargoMasterFrame::ID_PANEL6 = wxNewId();
const long CargoMasterFrame::ID_GRID6 = wxNewId();
const long CargoMasterFrame::ID_PANEL7 = wxNewId();
const long CargoMasterFrame::ID_NOTEBOOK1 = wxNewId();
const long CargoMasterFrame::ID_MENUITEM1 = wxNewId();
const long CargoMasterFrame::idMenuQuit = wxNewId();
const long CargoMasterFrame::idMenuAbout = wxNewId();
const long CargoMasterFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CargoMasterFrame,wxFrame)
    //(*EventTable(CargoMasterFrame)
    //*)
END_EVENT_TABLE()

CargoMasterFrame::CargoMasterFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(CargoMasterFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(920,713));
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxPoint(152,176), wxSize(1088,728), 0, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Grid1 = new wxGrid(Panel1, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
    Grid1->CreateGrid(8,5);
    Grid1->EnableEditing(true);
    Grid1->EnableGridLines(true);
    Grid1->SetRowLabelSize(200);
    Grid1->SetDefaultColSize(150, true);
    Grid1->SetColLabelValue(0, _("Weight, t"));
    Grid1->SetColLabelValue(1, _("LCG, m"));
    Grid1->SetColLabelValue(2, _("VCG, m"));
    Grid1->SetColLabelValue(3, _("TCG, m"));
    Grid1->SetColLabelValue(4, _("Fs, m*t"));
    Grid1->SetRowLabelValue(0, _("Constants"));
    Grid1->SetRowLabelValue(1, _("Tanks"));
    Grid1->SetRowLabelValue(2, _("Cargo Tanks"));
    Grid1->SetRowLabelValue(3, _("Deadweight"));
    Grid1->SetRowLabelValue(4, _("Dead Load"));
    Grid1->SetRowLabelValue(5, _("Light Ship"));
    Grid1->SetRowLabelValue(6, _("Displacement"));
    Grid1->SetRowLabelValue(7, _("Deadw. Reserve"));
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    BoxSizer1->Add(Grid1, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Grid2 = new wxGrid(Panel2, ID_GRID2, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID2"));
    Grid2->CreateGrid(50,5);
    Grid2->EnableEditing(true);
    Grid2->EnableGridLines(true);
    Grid2->SetDefaultColSize(150, true);
    Grid2->SetColLabelValue(0, _("Item"));
    Grid2->SetColLabelValue(1, _("Weight, t"));
    Grid2->SetColLabelValue(2, _("LCG, m"));
    Grid2->SetColLabelValue(3, _("VCG, m"));
    Grid2->SetColLabelValue(4, _("TCG, m"));
    Grid2->SetDefaultCellFont( Grid2->GetFont() );
    Grid2->SetDefaultCellTextColour( Grid2->GetForegroundColour() );
    BoxSizer2->Add(Grid2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel2);
    BoxSizer2->SetSizeHints(Panel2);
    Panel8 = new wxPanel(Notebook1, ID_PANEL8, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    Grid4 = new wxGrid(Panel8, ID_GRID4, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID4"));
    Grid4->CreateGrid(0,10);
    Grid4->EnableEditing(true);
    Grid4->EnableGridLines(true);
    Grid4->SetDefaultColSize(120, true);
    Grid4->SetColLabelValue(0, _("Name"));
    Grid4->SetColLabelValue(1, _("Weight, t"));
    Grid4->SetColLabelValue(2, _("LCG, m"));
    Grid4->SetColLabelValue(3, _("VCG, m"));
    Grid4->SetColLabelValue(4, _("TCG, m"));
    Grid4->SetColLabelValue(5, _("Fs, m*t"));
    Grid4->SetColLabelValue(6, _("Fs max"));
    Grid4->SetColLabelValue(7, _("Vol %"));
    Grid4->SetColLabelValue(8, _("Volume, m3"));
    Grid4->SetColLabelValue(9, _("Max Vol, m3"));
    Grid4->SetDefaultCellFont( Grid4->GetFont() );
    Grid4->SetDefaultCellTextColour( Grid4->GetForegroundColour() );
    BoxSizer4->Add(Grid4, 1, wxALL|wxEXPAND, 5);
    Panel8->SetSizer(BoxSizer4);
    BoxSizer4->Fit(Panel8);
    BoxSizer4->SetSizeHints(Panel8);
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    Grid3 = new wxGrid(Panel3, ID_GRID3, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID3"));
    Grid3->CreateGrid(0,10);
    Grid3->EnableEditing(true);
    Grid3->EnableGridLines(true);
    Grid3->SetDefaultColSize(120, true);
    Grid3->SetColLabelValue(0, _("Name"));
    Grid3->SetColLabelValue(1, _("Weight, t"));
    Grid3->SetColLabelValue(2, _("LCG, m"));
    Grid3->SetColLabelValue(3, _("VCG, m"));
    Grid3->SetColLabelValue(4, _("TCG, m"));
    Grid3->SetColLabelValue(5, _("Fs, m*t"));
    Grid3->SetColLabelValue(6, _("Fs max"));
    Grid3->SetColLabelValue(7, _("Vol %"));
    Grid3->SetColLabelValue(8, _("Vo,l m3"));
    Grid3->SetColLabelValue(9, _("Max Vol m3"));
    Grid3->SetDefaultCellFont( Grid3->GetFont() );
    Grid3->SetDefaultCellTextColour( Grid3->GetForegroundColour() );
    BoxSizer3->Add(Grid3, 1, wxALL|wxEXPAND, 5);
    Panel3->SetSizer(BoxSizer3);
    BoxSizer3->Fit(Panel3);
    BoxSizer3->SetSizeHints(Panel3);
    Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    Grid5 = new wxGrid(Panel4, ID_GRID5, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID5"));
    Grid5->CreateGrid(0,10);
    Grid5->EnableEditing(true);
    Grid5->EnableGridLines(true);
    Grid5->SetDefaultColSize(120, true);
    Grid5->SetColLabelValue(0, _("Name"));
    Grid5->SetColLabelValue(1, _("Weight, t"));
    Grid5->SetColLabelValue(2, _("LCG, m"));
    Grid5->SetColLabelValue(3, _("VCG, m"));
    Grid5->SetColLabelValue(4, _("TCG, m"));
    Grid5->SetColLabelValue(5, _("Fs, m*t"));
    Grid5->SetColLabelValue(6, _("Fs max"));
    Grid5->SetColLabelValue(7, _("Vol %"));
    Grid5->SetColLabelValue(8, _("Volume, m3"));
    Grid5->SetColLabelValue(9, _("Max Vol, m3"));
    Grid5->SetDefaultCellFont( Grid5->GetFont() );
    Grid5->SetDefaultCellTextColour( Grid5->GetForegroundColour() );
    BoxSizer5->Add(Grid5, 1, wxALL|wxEXPAND, 5);
    Panel4->SetSizer(BoxSizer5);
    BoxSizer5->Fit(Panel4);
    BoxSizer5->SetSizeHints(Panel4);
    Panel5 = new wxPanel(Notebook1, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    Panel6 = new wxPanel(Notebook1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    Panel7 = new wxPanel(Notebook1, ID_PANEL7, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    Grid6 = new wxGrid(Panel7, ID_GRID6, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID6"));
    Grid6->CreateGrid(50,8);
    Grid6->EnableEditing(true);
    Grid6->EnableGridLines(true);
    Grid6->SetDefaultColSize(150, true);
    Grid6->SetColLabelValue(0, _("Item"));
    Grid6->SetColLabelValue(1, _("Weight, t"));
    Grid6->SetColLabelValue(2, _("LCG, m"));
    Grid6->SetColLabelValue(3, _("VCG, m"));
    Grid6->SetColLabelValue(4, _("TCG, m"));
    Grid6->SetColLabelValue(5, _("Length, m"));
    Grid6->SetColLabelValue(6, _("Breadth, m"));
    Grid6->SetColLabelValue(7, _("Height, m"));
    Grid6->SetDefaultCellFont( Grid6->GetFont() );
    Grid6->SetDefaultCellTextColour( Grid6->GetForegroundColour() );
    BoxSizer6->Add(Grid6, 1, wxALL|wxEXPAND, 5);
    Panel7->SetSizer(BoxSizer6);
    BoxSizer6->Fit(Panel7);
    BoxSizer6->SetSizeHints(Panel7);
    Notebook1->AddPage(Panel1, _("General"), false);
    Notebook1->AddPage(Panel2, _("Constants"), false);
    Notebook1->AddPage(Panel8, _("Cargo Tanks"), false);
    Notebook1->AddPage(Panel3, _("Ballast Tanks"), false);
    Notebook1->AddPage(Panel4, _("Tanks"), false);
    Notebook1->AddPage(Panel5, _("Stability"), false);
    Notebook1->AddPage(Panel6, _("Strength"), false);
    Notebook1->AddPage(Panel7, _("Dead Load"), false);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    LoadButton = new wxMenuItem(Menu1, ID_MENUITEM1, _("Load"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(LoadButton);
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

    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CargoMasterFrame::OnLoadButtonSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CargoMasterFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CargoMasterFrame::OnAbout);
    //*)
}
//Automatically generated code end

CargoMasterFrame::~CargoMasterFrame()
{
    //(*Destroy(CargoMasterFrame)
    //*)
}

void CargoMasterFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CargoMasterFrame::OnAbout(wxCommandEvent& event)
{

}

void CargoMasterFrame::OnLoadButtonSelected(wxCommandEvent& event)
{
    wxFileDialog dialog(NULL, wxT("Choose a File"));
    if (dialog.ShowModal() == wxID_OK)
    {
        ShipBody.load(dialog.GetPath().ToStdString());
    }
}
