
#include <afxwin.h>
#include "resource.h"
#include "seminar.h"

/////////////////////////////////////////////////////////////////////////////
// class MainFrame

IMPLEMENT_DYNAMIC(MainFrame,CMDIFrameWnd)

/////////////////////////////////////////////////////////////////////////////
// class Application

Application _Application;

BOOL Application::InitInstance()
{
  Enable3dControls();

  MainFrame * Frame = new MainFrame;

  if (!Frame->                      (IDR_MAIN_FRAME))
    return FALSE;

  m_pMainWnd = Frame;

  m_pMainWnd->ShowWindow(m_nCmdShow);
  m_pMainWnd->UpdateWindow();
    
  return TRUE;
}
