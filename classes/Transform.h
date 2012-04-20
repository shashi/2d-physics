#ifndef CLASSES_TRANSFORM_
#define CLASSES_TRANSFORM_

#include "classes/Point.h"
#include "classes/Vector.h"

#include <iostream>
#include <math.h>

/**
 * A transformation
 *
 * TODO: overload *
 *
 */
class Transform {
  public:

    float matrix[3][3];

    /**
     * set matrix
     */
    void set_matrix(float[3][3]);
    void set_velocity(Vector);

    /**
     * Velocity
     */
    Vector velocity;

    /**
     * Acceleration
     */
    Vector acceleration;

    /**
     * Angular velocity
     */
    float angular_velocity;

    /**
     * alpha
     */
    float alpha;

    /**
     * Constructor, initialize a unit matrix
     */
    Transform(void);

    /**
     * Transform a point
     */
    Point operator*(Point inp);

    /**
     * Add rotation by an angle to the transform
     */
    void Rotate(float by);
    void Rotate(float by, Point about);

    /**
     * Add a translation to the transformation matrix
     */
    void Translate(float, float);

    /**
     * Add velocity
     */
    void AddVelocity(Vector v);

    /**
     * Add acceleration
     */
    void AddAcceleration(Vector a);

    /**
     * Add velocity
     */
    void AddAngularVelocity(float);

    /**
     * Awesomesauce.
     */
    void AddTime(float);

    void print();
};

#endif // CLASSES_TRANSFORM_
