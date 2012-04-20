#include "lib/Util.h"
#include "classes/Point.h"

#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)

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

bool Util::InsidePolygon(Point *polygon, int N, Point p)
{
      int counter = 0;
      int i;
      double xinters;
      Point p1,p2;

      p1 = polygon[0];
      for (i=1;i<=N;i++) {
        p2 = polygon[i % N];
        if (p.y > MIN(p1.y,p2.y)) {
          if (p.y <= MAX(p1.y,p2.y)) {
            if (p.x <= MAX(p1.x,p2.x)) {
              if (p1.y != p2.y) {
                xinters = (p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
                if (p1.x == p2.x || p.x <= xinters)
                  counter++;
              }
            }
          }
        }
        p1 = p2;
      }

      if (counter % 2 == 0)
        return(false);
      else
        return(true);
}
