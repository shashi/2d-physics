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

Point Point::applyTransform(Transform trans) {
    float input_matrix[3] = {(float) x, (float)y, 1.0};
    float output_matrix[3];

    Util::MatrixMultiply(trans.matrix, input_matrix, output_matrix);

    return Point(output_matrix[0], output_matrix[1]);
}

void Point::Print()
{
    printf("Point(x=%f, y=%f)\n", x, y);
}

Point Point::Translate(float dx, float dy) {
    return Point(x + dx, y +dy);
}
