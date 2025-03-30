#include <iostream>
#include "Simulation.h"
#include "Body.h"
#include "Vector2.h"
#include "Render.h"

int main() {
    Simulation sim;
    Renderer renderer;
    Body body1(5.972e24, Vector2(0, 0), Vector2(0, 0)); // Example: Earth
    Body body2(7.348e22, Vector2(384400000, 0), Vector2(0, 1022)); // Example: Moon

    sim.addBody(body1);
    sim.addBody(body2);

    double timestep = 1.0; // seconds
    for (int i = 0; i < 1000; ++i) {
        sim.update(timestep);
        // Print or log positions here if needed
    }

    return 0;
}
