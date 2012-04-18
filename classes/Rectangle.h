#ifndef CLASSES_RECTANGLE_
#define CLASSES_RECTANGLE_

#include "classes/Shape.h"
#include "classes/Line.h"
#include "classes/Point.h"

/**
 * B ----------- C
 *  |           |
 * A ----------- D
 */
class Rectangle: public Shape {
    Point A;
    float width, height, angleBAX;
  public:

    Rectangle(Point A, float width, float height, float angleBAX);
    Rectangle(Point A, float width, float height);

    void draw();
    Point* GetVertices();
};

#endif // CLASSES_RECTANGLE_
