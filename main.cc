#include "lib/Util.h"
#include "lib/Screen.h"
#include "classes/Circle.h"
#include "classes/Point.h"
#include "classes/Line.h"

#include<ctime>
#include<cstdio>

// Make points A and B global

Point A = Point(200, 200);

float radius=0;
Circle dotA = Circle(A, 0);

void draw()
{
    dotA = Circle(A, radius);
    dotA.draw();
}

void move(int x,int y)
{	
    y = 400 - y;
    radius = Line(Point(x, y), A).length();
    Screen::Draw();
}

int main(int argc, char **argv) {

    Util::Init(argc, argv);

    Screen s = Screen(800, 400, draw);
    s.SetMotionFunction(move);
    s.ShowWindow();
    return 0;
}
