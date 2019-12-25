
#ifndef __processor__
#define __processor__

/////////////////////////////////////////////////////////////////////////////
// class Point2D

class Point2D : public CObject
{
  public:
  double _X;
  double _Y;
};

/////////////////////////////////////////////////////////////////////////////
// class Processor

class Processor : 
  public IDispatchImpl<IProcessor,& IID_IProcessor,& LIBID_Processor>; ,
  public CComObjectRoot , public CComCoClass<Processor,& CLSID_Processor>
{
  BEGIN_COM_MAP(Processor)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(IProcessor)
  END_COM_MAP()

  DECLARE_NOT_AGGREGATABLE(Processor)

  DECLARE_REGISTRY(Processor,"Processor.Object","Processor.Object",
                   IDS_PROCESSOR_DESCRIPTION,THREADFLAGS_APARTMENT)

  // Processor members
  private:
  CObList _Geometry; 
  double _Xs,_Ys,_A,_Sx,_Sy,_Ix,_Iy,_Ixy;

  public:
  Processor();
  void Process();

  // IProcessor members
  public:
  HRESULT __stdcall AddNode(double X,double Y);
  HRESULT __stdcall GetResult(long Name,double * Result);
};

#endif
