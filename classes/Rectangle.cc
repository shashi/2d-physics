#include "lib/Util.h"
#include "classes/Rectangle.h"

#include <cmath>
#include <GL/glut.h>


Rectangle::Rectangle(Point _A_, float _width, float _height) {
    width = _width;
    height = _height;

    // Don't have to do this at every draw()
    float x = width / 2,
          y = height / 2;

    _A = Point(-x, -y);
    _B = Point(-x, y);
    _C = Point(x, y);
    _D = Point(x, -y);

    centre = Point(0, 0);

    transform.matrix[0][2] = _A_.x + x;
    transform.matrix[1][2] = _A_.y + y;
}

Rectangle::Rectangle(Point _A_, float _width, float _height, float _angleBAX) {

    Rectangle(_A_, _width, _height);
    transform.Rotate(_angleBAX);
}

Point Rectangle::Centroid() {
    return transform * centre;
}

Point Rectangle::A() {
    return transform * _A;
}

Point Rectangle::B() {
    return transform * _B;
}

Point Rectangle::C() {
    return transform * _C;
}

Point Rectangle::D() {
    return transform * _D;
}

void Rectangle::draw() {
    Point a = A(), b = B(), c = C(), d = D();

    Line(a, b).draw();
    Line(b, c).draw();
    Line(c, d).draw();
    Line(d, a).draw();
}

void Rectangle::InteractWith(Body * body) {
    // Find out the momentum vector of the other body,
    // Find out the component along the impact.
    // this.ApplyImpulse(Impulse);
    

    // Transform = Physics::ApplyForce(Transform);
    // Gradient = Physics::ApplyForce(Gradient);
    // Angular velocity = Physics::ApplyForce(Angular velocity, Force);
    // Torque / MI = Physics::ApplyForce(Angular momentunm, MI);
}

bool Rectangle::ContainsPoint(Point p) {
    Point polygon[4] = {A(), B(), C(), D()};

    return Util::InsidePolygon(polygon, 4, p);
}
