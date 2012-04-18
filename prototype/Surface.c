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
float c=0.0;
int cc=0;
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
	glOrtho(0,5000,0,5000,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}
float randP()
{
	unsigned int n,x,y,z;
	float r;
	time_t sec;
	time(&sec);
	n = (unsigned int)sec;
	n = n*x+n*y-n*z;
	n = n%600345;
	r = n/1000076.0;
	r = r-0.3+c;
	c = c+0.07;
	if(r>0.3){c=0.0;return randP();}
	printf("%f",r);
	//xx = xx + 2.0;
	return r/2;
}
float nextpt()
{
	int A[40]={0.25435,0.5245,0.5245,0.63456,0.1345,0.5235,0.8456,0.4567,0.75683,0.2462,0.75673,0.526,0.8456,0.7367,0.51561,0.234,0.622,0.253,0.673,0.2442,0.5345,0.2344,0.536,0.424,0.875,0.9867,0.425,0.2354,0.235,0.543,0.6316,0.754,0.765,0.2346,0.763,0.625,0.5424,0.2542,0.6456,0.234};
	if(cc>39)cc=0;
	cc++;
	return A[cc]; 
}
void drawTheFigure()
{
	int i,rr,ii,nn=-1;
	float xx=-0.8;
	float yy=0.0;
	float zz=-1.0;
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
        	        glBegin(GL_POLYGON);
			glPointSize(10.0);
			glColor3f(0.5f, 0.0f, 1.0f);
			printf("%f  %f\n",xx,yy);
			glVertex2f(xx-0.5,yy-1.0);
			glColor3f (0.4,0.8,0.2);
	                glVertex2f(xx-0.5,yy);
			glColor3f(0.4,0.8,0.2);
			glVertex2f(xx,yy);
			glColor3f (0.4,0.8,0.2);
			for(ii=0;ii<25;ii++)
			{
				yy=(randP()*zz);
				//yy=(nextpt()*5);
				xx=xx+0.2;
				zz=(-1)*zz;	
				glVertex2f(xx,yy);
				glColor3f (0.4,0.8,0.2); 
				//printf("%f  %f\n",xx,yy);
			}
			glVertex2f(xx+0.2,0.0);
			glColor3f (0.4,0.8,0.2);
			glVertex2f(xx+0.5,0.0);
			glColor3f (0.4,0.8,0.2);
			glVertex2f(xx+0.5,-1.0);
			glColor3f (0.4,0.8,0.2);
			glEnd();
		}
		glutSwapBuffers();
	}
	else///generating polygons of n side
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
    printf("%d %d %d %d", btn, state, x, y);
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
	int i;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	n=2;
	line=1;
	//for(i=0;i<=2;i++)
	drawTheFigure();//drawing the required shape
        glColor3f(01.0f, 1.0f, 1.0f);
	glFlush();
}
int main(int argc,char** argv)
{	
        glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(800,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("surface");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardfunc);
	init();
	glutMouseFunc(mouse);
	/*printf("\n Enter the order of the polygon\n For point... 1\n For line... 2\n");
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
		}*/
	display();
	glutMainLoop();               
}
