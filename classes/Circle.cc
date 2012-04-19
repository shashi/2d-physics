#include "classes/Circle.h"

#include <cmath>
#include <cstdio>

#include "classes/Line.h"

#define _FILL true

Circle::Circle(int xc, int yc, float _radius) {
    radius = _radius;
    centre = Point(xc, yc);
}

Circle::Circle(Point C, float _radius) {
    radius = _radius;
    centre = C;
}

Circle::Circle(float _radius) {
    radius = _radius;
    centre = Point(0, 0);
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
}
/**
 * Draw a circle with radial line
 */
void Circle::draw(float angle) {
    draw();
    drawRadialLine(angle);
}

void Circle::drawRadialLine(float angle) {
    Point C = Centroid();
    Point A = Centroid();

    A.x += cos(angle) * radius;
    A.y += sin(angle) * radius;

    Line(C, A).draw();
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
    if (Line(Centroid(), c->Centroid()).length()
            <= c->radius + radius) {
        float angle = Line(Centroid(), c->Centroid()).angle();
        Vector v, dv;
        Vector dp = momentum() - c->momentum();
        dv = dp / weight();

        transform.AddVelocity(dv);
        c->transform.AddVelocity(dv * -1);
    }
}

void Circle::InteractWith(Rectangle * r) {
}


