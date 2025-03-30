#include "Simulation.h"

Simulation::Simulation() {}

void Simulation::addBody(const Body &body)
{
    bodies.push_back(body);
}

const std::vector<Body> &Simulation::getBodies() const
{
    return bodies;
}

void Simulation::update(double dt)
{
    // Empty stub for now
}
