#include "classes/Vector.h"

#include <cstdio>

Vector::Vector() {
}

Vector Vector::operator/(float divisor) {
    return Vector(x / divisor, y / divisor);
}

Vector Vector::operator*(float multiplier) {
    return Vector(x * multiplier, y * multiplier);
}

float Vector::operator*(Vector multiplier) {
    return x * multiplier.x + y * multiplier.y;
}

Vector Vector::operator+(Vector v) {
    return Vector(x + v.x, y + v.y);
}

Vector Vector::operator-(Vector v) {
    return Vector(x - v.x, y - v.y);
}

void Vector::print() {
    fprintf(stderr, " (%f, %f) ", x, y);
}
