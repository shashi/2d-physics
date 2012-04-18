#include "lib/Util.h"
#include "lib/Screen.h"
#include "classes/Circle.h"
#include "classes/Point.h"
#include "classes/Line.h"

#include<ctime>
#include<cstdio>

// Make points A and B global

Point A = Point(50, 100), B = Point(150, 100), P;

Circle dotA = Circle(A, 10);
Circle dotB = Circle(B, 10);

bool A_sel = true, B_sel = false;

void draw()
{
    
    Line AB = Line(A, B);

    dotA = Circle(A, 10);
    dotB = Circle(B, 10);

    if (A_sel) {
        glColor3f(1.0, 0.0, 0.0);
    }
    dotA.draw();
    glColor3f(1,1,1);
    if (B_sel) {
        glColor3f(1.0, 0.0, 0.0);
    }
    dotB.draw();
    glColor3f(1,1,1);
    AB.draw();
}

void move(int x, int y) {
    y = 400 - y;

    P = Point(x, y);

    if (A_sel) {
        A = P;
    }
    if (B_sel) {
        B = P;
    }
    Screen::Draw();
}

void mouse(int btn,int state,int x,int y)
{	
    y = 400 - y;
    fprintf(stderr, "%d %d %d %d\n",btn,state,x,y);
	if(btn==0&&state==0) {
        // Select.

        Point P = Point(x, y);

        A_sel = dotA.ContainsPoint(P);
        B_sel = dotB.ContainsPoint(P);

        Screen::Draw();
    }
}

int main(int argc, char **argv) {

    Util::Init(argc, argv);

    Screen s = Screen(800, 400, draw);
    s.SetMouseFunction(mouse);
    s.SetMotionFunction(move);
    s.ShowWindow();
    return 0;
}
