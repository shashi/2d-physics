#include "simulator/System.h"
#include "classes/Circle.h"
#include <vector>
#include <cstdio>
#include <iostream>
#include <typeinfo>

void System::AddObject(Circle* circle) {
    std::vector<Vector>::iterator it;
    for(it=forces.begin(); it < forces.end(); it++) {
        circle->transform.AddAcceleration(*it / circle->weight());
    }
    circles.push_back(circle);
}

void System::AddObject(Rectangle* rec) {
    std::vector<Vector>::iterator it;
    for(it=forces.begin(); it < forces.end(); it++) {
        rec->transform.AddAcceleration(*it / rec->weight());
    }
    rectangles.push_back(rec);
}

// This is force is acceleration for now
void System::AddForce(Vector f) {
    unsigned  int i;
    for(i=0; i < circles.size() ; i++) {
        circles[i]->transform.AddAcceleration(f);
    }

    for(i=0; i < rectangles.size() ; i++) {
        rectangles[i]->transform.AddAcceleration(f);
    }
}

void System::AddTime(float time) {
    unsigned int i;
    for(i=0; i < circles.size(); i++) {
        circles[i]->transform.AddTime(time);
    }
    for(i=0; i < rectangles.size(); i++) {
        rectangles[i]->transform.AddTime(time);
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
        circles[i]->draw();
    }
    for(i=0; i<rectangles.size(); i++) {
        rectangles[i]->draw();
    }
}
