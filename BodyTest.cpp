#include <iostream>
#include <cmath>
#include "Vector2.h"
#include "Body.h"

bool doubleEquals(double a, double b, double epsilon = 1e-9)
{
    return std::abs(a - b) < epsilon;
}

void testConstructor()
{
    Body b(10.0, 5.0, Vector2(2.0, 3.0), Vector2(1.0, 0.0));

    if (
        doubleEquals(b.mass, 10.0) &&
        b.position == Vector2(2.0, 3.0) &&
        b.velocity == Vector2(1.0, 0.0) &&
        doubleEquals(b.radius, 5.0))
    {
        std::cout << "Constructor Test: PASSED\n";
    }
    else
    {
        std::cout << "Constructor Test: FAILED\n";
    }
}

void testApplyForce()
{
    Body b(10.0, 1.0, Vector2(), Vector2());
    b.applyForce(Vector2(20.0, 0.0));

    if (b.acceleration == Vector2(2.0, 0.0))
    {
        std::cout << "Apply Force Test: PASSED\n";
    }
    else
    {
        std::cout << "Apply Force Test: FAILED\n";
    }
}

void testUpdate()
{
    Body b(5.0, 1.0, Vector2(0.0, 0.0), Vector2(1.0, 0.0));
    b.applyForce(Vector2(5.0, 0.0)); // a = 1, v += 1*dt = 2, pos += 2*dt = 2
    b.update(1.0);

    if (
        b.velocity == Vector2(2.0, 0.0) &&
        b.position == Vector2(2.0, 0.0) &&
        b.acceleration == Vector2(0.0, 0.0))
    {
        std::cout << "Update Test: PASSED\n";
    }
    else
    {
        std::cout << "Update Test: FAILED\n";
    }
}

void testDistanceTo()
{
    Body a(1.0, 1.0, Vector2(0.0, 0.0), Vector2());
    Body b(1.0, 1.0, Vector2(3.0, 4.0), Vector2());

    double d = a.distanceTo(b);
    if (doubleEquals(d, 5.0))
    {
        std::cout << "Distance To Test: PASSED\n";
    }
    else
    {
        std::cout << "Distance To Test: FAILED\n";
    }
}

void testCollision()
{
    Body a(1.0, 2.0, Vector2(0.0, 0.0), Vector2());
    Body b(1.0, 2.0, Vector2(3.0, 0.0), Vector2()); // Distance = 3, Radii sum = 4

    if (a.isCollidingWith(b))
    {
        std::cout << "Collision Test: PASSED\n";
    }
    else
    {
        std::cout << "Collision Test: FAILED\n";
    }
}

int main()
{
    testConstructor();
    testApplyForce();
    testUpdate();
    testDistanceTo();
    testCollision();
    return 0;
}
