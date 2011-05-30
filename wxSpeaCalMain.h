/***************************************************************
 * Name:      wxSpeaCalMain.h
 * Purpose:   Defines Application Frame
 * Author:    Aditya Arie Nugraha (arie@aanugraha.web.id)
 * Created:   2011-04-19
 * Copyright: Aditya Arie Nugraha (http://blog.aanugraha.web.id)
 * License:
 **************************************************************/

#ifndef WXSPEACALMAIN_H
#define WXSPEACALMAIN_H

/********************************************************************************/
/** HEADERS *********************************************************************/
/********************************************************************************/

//(*Headers(wxSpeaCalFrame)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

#include <pthread.h>
#include <signal.h>
#include "portaudio.h"
#include <complex.h>
#include <fftw3.h>
#include "xcorr.h"
#include "pa_record.h"
#include <sys/time.h>
#include "floatfann.h"
#include <algorithm>

/********************************************************************************/


/********************************************************************************/
/** CONSTANTS *******************************************************************/
/********************************************************************************/

#define DEBUG_MODE          0

/**  Cek bagian ini dulu!  **/
#define FIRST_MIC_ID        2
#define RECORD_THREADS      4
#define NUM_TDOA            6  // = (RECORD_THREADS)C2 = RECORD_THREADS!/((RECORD_THREADS-2)! * 2!)
#define SAMPLE_RATE         24000
/****************************/

#define COMPUTE_XCORR       1
#define N_SEC_XCORR_WINDOW  0.5 // sec
#define N_SEC_BETWEEN_REC   1000 * N_SEC_XCORR_WINDOW // msec
//#define N_SEC_BETWEEN_REC   0 // msec

#define FRAMES_PER_BUFFER   SAMPLE_RATE * N_SEC_XCORR_WINDOW
#define NUM_CHANNELS        1
#define DITHER_FLAG         0
#define WRITE_TO_FILE       0
#define INF_LOOP            1
#define MAX_ANN_RES_COUNT   1

#define USE_BPF             1
/** Biquad Band-Pass Filter (Fs=24KHz, Fc=1800Hz, Butterworth **/
#define BPF_COEFF_A0        0.24301081704614158
#define BPF_COEFF_A1        0
#define BPF_COEFF_A2        -0.24301081704614158
#define BPF_COEFF_B1        -1.34896460150382
#define BPF_COEFF_B2        0.5139783659077168
/***************************************************************/

#define PA_SAMPLE_TYPE  paFloat32
typedef float SAMPLE;
#define SAMPLE_SILENCE  (0.0f)
#define PRINTF_S_FORMAT "%.8f"

//#define PA_SAMPLE_TYPE      paInt16
//typedef short SAMPLE;
//#define SAMPLE_SILENCE      (0)
//#define PRINTF_S_FORMAT     "%d"

/********************************************************************************/

typedef struct
{
    void*               mainThread;
    PaStreamParameters* inputParameters;
}
PAThreadData;

#ifdef __cplusplus

class wxSpeaCalFrame: public wxFrame
{
    public:

        wxSpeaCalFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxSpeaCalFrame();

        int             TimevalDiff(struct timeval*, struct timeval*, struct timeval*);
        void            RunANN(void);

        short int       pubXcorrReadyFlag[2];       // 0000 0000 0000 0000
        short int       pubBufFileID;
        short int       pubXcorrFileID;
        int             pubMenuNormTDOA;
        int             pubPAStreamRun;
        int             pubFramesPerBuffer;
        double          pubDevXcorrReadyTime[RECORD_THREADS];
        double          pubDevRecordStartTime[RECORD_THREADS];
        double          pubTDOAValue[NUM_TDOA];     // [0] time (xcorr finished) [1...n] TDOAValue
        double          pubNormTDOAValue[NUM_TDOA]; // [0] time (xcorr finished) [1...n] TDOAValue
        double          pubElapsedTime;
        double          pubPeakAmplitude[RECORD_THREADS];
        //double          pubRMSAmplitudeRatio[NUM_TDOA];
        //double          pubNormRMSAmplitudeRatio[NUM_TDOA];
        double          pubPeakAmplitudeRatio[NUM_TDOA];
        double          pubNormPeakAmplitudeRatio[NUM_TDOA];
        struct timeval  pubStartTime;

    private:

        //(*Handlers(wxSpeaCalFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnStartButtonClick(wxCommandEvent& event);
        void OnStopButtonClick(wxCommandEvent& event);
        void OnMenuNormTDOASelected(wxCommandEvent& event);
        void OnMenuEstimateSpeakerPosSelected(wxCommandEvent& event);
        void OnOpenTrainingSetFile(wxCommandEvent& event);
        void OnOpenNeuralNetFile(wxCommandEvent& event);
        //*)

        void OnMenuNormTDOA(wxCommandEvent& event);

        //(*Identifiers(wxSpeaCalFrame)
        static const long ID_STARTBUTTON;
        static const long ID_STOPBUTTON;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT15;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT16;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT17;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT18;
        static const long ID_STATICTEXT9;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT19;
        static const long ID_STATICTEXT10;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT20;
        static const long ID_STATICTEXT13;
        static const long ID_TEXTCTRL7;
        static const long ID_STATICTEXT21;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL8;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL9;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL10;
        static const long ID_PANEL1;
        static const long idMenuOpenNeuralNetFile;
        static const long idMenuQuit;
        static const long idMenuEstimateSpeakerPos;
        static const long idMenuNormTDOA;
        static const long idMenuDelRecOnQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxSpeaCalFrame)
        wxStaticText* StaticText10;
        wxStaticText* StaticText9;
        wxStaticText* StaticText20;
        wxTextCtrl* wxTDOA3Value;
        wxTextCtrl* wxTDOA5Value;
        wxTextCtrl* wxPosYValue;
        wxStaticText* StaticText13;
        wxStaticText* StaticText2;
        wxMenu* Menu3;
        wxStaticText* StaticText6;
        wxButton* StartButton;
        wxTextCtrl* wxPosZValue;
        wxMenuItem* MenuEstimateSpeakerPos;
        wxStaticText* StaticText19;
        wxStaticText* StaticText8;
        wxStaticText* StaticText18;
        wxPanel* Panel1;
        wxTextCtrl* wxTDOA6Value;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxTextCtrl* wxTDOA2Value;
        wxTextCtrl* wxTDOA4Value;
        wxButton* StopButton;
        wxMenuItem* MenuItem3;
        wxTextCtrl* wxElapsedTime;
        wxTextCtrl* wxPosXValue;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxStatusBar* StatusBar1;
        wxMenuItem* MenuNormTDOA;
        wxStaticText* StaticText15;
        wxTextCtrl* wxTDOA1Value;
        wxStaticText* StaticText4;
        wxStaticText* StaticText17;
        wxStaticText* StaticText16;
        wxMenuItem* MenuDelRecOnQuit;
        //*)

        void OnIdle(wxIdleEvent&);
        void OnPAError(void);
        void OnStart(void);
        void StopRunningThread(void);
        void OnOpenNeuralNetFileDialog(void);

        pthread_t           recordThread[RECORD_THREADS];
        pthread_t           tdoaComputeThread;

        PAThreadData        pPARecThreadData[RECORD_THREADS];
        PaError             err;
        int                 i;
        int                 speakerPosValue[3];
        double              recDuration;

        struct fann         *ann;
        wxString            wxstrNeuralNetFile;
        char                chNeuralNetFile[1024];
        fann_type           fann_input[4];
        fann_type           *fann_output;
        int                 annResultCounter;
        int                 annResultTemp[MAX_ANN_RES_COUNT];
        int                 annResult;

        DECLARE_EVENT_TABLE()
};

#else

typedef struct wxSpeaCalFrame wxSpeaCalFrame;

#endif

#ifdef __cplusplus
extern "C" {
#endif

    wxSpeaCalFrame*         TimevalDiff(struct timeval*, struct timeval*,
                                        struct timeval*, wxSpeaCalFrame*);
    wxSpeaCalFrame*         shintPubAttrCheck(int, int, wxSpeaCalFrame*, short int&);
    wxSpeaCalFrame*         shintPubAttrBitToggle(int, int, wxSpeaCalFrame*, int);
    wxSpeaCalFrame*         intPubAttrCheck(int, wxSpeaCalFrame*, int&);
    wxSpeaCalFrame*         doublePubAttrCheck(int, int, wxSpeaCalFrame*, double&);
    wxSpeaCalFrame*         doublePubAttrAssign(int, int, wxSpeaCalFrame*, double);
    wxSpeaCalFrame*         timevalPubStartTimeCheck(wxSpeaCalFrame*, struct timeval&);

#ifdef __cplusplus
}
#endif

#endif // WXSPEACALMAIN_H
