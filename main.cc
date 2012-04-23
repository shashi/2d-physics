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

#define PIXELS_PER_METER_X 0.05
#define PIXELS_PER_METER_Y 0.06

System sys;
Circle * c  = new Circle(100, 300, 20);

Vector gravity = Vector(0, -4.8 * PIXELS_PER_METER_Y);
long t;
float dt = 0.00;
struct timeval start_time, end_time;
bool paused = false;

Point seed_point = Point(400, 200);
Circle * circ = new Circle(seed_point, 20);

void draw () {
    if (paused) {
        circ->draw();
    } else {
        sys.AddTime(dt);
    }
    sys.draw();
}

void idle () {
    Screen::Draw();
    gettimeofday(&end_time, NULL);
    dt = (end_time.tv_sec - start_time.tv_sec + (float) (end_time.tv_usec - start_time.tv_usec) / 1000000.0);
    start_time = end_time;
}

void mouse(int btn, int state, int x, int y) {
    y = 400 - y;
    if (btn == 0 && state == 0) {
        sys.HandleClick(x, y);
        fprintf(stderr, "%d %d", x, y);
        paused = true;
        seed_point = Point(x, y);
    }
    if (btn == 0 && state == 1) {
        paused = false;
        sys.AddObject(circ);
    }
}

void motion(int x, int y) {
    y = 400 - y;
    circ = new Circle(
        seed_point,
        Line(seed_point, Point(x, y)).length()
    );

    float angle = Line(seed_point, Point(x, y)).angle();
    circ->transform.Rotate(angle);
    circ->transform.AddAngularVelocity(angle);
}

int main (int argc, char **argv) {
    Screen s = Screen(800, 400, draw);
    c->transform.AddVelocity(
        Vector(15 * PIXELS_PER_METER_X, 0)
    );
    c->transform.AddAngularVelocity(PI / 4);

    sys.AddObject(c);
    sys.AddGlobalAcceleration(gravity);

    Util::Init(argc, argv);

    s.SetIdleFunction(idle);
    s.SetMouseFunction(mouse);
    s.SetMotionFunction(motion);
    gettimeofday(&start_time, NULL);
    s.ShowWindow();
    return 0;
}
