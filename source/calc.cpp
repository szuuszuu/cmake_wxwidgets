#include "calc.h"
#include "MainFrame.h"
#include <wx/wx.h>

IMPLEMENT_APP(calc)

bool calc::OnInit() {
    MainFrame *mainFrame = new MainFrame("Calc GUI", 300, 300);
    mainFrame->Show(true);

    return true;
}