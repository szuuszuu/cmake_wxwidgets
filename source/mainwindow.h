/************************************************************************************//**
* \file         mainwindow.h
* \brief        Application's main window header file.
*
****************************************************************************************/

/****************************************************************************************
* Include files
****************************************************************************************/
#include <wx/wx.h>

/****************************************************************************************
* Class definitions
****************************************************************************************/
/** \brief Application's main window class. */
class MainWindow : public wxFrame
{
public:
  MainWindow(const wxString& title, int width, int height);
};


/*********************************** end of mainwindow.h *******************************/

