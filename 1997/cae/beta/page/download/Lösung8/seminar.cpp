
#include <afxwin.h>
#include <afxdisp.h>
#include "resource.h"
#include "interface.h"
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
    UpdateAllViews(NULL);
  }
  while (Result == IDOK);
}

CObList * Document::GetGeometryList()
{
  return (& _Geometry);
}

double * Document::GetResults()
{
  IClassFactory * ClassFactory;
  IProcessor * Processor;

  if (FAILED(CoGetClassObject(CLSID_Processor,CLSCTX_SERVER,
                              NULL,IID_IClassFactory,
                              (void **) & ClassFactory)))
  {
    AfxMessageBox("Could not find processor component.");
    return NULL;
  }
  
  if (FAILED(ClassFactory->CreateInstance(NULL,IID_IProcessor,
                                          (void **) & Processor)))
    return NULL;

  POSITION Position = _Geometry.GetHeadPosition();
  while (Position != NULL)
  {
    Point2D * Point = (Point2D *) _Geometry.GetNext(Position);
    if (Point != NULL)
      Processor->AddNode(Point->_X,Point->_Y);
  }

  for (int i = 0; i <= 7; i++)
    Processor->GetResult(i,& _Results[i]);

  Processor->Release();
  ClassFactory->Release();

  return ((double *) & _Results);
}

/////////////////////////////////////////////////////////////////////////////
// class View

IMPLEMENT_DYNCREATE(View,CView)

void View::OnDraw(CDC * DC)
{
  CObList * Geometry = ((Document *) m_pDocument)->GetGeometryList();

  double minX = 0;
  double maxX = 0;
  double minY = 0;
  double maxY = 0;

  POSITION Position;
  Point2D * Point;

  Position = Geometry->GetHeadPosition();
  while (Position != NULL)
  {
    Point = (Point2D *) Geometry->GetNext(Position);
    if (Point != NULL)
    {
       if (Point->_X < minX)
         minX = Point->_X;
       if (Point->_X > maxX)
         maxX = Point->_X;
       if (Point->_Y < minY)
         minY = Point->_Y;
       if (Point->_Y > maxY)
         maxY = Point->_Y;
    }
  }

  DC->SetBkMode(TRANSPARENT);

  CRect Rect;
  GetClientRect(& Rect);
  int BorderX = (int) (Rect.Width() * 0.2);
  int BorderY = (int) (Rect.Height() * 0.2);
  int SizeX = (int) (Rect.Width() - (2 * BorderX));
  int SizeY = (int) (Rect.Height() - (2 * BorderY));

  double * Results = ((Document *) m_pDocument)->GetResults();

  double ScaleX = SizeX / (maxX - minX);
  double ScaleY = SizeY / (maxY - minY);
  int ZeroX = (int) (- minX * ScaleX) + BorderX;
  int ZeroY = (int) (- minY * ScaleY) + BorderY;

  CPen NewPen(PS_SOLID,2,RGB(0,0,0));
  CPen * OldPen = DC->SelectObject(& NewPen);

  Position = Geometry->GetHeadPosition();
  if (Position != NULL)
  {
    Point = (Point2D *) Geometry->GetNext(Position);
    if (Point != NULL)
      DC->MoveTo(((int) (Point->_X * ScaleX)) + ZeroX,
                 Rect.Height() - (((int) (Point->_Y * ScaleY)) + ZeroY));
  }

  while (Position != NULL)
  {
    Point = (Point2D *) Geometry->GetNext(Position);
    if (Point != NULL)
      DC->LineTo(((int) (Point->_X * ScaleX)) + ZeroX,
                 Rect.Height() - (((int) (Point->_Y * ScaleY)) + ZeroY));
  }

  DC->SelectObject(OldPen);
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
  if (!AfxOleInit())
    return FALSE;

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
