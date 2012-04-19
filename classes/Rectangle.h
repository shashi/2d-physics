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
    Point A;
    float width, height, angleBAX;
  public:

    Rectangle(Point A, float width, float height, float angleBAX);
    Rectangle(Point A, float width, float height);

    void draw();
    Point* GetVertices();
    Point Centroid();
    void InteractWith(Body * body);
};

#endif // CLASSES_RECTANGLE_
