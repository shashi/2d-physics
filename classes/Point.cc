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

void Point::Print()
{
    printf("Point(x=%f, y=%f)\n", x, y);
}
