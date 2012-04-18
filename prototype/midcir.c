#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>

int global_dx = 0, global_dy = 0;

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glOrtho(-250,250,-250,250,0,500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
/**
 * Color a point and mark it as a border
 */
void colorPoint(int x, int y) {
//    colored_points[250+x][250+y] = 1;
    glVertex2f(global_dx + x, global_dy + y);
}

/**
 * Plot a point in the required octants
 */
void plot(int x, int y, int xc, int yc, int octants) {
    if (octants &   1) colorPoint(xc + x, yc + y);
    if (octants &   2) colorPoint(xc + y, yc + x);

    if (octants &   4) colorPoint(xc + x, yc - y);
    if (octants &   8) colorPoint(xc + y, yc - x);

    if (octants &  16) colorPoint(xc - y, yc - x);
    if (octants &  32) colorPoint(xc - x, yc - y);

    if (octants &  64) colorPoint(xc - y, yc + x);
    if (octants & 128) colorPoint(xc - x, yc + y);
}

void draw_octants(int xc, int yc, float radius, int octants) {
    int x = 0;
    float y = radius;
    float p0 = 1.25 - radius, p;

    // p is the decision variable
    p = p0;
    while(x <= y) {
        if (p < 0) {
            plot(x, y, xc, yc, octants);
            p += 1 + 2 * x;
        } else {
            plot(x, --y, xc, yc, octants);
            p += 1 + 2 * x - 2 * y;
		}
        x++;
    }
}

/**
 * Draw a circle
 */
void draw_circle(int xc, int yc, int radius) {
	glBegin(GL_POINTS);
	glColor3f(0.123f,0.456f,0.789f);
    int octants = 255;
    draw_octants(xc, yc, (float) radius, octants);
	glEnd();
  glutSwapBuffers();
	glFlush();
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

void cir(float r)
{

	glBegin(GL_POINTS);
	glColor3f(0.123f,0.456f,0.789f);
	float p0=1.25-r;
	float x=0;
	float y=r;
//	glVertex2f(0,r);
	float pk=0;
	float pk2=0;

	while(x<=y)
	{
		pk=p0;
		if(pk<0)
		{
			glVertex2f(x++,y);
			pk2=pk+1+2*x;
		}
		else
		{
			glVertex2f(x++,y--);
			pk2=pk+1+2*x-2*y;
		}
		p0=pk2;
		plotseven(x,y);
		}
	glEnd();
  glutSwapBuffers();
	glFlush();
}
		
void keyboardfunc(unsigned char key,int x,int y)
{

	switch(key)
	{
		case 27:
			exit(0);
		case 'w':
			global_dy += 1;
			break;
		case 'a':
			global_dx -= 1;
			break;

		case 'd':
			global_dx += 1;
			break;
		case 's':
			global_dy -= 1;
			break;
	}

	display();
	glFlush();
}		
					
	
void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
        fprintf(stderr, "%d %d %d %d", btn, state, x, y);
		float radius=rad+10;
		rad=radius;
//		cir(radius);
		display();
		glFlush();			
		
	}
	if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)	
	{
        fprintf(stderr, "%d %d %d %d", btn, state, x, y);
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
	draw_circle(0,0,rad);
}

int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Hari");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboardfunc);
	init();
	display();
	glutMainLoop();
}
