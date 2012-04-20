#include "classes/Point.h"
#include "lib/Util.h"
#include "stdio.h"

Point::Point (float a, float b) {
    x = a;
    y = b;
}

Point::Point() {
    x=0; y=0;
}

Point Point::operator/(float divisor) {
    return Point(x / divisor, y / divisor);
}

Point Point::operator*(float multiplier) {
    return Point(x * multiplier, y * multiplier);
}

float Point::operator*(Point multiplier) {
    return x * multiplier.x + y * multiplier.y;
}

Point Point::operator+(Point v) {
    return Point(x + v.x, y + v.y);
}

Point Point::operator-(Point v) {
    return Point(x - v.x, y - v.y);
}

void Point::Print()
{
    printf("Point(x=%f, y=%f)\n", x, y);
}
