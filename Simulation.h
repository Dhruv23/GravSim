#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "Body.h"

class Simulation {
private:
    std::vector<Body> bodies;
    const double G = 6.67430e-11; // Gravitational constant

public:
    Simulation();

    void addBody(const Body& body);
    void update(double dt);
    const std::vector<Body>& getBodies() const;
};

#endif
