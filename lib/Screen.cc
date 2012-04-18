#include "lib/Screen.h"
#include <cstdio>

Screen::Screen () {
    bgColor[0] = bgColor[1] = bgColor[2] = 0.0;
    fgColor[0] = fgColor[1] = fgColor[2] = 1.0;
}

Screen::Screen(float w, float h, void (*draw_function)()) {
    SetDrawFunction(draw_function);
    width  = w;
    height = h;

    bgColor[0] = bgColor[1] = bgColor[2] = 0.0;
    fgColor[0] = fgColor[1] = fgColor[2] = 1.0;
}

void Screen::Width(float w) {
	// resize
    width = w;
}

void Screen::Height(float h) {
	// resize
    height = h;
}

float Screen::Width() {
    return width;
}

float Screen::Height() {
    return height;
}

// wraps drawFunction around required OpenGL functions
void Screen::Setup() {
    glClearColor(0.0, bgColor[0], bgColor[1], bgColor[2]);

    glColor3f(fgColor[0], fgColor[1], fgColor[2]);

    glOrtho(0, Width(), 0, Height(), 0, 500);

    // load identity matrix as the transformation matrix
    float matrix[] = {1, 0, 0, 0,
                      0, -1, 0, Height(),
                      0, 0, 1, 0,
                      0, 0, 0, 1};
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
}

// HACK: to pass instance variable  to static function
void (*__drawFunction)();
void (*__mouseFunction)(int, int, int, int);
void (*__motionFunction)(int, int);
void (*__passiveMotionFunction)(int, int);
void Screen::Draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

    glBegin(GL_POINTS);

    __drawFunction();

    glEnd();
    glFlush();
}

void _mouse(int a, int  b, int c, int d) {
    fprintf(stderr, "%d %d %d %d\n", a, b, c, d);
}

void Screen::ShowWindow() {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(Width(), Height());
    glutInitWindowPosition(0,0);
    glutCreateWindow("Physics Simulator");
    __drawFunction = drawFunction;
    glutDisplayFunc(Draw);
    glutMouseFunc(__mouseFunction);
    glutMotionFunc(__motionFunction);
    glutPassiveMotionFunc(__passiveMotionFunction);

    Setup();

    glutMainLoop();
}

void Screen::SetDrawFunction(void (*df) ()) {
    drawFunction = df;
}

void Screen::SetMouseFunction(void (*mf) (int, int, int, int)) {
    __mouseFunction = mf;
}

void Screen::SetMotionFunction(void (*mf) (int, int)) {
    __motionFunction = mf;
}

void Screen::SetPassiveMotionFunction(void (*mf) (int, int)) {
    __passiveMotionFunction = mf;
}

