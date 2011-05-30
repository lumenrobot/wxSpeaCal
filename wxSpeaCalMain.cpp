/***************************************************************
 * Name:      wxSpeaCalMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Aditya Arie Nugraha (arie@aanugraha.web.id)
 * Created:   2011-04-19
 * Copyright: Aditya Arie Nugraha (http://blog.aanugraha.web.id)
 * License:
 **************************************************************/

#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include "wx_pch.h"
#include "wxSpeaCalMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxSpeaCalFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxSpeaCalFrame)
const long wxSpeaCalFrame::ID_STARTBUTTON = wxNewId();
const long wxSpeaCalFrame::ID_STOPBUTTON = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT1 = wxNewId();
const long wxSpeaCalFrame::ID_TEXTCTRL1 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT15 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT3 = wxNewId();
const long wxSpeaCalFrame::ID_TEXTCTRL2 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT16 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT5 = wxNewId();
const long wxSpeaCalFrame::ID_TEXTCTRL3 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT17 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT7 = wxNewId();
const long wxSpeaCalFrame::ID_TEXTCTRL4 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT18 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT9 = wxNewId();
const long wxSpeaCalFrame::ID_TEXTCTRL5 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT19 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT10 = wxNewId();
const long wxSpeaCalFrame::ID_TEXTCTRL6 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT20 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT13 = wxNewId();
const long wxSpeaCalFrame::ID_TEXTCTRL7 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT21 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT2 = wxNewId();
const long wxSpeaCalFrame::ID_TEXTCTRL8 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT4 = wxNewId();
const long wxSpeaCalFrame::ID_TEXTCTRL9 = wxNewId();
const long wxSpeaCalFrame::ID_STATICTEXT6 = wxNewId();
const long wxSpeaCalFrame::ID_TEXTCTRL10 = wxNewId();
const long wxSpeaCalFrame::ID_PANEL1 = wxNewId();
const long wxSpeaCalFrame::idMenuOpenNeuralNetFile = wxNewId();
const long wxSpeaCalFrame::idMenuQuit = wxNewId();
const long wxSpeaCalFrame::idMenuEstimateSpeakerPos = wxNewId();
const long wxSpeaCalFrame::idMenuNormTDOA = wxNewId();
const long wxSpeaCalFrame::idMenuDelRecOnQuit = wxNewId();
const long wxSpeaCalFrame::idMenuAbout = wxNewId();
const long wxSpeaCalFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxSpeaCalFrame,wxFrame)
    //(*EventTable(wxSpeaCalFrame)
    //*)
END_EVENT_TABLE()

wxSpeaCalFrame::wxSpeaCalFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxSpeaCalFrame)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("wxSpeaCal (Run)"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Control"));
    StartButton = new wxButton(Panel1, ID_STARTBUTTON, _("Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_STARTBUTTON"));
    StaticBoxSizer1->Add(StartButton, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StopButton = new wxButton(Panel1, ID_STOPBUTTON, _("Stop"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_STOPBUTTON"));
    StaticBoxSizer1->Add(StopButton, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Time Difference of Arrival (TDOA)"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 6, 0, 0);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("PtPAR12"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 10);
    wxTDOA1Value = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(80,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer1->Add(wxTDOA1Value, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText15 = new wxStaticText(Panel1, ID_STATICTEXT15, _("dB"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    FlexGridSizer1->Add(StaticText15, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("PtPAR13"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer1->Add(StaticText3, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 10);
    wxTDOA2Value = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(80,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer1->Add(wxTDOA2Value, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText16 = new wxStaticText(Panel1, ID_STATICTEXT16, _("dB"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    FlexGridSizer1->Add(StaticText16, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("PtPAR14"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer1->Add(StaticText5, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 10);
    wxTDOA3Value = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(80,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer1->Add(wxTDOA3Value, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText17 = new wxStaticText(Panel1, ID_STATICTEXT17, _("dB"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    FlexGridSizer1->Add(StaticText17, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("PtPAR23"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer1->Add(StaticText7, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 10);
    wxTDOA4Value = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(80,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer1->Add(wxTDOA4Value, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText18 = new wxStaticText(Panel1, ID_STATICTEXT18, _("dB"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    FlexGridSizer1->Add(StaticText18, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _("PtPAR24"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    FlexGridSizer1->Add(StaticText9, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 10);
    wxTDOA5Value = new wxTextCtrl(Panel1, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(80,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    FlexGridSizer1->Add(wxTDOA5Value, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText19 = new wxStaticText(Panel1, ID_STATICTEXT19, _("dB"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    FlexGridSizer1->Add(StaticText19, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("PtPAR34"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer1->Add(StaticText10, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 10);
    wxTDOA6Value = new wxTextCtrl(Panel1, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(80,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    FlexGridSizer1->Add(wxTDOA6Value, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText20 = new wxStaticText(Panel1, ID_STATICTEXT20, _("dB"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    FlexGridSizer1->Add(StaticText20, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    StaticText13 = new wxStaticText(Panel1, ID_STATICTEXT13, _("Time"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    FlexGridSizer1->Add(StaticText13, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 10);
    wxElapsedTime = new wxTextCtrl(Panel1, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxSize(80,-1), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    FlexGridSizer1->Add(wxElapsedTime, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT21, _("sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer2->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Speaker Position Estimation"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 6, 0, 0);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT2, _("X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer2->Add(StaticText4, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 16);
    wxPosXValue = new wxTextCtrl(Panel1, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    FlexGridSizer2->Add(wxPosXValue, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer2->Add(StaticText6, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 16);
    wxPosYValue = new wxTextCtrl(Panel1, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    FlexGridSizer2->Add(wxPosYValue, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Z"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer2->Add(StaticText8, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 16);
    wxPosZValue = new wxTextCtrl(Panel1, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    FlexGridSizer2->Add(wxPosZValue, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuOpenNeuralNetFile, _("Open Neural Network File"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuEstimateSpeakerPos = new wxMenuItem(Menu3, idMenuEstimateSpeakerPos, _("Estimate Speaker Position"), wxEmptyString, wxITEM_CHECK);
    Menu3->Append(MenuEstimateSpeakerPos);
    MenuNormTDOA = new wxMenuItem(Menu3, idMenuNormTDOA, _("Normalize TDOA"), wxEmptyString, wxITEM_CHECK);
    Menu3->Append(MenuNormTDOA);
    MenuDelRecOnQuit = new wxMenuItem(Menu3, idMenuDelRecOnQuit, _("Delete Recording Buffer On Exit"), wxEmptyString, wxITEM_CHECK);
    Menu3->Append(MenuDelRecOnQuit);
    MenuBar1->Append(Menu3, _("&Options"));
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
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_STARTBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxSpeaCalFrame::OnStartButtonClick);
    Connect(ID_STOPBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxSpeaCalFrame::OnStopButtonClick);
    Connect(idMenuOpenNeuralNetFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSpeaCalFrame::OnOpenNeuralNetFile);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSpeaCalFrame::OnQuit);
    Connect(idMenuEstimateSpeakerPos,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSpeaCalFrame::OnMenuEstimateSpeakerPosSelected);
    Connect(idMenuNormTDOA,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSpeaCalFrame::OnMenuNormTDOASelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSpeaCalFrame::OnAbout);
    //*)

    for(i=0; i<3; i++)
    {
        speakerPosValue[i] = 0;
    }
    wxPosXValue->ChangeValue(wxString::Format(wxT("%d"), speakerPosValue[0]));
    wxPosYValue->ChangeValue(wxString::Format(wxT("%d"), speakerPosValue[1]));
    wxPosZValue->ChangeValue(wxString::Format(wxT("%d"), speakerPosValue[2]));

    recDuration = N_SEC_XCORR_WINDOW;
    //wxRecDuration->ChangeValue(wxString::Format(wxT("%.1f"), recDuration));

    MenuNormTDOA->Check(TRUE);
    MenuDelRecOnQuit->Check(TRUE);
    wxstrNeuralNetFile.Empty();

    pubPAStreamRun = 0;
    Connect(wxID_ANY, wxEVT_IDLE, wxIdleEventHandler(wxSpeaCalFrame::OnIdle));
}

wxSpeaCalFrame::~wxSpeaCalFrame()
{
    //(*Destroy(wxSpeaCalFrame)
    //*)
}

void wxSpeaCalFrame::OnQuit(wxCommandEvent& event)
{
    char    filename[32];
    int     i, j;

    if(MenuDelRecOnQuit->IsChecked())
    {
        for(i=FIRST_MIC_ID; i<FIRST_MIC_ID+RECORD_THREADS; i++)
        {
            for(j=0; j<2; j++)
            {
                sprintf(filename,"dev-%d-buf-rec-%d.raw", i, j);
                remove(filename);
            }
        }
    }

    Close();
}

void wxSpeaCalFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("wxSpeaCal (Run)\n\nAditya Arie Nugraha\narie@aanugraha.web.id"));
    wxMessageBox(msg, _("About"));
}

void wxSpeaCalFrame::OnMenuNormTDOASelected(wxCommandEvent& event)
{
    pubMenuNormTDOA = MenuNormTDOA->IsChecked();
}

void wxSpeaCalFrame::OnStartButtonClick(wxCommandEvent& event)
{
    OnStart();
}

void wxSpeaCalFrame::OnStart(void)
{
    //wxRecDuration->GetValue().ToDouble(&recDuration);
    pubFramesPerBuffer = SAMPLE_RATE * recDuration;

    if (!pubPAStreamRun)
    {
        gettimeofday(&pubStartTime, NULL);

        err = paNoError;

        err = Pa_Initialize();
        if(err != paNoError) OnPAError();

        for(i=0; i<RECORD_THREADS; i++)
        {
            pPARecThreadData[i].mainThread = this;
            pPARecThreadData[i].inputParameters = (PaStreamParameters *) malloc(sizeof(PaStreamParameters));
            pPARecThreadData[i].inputParameters->device = FIRST_MIC_ID+i;
            if (pPARecThreadData[i].inputParameters->device == paNoDevice)
            {
                fprintf(stderr,"Error: Specified input device unavailable.\n");
                OnPAError();
            }
            else
            {
                printf("inputParameters[%d] device = %s\n",
                       i, Pa_GetDeviceInfo(pPARecThreadData[i].inputParameters->device)->name);
                pPARecThreadData[i].inputParameters->channelCount = NUM_CHANNELS;
                pPARecThreadData[i].inputParameters->sampleFormat = PA_SAMPLE_TYPE;
                pPARecThreadData[i].inputParameters->suggestedLatency = Pa_GetDeviceInfo(pPARecThreadData[i].inputParameters->device)->defaultLowInputLatency;
                pPARecThreadData[i].inputParameters->hostApiSpecificStreamInfo = NULL;
            }
        }

        for(i=0; i<NUM_TDOA; i++)
        {
            pubTDOAValue[i] = 0;
            pubNormTDOAValue[i] = 0;
        }
        pubElapsedTime       = 0;
        pubBufFileID         = 0;
        pubXcorrFileID       = 0;
        pubXcorrReadyFlag[0] = 0;
        pubXcorrReadyFlag[1] = 0;
        pubMenuNormTDOA      = MenuNormTDOA->IsChecked();

        pthread_create(&tdoaComputeThread, NULL, xcorr_thread, (void *) this);

        pubPAStreamRun       = 1;
        annResultCounter     = 0;

        for(i=0; i<RECORD_THREADS; i++)
        {
            pubPeakAmplitude[i] = 0;
            pthread_create(&recordThread[i], NULL, pa_record_thread, (void *) &pPARecThreadData[i]);
        }
    }
}

void wxSpeaCalFrame::OnStopButtonClick(wxCommandEvent& event)
{
    StopRunningThread();
}

void wxSpeaCalFrame::OnIdle(wxIdleEvent& evt)
{
    usleep(200000); // .2 sec; rate = 5fps

    if(pubPAStreamRun)
    {
        if(pubMenuNormTDOA)
        {
            /*wxTDOA1Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormTDOAValue[0]));
            wxTDOA2Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormTDOAValue[1]));
            wxTDOA3Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormTDOAValue[2]));
            wxTDOA4Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormTDOAValue[3]));
            wxTDOA5Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormTDOAValue[4]));
            wxTDOA6Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormTDOAValue[5]));*/
            wxTDOA1Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormPeakAmplitudeRatio[0]));
            wxTDOA2Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormPeakAmplitudeRatio[1]));
            wxTDOA3Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormPeakAmplitudeRatio[2]));
            wxTDOA4Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormPeakAmplitudeRatio[3]));
            wxTDOA5Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormPeakAmplitudeRatio[4]));
            wxTDOA6Value->ChangeValue(wxString::Format(wxT("%.3f"), pubNormPeakAmplitudeRatio[5]));
        }
        else
        {
            wxTDOA1Value->ChangeValue(wxString::Format(wxT("%.3f"), pubTDOAValue[0]));
            wxTDOA2Value->ChangeValue(wxString::Format(wxT("%.3f"), pubTDOAValue[1]));
            wxTDOA3Value->ChangeValue(wxString::Format(wxT("%.3f"), pubTDOAValue[2]));
            wxTDOA4Value->ChangeValue(wxString::Format(wxT("%.3f"), pubTDOAValue[3]));
            wxTDOA5Value->ChangeValue(wxString::Format(wxT("%.3f"), pubTDOAValue[4]));
            wxTDOA6Value->ChangeValue(wxString::Format(wxT("%.3f"), pubTDOAValue[5]));
        }

        wxElapsedTime->ChangeValue(wxString::Format(wxT("%.3f"), pubElapsedTime));
        wxPosXValue->ChangeValue(wxString::Format(wxT("%d"), speakerPosValue[0]));
        wxPosYValue->ChangeValue(wxString::Format(wxT("%d"), speakerPosValue[1]));
        wxPosZValue->ChangeValue(wxString::Format(wxT("%d"), speakerPosValue[2]));

        evt.RequestMore(); // render continuously, not only once on idle
    }
}

void wxSpeaCalFrame::OnPAError(void)
{
    StopRunningThread();
}

void wxSpeaCalFrame::StopRunningThread(void)
{
    if(pubPAStreamRun)
    {
        pubPAStreamRun = 0;
        for(i=0; i<RECORD_THREADS; i++)
        {
            if (recordThread[i])
                pthread_join(recordThread[i], NULL);
            free(pPARecThreadData[i].inputParameters);
        }
        Pa_Terminate();
        if (tdoaComputeThread)
            pthread_cancel(tdoaComputeThread);
    }
}

int wxSpeaCalFrame::TimevalDiff (struct timeval *result, struct timeval *x, struct timeval *y)
{
    // Perform the carry for the later subtraction by updating y.
    if(x->tv_usec < y->tv_usec)
    {
        int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
        y->tv_usec -= 1000000 * nsec;
        y->tv_sec += nsec;
    }
    if(x->tv_usec - y->tv_usec > 1000000)
    {
        int nsec = (x->tv_usec - y->tv_usec) / 1000000;
        y->tv_usec += 1000000 * nsec;
        y->tv_sec -= nsec;
    }

    // Compute the time remaining to wait. tv_usec is certainly positive.
    result->tv_sec = x->tv_sec - y->tv_sec;
    result->tv_usec = x->tv_usec - y->tv_usec;

    // Return 1 if result is negative.
    return x->tv_sec < y->tv_sec;
}

wxSpeaCalFrame* TimevalDiff(struct timeval *result, struct timeval *x,
                            struct timeval *y, wxSpeaCalFrame* wxSpeaCal)
{
    wxSpeaCal->TimevalDiff(result, x, y);

    return wxSpeaCal;
}

wxSpeaCalFrame* shintPubAttrCheck(int index, int arrayIndex, wxSpeaCalFrame* wxSpeaCal, short int& result)
{
    // Index:
    //  0 = pubXcorrReadyFlag
    //  1 = pubBufFileID
    //  2 = pubXcorrFileID

    switch(index)
    {
        case 0:
            result = wxSpeaCal->pubXcorrReadyFlag[arrayIndex];
            break;
        case 1:
            result = wxSpeaCal->pubBufFileID;
            break;
        case 2:
            result = wxSpeaCal->pubXcorrFileID;
            break;
        default:
            break;
    }

    return wxSpeaCal;
}

wxSpeaCalFrame* shintPubAttrBitToggle(int index, int arrayIndex, wxSpeaCalFrame* wxSpeaCal, int bitNum)
{
    // Index:
    //  0 = pubXcorrReadyFlag
    //  1 = pubBufFileID
    //  2 = pubXcorrFileID

    switch(index)
    {
        case 0:
            wxSpeaCal->pubXcorrReadyFlag[arrayIndex] ^= 1 << bitNum;
            break;
        case 1:
            wxSpeaCal->pubBufFileID ^= 1 << bitNum;
            break;
        case 2:
            wxSpeaCal->pubXcorrFileID ^= 1 << bitNum;
            wxSpeaCal->RunANN();
            break;
        default:
            break;
    }

    return wxSpeaCal;
}

wxSpeaCalFrame* intPubAttrCheck(int index, wxSpeaCalFrame* wxSpeaCal, int& result)
{
    // Index:
    //  0 = pubMenuNormTDOA
    //  1 = pubPAStreamRun
    //  6 = pubFramesPerBuffer

    switch(index)
    {
        case 0:
            result = wxSpeaCal->pubMenuNormTDOA;
            break;
        case 1:
            result = wxSpeaCal->pubPAStreamRun;
            break;
        case 6:
            result = wxSpeaCal->pubFramesPerBuffer;
            break;
        default:
            break;
    }

    return wxSpeaCal;
}

wxSpeaCalFrame* doublePubAttrCheck(int index, int arrayIndex, wxSpeaCalFrame* wxSpeaCal, double& result)
{
    // Index:
    //  3 = pubDevXcorrReadyTime
    // 11 = pubDevRecordStartTime

    switch(index)
    {
        case 3:
            result = wxSpeaCal->pubDevXcorrReadyTime[arrayIndex];
            break;
        case 8:
            result = wxSpeaCal->pubPeakAmplitude[arrayIndex];
            break;
        case 11:
            result = wxSpeaCal->pubDevRecordStartTime[arrayIndex];
            break;
        default:
            break;
    }

    return wxSpeaCal;
}

wxSpeaCalFrame* doublePubAttrAssign(int index, int arrayIndex, wxSpeaCalFrame* wxSpeaCal, double value)
{
    // Index:
    //  0 = pubXcorrReadyFlag
    //  3 = pubDevXcorrReadyTime
    //  4 = pubTDOAValue
    //  5 = pubElapsedTime
    //  7 = pubNormTDOAValue
    //  8 = pubAbsAmplitudeMean
    //  9 = pubRMSAmplitudeRatio
    // 10 = pubNormRMSAmplitudeRatio
    // 11 = pubDevRecordStartTime
    // 12 = pubPeakAmplitudeRatio
    // 13 = pubNormPeakAmplitudeRatio

    switch(index)
    {
        case 0:
            wxSpeaCal->pubXcorrReadyFlag[arrayIndex] = (short int) value;
            break;
        case 3:
            wxSpeaCal->pubDevXcorrReadyTime[arrayIndex] = value;
            break;
        case 4:
            wxSpeaCal->pubTDOAValue[arrayIndex] = value;
            break;
        case 5:
            wxSpeaCal->pubElapsedTime = value;
            break;
        case 7:
            wxSpeaCal->pubNormTDOAValue[arrayIndex] = value;
            break;
        case 8:
            wxSpeaCal->pubPeakAmplitude[arrayIndex] = value;
            break;
        //case 9:
        //    wxSpeaCal->pubRMSAmplitudeRatio[arrayIndex] = value;
        //    break;
        //case 10:
        //    wxSpeaCal->pubNormRMSAmplitudeRatio[arrayIndex] = value;
        //    break;
        case 11:
            wxSpeaCal->pubDevRecordStartTime[arrayIndex] = value;
            break;
        case 12:
            wxSpeaCal->pubPeakAmplitudeRatio[arrayIndex] = value;
            break;
        case 13:
            wxSpeaCal->pubNormPeakAmplitudeRatio[arrayIndex] = value;
            break;
        default:
            break;
    }

    return wxSpeaCal;
}

wxSpeaCalFrame* timevalPubStartTimeCheck(wxSpeaCalFrame* wxSpeaCal, struct timeval& result)
{
    result = wxSpeaCal->pubStartTime;

    return wxSpeaCal;
}

void wxSpeaCalFrame::OnMenuEstimateSpeakerPosSelected(wxCommandEvent& event)
{
    if(MenuEstimateSpeakerPos->IsChecked())
    {
        if(wxstrNeuralNetFile.IsEmpty())
            OnOpenNeuralNetFileDialog();
    }
}

void wxSpeaCalFrame::OnOpenNeuralNetFile(wxCommandEvent& event)
{
    OnOpenNeuralNetFileDialog();
}

void wxSpeaCalFrame::OnOpenNeuralNetFileDialog(void)
{
    wxFileDialog* createFileDialog =
		new wxFileDialog( this, _("Open Neural Network File"),
                   wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr,
                   wxFD_OPEN, wxDefaultPosition);

	if (createFileDialog->ShowModal() == wxID_OK)
	{
        wxstrNeuralNetFile = createFileDialog->GetPath();
        strncpy(chNeuralNetFile, (const char*) wxstrNeuralNetFile.ToUTF8(), 1023);
        ann = fann_create_from_file(chNeuralNetFile);
        MenuEstimateSpeakerPos->Check(TRUE);
    }
    else
    {
        MenuEstimateSpeakerPos->Check(FALSE);
    }
}

void wxSpeaCalFrame::RunANN(void)
{
    double  threshold = 0.2;
    int     checker = 0;

    if(MenuEstimateSpeakerPos->IsChecked())
    {
        for (i=0; i<RECORD_THREADS; i++)
        {
            if (pubPeakAmplitude[i] >= threshold)
            {
                checker = 1;
                break;
            }
        }

        if (checker)
        {
            for (i=1; i<5; i++)
            {
                if(pubMenuNormTDOA)
                {
                    //fann_input[i] = pubNormTDOAValue[i];
                    fann_input[i-1] = 20*log10(pubNormPeakAmplitudeRatio[i]);
                }
                else
                {
                    //fann_input[i] = pubTDOAValue[i];
                    fann_input[i-1] = 20*log10(pubPeakAmplitudeRatio[i]);
                }
            }

            /*for (i=0; i<4; i++)
            {
                fprintf(stdout, "fann_input[%d] = %.3f\n", i, fann_input[i]);
            }*/

            fann_output = fann_run(ann, fann_input);
            //fprintf(stdout, "speakerPosValue => Region %.0f\n", *fann_output++);

            annResultTemp[annResultCounter] = *fann_output++;
            //fprintf(stdout, "speakerPosValue Candidate => Region %d\n", annResultTemp[annResultCounter]);
            annResultCounter++;
            if (annResultCounter == MAX_ANN_RES_COUNT)
            {
                if (MAX_ANN_RES_COUNT > 2)
                {
                    std::sort(annResultTemp, annResultTemp + MAX_ANN_RES_COUNT);
                    annResult = annResultTemp[MAX_ANN_RES_COUNT/2];
                }
                else if (MAX_ANN_RES_COUNT == 2)
                {
                    annResult = (annResultTemp[0] + annResultTemp[1])/2;
                }
                else
                    annResult = annResultTemp[0];

                fprintf(stdout, "speakerPosValue => Region %d\n", annResult);

                speakerPosValue[0] = annResult * 60 + 70;
                speakerPosValue[1] = 120;
                speakerPosValue[2] = -30;

                try
                {
                    boost::asio::io_service io_service;

                    boost::asio::ip::tcp::resolver resolver(io_service);
                    boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(),
                                                                "167.205.56.139", "1234");
                    boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
                    boost::asio::ip::tcp::resolver::iterator end;

                    boost::asio::ip::tcp::socket socket(io_service);
                    boost::system::error_code error = boost::asio::error::host_not_found;
                    while (error && endpoint_iterator != end)
                    {
                        socket.close();
                        socket.connect(*endpoint_iterator++, error);
                    }
                    if (error)
                        throw boost::system::system_error(error);

                    //char pos_info[64];
                    //sprintf(pos_info, "a | %d | %d | %d\r\n",
                    //        speakerPosValue[0], speakerPosValue[1], speakerPosValue[2]);

                    std::string pos_info;
                    std::string pos_data_start ("a");
                    std::string pos_data_separator ("|");

                    pos_info.clear();
                    pos_info = pos_data_start;
                    pos_info += pos_data_separator;
                    pos_info += boost::lexical_cast<std::string>(speakerPosValue[2]);
                    pos_info += pos_data_separator;
                    pos_info += boost::lexical_cast<std::string>(speakerPosValue[1]);
                    pos_info += pos_data_separator;
                    pos_info += boost::lexical_cast<std::string>(speakerPosValue[0]);
                    pos_info += pos_data_separator;
                    //pos_info += '\n';

                    try {
                        boost::asio::write(socket, boost::asio::buffer( pos_info ));
                        std::cout << pos_info << std::endl;
                    }
                    catch( std::exception e ) {
                        throw std::runtime_error("message send error | " + std::string( e.what() ) );
                    }
                }
                catch (std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                }

                annResultCounter = 0;
            }
        }
    }
}
