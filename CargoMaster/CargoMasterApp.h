/***************************************************************
 * Name:      CargoMasterApp.h
 * Purpose:   Defines Application Class
 * Author:    Vilis Erglis (vilis@taksis.org)
 * Created:   2019-05-07
 * Copyright: Vilis Erglis ()
 * License:   GNU General Public License v3.0
 **************************************************************/

#ifndef CARGOMASTERAPP_H
#define CARGOMASTERAPP_H

#include <wx/app.h>

class CargoMasterApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // CARGOMASTERAPP_H
