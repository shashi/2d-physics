#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>


void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glOrtho(0,500,0,500,0,500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}


void plotseven(float x,float y)
{
		glVertex2f(-1*x,-1*y);
		glVertex2f(-1*y,-1*x);
		glVertex2f(y,x);
		glVertex2f(x,-1*y);
		glVertex2f(-1*x,y);
		glVertex2f(y,-1*x);
		glVertex2f(-1*y,x);

}

float rad=150;

		
void keyboardfunc(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 27:
			{
			exit(0);
			}
	}
}		
					
	
void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
		float radius=rad+10;
		rad=radius;
//		cir(radius);
		display();
		glFlush();			
		
	}
	if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)	
	{
		float radius=rad-10;
		rad=radius;
//		cir(radius);
		display();
		glFlush();
	}
}



void display()
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	//cir(rad);
	glBegin(GL_POINTS);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(10,20);
	glVertex2f(10,480);
	float color[3];
	glReadPixels(10, 480, 1, 1, GL_RGB, GL_FLOAT, color);

	printf("	%f	%f	%f	",color[0],color[1],color[2]);
	glEnd();

	glFlush();
}

int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Hari");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardfunc);
	glutMouseFunc(mouse);
	init();
//	display();
	glutMainLoop();
}
