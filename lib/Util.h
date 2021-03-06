#ifndef LIB_UTIL_
#define LIB_UTIL_
#include "classes/Point.h"

typedef struct _Color {
    float red;
    float blue;
    float green;
} Color;

class Util {
  public:
    static void MatrixMultiply(float[3][3], float[3], float[3]);

    static Color getPixel(int, int);

    static int Init(int argc, char** argv);
    static bool InsidePolygon(Point *, int, Point);
};

#endif // LIB_UTIL_
