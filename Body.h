#ifndef BODY_H
#define BODY_H

#include "Vector2.h"

class Body {
public:
    double mass;
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;

    Body();
    Body(double mass, Vector2 position, Vector2 velocity);

    void update(double dt);
    void applyForce(const Vector2& force);
};

#endif
