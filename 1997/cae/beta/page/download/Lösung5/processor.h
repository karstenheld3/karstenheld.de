
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

class Processor
{
  private:
  CObList _Geometry; 
  double _Xs,_Ys,_A,_Sx,_Sy,_Ix,_Iy,_Ixy;

  public:
  Processor();
  void Process();

  public:
  HRESULT AddNode(double X,double Y);
  HRESULT GetResult(long Name,double * Result);
};

#endif
