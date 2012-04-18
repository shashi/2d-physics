#ifndef CLASSES_BODY_
#define CLASSES_BODY_

#include "classes/Point.h"
#include "classes/GraphicObject.h"
//#include "classes/Force.h"

class Body: public GraphicObject {
  public:
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
    Point centroid();

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
    void interactWith(Body body);

    /**
     * Weight = area or length * density
     */
    float weight();

    /**
     * area
     */
    float area();
};

#endif // CLASSES_BODY_
