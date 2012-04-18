#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

float xc1=-101;
float yc1=50;
float r=50;
float xc2=0;
float xc3=0;
float yc2=50;
float yc3=50;
float theta=0.0;
float xxc1=-101;
float g=0.0f; //for loop in mouse
float balls_val=0.0;
float cloud_val=0.0;


void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glOrtho(-200,500,-50,500,0,500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

// circel code new
void circle (int x0,int y0,int r)
{
int p,x,y;
void points()
{
glVertex2f(x0+x,y0+y);
glVertex2f(x0-x,y0+y);
glVertex2f(x0+x,y0-y);
glVertex2f(x0-x,y0-y);
glVertex2f(x0+y,y0+x);
glVertex2f(x0-y,y0+x);
glVertex2f(x0+y,y0-x);
glVertex2f(x0-y,y0-x);
}

 x=0;
 y=r;
 p=3-2*r;
while(x<y)
{
points();
if (p<0)
{
p=p+4*x+6;
}
else
{p=p+4*(x-y)+10;
y=y-1;
}
x=x+1;
}
if(x==y)
{
points();
}
}	




// cloud creating code
			void badal()
{
int i=0;
// sun macha sun!!

glColor3f(1.0,1.0,0.0);
for(i=0;i<=45;i++)
{

circle(270,410,i);

}
// cloud 1

for(i=0;i<=35;i++)
{
glColor3f(0,0,0.8);
circle(0+cloud_val,	400,	i);
circle(100+cloud_val,	400,	i);
circle(50+cloud_val	,375,	i);
circle(50+cloud_val	,425,	i);
}

//
//obviously cloud 2
//
for(i=0;i<=35;i++)
{
glColor3f(0,0,0.8);
circle(200-cloud_val,400,i);
circle(300-cloud_val,400,i);
circle(250-cloud_val,375,i);
circle(250-cloud_val,425,i);
}

}




makexcval()
{
	xc2=xc1+105;
	xc3=xc2+200;
}

void makecircle(float x,float y,int circno)
{
	float xc=0.0;
	float yc=yc1;
																													
	
	switch(circno)
	{
		case 1: {xc=xc1;
		break;}
		case 2:{ xc=xc2;
		break;}
		case 3:{ xc=xc3;
		break;}
		default : {xc=xc1;yc=yc1+102;}
	}

	glColor3f(0.123f,0.456f,0.789f);		
	glVertex2f(xc+x,yc+y);
	glVertex2f(xc-x,yc-y);	
	glVertex2f(xc+x,yc-y);
	glVertex2f(xc-x,yc+y);
	glVertex2f(xc+y,yc+x);
	glVertex2f(xc-y,yc-x);
	glVertex2f(xc+y,yc-x);
	glVertex2f(xc-y,yc+x);


}



float abso(float m)
{
	if(m<0)
	m=m*-1;;
	return m;
}


bres(float x1,float y1,float x2,float y2)
{
	
//	glBegin(GL_POINTS);
//	glColor3f(0.123f,0.456f,0.789f);
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
	if(abso(m)<1||dy==0)
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
	if(abso(m)>1||dx==0)
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
//	glEnd();
//	glFlush();
		
}

/*
void polygon()
{

glColor3f(0,1,0);
glBegin(GL_POLYGON);
glVertex2f(-500,0);
glVertex2f(500,0);
glVertex2f(-500,-200);
glVertex2f(-500,200);
glEnd();
}
*/
				void balls()
{
glColor3f(1,1,0);

circle(  0.4+balls_val  ,172    ,20);//layer 1
circle(-43.5+balls_val	,172	,20);//layer 1
circle(-88.0+balls_val	,172	,20);//layer 1
circle(-66.0+balls_val	,208	,20);//2nd layer
circle(-22.0+balls_val	,208	,20);//2nd layer
circle(-43.5+balls_val	,245	,20);//3rd layer

badal();
}

void rectangle(x1,x2,x3,x4,y1,y2,y3,y4)
{
	
	bres(x1,y1,x2,y2);//first horizontal line just above the wheels
	bres(x3,y3,x4,y4);//second horizontal line just above the wheels
	bres(x1,y1,x3,y3);//vertical line above wheel on the left
	bres(x2,y2,x4,y4);//vertical line above wheel on the right
	}


				void drawthefigure()
{
	
//	if(t1!=0||t2!=0)
	{
	glBegin(GL_POINTS);
        balls();
	float p0;
	float pk;
	float pk2;
	p0=1.25-r;
	makexcval();
	float x=0;
	float y=r;
	while(x<y)
	{
		if(pk<0)
		{
			pk2=pk+2*x+1;
			makecircle(x,y,1);//first wheel from left
			makecircle(x,y,2);//second wheel from left
			makecircle(x,y,3);//third wheel from left
			x++;
		}
		else
		{
			pk2=pk+2*x-2*y+1;
			makecircle(x,y,1);
			makecircle(x,y,2);
			makecircle(x,y,3);
			balls();
			x++;
			y--;
		}
		pk=pk2;
		
	}
	float xx=(xc2+xc3)/2;
	float xxx=(xc1+xc2)/2;
	float yy=yc1+62.5;
	float yyy=yc1+97.5;
	glColor3f(0.123f,0.456f,0.789f);
	bres(xc1-50,yc1+50,xc3+50,yc3+50);//first horizontal line just above the wheels
	bres(xc1-50,yc1+75,xc3+50,yc3+75);//second horizontal line just above the wheels
	bres(xc1-50,yc1+50,xc1-50,yc1+75);//vertical line above wheel on the left
	bres(xc3+50,yc3+50,xc3+50,yc3+75);//vertical line above wheel on the right
	
//	rectangle(xc1-50,xc3+50,xc1-50,xc3+50,yc1+50,yc3+50,yc1+75,yc3+75);
	bres(xx,yc3+75,xx,yc3+150);
	bres(xx,yc3+150,xc3+50,yc3+150);
	bres(xc3+50,yc3+50,xc3+50,yc3+150);
	bres(xx+40,yc3+150,xc3+50,yc3);
	/*barrel*/
	bres(xc1-50,yc1+95,xx-25,yc3+95);
	bres(xc1-50,yc1+95,xc1-50,yc3+195);
	bres(xc1-45,yc1+100,xx-30,yc3+100);
	bres(xc1-45,yc1+100,xc1-50,yc3+195);
	bres(xx-25,yc3+95,xx-25,yc3+195);
	bres(xx-30,yc3+100,xx-30,yc3+195);
	bres(xc1-50,yc3+195,xc1-45,yc3+195);	
	bres(xx-30,yc3+195,xx-25,yc3+195);
	/*Hinge*/
	bres(xxx-3,yy,xxx+10,yyy);
	bres(xxx+3,yy,xxx+16,yyy);
	
	/*Lines in the wheels*/
	/* i'm not able to manage their turning*/
	bres(xc1,yc1,xc1+25*cos(theta),yc1+25*sin(theta));
	bres(xc2,yc2,xc2+25*cos(theta),yc2+25*sin(theta));
	bres(xc3,yc3,xc3+25*cos(theta),yc3+25*sin(theta));
	glColor3f(0,1,0);


	bres(-5000,0.4,5000,0.4);
	bres(-5000,0.4,5000,0.3);
	bres(-5000,0.4,5000,0.2);
	bres(-5000,0.4,5000,0.1);
	bres(-5000,0.4,5000,0.0);
	bres(-5000,0.4,5000,-0.1);
	bres(-5000,0.4,5000,-0.2);
	bres(-5000,0.4,5000,-0.3);
	bres(-5000,0.4,5000,-0.4);			
	glEnd();	
	glFlush();
	}
}








					void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	drawthefigure();
	
	}


					void keyboardFunc(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 27:
			{
			exit(0);
			}
		case 'd':
			{
			glFlush();
			xc1=xc1+1;
			balls_val=balls_val+1.0;
			cloud_val=cloud_val+0.1;
			theta=theta-3.142/8;
			display();
			break;
			}
		case 'a':
			{
			glFlush();
			xc1=xc1-1;		
			cloud_val=cloud_val+0.1;
			balls_val=balls_val-1.0;
			theta=theta+3.142/8;
			display();
			break;
			}
}
}		







				void mouse(int btn,int state,int x,int y)
{	
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
		printf("%d\t",x);
		printf("%d\t",y);
		xc1=x;
		makexcval();
		yc1=500-y;
		yc2=500-y;
		yc3=500-y;
		display();
	}	
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_UP)
	{
		printf("%d\t",x);
		printf("%d\t",y);
		xc1=x;
		makexcval();
	//	while(y-->=50)
		{
	//	y=y-10;
	//	yc1=y;
	//	yc2=y;
	//	yc3=y;
		display();
		}	
	}
}









// chumma moving around

					void Motion(int x, int y)
{
		xc1=x;
		makexcval();
		yc1=500-y;
		yc2=500-y;
		yc3=500-y;
		display();
}

					int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("CgLab");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardFunc);
        glutMotionFunc(Motion);
	glutMouseFunc(mouse);	
//glutReshapeFunc(Reshape);
	init();
	glutMainLoop();
}
