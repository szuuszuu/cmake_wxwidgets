/************************************************************************************//**
* \file         mainwindow.h
* \brief        Application's main window header file.
*
****************************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
private:
  wxPanel * m_Panel;  
};

#endif /* MAINWINDOW_H */
/*********************************** end of mainwindow.h *******************************/

