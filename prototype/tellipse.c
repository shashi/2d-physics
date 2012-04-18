#include<stdio.h>
#include <stdlib.h>
#include<GL/glut.h>
#include<math.h>
# define ROUND(a) ((int)(a+0.5))

void ellipse (int x0,int y0,int rx, int ry)
{
int rx2=rx*rx;
int ry2=ry*ry;
int tworx2=2*rx2;
int twory2=2*ry2;
int p;
int x=0;
int y=ry;
int px=0;
int py= tworx2*y;
void points(int x0,int y0,int x,int y)
{
glVertex2f(x0+x,y0+y);
glVertex2f(x0-x,y0+y);
glVertex2f(x0+x,y0-y);
glVertex2f(x0-x,y0-y);
}
{
p=ROUND(ry2-(rx2*ry)+(0.25*rx2));
while(px<py)
{
x++;
px+=twory2;
if(p<0)
p+=ry2+px;
else
{
y--;
py-=tworx2;
p+=ry2+px-py;


}
points(x0,y0,x,y);

}

p=ROUND(ry2*(x+0.5)*(x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2);
while(y>0)
{
y--;
py-=tworx2;
if(p>0)
p+=rx2-py;
else
{
x++;
px+=twory2;
p+=rx2-py+px;
}
points(x0,y0,x,y); 	
}
}

}




void Init()
{
glClearColor(0.1,0.5,0.3,0.0);
glColor3f(0.9,0.9,0.9);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0,500,0,500,0,500);
}
void Display ()
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
ellipse(100,200,100,50);
glEnd();
glFlush();
}






int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

glutInitWindowSize(500,500);
glutInitWindowPosition(500,500);
glutCreateWindow("simple");
glutDisplayFunc(Display);
Init();
glutMainLoop();
}

