#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
void drawDAA(float x1,float y1,float x2,float y2){
        float dx=x2-x1;
        float dy=y2-y1;
        float x=x1;
        float y=y1;
        float steps;
        if(dx>dy)
                steps=dx;
        else
                steps=dy;
        float xIncrement=(float)(1)*(dx/steps);
        float yIncrement=(float)(1)*(dy/steps);
        //glVertex2f(round(x),round(y));
        //glVertex2f(round(x+100),round(y+100));
        float k;
                glBegin(GL_POINTS);
	while(x<1.0){
                glPointSize(10.0);
                //printf("%f,%f\n",(x),(y));
                x+=xIncrement;
                y+=yIncrement;
                glVertex2f(x,y);                
        }       
	glEnd();
}
void init(){
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,500,0,500,0,0);
}
void keyboardfunc(unsigned char key,int x,int y){
	switch(key){
		case 27:exit(0);break;
	}
}
void display(){
	int x1,y1,x2,y2;
	glClear(GL_COLOR_BUFFER_BIT);
	drawDAA(-0.0f,0.0f,345.7f,564.4f);
	glFlush();
	drawDAA(-0.1f,-0.2f,0.6f,0.3f);
	glFlush();//drawDAA(0.0f,0.0f,-0.7f,-0.4f);
	//drawlineBresenhan(x1,y1,x2,y2);
}
int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("lines");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardfunc);
	init();
	glutMainLoop();
	return 0;
}
