
#ifndef __seminar__
#define __seminar__

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
  public:
  virtual BOOL InitInstance();
};

#endif