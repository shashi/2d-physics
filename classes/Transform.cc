#include "classes/Transform.h"
#include <cstring>
#include <cstdio>
#include <cmath>

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

inline void Transform::Translate(float dx, float dy) {
    matrix[0][2] += dx;
    matrix[1][2] += dy;
}

inline void Transform::Rotate(float dtheta) {
    // For small rotations
    // Sin(theta+dtheta) = Sin(theta)cos(dtheta) +
    //                     Cos(theta)sin(dtheta)
    // Cos(theta+dtheta) = Sin(theta)sin(dtheta) -
    //                     Cos(theta)Cos(dtheta)
    // =>
    float sinT = matrix[1][0],
          cosT = matrix[0][0],
          sinT_, cosT_;
    // We are rotating by dtheta.

    sinT_ = sinT*cos(dtheta) + cosT*sin(dtheta);
    cosT_ = cosT*cos(dtheta) - sinT*sin(dtheta);

    matrix[0][0] = matrix[1][1] = cosT_;
    matrix[0][1] = -sinT_;
    matrix[1][0] = sinT_;
}

inline void Transform::Rotate(float dtheta, Point about) {
    // For small rotations
    // Sin(theta+dtheta) = Sin(theta)cos(dtheta) +
    //                     Cos(theta)sin(dtheta)
    // Cos(theta+dtheta) = Sin(theta)sin(dtheta) -
    //                     Cos(theta)Cos(dtheta)
    // =>
    float sinT = matrix[1][0],
          cosT = matrix[0][0],
          sinT_, cosT_;
    // We are rotating by dtheta.

    sinT_ = sinT*cos(dtheta) + cosT*sin(dtheta);
    cosT_ = cosT*cos(dtheta) - sinT*sin(dtheta);

    matrix[0][0] = matrix[1][1] = cosT_;
    matrix[0][1] = -sinT_;
    matrix[1][0] = sinT_;
}

void Transform::AddVelocity(Vector dv) {
    velocity = velocity + dv;
}

void Transform::set_velocity(Vector v) {
    velocity = v;
}

void Transform::AddAcceleration(Vector da) {
    acceleration = acceleration + da;
}

void Transform::AddAngularVelocity(float dmu) {
    angular_velocity += dmu;
}

Point Transform::operator*(Point p) {
    Point result;
    result.x = p.x * matrix[0][0] + p.y * matrix[0][1] + matrix[0][2];
    result.y = p.x * matrix[1][0] + p.y * matrix[1][1] + matrix[1][2];

    return result;
}

void Transform::print() {
    fprintf(stderr, "\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++)
            fprintf(stderr, "%f\t", matrix[i][j]);
        fprintf(stderr, "\n");
    }
}

// Age v.,
// aka. Function Awesome.
void Transform::AddTime(float dt) {
    //fprintf(stderr, "Transform: ");
    // FIXME: Performance hit to add half a t square?
    // Not very trivial, could reach about 1px.
    float dtheta, dx, dy;

    dx = velocity.x + 0.5 * acceleration.x * pow(dt, 2);
    dy = velocity.y + 0.5 * acceleration.y * pow(dt, 2);
    //velocity.print();
    //acceleration.print();

    Translate(dx, dy);
    // Keeping up the velocity is necessary for
    // The formula ut + 1/2 at^2 next time
    // ^^^^^^^ I told you so!
    velocity = velocity + (acceleration * dt);

    dtheta = (angular_velocity * dt) + 0.5 * alpha * pow(dt, 2);
    // angular is a scalar
    Rotate(dtheta);
    angular_velocity += alpha * dt;

    //print();
}

