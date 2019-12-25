
#ifndef __seminar__
#define __seminar__

/////////////////////////////////////////////////////////////////////////////
// class Document

class Document : public CDocument
{
  DECLARE_DYNCREATE(Document)
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