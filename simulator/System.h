#ifndef SIMULATOR_SYSTEM_
#define SIMULATOR_SYSTEM_

#include "classes/Body.h"
#include "classes/Rectangle.h"
#include "classes/Circle.h"
#include "classes/Vector.h"
#include <vector>

class System {
  public:
    std::vector<Circle*> circles;
    std::vector<Rectangle*> rectangles;
    std::vector<Vector> forces;
    System();
    void AddObject(Circle*);
    void AddObject(Rectangle*);
    void AddForce(Vector vector);
    void draw();
    void Dump(); // Save to a display file
    void Load(); // Load from the display file
    void AddTime(float dt);
    void HandleCollisions();
};

#endif // SIMULATOR_SYSTEM_
