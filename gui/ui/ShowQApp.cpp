#include "ShowQApp.h"
#include "ShowQFrame.h"

bool ShowQApp::OnInit()
{
    ShowQFrame* frame = new ShowQFrame;
    frame->Show(true);
    SetTopWindow(frame);
    return true;
}
