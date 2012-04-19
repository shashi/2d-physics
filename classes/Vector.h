#ifndef CLASSES_VECTOR_
#define CLASSES_VECTOR_

#include "classes/Point.h"

class Vector {
  public:
    float x, y;
    Vector(float _x, float _y) {
        x=_x;
        y=_y;
    }
    Vector();
    // scalar division
    Vector operator/(float);
    Vector operator*(float);
    float operator*(Vector);

    Vector operator+(Vector);
    Vector operator-(Vector);
    void print();
};

#endif // CLASSES_VECTOR_
