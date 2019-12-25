
#include <afxwin.h>
#include "processor.h"

/////////////////////////////////////////////////////////////////////////////
// class Processor

Processor::Processor()
{
  _Geometry.RemoveAll();
}

void Processor::Process()
{
  _A = 0.0;
  _Sx = 0.0;
  _Sy = 0.0;
  _Ix = 0.0;
  _Iy = 0.0;
  _Ixy = 0.0;

  Point2D * Point;
  double X,Y,X1,Y1;

  POSITION Position = _Geometry.GetHeadPosition();
  
  if (Position != NULL)
  {
    Point = (Point2D *) _Geometry.GetNext(Position);
    if (Point != NULL)
    {
      X1 = Point->_X - _Xs;
      Y1 = Point->_Y - _Ys;
    }
  }

  while (Position != NULL)
  {
    Point = (Point2D *) _Geometry.GetNext(Position);
    if (Point != NULL)
    {
      X = Point->_X - _Xs;
      Y = Point->_Y - _Ys;
      
      double A = (X1 * Y) - (X * Y1);
      double B = X1 + X;
      double C = Y1 + Y;
      double D = ((X1 * Y) + (X * Y1)) / 2;
      
      _A += A / 2;
      _Sx += (A * C) / 6;
      _Sy += (A * B) / 6;
      _Ix += (A * ((C * C) - (Y1 * Y))) / 12;
      _Iy += (A * ((B * B) - (X1 * X))) / 12;
      _Ixy += (A * ((B * C) - D)) / 12;
      
      X1 = X;
      Y1 = Y;
    }
  }
}

HRESULT Processor::AddNode(double X,double Y)
{
  Point2D * Point = new Point2D;
  Point->_X = X;
  Point->_Y = Y;
  _Geometry.AddTail(Point);
  return S_OK;
}

HRESULT Processor::GetResult(long Name,double * Result)
{
  _Xs = 0;
  _Ys = 0;
  Process();
  if (_A != 0)
  {
    double Sx = _Sx;
    double Sy = _Sy;
    _Xs = _Sy / _A;
    _Ys = _Sx / _A;
    Process();
    _Sx = Sx;
    _Sy = Sy;
  }

  if (_A < 0)
  {
    _A *= -1;
    _Sx *= -1;
    _Sy *= -1;
    _Ix *= -1;
    _Iy *= -1;
    _Ixy *= -1;
  }

  * Result = 0.0;

  if (Name == 0)
    * Result = _A;
  if (Name == 1)
    * Result = _Xs;
  if (Name == 2)
    * Result = _Ys;
  if (Name == 3)
    * Result = _Sx;
  if (Name == 4)
    * Result = _Sy;
  if (Name == 5)
    * Result = _Ix;
  if (Name == 6)
    * Result = _Iy;
  if (Name == 7)
    * Result = _Ixy;

  return S_OK;
}
