#ifndef CLASSES_POINT_
#define CLASSES_POINT_

#include "classes/Vector.h"

class Point {
    public:
        float x, y;
        /**
         * Constructor
         */
        Point (float, float);

        /**
         * Constructor
         */
        Point();

        Point operator/(float);
        Point operator*(float);
        float operator*(Point);

        Point operator+(Point);
        Point operator-(Point);
        /**
         * Print info about point
         */
        void Print();
};

#endif // CLASSES_POINT_
