

#ifndef __seminar__
#define __seminar__

/////////////////////////////////////////////////////////////////////////////
// class Point2D

class Point2D : public CObject
{
  public:
  double _X;
  double _Y;
};

/////////////////////////////////////////////////////////////////////////////
// class CreateDlg

class CreateDlg : public CDialog
{
  enum { IDD = IDD_CREATE };

  private:
  double _X;
  double _Y;

  public:
  CreateDlg();
  virtual void DoDataExchange(CDataExchange * DX);
  double GetX();
  double GetY();
};

/////////////////////////////////////////////////////////////////////////////
// class Document

class Document : public CDocument
{
  DECLARE_DYNCREATE(Document)
  DECLARE_MESSAGE_MAP()

  private:
  CObList _Geometry;
  double _Results[8];

  public:
  void OnCreateDlg();
  CObList * GetGeometryList();
  double * GetResults();
};

/////////////////////////////////////////////////////////////////////////////
// class View

class View : public CView
{
  DECLARE_DYNCREATE(View)

  protected:
  virtual void OnDraw(CDC * DC);
};

/////////////////////////////////////////////////////////////////////////////
// class MainFrame

class MainFrame : public CMDIFrameWnd
{
  DECLARE_DYNAMIC(MainFrame)
};

/////////////////////////////////////////////////////////////////////////////
// class Application

class Application : public CWinApp
{
  DECLARE_MESSAGE_MAP()

  public:
  virtual BOOL InitInstance();
};

#endif
