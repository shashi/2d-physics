#include "simulator/System.h"
#include "classes/Circle.h"
#include <vector>
#include <cstdio>
#include <iostream>
#include <typeinfo>
#include <GL/glut.h>

#define BOXED true

void System::AddObject(Circle* circle) {
    unsigned  int i;
    for(i=0; i < forces.size() ; i++) {
        circle->transform.AddAcceleration(forces[i] / circle->weight());
    }
    for(i=0; i < accelerations.size() ; i++) {
        circle->transform.AddAcceleration(
            accelerations[i]
        );
    }
    circles.push_back(circle);
}

void System::AddGlobalAcceleration(Vector acc) {
    unsigned  int i;
    for(i=0; i < circles.size() ; i++) {
        circles[i]->transform.AddAcceleration(acc);
    }
    accelerations.push_back(acc);
}

void System::AddObject(Rectangle* rec) {
    std::vector<Vector>::iterator it;
    for(it=forces.begin(); it < forces.end(); it++) {
        rec->transform.AddAcceleration(
            *it / rec->weight()
        );
    }
    rectangles.push_back(rec);
}

// This is force is acceleration for now
void System::AddForce(Vector f) {
    unsigned  int i;
    for(i=0; i < circles.size() ; i++) {
        circles[i]->transform.AddAcceleration(
            f / circles[i]->weight()
        );
    }

    for(i=0; i < rectangles.size() ; i++) {
        rectangles[i]->transform.AddAcceleration(
            f / circles[i]->weight()
        );
    }
    forces.push_back(f);
}

void System::HandleClick(int x, int y) {
    unsigned  int i;
    for(i=0; i < circles.size() ; i++) {
        if (circles[i]->ContainsPoint(Point(x, y))) {
            circles[i]->fg_color[0] = 1;
            circles[i]->fg_color[1] = 0;
            circles[i]->fg_color[2] = 0;
        } else {
            circles[i]->fg_color[0] = 1;
            circles[i]->fg_color[1] = 1;
            circles[i]->fg_color[2] = 1;
        }
    }
}

void System::AddTime(float time) {
    unsigned int i;
    for(i=0; i < circles.size(); i++) {
        if (!circles[i]->fixed) {
            circles[i]->transform.AddTime(time);
        }
    }
    for(i=0; i < rectangles.size(); i++) {
        if (!rectangles[i]->fixed) {
            rectangles[i]->transform.AddTime(time);
        }
    }

    if (BOXED) {
        for(i=0; i < circles.size(); i++) {
            Point c = circles[i]->Centroid();
            Vector v = circles[i]->transform.velocity;
            float r = circles[i]->radius;
            if (c.x - r<= 0 || c.x + r >= 800) {
                circles[i]->transform.AddVelocity(
                    Vector(-2 * v.x, 0));
            }
            if (c.y - r<= 0 || c.y + r >= 400) {
                circles[i]->transform.AddVelocity(
                    Vector(0, -2 * v.y));
            }
        }
    }
    HandleCollisions();
}

void System::HandleCollisions() {
    unsigned int i, j;
    // Will the order matter?
    // Yes. But is it neglegible?
    // Is it better to create a copy?
    for(i=0; i<circles.size(); i++) {
        // rectangles and the circles
        for(j=0; j < rectangles.size(); j++) {
            circles[i]->InteractWith(rectangles[j]);
        }
        // circles and circles
        for(j=i+1; j < circles.size(); j++) {
            circles[i]->InteractWith(circles[j]);
        }
    }

    for(i=0; i<rectangles.size(); i++) {
        // rectangles and rectangles
        for(j=i+1; j < rectangles.size(); i++) {
            rectangles[i]->InteractWith(rectangles[j]);
        }
    }
}

System::System() {
}

void System::draw() {
    unsigned int i;
    for(i=0; i<circles.size(); i++) {
        float *c = circles[i]->fg_color;
        glColor3f(c[0], c[1],c[2]);
        circles[i]->draw();
    }
    for(i=0; i<rectangles.size(); i++) {
        rectangles[i]->draw();
    }
}
