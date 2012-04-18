#ifndef CLASSES_ANCHOR_
#define CLASSES_ANCHOR_

#include "classes/Body.h"

class Anchor {
    public:
        static const short int glue = 0;
        static const short int hinge = 1;

        /**
         * How is the object anchored?
         */
        Body body;
        short int type;
};

#endif // CLASSES_ANCHOR_
