#include "classes/Body.h"

#include <vector>

#include "classes/Anchor.h"

using namespace std;

class CompositeBody: public Body {
  public:
    vector<Body> parts;

    CompositeBody();
    void draw();
    float weight();
    float moment();
    Point centroid();
    float moment(Point);

    void ApplyTransform(Transform trans);
};
