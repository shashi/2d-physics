#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glOrtho(0,500,0,500,0,500);
        glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}


void DDA(float y1,float y2,float x1,float x2)
{
	glBegin(GL_POINTS);
	glColor3f(0.5,0.2,0.7);	
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT);
	float dx=x2-x1;
	float dy=y2-y1;
	float steps=1.0;
	float x=x1;
	float y=y1;
         printf("%f %f %f %f\n",dx,dy,x,y);
	if(dx>dy)
	steps=dx;
	else
	steps=dy;
	printf("Steps is %f \n",steps);
	float xinc=dx/steps;
	float yinc=dy/steps;
	glVertex2f(x,y);
	glVertex2f(x+0.01,y+0.01);
	glBegin(GL_POINTS);
	while(x<=x2 && y<=y2)
	{
		//glPointSize(10.0);
                
		x=x+xinc;
		y=y+yinc;
		printf("%f %f \n",x,y);
		//glColor3f(1.0,1.0,1.0); 

	glVertex2f(x,y);
		}
	glEnd();
	glFlush();


}
		
void Display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glClear(GL_COLOR_BUFFER_BIT);
	/*	glVertex2f(-0.1,-0.0);
	glVertex2f(-0.0,0.1);
	glVertex2f(0.1,0.0);
	glVertex2f(0.0,-0.1);
*/	


DDA(10,10,70,450);
DDA(10,100,70,70);
DDA(100,100,70,450);
DDA(10,100,450,450);

}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1500,1500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Hari");
	glutDisplayFunc(Display);
	init();
	Display();

	glutMainLoop();
}

