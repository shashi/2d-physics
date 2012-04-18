#include "classes/Rectangle.h"
#include <cmath>
#include <GL/glut.h>

Rectangle::Rectangle(Point _A, float _width, float _height, float _angleBAX) {
    A = _A;
    width = _width;
    height = _height;
    angleBAX = _angleBAX;
}

Rectangle::Rectangle(Point _A, float _width, float _height) {
    A = _A;
    width = _width;
    height = _height;
    angleBAX = 0;
}

void Rectangle::draw() {
    Point B = Point(A.x - sin(angleBAX) * height, A.y + cos(angleBAX) * height);
    Point D = Point(A.x + cos(angleBAX) * width, A.y + sin(angleBAX) * width);
    Point C = Point(B.x + cos(angleBAX) * width, B.y + sin(angleBAX) * width);

    Line(A, B).draw();
    Line(B, C).draw();
    Line(D, C).draw();
    Line(A, D).draw();
}
