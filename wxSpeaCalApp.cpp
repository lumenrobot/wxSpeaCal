/***************************************************************
 * Name:      wxSpeaCalApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Aditya Arie Nugraha (arie@aanugraha.web.id)
 * Created:   2011-04-19
 * Copyright: Aditya Arie Nugraha (http://blog.aanugraha.web.id)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxSpeaCalApp.h"

//(*AppHeaders
#include "wxSpeaCalMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxSpeaCalApp);

bool wxSpeaCalApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxSpeaCalFrame* Frame = new wxSpeaCalFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
