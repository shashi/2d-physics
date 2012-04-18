#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>


void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glOrtho(0,500,0,500,0,500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}


bres(float x1,float y1,float x2,float y2)
{
	
	glBegin(GL_POINTS);
	glColor3f(0.123f,0.456f,0.789f);
	glVertex2f(x1,y1);
	float dx=x2-x1;
	float dy=y2-y1;
	float m=dy/dx;
	float dx2=2*dx;
	float dy2=2*dy;
	float p0=0;
	float pk=0;
	float pk2=0;
	p0=dy2-dx;
	if(abs(m)<1)
	{
	while(x1<=x2)
	{
		pk=p0;
		if(pk<0)
		{
			glVertex2f(x1++,y1);
			pk2=pk+dy2;
		}
		else
		{
			glVertex2f(x1++,y1++);
			pk2=pk+dy2-dx2;
		}
		p0=pk2;
	}
	}
	p0=dx2-dy;
	if(abs(m)>1)
	{
	while(y1<=y2)
	{
		pk=p0;
		if(pk<0)
		{
			glVertex2f(x1,y1++);
			pk2=pk+dx2;
		}
		else
		{
			glVertex2f(x1++,y1++);
			pk2=pk+dx2-dy2;
		}
		p0=pk2;
	}
	}
	glEnd();
	glFlush();
		
}
void display()
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	bres(x1,y1,x2,y2);
}

int main(int argc,char** argv)
{
  scanf("%f%f%f%f",x1,y1,x2,y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Hari");
	glutDisplayFunc(display);
	init();
	display();
	glutMainLoop();
}
