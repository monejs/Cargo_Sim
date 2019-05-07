/***************************************************************
 * Name:      BodyMasterMain.h
 * Purpose:   Defines Application Frame
 * Author:    Vilis Erglis (vilis@erglis.org)
 * Created:   2019-05-07
 * Copyright: Vilis Erglis ()
 * License:
 **************************************************************/

#ifndef BODYMASTERMAIN_H
#define BODYMASTERMAIN_H
#include "../Ship.h"

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
        //*)

        //(*Identifiers(BodyMasterFrame)
        static const long ID_GRID1;
        static const long ID_BUTTON4;
        static const long ID_BUTTON3;
        static const long ID_BUTTON2;
        static const long ID_BUTTON1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(BodyMasterFrame)
        wxButton* AddButton;
        wxButton* CalculateButton;
        wxButton* DeleteButton;
        wxButton* ParticularsButton;
        wxGrid* Grid;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // BODYMASTERMAIN_H
