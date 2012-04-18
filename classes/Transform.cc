#include "classes/Transform.h"
#include <cstring>

void Transform::set_matrix(float new_transform_matrix[3][3]) {
    memcpy(matrix, new_transform_matrix, sizeof(new_transform_matrix));
}

Transform::Transform(void) {
    float identity_matrix[3][3] = {
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0
    };
    set_matrix(identity_matrix);
}

void Transform::addTranslate(float dx, float dy) {
    matrix[0][2] += dx;
    matrix[1][2] += dy;
}
