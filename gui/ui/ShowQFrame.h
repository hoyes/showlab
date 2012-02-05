#ifndef SHOWQ_FRAME_H
#define SHOWQ_FRAME_H

#include "wx/wx.h"
#include "wx/aui/aui.h"

class ShowQFrame : public wxFrame
{
public:
    ShowQFrame();
    ~ShowQFrame();
    
    void OnQuit(wxCommandEvent& event);
    
    void updateCueTypes();

private:
        
    wxAuiManager m_mgr;
    DECLARE_EVENT_TABLE()
    
    wxButton* btnGo;
    wxListCtrl* lstCues;
    wxListCtrl* lstCueTypes;
    wxPanel* pnCueInfo;
    wxPanel* pnTop;
    wxStaticText* lblCueInfo;
    wxTextCtrl* txtCueNotes;
    
    wxPanel* pnActiveCues;
    
    wxPanel* pnProperties;
    
    wxMenuBar* mnuTop;
    wxToolBar* toolbar;
};

enum
{
    ID_Quit = 1
};

#endif
