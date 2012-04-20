#ifndef CLASSES_RECTANGLE_
#define CLASSES_RECTANGLE_

#include "classes/Body.h"
#include "classes/Line.h"
#include "classes/Point.h"
#include "classes/GraphicObject.h"

/**
 * B ----------- C
 *  |           |
 * A ----------- D
 */
class Rectangle: public Body {
    Point _A, _B, _C, _D, centre;
  public:
    float width, height;
    Transform local_transform;

    Rectangle(Point A, float width, float height, float angleBAX);
    Rectangle(Point A, float width, float height);

    void draw();
    Point* GetVertices();
    bool ContainsPoint(Point);
    Point Centroid();
    void InteractWith(Body * body);
    float area();
    Point A();
    Point B();
    Point C();
    Point D();
};

#endif // CLASSES_RECTANGLE_
