#include<iostream>
#include<math.h>

/**
 * A transformation
 *
 * TODO: overload +, -
 */
class Transform {
  public:

    float matrix[3][3];

    /**
     * set matrix
     */
    void set_matrix(float[3][3]);

    /**
     * Constructor, initialize a unit matrix
     */
    Transform(void);
    /**
     * Add rotation by an angle to the transform
     */
    void addRotate(void);

    /**
     * Add a translation to the transformation matrix
     */
    void addTranslate(float, float);
};
