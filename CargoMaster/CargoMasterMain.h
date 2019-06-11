/***************************************************************
 * Name:      CargoMasterMain.h
 * Purpose:   Defines Application Frame
 * Author:    Vilis Erglis (vilis@taksis.org)
 * Created:   2019-05-07
 * Copyright: Vilis Erglis ()
 * License:   GNU General Public License v3.0
 **************************************************************/

#ifndef CARGOMASTERMAIN_H
#define CARGOMASTERMAIN_H
#include "../Ship.h"
#include "wx/filedlg.h"
#include "Particulars.h"
#include <iostream>

//(*Headers(CargoMasterFrame)
#include "mathplot.h"
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
//*)

class CargoMasterFrame: public wxFrame
{
    public:

        CargoMasterFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~CargoMasterFrame();

    private:

        //(*Handlers(CargoMasterFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnLoadButtonSelected(wxCommandEvent& event);
        void OnConstantsGridCellChanged(wxGridEvent& event);
        void OnDeadLoadGridCellChanged(wxGridEvent& event);
        void OnParticularsOpenSelected(wxCommandEvent& event);
        void OnCargoTankGridCellChanged(wxGridEvent& event);
        void OnBallastGridCellChanged(wxGridEvent& event);
        void OnTankGridCellChanged(wxGridEvent& event);
        void OnSaveItemSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(CargoMasterFrame)
        static const long ID_GRID1;
        static const long ID_PANEL1;
        static const long ID_GRID2;
        static const long ID_PANEL2;
        static const long ID_GRID4;
        static const long ID_PANEL8;
        static const long ID_GRID3;
        static const long ID_PANEL5;
        static const long ID_PANEL6;
        static const long ID_GRID6;
        static const long ID_PANEL7;
        static const long ID_NOTEBOOK1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM1;
        static const long idMenuQuit;
        static const long ID_MENUITEM3;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(CargoMasterFrame)
        mpWindow* m_plot;
        wxGrid* CargoTankGrid;
        wxGrid* ConstantsGrid;
        wxGrid* DeadLoadGrid;
        wxGrid* GeneralGrid;
        wxGrid* StabilityGrid;
        wxMenu* Menu3;
        wxMenuItem* LoadButton;
        wxMenuItem* ParticularsOpen;
        wxMenuItem* SaveItem;
        wxNotebook* Notebook1;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxPanel* Panel5;
        wxPanel* Panel6;
        wxPanel* Panel7;
        wxPanel* Panel8;
        wxStatusBar* StatusBar1;
        //*)
        std::vector<double> vectorx, vectory;
        mpFXYVector* vectorLayer;
        void update();
        void rowColor(int, const wxColour&);
        DECLARE_EVENT_TABLE()
};

#endif // CARGOMASTERMAIN_H
