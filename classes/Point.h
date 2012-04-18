#ifndef CLASSES_POINT_
#define CLASSES_POINT_

#include "classes/Transform.h"

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

        /**
         * Print info about point
         */
        void Print();

        /**
         * Apply a transformation object
         */
        Point applyTransform(Transform);

        /**
         * Translate
         */
        Point Translate(float dx, float dy);
};

#endif // CLASSES_POINT_
