#include "ShowQFrame.h"

BEGIN_EVENT_TABLE(ShowQFrame, wxFrame)
    EVT_MENU(ID_Quit, ShowQFrame::OnQuit)
END_EVENT_TABLE()

ShowQFrame::ShowQFrame() 
    : wxFrame(NULL, -1, _("ShowQ"), wxDefaultPosition, wxSize(600,450)) {
    
    wxAuiPaneInfo pinfo;
    pinfo.MinSize(200,100);
    pinfo.Top();
    pinfo.CaptionVisible(false);
    pinfo.PaneBorder(false);
   // pinfo.Fixed();

    m_mgr.SetManagedWindow(this);
    m_mgr.SetFlags(wxAUI_MGR_TRANSPARENT_HINT |
                        wxAUI_MGR_HINT_FADE |
                        wxAUI_MGR_NO_VENETIAN_BLINDS_FADE);
    
    lstCues = new wxListCtrl(this, -1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
    m_mgr.AddPane(lstCues, wxCENTER);
    
    wxBoxSizer* szCueInfo = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* szTop = new wxBoxSizer(wxHORIZONTAL);
    pnTop = new wxPanel(this, -1);
    
    pnTop->SetSizer(szTop);
    lblCueInfo = new wxStaticText(pnTop, -1, _T("Cue 1: xxx"));
    txtCueNotes = new wxTextCtrl(pnTop, -1, _T(""), wxDefaultPosition, wxSize(200,50), wxTE_MULTILINE);
    szCueInfo->Add(lblCueInfo, 0, wxBOTTOM, 5);
    szCueInfo->Add(txtCueNotes, 1, wxEXPAND);
    
    btnGo = new wxButton(pnTop, -1, _T("GO"), wxDefaultPosition, wxSize(120,80));
    szTop->Add(btnGo, 0, wxEXPAND | wxLEFT | wxTOP | wxBOTTOM, 5);
    szTop->Add(szCueInfo, 1, wxEXPAND | wxALL, 5);
    
    m_mgr.AddPane(pnTop, pinfo);
    
    lstCueTypes = new wxListCtrl(this, -1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_NO_HEADER);
    m_mgr.AddPane(lstCueTypes, wxLEFT, _T("Cue Types"));
    updateCueTypes();
    
    pnActiveCues = new wxPanel(this, -1);
    m_mgr.AddPane(pnActiveCues, wxRIGHT, _T("Active Cues"));
    
    pnProperties = new wxPanel(this, -1);
    m_mgr.AddPane(pnProperties, wxBOTTOM, _T("Cue Properties"));
    
    m_mgr.Update();
    
    mnuTop = new wxMenuBar;
    mnuTop->Append(new wxMenu(_T("&New")), _T("&File"));
    this->SetMenuBar(mnuTop);
}

ShowQFrame::~ShowQFrame() {
    m_mgr.UnInit();
}

void ShowQFrame::OnQuit(wxCommandEvent& event)
{

}

void ShowQFrame::updateCueTypes()
{
    wxListItem col0;
    col0.SetId(0);
    col0.SetText(_("Cue Type") );
    col0.SetWidth(wxLIST_AUTOSIZE);
    lstCueTypes->InsertColumn(0, col0);
    
    lstCueTypes->InsertItem(0, _("Memo"));
    lstCueTypes->InsertItem(1, _("Audio"));
    lstCueTypes->InsertItem(2, _("MIDI"));
    lstCueTypes->InsertItem(3, _("OSC"));
}
