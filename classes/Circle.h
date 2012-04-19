#ifndef CLASSES_CIRCLE_
#define CLASSES_CIRCLE_

#include "classes/Body.h"
#include "classes/Point.h"
#include "classes/Rectangle.h"
#include "GL/glut.h"

class Circle: public Body {
  public:
    float radius;
    Point centre;

    Circle(int, int, float);
    Circle(Point, float);
    Circle(float);
    Circle();

    Point Centroid();
    void draw();
    void draw(float angle);
    void drawRadialLine(float angle);
    bool ContainsPoint(Point P);
    void InteractWith(Body * body);
    void InteractWith(Circle * body);
    void InteractWith(Rectangle * body);

  private:
    void MidPointAlgo(int x, int y, float r);
    void PlotOctantPoints(int x, int y, int xc, int yc);
};

#endif // CLASSES_CIRCLE_
