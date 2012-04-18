#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.142

float theta;
float zoom=1.0;//for scaling
float angle=0.0;//for rotation
float transx=0.0;//for translation along X axis 
float transy=0.0;//for translation along y axis
int shade=1;
int n;
int line;
void initializeall()// reinitializing every value to the oiginal
{
	zoom=1.0;
	angle=0.0;
	transx=0.0; 
	transy=0.0;
}
void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}
void drawTheFigure()
{
	int i,rr,nn=-1;
	float xx,yy;
	glRotatef(angle,0.0,0.0,1.0);
	glScalef(1.0*zoom,1.0*zoom,1.0*zoom);
	glTranslatef(0.0+transx,0.0+transy,0.0);	
        if(n==1)//generating a point
	{
		glBegin(GL_POINTS);
		glColor3f(0.0f, 0.0f, 1.0f);
 		glVertex2f(0.0f,0.0f);
		glEnd();
	}
        if(n==2)//generating lines
	{
		glFlush();
		if(line==2)//if nn line required
		{
			glBegin(GL_POINTS);
			float i;
			for(i=0.0;i<2.5;i=i+0.005)
			{
				glColor3f(0.0f, 0.0f, 1.0f);
		 		glVertex2f(i*nn,i*nn);
				glTranslatef(0.1,0.1,0.0);
				nn=(-1)*nn;
			}
			glEnd();
		}
		else
		{
        	        glBegin(GL_LINES);
			glPointSize(10.0);
			glColor3f(0.5f, 0.0f, 1.0f);
	                glVertex2f(xx+0.5,yy+0.5);
			glColor3f(1.0f,0.0f,0.5f);	
			glVertex2f(xx-0.5,yy-0.5);
			glColor3f (1.0, 0.0, 1.0); 
			glEnd();
		}
		glutSwapBuffers();
	}
	else//generating polygons of n side
	{ 
		glBegin(GL_POLYGON);
		if(shade==1)
		glShadeModel(GL_FLAT);
		else
		glShadeModel(GL_SMOOTH);
		theta=(float)(2.0*(PI/n));// to draw the correct no of lines
		for(i=0;i<n;i++)
		{	
			glColor3f(0.0f,0.1f,1.1f);
			xx = 0.619*sin(theta*i);
			yy = 0.619*cos(theta*i);
			glVertex2f(xx,yy);			
		}
	glEnd();
        glutSwapBuffers();
	}
	glFlush();
}
void mouse(int btn,int state,int x,int y)
{	
	if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
	exit(0);
}
void keyboardfunc(unsigned char key,int x,int y)
{
	switch(key)
	{
			case 27:exit(0);break;//esc to quit the program
			case 119:{initializeall();zoom=zoom+0.001;   display(); glFlush();}break;//w to scale up
			case 115:{initializeall();zoom=zoom-0.001;   display(); glFlush();}break;//s to scale down
			case 57: {initializeall();angle=1.5;  	     display(); glFlush();}break;//0 to rotate rightwards
			case 48: {initializeall();angle=-1.5;        display(); glFlush();}break;//9 to rotate leftwards
			case 108:{initializeall();transx=0.01;       display(); glFlush();}break;//l to translate right
			case 106:{initializeall();transx=-0.01;	     display(); glFlush();}break;//j to translate left
			case 105:{initializeall();transy=0.01;       display(); glFlush();}break;//i to translate up
			case 107:{initializeall();transy=-0.01;      display(); glFlush();}break;//k to translate down
	}		
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawTheFigure();//drawing the required shape
        glColor3f(01.0f, 1.0f, 1.0f);
	glFlush();
}
int main(int argc,char** argv)
{	
        glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Amogh Reddy");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardfunc);
	init();
	glutMouseFunc(mouse);
	printf("\n Enter the order of the polygon\n For point... 1\n For line... 2\n");
	scanf("%d",&n);
	if(n<1||n>12) 
	{
		printf("Invalid number of sides!!!");
		exit(0);
	}
	if(n>2){
		printf("\n For Flat shading press 1 \n For Smooth shading press 0 \n");
		scanf("%d",&shade);//Flat or smooth
		printf("\n");
		}
	if(n==2)
		{
		printf("\n Enter the choice of types lines \n 1>Normal line \n 2>Dotted Line \n");
		scanf("%d",&line);
		}
	display();
	glutMainLoop();               
}
