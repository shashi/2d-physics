#include "lib/Util.h"
#include "lib/Screen.h"
#include "classes/Circle.h"
#include "classes/Rectangle.h"
#include "simulator/System.h"
#include "classes/Point.h"
#include "classes/Line.h"

#include<sys/time.h>
#include<ctime>
#include<cstdio>

#define PIXELS_PER_METER 0.05

System sys;
Circle * c = new Circle(0, 0, 20);
Vector gravity = Vector(0, -9.8 * PIXELS_PER_METER);
long t;
float dt = 0.00;
struct timeval start_time, end_time;

void draw () {
    sys.AddTime(dt);
    sys.draw();
}

void idle () {
    Screen::Draw();
    gettimeofday(&end_time, NULL);
    dt = (end_time.tv_sec - start_time.tv_sec + (float) (end_time.tv_usec - start_time.tv_usec) / 1000000.0);
    start_time = end_time;

    fprintf(stderr, "%f\n", dt);
}

int main (int argc, char **argv) {
    Screen s = Screen(800, 400, draw);
    c->transform.AddVelocity(Vector(10 * PIXELS_PER_METER, 30 * PIXELS_PER_METER));
    sys.AddObject(c);
    sys.AddForce(gravity);

    Util::Init(argc, argv);

    //s.SetMouseFunction(mouse);
    //s.SetMotionFunction(move);
    s.SetIdleFunction(idle);
    gettimeofday(&start_time, NULL);
    s.ShowWindow();
    return 0;
}
