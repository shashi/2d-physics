#include "classes/Circle.h"

#include <cmath>
#include <cstdio>

#include "classes/Line.h"

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

    // p is the decision variable
    p = p0;
    while(x <= y) {
        if (p < 0) {
            PlotOctantPoints(x, y, xc, yc);
            p += 1 + 2 * x;
        } else {
            PlotOctantPoints(x, --y, xc, yc);
            p += 1 + 2 * x - 2 * y;
		}
        x++;
    }
}

Point Circle::Centroid() {
    return centre;
}

/**
 * Draw a circle
 */
void Circle::draw() {
    Circle::MidPointAlgo(centre.x, centre.y, (float) radius);
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
    Point A = Centroid().Translate(cos(angle) * radius, sin(angle) * radius);

    Line(C, A).draw();
}

bool Circle::ContainsPoint(Point P) {
    return Line(P, centre).length() < radius;
}
