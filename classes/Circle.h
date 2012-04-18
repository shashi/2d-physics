#include "classes/Shape.h"
#include "classes/Point.h"
#include "GL/glut.h"

class Circle: public Shape {
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

  private:
    void MidPointAlgo(int x, int y, float r);
    void PlotOctantPoints(int x, int y, int xc, int yc);
};
