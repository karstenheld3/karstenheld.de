
#include <afxwin.h>
#include "resource.h"
#include "seminar.h"

/////////////////////////////////////////////////////////////////////////////
// class Document

IMPLEMENT_DYNCREATE(Document,CDocument)

/////////////////////////////////////////////////////////////////////////////
// class View

IMPLEMENT_DYNCREATE(View,CView)

void View::OnDraw(CDC * DC)
{

}

/////////////////////////////////////////////////////////////////////////////
// class MainFrame

IMPLEMENT_DYNAMIC(MainFrame,CMDIFrameWnd)

/////////////////////////////////////////////////////////////////////////////
// class Application

Application _Application;

BEGIN_MESSAGE_MAP(Application,CWinApp)
  ON_COMMAND(ID_FILE_NEW,CWinApp::OnFileNew)
END_MESSAGE_MAP()

BOOL Application::InitInstance()
{
  Enable3dControls();

  CMultiDocTemplate * DocTemplate;
  DocTemplate = new CMultiDocTemplate(IDR_DOCUMENT,RUNTIME_CLASS(Document),
                                      RUNTIME_CLASS(CMDIChildWnd),
                                      RUNTIME_CLASS(View));
  AddDocTemplate(DocTemplate);

  MainFrame * Frame = new MainFrame;

  if (!Frame->LoadFrame(IDR_MAIN_FRAME))
    return FALSE;

  m_pMainWnd = Frame;

  m_pMainWnd->ShowWindow(m_nCmdShow);
  m_pMainWnd->UpdateWindow();
    
  return TRUE;
}
