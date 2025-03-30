#include "Body.h"

Body::Body() : mass(0), position(), velocity(), acceleration() {}
Body::Body(double mass, Vector2 position, Vector2 velocity)
    : mass(mass), position(position), velocity(velocity), acceleration() {}

// Function definitions will be filled in later.
