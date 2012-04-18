#include "lib/Util.h"

#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

// global variable: draw function;
void (*_drawFunction)();

void Util::MatrixMultiply(float A[3][3], float B[3], float output[3])
{
    output[0] = A[0][0] * B[0] + A[0][1] * B[1] + A[0][2] * B[2];
    output[1] = A[1][0] * B[0] + A[1][1] * B[1] + A[1][2] * B[2];
    output[2] = A[2][0] * B[0] + A[2][1] * B[1] + A[2][2] * B[2];
}

Color Util::getPixel(int x, int y) {
    Color c;
    float color[3];

    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);

    c.red = color[0];
    c.green = color[1];
    c.blue = color[2];

    return c;
}

int Util::Init(int argc,char** argv)
{
    glutInit(&argc,argv);
    return 0;
}
