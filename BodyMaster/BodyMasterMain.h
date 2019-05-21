/***************************************************************
 * Name:      BodyMasterMain.h
 * Purpose:   Defines Application Frame
 * Author:    Vilis Erglis (vilis@taksis.org)
 * Created:   2019-05-07
 * Copyright: Vilis Erglis ()
 * License:   GNU General Public License v3.0
 **************************************************************/

#ifndef BODYMASTERMAIN_H
#define BODYMASTERMAIN_H
#include "../Ship.h"
#include "../Particulars.h"
#include <wx/msgdlg.h>
#include <wx/filedlg.h>

//(*Headers(BodyMasterFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/menu.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
//*)

class BodyMasterFrame: public wxFrame
{
    public:

        BodyMasterFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~BodyMasterFrame();

    private:

        //(*Handlers(BodyMasterFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnAddButtonClick(wxCommandEvent& event);
        void OnParticularsButtonClick(wxCommandEvent& event);
        void OnGridCellChanged(wxGridEvent& event);
        void OnDeleteButtonClick(wxCommandEvent& event);
        void OnLoadItemSelected(wxCommandEvent& event);
        void OnSaveItemSelected(wxCommandEvent& event);
        void OnCalculateButtonClick1(wxCommandEvent& event);
        void OnPrintHydrostaticsSelected(wxCommandEvent& event);
        void OnResize(wxSizeEvent& event);
        //*)

        //(*Identifiers(BodyMasterFrame)
        static const long ID_GRID1;
        static const long ID_BUTTON4;
        static const long ID_BUTTON3;
        static const long ID_BUTTON2;
        static const long ID_BUTTON1;
        static const long idMenuSave;
        static const long idMenuLoad;
        static const long idMenuQuit;
        static const long idPrintHydroStatics;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(BodyMasterFrame)
        wxButton* AddButton;
        wxButton* CalculateButton;
        wxButton* DeleteButton;
        wxButton* ParticularsButton;
        wxFlexGridSizer* FlexGridSizer1;
        wxGrid* Grid;
        wxMenu* Menu3;
        wxMenuItem* LoadItem;
        wxMenuItem* PrintHydrostatics;
        wxMenuItem* SaveItem;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // BODYMASTERMAIN_H
