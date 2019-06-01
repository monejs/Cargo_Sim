/***************************************************************
 * Name:      BodyMasterMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Vilis Erglis (vilis@taksis.org)
 * Created:   2019-05-07
 * Copyright: Vilis Erglis ()
 * License:   GNU General Public License v3.0
 **************************************************************/

#include "BodyMasterMain.h"

#define output(x,y) if (!x(particulars->y->GetValue().ToStdString()))\
   // {\
        wxMessageBox(wxT("Invalid input"), wxT("Error"));\
    }

#define convert(x) wxString::Format(wxT("%.2f"), x)

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
const long BodyMasterFrame::idMenuSave = wxNewId();
const long BodyMasterFrame::idMenuLoad = wxNewId();
const long BodyMasterFrame::idMenuQuit = wxNewId();
const long BodyMasterFrame::idPrintHydroStatics = wxNewId();
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
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("BodyMaster"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
    Grid = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE, _T("ID_GRID1"));
    Grid->CreateGrid(0,8);
    Grid->SetMinSize(wxSize(1300,800));
    Grid->EnableEditing(true);
    Grid->EnableGridLines(true);
    Grid->SetDefaultColSize(150, true);
    Grid->SetColLabelValue(0, _("Name"));
    Grid->SetColLabelValue(1, _("Type"));
    Grid->SetColLabelValue(2, _("LCG"));
    Grid->SetColLabelValue(3, _("TCG"));
    Grid->SetColLabelValue(4, _("VCG"));
    Grid->SetColLabelValue(5, _("Leangth"));
    Grid->SetColLabelValue(6, _("Breath"));
    Grid->SetColLabelValue(7, _("Height"));
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
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_RIGHT, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    SaveItem = new wxMenuItem(Menu1, idMenuSave, _("Save\tCtrl + s"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(SaveItem);
    LoadItem = new wxMenuItem(Menu1, idMenuLoad, _("Load\tCtrl + o"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(LoadItem);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    PrintHydrostatics = new wxMenuItem(Menu3, idPrintHydroStatics, _("Print Hydrostatics"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(PrintHydrostatics);
    MenuBar1->Append(Menu3, _("&Ship"));
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
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BodyMasterFrame::OnParticularsButtonClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BodyMasterFrame::OnCalculateButtonClick1);
    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BodyMasterFrame::OnSaveItemSelected);
    Connect(idMenuLoad,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BodyMasterFrame::OnLoadItemSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BodyMasterFrame::OnQuit);
    Connect(idPrintHydroStatics,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BodyMasterFrame::OnPrintHydrostaticsSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BodyMasterFrame::OnAbout);
    Connect(wxEVT_SIZE,(wxObjectEventFunction)&BodyMasterFrame::OnResize);
    //*)
}

BodyMasterFrame::~BodyMasterFrame()
{
    //(*Destroy(BodyMasterFrame)
    //*)
}
//Closes the program
void BodyMasterFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}
//Opens the about window. Still working on this one
void BodyMasterFrame::OnAbout(wxCommandEvent& event)
{
}
//Adds a unit to the array in the grid and in the ShipBody instance
//This approach is used to save memory and give more flexibility
void BodyMasterFrame::OnAddButtonClick(wxCommandEvent& event)
{
    wxArrayString choices;
    for (unsigned int i=0; i<sizeof(ShipBody.u_type_strings)/sizeof(ShipBody.u_type_strings[0]); i++)
    {
        choices.Add(ShipBody.u_type_strings[i]);
    }
    Grid->AppendRows();
    Grid->SetCellEditor(Grid->GetNumberRows()-1,1, new wxGridCellChoiceEditor(choices, false));
    Grid->SetCellValue(Grid->GetNumberRows()-1,1, choices[0]);
    ShipBody.new_unit(ShipBody.u_types::Ballast);
    BodyMasterFrame::Layout();
}

void BodyMasterFrame::OnParticularsButtonClick(wxCommandEvent& event)
{
    Particulars* particulars = new Particulars(NULL);

    particulars->ShipNameText->SetValue(wxString::Format(wxT("%s"),ShipBody.read_s_name()));
    particulars->LOAText->SetValue(wxString::Format(wxT("%.2f"),ShipBody.read_s_LOA()));
    particulars->HText->SetValue(wxString::Format(wxT("%.2f"),ShipBody.read_s_height()));
    particulars->BText->SetValue(wxString::Format(wxT("%.2f"),ShipBody.read_s_beam()));
    particulars->LCGText->SetValue(wxString::Format(wxT("%.2f"),ShipBody.read_s_LCGLight()));
    particulars->VCGText->SetValue(wxString::Format(wxT("%.2f"),ShipBody.read_s_VCGLight()));
    particulars->TCGText->SetValue(wxString::Format(wxT("%.2f"),ShipBody.read_s_TCGLight()));
    particulars->LightShipText->SetValue(wxString::Format(wxT("%i"),ShipBody.read_s_lightShip()));
    particulars->MaxDrText->SetValue(wxString::Format(wxT("%.2f"),ShipBody.read_s_maxDraft()));
    particulars->MinDrText->SetValue(wxString::Format(wxT("%.2f"),ShipBody.read_s_minDraft()));
    particulars->MaxDWTText->SetValue(wxString::Format(wxT("%i"),ShipBody.read_s_maxDWT()));
    particulars->DeckStrText->SetValue(wxString::Format(wxT("%.2f"),ShipBody.read_s_strengthCover()));
    particulars->TankStrText->SetValue(wxString::Format(wxT("%.2f"),ShipBody.read_s_strengthTank()));

    particulars->ShowModal();

    output(ShipBody.set_s_name, ShipNameText);
    output(ShipBody.set_s_LOA, LOAText);
    output(ShipBody.set_s_beam, BText);
    output(ShipBody.set_s_height, HText);
    output(ShipBody.set_s_lightShip, LightShipText);
    output(ShipBody.set_s_LCGLight, LCGText);
    output(ShipBody.set_s_TCGLight, TCGText);
    output(ShipBody.set_s_VCGLight, VCGText);
    output(ShipBody.set_s_maxDraft, MaxDrText);
    output(ShipBody.set_s_minDraft, MinDrText);
    output(ShipBody.set_s_maxDWT, MaxDWTText);
    output(ShipBody.set_s_strengthCover, DeckStrText);
    output(ShipBody.set_s_strengthTank, TankStrText);

    delete particulars;
}

void BodyMasterFrame::OnGridCellChanged(wxGridEvent& event)
{

}

void BodyMasterFrame::OnDeleteButtonClick(wxCommandEvent& event)
{
    Grid->DeleteRows(Grid->GetGridCursorRow());
    ShipBody.delete_unit(Grid->GetGridCursorRow());
}

void BodyMasterFrame::OnLoadItemSelected(wxCommandEvent& event)
{
    ShipBody.clear_data();
    Grid->DeleteRows(0,Grid->GetNumberRows());
    wxFileDialog dialog(NULL, wxT("Choose a ship file"));
  //  dialog.ShowModal();
    if (dialog.ShowModal()==wxID_OK){
        if (!ShipBody.load(dialog.GetPath().ToStdString()))
        {
            wxMessageBox(wxT("Error loading file"), wxT("Error"));
        }else{
        wxMessageBox("File loaded!");}
    }
    for (int i=0; i<ShipBody.unit_count(); i++)
    {
        Grid->AppendRows();
        Grid->SetCellValue(Grid->GetNumberRows()-1,0,ShipBody.read_unit_name(i));
        Grid->SetCellValue(Grid->GetNumberRows()-1,1,ShipBody.read_unit_type(i));
        Grid->SetCellValue(Grid->GetNumberRows()-1,2,convert(ShipBody.read_u_LCG(i)));
        Grid->SetCellValue(Grid->GetNumberRows()-1,3,convert(ShipBody.read_u_TCG(i)));
        Grid->SetCellValue(Grid->GetNumberRows()-1,4,convert(ShipBody.read_u_VCG(i)));
        Grid->SetCellValue(Grid->GetNumberRows()-1,5,convert(ShipBody.read_u_length(i)));
        Grid->SetCellValue(Grid->GetNumberRows()-1,6,convert(ShipBody.read_u_breadth(i)));
        Grid->SetCellValue(Grid->GetNumberRows()-1,7,convert(ShipBody.read_u_height(i)));
    }
}

void BodyMasterFrame::OnSaveItemSelected(wxCommandEvent& event)
{
    for (int i=0; i<Grid->GetNumberRows(); i++)
    {
        ShipBody.set_u_name(i, Grid->GetCellValue(i,0).ToStdString());
        ShipBody.set_u_type(i, Grid->GetCellValue(i,1).ToStdString());
        ShipBody.set_u_lcg(i, Grid->GetCellValue(i,2).ToStdString());
        ShipBody.set_u_tcg(i, Grid->GetCellValue(i,3).ToStdString());
        ShipBody.set_u_vcg(i, Grid->GetCellValue(i,4).ToStdString());
        ShipBody.set_u_length(i, Grid->GetCellValue(i,5).ToStdString());
        ShipBody.set_u_breadth(i, Grid->GetCellValue(i,6).ToStdString());
        ShipBody.set_u_height(i, Grid->GetCellValue(i,7).ToStdString());

    }
    if(ShipBody.save(ShipBody.read_s_name()))
    {
        wxMessageBox("File Saved", "Success");
    }else {wxMessageBox("Error Saving File", "Error");}
}

void BodyMasterFrame::OnCalculateButtonClick1(wxCommandEvent& event)
{
    ShipBody.calculate();
}

void BodyMasterFrame::OnPrintHydrostaticsSelected(wxCommandEvent& event)
{
        for (int i=0; i<Grid->GetNumberRows(); i++)
    {
        ShipBody.set_u_name(i, Grid->GetCellValue(i,0).ToStdString());
        ShipBody.set_u_type(i, Grid->GetCellValue(i,1).ToStdString());
        ShipBody.set_u_lcg(i, Grid->GetCellValue(i,2).ToStdString());
        ShipBody.set_u_tcg(i, Grid->GetCellValue(i,3).ToStdString());
        ShipBody.set_u_vcg(i, Grid->GetCellValue(i,4).ToStdString());
        ShipBody.set_u_length(i, Grid->GetCellValue(i,5).ToStdString());
        ShipBody.set_u_breadth(i, Grid->GetCellValue(i,6).ToStdString());
        ShipBody.set_u_height(i, Grid->GetCellValue(i,7).ToStdString());

    }
    ShipBody.variable_update();
    ShipBody.text_print();
}

void BodyMasterFrame::OnResize(wxSizeEvent& event)
{
    BodyMasterFrame::Fit();
}
