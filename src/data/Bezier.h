#pragma once
#ifndef INCLUDED_BEZIER_H
#define INCLUDED_BEZIER_H
#include "Geometry.h"
#include <vector>
#include "Point.h"

class Bezier : public Geometry
{
	Point p3;
public:
   ~Bezier() {}
   Bezier() {}
	Bezier(const Point& _p1, const Point& _p2, const Point& _p3) : Geometry(_p1, _p2) { p3 = _p3; }	

   Point& getP3() { return p3; }
   void setP3(const Point p) { p3 = p; }

	std::vector<Point> getPoints() override;
};


#endif