#include "classes/Circle.h"

#include <cmath>
#include <cstdio>
#include <ctime>

#include "classes/Line.h"

#define _FILL false

Circle::Circle(int xc, int yc, float _radius) {
    radius = _radius;
    centre = Point(0, 0);
    transform.matrix[0][2] = xc;
    transform.matrix[1][2] = yc;
    fg_color[0]
        = fg_color[1]
        = fg_color[2]
        = 1.0;

    fixed = false;
    setType(BODY_CIRCLE);
}

Circle::Circle(Point C, float _radius) {
    radius = _radius;
    centre = Point(0, 0);
    transform.matrix[0][2] = C.x;
    transform.matrix[1][2] = C.y;
    fg_color[0]
        = fg_color[1]
        = fg_color[2]
        = 1.0;

    fixed = false;
    setType(BODY_CIRCLE);
}

Circle::Circle(float _radius) {
    radius = _radius;
    centre = Point(0, 0);
    fg_color[0]
        = fg_color[1]
        = fg_color[2]
        = 1.0;

    fixed = false;
    setType(BODY_CIRCLE);
}

bool filled_verticals[1000];

void fill_upto(int x, int y, int Y) {
    for(;y <= Y; y++) {
        glVertex2d(x, y);
    }
}


/**
 * Plot a point in all the octants
 */
void Circle::PlotOctantPoints(int x, int y, int xc, int yc) {


    colorPoint(xc + x, yc + y);
    colorPoint(xc + y, yc + x);

    colorPoint(xc + x, yc - y);
    colorPoint(xc + y, yc - x);

    colorPoint(xc - y, yc - x);
    colorPoint(xc - x, yc - y);

    colorPoint(xc - y, yc + x);
    colorPoint(xc - x, yc + y);
}


/**
 * Draw octants of a circle
 * octants is a bit map of which octants to fill
 */
void Circle::MidPointAlgo(int xc, int yc, float radius) {
    int x = 0;
    float y = radius;
    float p0 = 1.25 - radius, p;
    //fprintf(stderr, ">> %d %d", xc, yc);
    // p is the decision variable
    p = p0;
    while(x <= y) {
        if (p < 0) {
            PlotOctantPoints(x, y, xc, yc);
            p += 1 + 2 * x;
            if (_FILL) {
                // Half the work! WOot!
                fill_upto(x+xc, yc, y + yc);
                fill_upto(xc-x, yc, y + yc);
                fill_upto(x+xc, yc - y, yc);
                fill_upto(xc-x, yc - y, yc);
            }
        } else {
            PlotOctantPoints(x, --y, xc, yc);
            p += 1 + 2 * x - 2 * y;
            if (_FILL) {
                fill_upto(xc + x, yc, y + yc);
                fill_upto(xc - x, yc, y + yc);
                fill_upto(xc + x, yc - y, yc);
                fill_upto(xc - x, yc - y, yc);
                fill_upto(xc + y, yc, yc + x);
                fill_upto(xc + y, yc - x, yc);
                fill_upto(xc - y, yc, yc + x);
                fill_upto(xc - y, yc - x, yc);
            }
		}
        x++;
    }
}

Point Circle::Centroid() {
    return transform * centre;
}

/**
 * Draw a circle
 */
void Circle::draw() {
    Point C = Centroid();
    Circle::MidPointAlgo(C.x, C.y, (float) radius);
    drawRadialLine(0);
}
/**
 * Draw a circle with radial line
 */
void Circle::draw(float angle) {
    draw();
    drawRadialLine(angle);
}

void Circle::drawRadialLine(float angle) {
    Point A = Point(radius, 0);
    A = transform * A;

    Line(Centroid(), A).draw();
}

bool Circle::ContainsPoint(Point P) {
    return Line(P, centre).length() <= radius;
}

void Circle::InteractWith(Body * body) {
    switch (body->getType()) {
      case BODY_CIRCLE:
        InteractWith(body);
      case BODY_RECTANGLE:
        InteractWith(body);
    }
}

void Circle::InteractWith(Circle * c) {
    Line l = Line(Centroid(), c->Centroid());
    if (l.length() <= c->radius + radius) {
        // collision!
        // exchange a bit of momentum
        // Using equation of conservation of momentum and
        // Elastic collision

        Vector u1 = transform.velocity,
               u2 = c->transform.velocity;

        float angle = l.angle();
        // vector along which collision occured.
        Vector unit_vector = Vector(cos(angle), sin(angle));

        float _u1 = u1 * unit_vector,
              _u2 = u2 * unit_vector,

              m1 = weight(),
              m2 = c->weight(),
              _v1, _v2;

        _v1 = (_u1 * (m1 - m2) + 2 * m2 * _u2) / (m1 + m2);
        _v2 = (_u2 * (m2 - m1) + 2 * m1 * _u1) / (m1 + m2);

        Vector v1, v2;
        v1 = unit_vector * (_v1 - _u1);
        v2 = unit_vector * (_v2 - _u2);

        transform.AddVelocity(v1);
        c->transform.AddVelocity(v2);
    }
}

void Circle::InteractWith(Rectangle * r) {
    Point A = r->A(), B = r->B(), C = r->C(), D = r->D();
    Line edge = Line(A, B);
    float angle;

    if (fabs(Line(A, B).DistanceFrom(Centroid())) <= radius) {
        edge = Line(A, B);
    } else if (fabs(Line(B, C).DistanceFrom(Centroid())) <= radius) {
        edge = Line(B, C);
    }
    else if (fabs(Line(C, D).DistanceFrom(Centroid())) <= radius) {
        edge = Line(C, D);
    }
    else if (fabs(Line(D, A).DistanceFrom(Centroid())) <= radius) {
        edge = Line(D, A);
    } else {
        return;
    }

    // Point of impact.
    Point poi = edge.ProjectionOf(Centroid());

    Vector u1 = transform.velocity,
           u2 = r->transform.velocity;

    angle = Line(Centroid(), poi).angle();
    // vector along which collision occured.
    Vector unit_vector = Vector(sin(angle), cos(angle));

    if (r->fixed) {
        float v = u1 * unit_vector;
        Vector v_ = unit_vector * (v * -2);
        transform.AddVelocity(v_);
        return;
    }

    fprintf(stderr, "COLLISION %f\n", edge.DistanceFrom(Centroid()));

    float _u1 = u1 * unit_vector,
          _u2 = u2 * unit_vector,

          m1 = weight(),
          m2 = r->weight(),
          _v1, _v2;

    _v1 = (_u1 * (m1 - m2) + 2 * m2 * _u2) / (m1 + m2);
    _v2 = (_u2 * (m2 - m1) + 2 * m1 * _u1) / (m1 + m2);

    Vector v1, v2;
    v1 = unit_vector * (_v1 - _u1);
    v2 = unit_vector * (_v2 - _u2);

    transform.AddVelocity(v1);
    r->transform.AddVelocity(v2);
}

float Circle::weight() {
    return area() * density;
}

float Circle::area() {
    return PI * pow(radius, 2);
}
