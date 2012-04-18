#include "classes/Body.h"
#include "classes/Point.h"

class Line: public Body {
    Point end1, end2;
  public:
    Line(float x1, float y1, float x2, float y2);
    Line(Point, Point);

    float slope();
    float length();

    Point OneEnd();
    Point OtherEnd();

    void draw();
  private:
    void BresenhamsAlgo(float x1, float y1, float x2, float y2);
    void DDA(float x1, float y1, float x2, float y2);
};
