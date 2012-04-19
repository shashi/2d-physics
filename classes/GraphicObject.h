#ifndef CLASSES_GRAPHIC_OBJECT_
#define CLASSES_GRAPHIC_OBJECT_

#include "lib/Util.h"
#include "GL/glut.h"

class GraphicObject {
  public:
    void colorPoint(int x, int y);
    static void setColor(float red, float green, float blue) {
        glColor3f(red, green, blue);
    }
};

#endif // CLASSES_GRAPHIC_OBJECT_
