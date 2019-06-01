/***************************************************************
 * Name:      CargoMasterMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Vilis Erglis (vilis@taksis.org)
 * Created:   2019-05-07
 * Copyright: Vilis Erglis ()
 * License:   GNU General Public License v3.0
 **************************************************************/

#include "CargoMasterMain.h"
#include <wx/msgdlg.h>
#include <iostream>

#define CellVal(n) n->GetCellValue(n->GetGridCursorRow(), n->GetGridCursorCol())

//(*InternalHeaders(CargoMasterFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
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
const long CargoMasterFrame::ID_STATICBITMAP1 = wxNewId();
const long CargoMasterFrame::ID_PANEL5 = wxNewId();
const long CargoMasterFrame::ID_PANEL6 = wxNewId();
const long CargoMasterFrame::ID_GRID6 = wxNewId();
const long CargoMasterFrame::ID_PANEL7 = wxNewId();
const long CargoMasterFrame::ID_NOTEBOOK1 = wxNewId();
const long CargoMasterFrame::ID_MENUITEM2 = wxNewId();
const long CargoMasterFrame::ID_MENUITEM1 = wxNewId();
const long CargoMasterFrame::idMenuQuit = wxNewId();
const long CargoMasterFrame::ID_MENUITEM3 = wxNewId();
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
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer6;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Cargo Master"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(920,713));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("/home/vilis/Cargo_Sim/Logo.png"))));
    	SetIcon(FrameIcon);
    }
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxPoint(152,176), wxSize(1088,728), 0, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    GeneralGrid = new wxGrid(Panel1, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
    GeneralGrid->CreateGrid(7,5);
    GeneralGrid->EnableEditing(false);
    GeneralGrid->EnableGridLines(true);
    GeneralGrid->SetRowLabelSize(200);
    GeneralGrid->SetDefaultColSize(150, true);
    GeneralGrid->SetColLabelValue(0, _("Weight, t"));
    GeneralGrid->SetColLabelValue(1, _("LCG, m"));
    GeneralGrid->SetColLabelValue(2, _("VCG, m"));
    GeneralGrid->SetColLabelValue(3, _("TCG, m"));
    GeneralGrid->SetColLabelValue(4, _("Fs, m*t"));
    GeneralGrid->SetRowLabelValue(0, _("Constants"));
    GeneralGrid->SetRowLabelValue(1, _("Tanks/Holds"));
    GeneralGrid->SetRowLabelValue(2, _("Dead Load"));
    GeneralGrid->SetRowLabelValue(3, _("Deadweight"));
    GeneralGrid->SetRowLabelValue(4, _("Light Ship"));
    GeneralGrid->SetRowLabelValue(5, _("Displacement"));
    GeneralGrid->SetRowLabelValue(6, _("Deadw. Reserve"));
    GeneralGrid->SetDefaultCellFont( GeneralGrid->GetFont() );
    GeneralGrid->SetDefaultCellTextColour( GeneralGrid->GetForegroundColour() );
    BoxSizer1->Add(GeneralGrid, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    ConstantsGrid = new wxGrid(Panel2, ID_GRID2, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID2"));
    ConstantsGrid->CreateGrid(50,5);
    ConstantsGrid->EnableEditing(true);
    ConstantsGrid->EnableGridLines(true);
    ConstantsGrid->SetDefaultColSize(150, true);
    ConstantsGrid->SetColLabelValue(0, _("Item"));
    ConstantsGrid->SetColLabelValue(1, _("Weight, t"));
    ConstantsGrid->SetColLabelValue(2, _("LCG, m"));
    ConstantsGrid->SetColLabelValue(3, _("VCG, m"));
    ConstantsGrid->SetColLabelValue(4, _("TCG, m"));
    ConstantsGrid->SetDefaultCellFont( ConstantsGrid->GetFont() );
    ConstantsGrid->SetDefaultCellTextColour( ConstantsGrid->GetForegroundColour() );
    BoxSizer2->Add(ConstantsGrid, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel2);
    BoxSizer2->SetSizeHints(Panel2);
    Panel8 = new wxPanel(Notebook1, ID_PANEL8, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    CargoTankGrid = new wxGrid(Panel8, ID_GRID4, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID4"));
    CargoTankGrid->CreateGrid(0,10);
    CargoTankGrid->EnableEditing(true);
    CargoTankGrid->EnableGridLines(true);
    CargoTankGrid->SetDefaultColSize(120, true);
    CargoTankGrid->SetColLabelValue(0, _("Name"));
    CargoTankGrid->SetColLabelValue(1, _("Weight, t"));
    CargoTankGrid->SetColLabelValue(2, _("LCG, m"));
    CargoTankGrid->SetColLabelValue(3, _("VCG, m"));
    CargoTankGrid->SetColLabelValue(4, _("TCG, m"));
    CargoTankGrid->SetColLabelValue(5, _("Fs, m*t"));
    CargoTankGrid->SetColLabelValue(6, _("Fs max"));
    CargoTankGrid->SetColLabelValue(7, _("Vol %"));
    CargoTankGrid->SetColLabelValue(8, _("Volume, m3"));
    CargoTankGrid->SetColLabelValue(9, _("Max Vol, m3"));
    CargoTankGrid->SetDefaultCellFont( CargoTankGrid->GetFont() );
    CargoTankGrid->SetDefaultCellTextColour( CargoTankGrid->GetForegroundColour() );
    BoxSizer4->Add(CargoTankGrid, 1, wxALL|wxEXPAND, 5);
    Panel8->SetSizer(BoxSizer4);
    BoxSizer4->Fit(Panel8);
    BoxSizer4->SetSizeHints(Panel8);
    Panel5 = new wxPanel(Notebook1, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    StabilitySizer = new wxBoxSizer(wxHORIZONTAL);
    StabilityBit = new wxStaticBitmap(Panel5, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    StabilitySizer->Add(StabilityBit, 1, wxALL|wxEXPAND, 5);
    Panel5->SetSizer(StabilitySizer);
    StabilitySizer->Fit(Panel5);
    StabilitySizer->SetSizeHints(Panel5);
    Panel6 = new wxPanel(Notebook1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    Panel7 = new wxPanel(Notebook1, ID_PANEL7, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    DeadLoadGrid = new wxGrid(Panel7, ID_GRID6, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID6"));
    DeadLoadGrid->CreateGrid(50,8);
    DeadLoadGrid->EnableEditing(true);
    DeadLoadGrid->EnableGridLines(true);
    DeadLoadGrid->SetDefaultColSize(150, true);
    DeadLoadGrid->SetColLabelValue(0, _("Item"));
    DeadLoadGrid->SetColLabelValue(1, _("Weight, t"));
    DeadLoadGrid->SetColLabelValue(2, _("LCG, m"));
    DeadLoadGrid->SetColLabelValue(3, _("VCG, m"));
    DeadLoadGrid->SetColLabelValue(4, _("TCG, m"));
    DeadLoadGrid->SetColLabelValue(5, _("Length, m"));
    DeadLoadGrid->SetColLabelValue(6, _("Breadth, m"));
    DeadLoadGrid->SetColLabelValue(7, _("Height, m"));
    DeadLoadGrid->SetDefaultCellFont( DeadLoadGrid->GetFont() );
    DeadLoadGrid->SetDefaultCellTextColour( DeadLoadGrid->GetForegroundColour() );
    BoxSizer6->Add(DeadLoadGrid, 1, wxALL|wxEXPAND, 5);
    Panel7->SetSizer(BoxSizer6);
    BoxSizer6->Fit(Panel7);
    BoxSizer6->SetSizeHints(Panel7);
    Notebook1->AddPage(Panel1, _("General"), false);
    Notebook1->AddPage(Panel2, _("Constants"), false);
    Notebook1->AddPage(Panel8, _("Tanks/Holds"), false);
    Notebook1->AddPage(Panel5, _("Stability"), false);
    Notebook1->AddPage(Panel6, _("Strength"), false);
    Notebook1->AddPage(Panel7, _("Dead Load"), false);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    SaveItem = new wxMenuItem(Menu1, ID_MENUITEM2, _("Save\tCtrl+s"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(SaveItem);
    LoadButton = new wxMenuItem(Menu1, ID_MENUITEM1, _("Load"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(LoadButton);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    ParticularsOpen = new wxMenuItem(Menu3, ID_MENUITEM3, _("Particulars"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(ParticularsOpen);
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

    Connect(ID_GRID2,wxEVT_GRID_CELL_CHANGED,(wxObjectEventFunction)&CargoMasterFrame::OnConstantsGridCellChanged);
    Connect(ID_GRID4,wxEVT_GRID_CELL_CHANGED,(wxObjectEventFunction)&CargoMasterFrame::OnCargoTankGridCellChanged);
    Connect(ID_GRID6,wxEVT_GRID_CELL_CHANGED,(wxObjectEventFunction)&CargoMasterFrame::OnDeadLoadGridCellChanged);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CargoMasterFrame::OnSaveItemSelected);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CargoMasterFrame::OnLoadButtonSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CargoMasterFrame::OnQuit);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CargoMasterFrame::OnParticularsOpenSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CargoMasterFrame::OnAbout);
    //*)
}
//Automatically generated code end

void CargoMasterFrame::update()
{
    GeneralGrid->SetCellValue(0,0,wxString::Format(wxT("%.2f"), ShipBody.constants_weight()));
    GeneralGrid->SetCellValue(0,1,wxString::Format(wxT("%.2f"), ShipBody.constants_LCG()));
    GeneralGrid->SetCellValue(0,2,wxString::Format(wxT("%.2f"), ShipBody.constants_VCG()));
    GeneralGrid->SetCellValue(0,3,wxString::Format(wxT("%.2f"), ShipBody.constants_TCG()));
    GeneralGrid->SetCellValue(1,0,wxString::Format(wxT("%.2f"), ShipBody.unit_weight()));
    GeneralGrid->SetCellValue(1,1,wxString::Format(wxT("%.2f"), ShipBody.unit_LCG()));
    GeneralGrid->SetCellValue(1,2,wxString::Format(wxT("%.2f"), ShipBody.unit_VCG()));
    GeneralGrid->SetCellValue(1,3,wxString::Format(wxT("%.2f"), ShipBody.unit_TCG()));
    GeneralGrid->SetCellValue(2,0,wxString::Format(wxT("%.2f"), ShipBody.deadLoad_weight()));
    GeneralGrid->SetCellValue(2,1,wxString::Format(wxT("%.2f"), ShipBody.deadLoad_lcg()));
    GeneralGrid->SetCellValue(2,2,wxString::Format(wxT("%.2f"), ShipBody.deadLoad_vcg()));
    GeneralGrid->SetCellValue(2,3,wxString::Format(wxT("%.2f"), ShipBody.deadLoad_tcg()));
    GeneralGrid->SetCellValue(3,0,wxString::Format(wxT("%.2f"), ShipBody.deadweight()));
    GeneralGrid->SetCellValue(3,1,wxString::Format(wxT("%.2f"), ShipBody.deadweight_lcg()));
    GeneralGrid->SetCellValue(3,2,wxString::Format(wxT("%.2f"), ShipBody.deadweight_vcg()));
    GeneralGrid->SetCellValue(3,3,wxString::Format(wxT("%.2f"), ShipBody.deadweight_tcg()));
    GeneralGrid->SetCellValue(5,0,wxString::Format(wxT("%.2f"), ShipBody.disp()));
    GeneralGrid->SetCellValue(5,1,wxString::Format(wxT("%.2f"), ShipBody.disp_lcg()));
    GeneralGrid->SetCellValue(5,2,wxString::Format(wxT("%.2f"), ShipBody.disp_vcg()));
    GeneralGrid->SetCellValue(5,3,wxString::Format(wxT("%.2f"), ShipBody.disp_tcg()));
    GeneralGrid->SetCellValue(6,0,wxString::Format(wxT("%.2f"), ShipBody.rest_dwt()));
    ShipBody.gz_curve();
    wxBitmap bitmap (wxT("gz.png"), wxBITMAP_TYPE_PNG);
    StabilityBit->SetBitmap(bitmap);
}

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
    if (dialog.ShowModal()==wxID_OK){
        if (!ShipBody.load(dialog.GetPath().ToStdString()))
        {
            wxMessageBox(wxT("Error loading file"), wxT("Error"));
        }else{
        ShipBody.variable_update();
        for (int i=0; i<ShipBody.unit_count(); i++)
        {
            CargoTankGrid->AppendRows();
            CargoTankGrid->SetCellValue(i,0, ShipBody.read_unit_name(i));
            CargoTankGrid->SetCellValue(i,1, wxString::Format(wxT("%.2f"), ShipBody.read_u_weight(i)));
            CargoTankGrid->SetCellValue(i,2, wxString::Format(wxT("%.2f"), ShipBody.read_u_LCG(i)));
            CargoTankGrid->SetCellValue(i,3, wxString::Format(wxT("%.2f"), ShipBody.read_u_VCG(i)));
            CargoTankGrid->SetCellValue(i,4, wxString::Format(wxT("%.2f"), ShipBody.read_u_TCG(i)));
            CargoTankGrid->SetCellValue(i,6, wxString::Format(wxT("%.2f"), ShipBody.read_u_density(i)));
            CargoTankGrid->SetCellValue(i,5, wxString::Format(wxT("%.2f"), ShipBody.read_u_fsmax(i)));
            CargoTankGrid->SetCellValue(i,7, wxString::Format(wxT("%.2f"), ShipBody.read_u_maxvol(i)/ShipBody.read_u_volume(i)*100));
            CargoTankGrid->SetCellValue(i,8, wxString::Format(wxT("%.2f"), ShipBody.read_u_volume(i)));
            CargoTankGrid->SetCellValue(i,9, wxString::Format(wxT("%.2f"), ShipBody.read_u_maxvol(i)));

            CargoTankGrid->SetReadOnly(i,0);
            CargoTankGrid->SetReadOnly(i,2);
            CargoTankGrid->SetReadOnly(i,3);
            CargoTankGrid->SetReadOnly(i,4);
            CargoTankGrid->SetReadOnly(i,5);
            CargoTankGrid->SetReadOnly(i,9);
        }
        update();
        GeneralGrid->SetCellValue(4,0,wxString::Format(wxT("%i"), ShipBody.read_s_lightShip()));
        GeneralGrid->SetCellValue(4,1,wxString::Format(wxT("%.2f"), ShipBody.read_s_LCGLight()));
        GeneralGrid->SetCellValue(4,2,wxString::Format(wxT("%.2f"), ShipBody.read_s_VCGLight()));
        GeneralGrid->SetCellValue(4,3,wxString::Format(wxT("%.2f"), ShipBody.read_s_TCGLight()));
        wxMessageBox("File loaded!");}
    }
}

void CargoMasterFrame::OnConstantsGridCellChanged(wxGridEvent& event)
{
    if (ConstantsGrid->GetGridCursorCol()==0)
    {
        if (ShipBody.set_con_name(ConstantsGrid->GetGridCursorRow(),CellVal(ConstantsGrid).ToStdString()))
        {
            ConstantsGrid->SetCellTextColour(ConstantsGrid->GetGridCursorRow(),0,*wxBLACK);
        }else{
            ConstantsGrid->SetCellTextColour(ConstantsGrid->GetGridCursorRow(),0,*wxRED);
            return;
        }
    }
    if (ConstantsGrid->GetGridCursorCol()==1)
    {
        if(ShipBody.set_con_weight(ConstantsGrid->GetGridCursorRow(),CellVal(ConstantsGrid).ToStdString()))
        {

        ConstantsGrid->SetCellTextColour(ConstantsGrid->GetGridCursorRow(),1,*wxBLACK);
    }else{
        ConstantsGrid->SetCellTextColour(ConstantsGrid->GetGridCursorRow(),1,*wxRED);
        return;
        }
    }
    if (ConstantsGrid->GetGridCursorCol()==2)
    {
        if (ShipBody.set_con_lcg(ConstantsGrid->GetGridCursorRow(),CellVal(ConstantsGrid).ToStdString()))

    {
        ConstantsGrid->SetCellTextColour(ConstantsGrid->GetGridCursorRow(),2,*wxBLACK);
    }else{
        ConstantsGrid->SetCellTextColour(ConstantsGrid->GetGridCursorRow(),2,*wxRED);
        return;
    }
    }
    if (ConstantsGrid->GetGridCursorCol()==3)
    {
        if (ShipBody.set_con_vcg(ConstantsGrid->GetGridCursorRow(),CellVal(ConstantsGrid).ToStdString()))
        {

        ConstantsGrid->SetCellTextColour(ConstantsGrid->GetGridCursorRow(),3,*wxBLACK);
    }else{
        ConstantsGrid->SetCellTextColour(ConstantsGrid->GetGridCursorRow(),3,*wxRED);
        return;
        }
    }
    if (ConstantsGrid->GetGridCursorCol()==4)
    {
        if (ShipBody.set_con_tcg(ConstantsGrid->GetGridCursorRow(),CellVal(ConstantsGrid).ToStdString()))
        {

        ConstantsGrid->SetCellTextColour(ConstantsGrid->GetGridCursorRow(),4,*wxBLACK);
    }else{
        ConstantsGrid->SetCellTextColour(ConstantsGrid->GetGridCursorRow(),4,*wxRED);
        return;
        }
    }
    update();
}

void CargoMasterFrame::OnDeadLoadGridCellChanged(wxGridEvent& event)
{
    if (DeadLoadGrid->GetGridCursorCol()==0)
    {
        if (ShipBody.set_car_name(DeadLoadGrid->GetGridCursorRow(), CellVal(DeadLoadGrid).ToStdString()))
        {
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxBLACK);
        }else{
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxRED);
        }
    }
    if (DeadLoadGrid->GetGridCursorCol()==1)
    {
        if (ShipBody.set_car_weight(DeadLoadGrid->GetGridCursorRow(), CellVal(DeadLoadGrid).ToStdString()))
        {
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxBLACK);
        }else{
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxRED);
        }
    }
    if (DeadLoadGrid->GetGridCursorCol()==2)
    {
        if (ShipBody.set_car_lcg(DeadLoadGrid->GetGridCursorRow(), CellVal(DeadLoadGrid).ToStdString()))
        {
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxBLACK);
        }else{
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxRED);
        }
    }
    if (DeadLoadGrid->GetGridCursorCol()==3)
    {
        if (ShipBody.set_car_vcg(DeadLoadGrid->GetGridCursorRow(), CellVal(DeadLoadGrid).ToStdString()))
        {
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxBLACK);
        }else{
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxRED);
        }
    }
    if (DeadLoadGrid->GetGridCursorCol()==4)
    {
        if (ShipBody.set_car_tcg(DeadLoadGrid->GetGridCursorRow(), CellVal(DeadLoadGrid).ToStdString()))
        {
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxBLACK);
        }else{
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxRED);
        }
    }
    if (DeadLoadGrid->GetGridCursorCol()==5)
    {
        if (ShipBody.set_car_length(DeadLoadGrid->GetGridCursorRow(), CellVal(DeadLoadGrid).ToStdString()))
        {
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxBLACK);
        }else{
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxRED);
        }
    }
    if (DeadLoadGrid->GetGridCursorCol()==6)
    {
        if (ShipBody.set_car_breadth(DeadLoadGrid->GetGridCursorRow(), CellVal(DeadLoadGrid).ToStdString()))
        {
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxBLACK);
        }else{
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxRED);
        }
    }
    if (DeadLoadGrid->GetGridCursorCol()==7)
    {
        if (ShipBody.set_car_height(DeadLoadGrid->GetGridCursorRow(), CellVal(DeadLoadGrid).ToStdString()))
        {
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxBLACK);
        }else{
            DeadLoadGrid->SetCellTextColour(DeadLoadGrid->GetGridCursorRow(), DeadLoadGrid->GetGridCursorCol(), *wxRED);
        }
    }
    update();
}

void CargoMasterFrame::OnParticularsOpenSelected(wxCommandEvent& event)
{
   Particulars* particulars = new Particulars(NULL);
   particulars->nameText->SetLabel(ShipBody.read_s_name());
   particulars->LOAText->SetLabel(wxString::Format(wxT("%2.f m"), ShipBody.read_s_LOA()));
   particulars->beamText->SetLabel(wxString::Format(wxT("%2.f m"), ShipBody.read_s_beam()));
   particulars->heightText->SetLabel(wxString::Format(wxT("%2.f m"), ShipBody.read_s_height()));
   particulars->lightShipText->SetLabel(wxString::Format(wxT("%i t"), ShipBody.read_s_lightShip()));
   particulars->LCGText->SetLabel(wxString::Format(wxT("%2.f m"), ShipBody.read_s_LCGLight()));
   particulars->TCGText->SetLabel(wxString::Format(wxT("%2.f m"), ShipBody.read_s_TCGLight()));
   particulars->VCGText->SetLabel(wxString::Format(wxT("%2.f m"), ShipBody.read_s_VCGLight()));
   particulars->ShowModal();

   delete particulars;
}

void CargoMasterFrame::OnCargoTankGridCellChanged(wxGridEvent& event)
{
    if (CargoTankGrid->GetGridCursorCol()==1)
    {
        if (ShipBody.set_u_weight(CargoTankGrid->GetGridCursorRow(), CellVal(CargoTankGrid).ToStdString()))
        {
            CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 1, *wxBLACK);
            CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 7, *wxBLACK);
            CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 8, *wxBLACK);
            CargoTankGrid->SetCellValue(CargoTankGrid->GetGridCursorRow(), 7, wxString::Format(wxT("%.1f"), ShipBody.read_u_pvol(CargoTankGrid->GetGridCursorRow())));
            CargoTankGrid->SetCellValue(CargoTankGrid->GetGridCursorRow(), 8, wxString::Format(wxT("%.2f"), ShipBody.read_u_volume(CargoTankGrid->GetGridCursorRow())));
            update();
        }else{CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 1, *wxRED);}
    }
    if (CargoTankGrid->GetGridCursorCol()==7)
    {
        if (ShipBody.set_u_pvol(CargoTankGrid->GetGridCursorRow(), CellVal(CargoTankGrid).ToStdString()))
        {
            CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 7, *wxBLACK);
            CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 8, *wxBLACK);
            CargoTankGrid->SetCellValue(CargoTankGrid->GetGridCursorRow(), 1, wxString::Format(wxT("%.2f"), ShipBody.read_u_weight(CargoTankGrid->GetGridCursorRow())));
            CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 1, *wxBLACK);
            CargoTankGrid->SetCellValue(CargoTankGrid->GetGridCursorRow(), 8, wxString::Format(wxT("%.2f"), ShipBody.read_u_volume(CargoTankGrid->GetGridCursorRow())));
            update();
        }else{CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 7, *wxRED);}
    }
    if (CargoTankGrid->GetGridCursorCol()==8)
    {
        if (ShipBody.set_u_vol(CargoTankGrid->GetGridCursorRow(), CellVal(CargoTankGrid).ToStdString()))
        {
            CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 8, *wxBLACK);
            CargoTankGrid->SetCellValue(CargoTankGrid->GetGridCursorRow(), 1, wxString::Format(wxT("%.2f"), ShipBody.read_u_weight(CargoTankGrid->GetGridCursorRow())));
            CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 1, *wxBLACK);
            CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 7, *wxBLACK);
            CargoTankGrid->SetCellValue(CargoTankGrid->GetGridCursorRow(), 7, wxString::Format(wxT("%.1f"), ShipBody.read_u_pvol(CargoTankGrid->GetGridCursorRow())));
            update();
        }else{CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 8, *wxRED);}
    }
    if (CargoTankGrid->GetGridCursorCol()==6)
    {
        if(ShipBody.set_u_density(CargoTankGrid->GetGridCursorRow(), CellVal(CargoTankGrid).ToStdString()))
        {
            CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 1, *wxBLACK);
            CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 7, *wxBLACK);
            CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 8, *wxBLACK);
            CargoTankGrid->SetCellValue(CargoTankGrid->GetGridCursorRow(), 1, wxString::Format(wxT("%.2f"), ShipBody.read_u_weight(CargoTankGrid->GetGridCursorRow())));
            CargoTankGrid->SetCellValue(CargoTankGrid->GetGridCursorRow(), 7, wxString::Format(wxT("%.1f"), ShipBody.read_u_pvol(CargoTankGrid->GetGridCursorRow())));
            CargoTankGrid->SetCellValue(CargoTankGrid->GetGridCursorRow(), 8, wxString::Format(wxT("%.2f"), ShipBody.read_u_volume(CargoTankGrid->GetGridCursorRow())));
            update();
        }else{CargoTankGrid->SetCellTextColour(CargoTankGrid->GetGridCursorRow(), 8, *wxRED);}
    }
}

void CargoMasterFrame::OnSaveItemSelected(wxCommandEvent& event)
{
     ShipBody.save(ShipBody.read_s_name()+" Condition at ");
}
