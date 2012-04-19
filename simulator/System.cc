#include "simulator/System.h"
#include "classes/Circle.h"
#include <vector>
#include <cstdio>

void System::AddObject(Body* body) {
    std::vector<Vector>::iterator it;
    for(it=forces.begin(); it < forces.end(); it++) {
        body->transform.AddAcceleration(*it / body->weight());
    }
    bodies.push_back(body);
}

// This is force is acceleration for now
void System::AddForce(Vector f) {
    std::vector<Body*>::iterator it;
    for(it=bodies.begin(); it < bodies.end(); it++) {
        (*it)->transform.AddAcceleration(f);
    }
}

void System::AddTime(float time) {
    std::vector<Body*>::iterator it;
    for(it=bodies.begin(); it < bodies.end(); it++) {
        (*it)->transform.AddTime(time);
    }
}

void System::HandleCollisions() {
    for(int i=0; i<bodies.size(); i++) {
        for(int j=i+1; j < bodies.size(); i++) {
            ((Circle *) bodies[i])->InteractWith(bodies[j]);
        }
    }
}

System::System() {
}

void System::draw() {
    for(int i=0; i<bodies.size(); i++) {
        ((Circle *) bodies[i])->draw();
    }
}
