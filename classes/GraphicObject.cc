#include "classes/GraphicObject.h"

#include "GL/glut.h"

void GraphicObject::colorPoint(int x, int y)
{
    glVertex2f(x, y);
}
