#include <iostream>
#include <cmath>
#include "Vector2.h"

bool doubleEquals(double a, double b, double epsilon = 1e-9)
{
    return std::abs(a - b) < epsilon;
}

void testConstructors()
{
    Vector2 v1;
    Vector2 v2(3.0, 4.0);

    std::cout << "Constructor Test: "
              << (v1.x == 0 && v1.y == 0 && v2.x == 3.0 && v2.y == 4.0 ? "PASSED" : "FAILED")
              << "\n";
}

void testOperators()
{
    Vector2 v1(1.0, 2.0);
    Vector2 v2(3.0, 4.0);

    Vector2 vAdd = v1 + v2;
    Vector2 vSub = v1 - v2;
    Vector2 vMul = v1 * 2.0;
    Vector2 vDiv = v2 / 2.0;

    v1 += v2;
    v2 -= Vector2(1.0, 1.0);
    v1 *= 0.5;
    v2 /= 2.0;

    std::cout << "Operator Test: "
              << (vAdd.x == 4.0 && vAdd.y == 6.0 &&
                  vSub.x == -2.0 && vSub.y == -2.0 &&
                  vMul.x == 2.0 && vMul.y == 4.0 &&
                  vDiv.x == 1.5 && vDiv.y == 2.0 &&
                  v1.x == 2.0 && v1.y == 3.0 &&
                  v2.x == 1.0 && v2.y == 1.5)
              << "\n";
}

void testMagnitudeNormalize()
{
    Vector2 v(3.0, 4.0);
    double mag = v.magnitude();
    Vector2 norm = v.normalize();

    std::cout << "Magnitude/Normalize Test: "
              << (doubleEquals(mag, 5.0) &&
                  doubleEquals(norm.x, 0.6) &&
                  doubleEquals(norm.y, 0.8))
              << "\n";
}

void testDotDistance()
{
    Vector2 v1(1.0, 0.0);
    Vector2 v2(0.0, 1.0);
    Vector2 v3(3.0, 4.0);

    double dot = v1.dot(v2);                            // Should be 0
    double distance = v3.distanceTo(Vector2(0.0, 0.0)); // Should be 5

    std::cout << "Dot/Distance Test: "
              << (dot == 0.0 && doubleEquals(distance, 5.0))
              << "\n";
}

void testRotation()
{
    Vector2 v(1.0, 0.0);
    Vector2 rotated = v.rotate(M_PI / 2); // 90 degrees rotation

    std::cout << "Rotate Test: "
              << (doubleEquals(rotated.x, 0.0) && doubleEquals(rotated.y, 1.0))
              << "\n";
}

void testEquality()
{
    Vector2 v1(1.0, 2.0);
    Vector2 v2(1.0, 2.0);
    Vector2 v3(2.0, 3.0);

    std::cout << "Equality Test: "
              << (v1 == v2 && !(v1 == v3))
              << "\n";
}

void testZero()
{
    Vector2 zero = Vector2::zeroObj();
    std::cout << "Zero Vector Test: "
              << (zero.x == 0.0 && zero.y == 0.0)
              << "\n";
}

int main()
{
    testConstructors();
    testOperators();
    testMagnitudeNormalize();
    testDotDistance();
    testRotation();
    testEquality();
    testZero();

    return 0;
}
