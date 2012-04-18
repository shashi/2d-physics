#ifndef CLASSES_GRAPHIC_OBJECT_
#define CLASSES_GRAPHIC_OBJECT_

#include "classes/GraphicObject.h"

#include "GL/glut.h"

void GraphicObject::colorPoint(int x, int y)
{
    glVertex2f(x, y);
}

#endif // CLASSES_GRAPHIC_OBJECT_
