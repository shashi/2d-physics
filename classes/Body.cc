#include "classes/Body.h"
#include "classes/Line.h"
#include "classes/Vector.h"

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

float Body::moment() {
    return 1.0;
}

Point Body::Centroid() {
    Point(0, 0);
}

/**
 * Parallel axis theorem
 */

float Body::moment(Point about) {
    float distance = Line(Centroid(), about).length();
    float mass = weight();

    return moment() + mass * distance * distance;
}

void Body::draw() {
}

void Body::InteractWith(Body * body)  {
}

void Body::ApplyImpulse(Vector delmomentum, float delangular) {
    float m = weight();
    float mi = moment();
    // assume off weight = mass
    transform.AddVelocity(delmomentum / m);
    transform.AddAngularVelocity(delangular / mi);
}

void Body::AddTime(float dt) {
    transform.AddTime(dt);
}

Vector Body::momentum() {
    return transform.velocity * weight();
}
