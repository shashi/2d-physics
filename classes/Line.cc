#include "classes/Line.h"
#include <cmath>

Line::Line(float x1, float y1, float x2, float y2) {
    end1 = Point(x1, y1);
    end2 = Point(x2, y2);
}

Line::Line(Point _end1, Point _end2) {
    end1 = _end1;
    end2 = _end2;
}

float Line::angle() {
    return atan2(end2.x - end1.x, end2.y - end1.y);
}

float Line::slope() {
    return (end2.y - end1.y) / (end2.x - end1.x);
}

float Line::length() {
    return sqrt((end1.y - end2.y) * (end1.y - end2.y)
                + (end1.x - end2.x) * (end1.x - end2.x));
}

Point Line::OneEnd() {
    return end1;
}

Point Line::OtherEnd() {
    return end2;
}

void Line::draw()
{
    //BresenhamsAlgo(end1.x, end1.y, end2.x, end2.y);
    DDA(end1.x, end1.y, end2.x, end2.y);
}

void Line::BresenhamsAlgo(float x1,float y1,float x2,float y2)
{
	float dx  = x2-x1,
	      dy  = y2-y1,
	      m   = dy/dx,
	      dx2 = 2 * dx,
	      dy2 = 2 * dy,
	      p   = 0;

	colorPoint(x1,y1);
	colorPoint(x2,y2);

    // initialize decision variable
	p = dy2 - dx;

	if(std::abs(m) < 1 || dy == 0) {
        if (x1 > x2) {
            BresenhamsAlgo(x2, y2, x1, y1);
        }

        while(x1 <= x2)
        {
            if (p < 0) {
                colorPoint(x1++,y1);
                p += dy2;
            } else {
                colorPoint(x1++,y1++);
                p += dy2 - dx2;
            }
        }
	}

    // initialize decition variable
    p = dx2 - dy;

	if(std::abs(m) > 1 || dx == 0) {
        if (y1 > y2) {
            BresenhamsAlgo(x2, y2, x1, y1);
        }

        while(y1 <= y2) {
            if (p < 0) {
                colorPoint(x1,y1++);
                p += dx2;
            } else {
                colorPoint(x1++, y1++);
                p += dx2 - dy2;
            }
        }
	}
}

void Line::DDA(float x1,float y1,float x2,float y2)
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glClear(GL_COLOR_BUFFER_BIT);
    float x,y,xinc,yinc,dx,dy;
    int k;
    int step;
    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
        step=abs(dx);
    else
        step=abs(dy);

    xinc=dx/step;
    yinc=dy/step;

    x=x1;
    y=y1;
    colorPoint(x,y);

    for(k=1;k<=step;k++)
    {
        x=x+xinc;
        y=y+yinc;
        colorPoint(x,y);
    }

}

Point Line::ProjectionOf(Point p) {
  float l2 = length();
        l2 *= l2; // Fix this
  // Consider the line extending the segment, parameterized as v + t (w - v).
  // We find projection of point p onto the line. 
  // It falls where t = [(p-v) . (w-v)] / |w-v|^2
  float t = (p - end1) * (end2 - end1) / l2;
  Point projection = end1 + ((end2 - end1) * t);  // Projection falls on the segment
}

float Line::DistanceFrom(Point p) {
  float l2 = length(),
        t = (p - end1) * (end2 - end1) / l2;

    l2 *= l2; // Fix this

  if (t < 0.0) return Line(p, end1).length();       // Beyond the 'v' end of the segment
  else if (t > 1.0) return Line(p, end2).length();
  Point projection = end1 + ((end2 - end1) * t);  // Projection falls on the segment
  return Line(p, projection).length();
}
