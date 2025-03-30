#ifndef RENDER_H
#define RENDER_H

#include <vector>
#include "Body.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void init();
    void render(const std::vector<Body>& bodies);
    void cleanup();
};

#endif
