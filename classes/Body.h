#ifndef CLASSES_BODY_
#define CLASSES_BODY_

#include "classes/Point.h"
#include "classes/Vector.h"
#include "classes/Transform.h"
#include "classes/GraphicObject.h"
//#include "classes/Force.h"

#define BODY_LINE 1
#define BODY_CIRCLE 2
#define BODY_RECTANGLE 3

class Body: public GraphicObject {
  private:
    int type;
  public:
    void setType(int t) {
        t = type;
    }
    int getType() {
        return type;
    }
    /**
     * Density of the shape
     *
     * for example: a value of 2.0 means this shape is twice
     * as that of another with the same area and 1.0 density
     *
     */
    double density;

    /*
     * Young's modulus
     */
    double youngs;

    /*
     * Friction coeffecient at the boundaries
     */
    double friction;

    /**
     * Only bodies in the same layer can interact with each other.
     */
    int layer;

    /**
     * Constructor: set-up default attribute values
     */
    Body();

    /**
     * Draw the shape in its current state
     */
    void draw();

    /**
     * Get the centroid of the shape
     */
    Point Centroid();

    /**
     * Get moment of inertia about a line perpendicular to the plane
     * and passing through the centroid
     */
    float moment();

    /**
     * Get moment of inertia about a line perpendicular to the plane
     * and passing through a given point
     */
    float moment(Point about);

    /**
     * Move the shape
     */
    void translate(int dx, int dy);

    /**
     * Rotate the shape by an angle
     */
    void rotate(double dtheta);

    /**
     * Apply a transformation matrix on the shape
     */
    void ApplyTransform(Transform trans);

    /**
     * Interact with another body
     */
    void InteractWith(Body * body);

    /**
     * Weight = area or length * density
     */
    float weight();

    /**
     * area
     */
    float area();

    /**
     *
     */
    Transform transform;

    void ApplyImpulse(Vector delmom, float delangular);

    void AddTime(float dt);
    Vector momentum();
};

#endif // CLASSES_BODY_
