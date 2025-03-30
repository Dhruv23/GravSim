#include "Body.h"

// CONSTRUCTORS
Body::Body() : mass(0), radius(0), position(), velocity(), acceleration() {}
Body::Body(double mass, double radius, Vector2 position, Vector2 velocity)
    : mass(mass), radius(radius), position(position), velocity(velocity), acceleration() {}

// FUNCTIONS
void Body::update(double dt)
{
    velocity += (acceleration * dt);
    position += (velocity * dt);
    acceleration.zero();
}
void Body::applyForce(const Vector2 &force)
{
    if (mass == 0)
    {
        return;
    }
    Vector2 accelFromForce = force / mass;
    acceleration += accelFromForce;
}
double Body::distanceTo(const Body &other) const
{
    return this->position.distanceTo(other.position);
}
bool Body::isCollidingWith(const Body &other) const
{
    if (distanceTo(other) >= (this->radius + other.radius))
    {
        return false;
    }
    return true;
}
