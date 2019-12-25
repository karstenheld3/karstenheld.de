
#include <afxwin.h>
#include "resource.h"
#include "seminar.h"

/////////////////////////////////////////////////////////////////////////////
// class CreateDlg

CreateDlg::CreateDlg() : CDialog(CreateDlg::IDD)
{
  _X = 0;
  _Y = 0;
}

void CreateDlg::DoDataExchange(CDataExchange * DX)
{
  CDialog::DoDataExchange(DX);
  DDX_Text(DX,IDC_X,_X);
  DDX_Text(DX,IDC_Y,_Y);
}

double CreateDlg::GetX()
{
  return _X;
}

double CreateDlg::GetY()
{
  return _Y;
}

/////////////////////////////////////////////////////////////////////////////
// class Document

IMPLEMENT_DYNCREATE(Document,CDocument)

BEGIN_MESSAGE_MAP(Document,CDocument)
  ON_COMMAND(IDM_CREATE,OnCreateDlg)
END_MESSAGE_MAP()

void Document::OnCreateDlg()
{
  CreateDlg Dialog;
  Point2D * Point;
  int Result;

  _Geometry.RemoveAll();
  
  do
  {
    Result = Dialog.DoModal();
    if (Result == IDOK)
    {
      Point = new Point2D;
      Point->_X = Dialog.GetX();
      Point->_Y = Dialog.GetY();
      _Geometry.AddTail(Point);
    }
  }
  while (Result == IDOK);
}

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
