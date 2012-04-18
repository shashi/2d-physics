#include "classes/Body.h"
#include "classes/Line.h"

Body::Body()
{
    density = 1.0;
    youngs = 0.0;
    friction = -1.0; // infinity
    layer = 0;
}

float Body::area() {
    return 1.0;
}

float Body::weight() {
    return area() * density;
}

Point Body::centroid() {
    return Point(0, 0);
}

float Body::moment() {
    return 1.0;
}

/**
 * Parallel axis theorem
 */

float Body::moment(Point about) {
    float distance = Line(centroid(), about).length();
    float mass = weight();

    return moment() + mass * distance * distance;
}

void Body::draw() {
}
