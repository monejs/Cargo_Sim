/***************************************************************
 * Name:      CargoMasterApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Vilis Erglis (vilis@erglis.org)
 * Created:   2019-05-07
 * Copyright: Vilis Erglis ()
 * License:   GNU General Public License v3.0
 **************************************************************/

#include "CargoMasterApp.h"

//(*AppHeaders
#include "CargoMasterMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(CargoMasterApp);

bool CargoMasterApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	CargoMasterFrame* Frame = new CargoMasterFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
