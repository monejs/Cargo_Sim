/***************************************************************
 * Name:      BodyMasterApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Vilis Erglis (vilis@taksis.org)
 * Created:   2019-05-07
 * Copyright: Vilis Erglis ()
 * License:   GNU General Public License v3.0
 **************************************************************/

#include "BodyMasterApp.h"

//(*AppHeaders
#include "BodyMasterMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(BodyMasterApp);

bool BodyMasterApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	BodyMasterFrame* Frame = new BodyMasterFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
