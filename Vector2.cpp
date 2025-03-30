#include "Vector2.h"
#include <cmath>
/* Constructors */
Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(double x, double y) : x(x), y(y) {}

/* OPERATORS */
Vector2 Vector2::operator+(const Vector2 &other) const
{
    return Vector2(x + other.x, y + other.y);
}
Vector2 &Vector2::operator+=(const Vector2 &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 Vector2::operator-(const Vector2 &other) const
{
    return Vector2(x - other.x, y - other.y);
}
Vector2 &Vector2::operator-=(const Vector2 &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2 Vector2::operator*(double scalar) const
{
    return Vector2(scalar * x, scalar * y);
}
Vector2 &Vector2::operator*=(double scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2 Vector2::operator/(double scalar) const
{
    return Vector2(x / scalar, y / scalar);
}
Vector2 &Vector2::operator/=(double scalar)
{
    x /= scalar;
    y /= scalar;
    return *this;
}

bool Vector2::operator==(const Vector2 &other) const
{
    return x == other.x && y == other.y;
}

/* FUNCTIONS */
double Vector2::magnitude() const
{
    return (std::sqrt((x * x) + (y * y)));
}

Vector2 Vector2::normalize() const
{
    double magnitude = this->magnitude();
    if (magnitude == 0)
        return Vector2(0, 0);
    double normalX = x / magnitude;
    double normalY = y / magnitude;

    return Vector2(normalX, normalY);
}

double Vector2::dot(const Vector2 &other) const
{
    return x * other.x + y * other.y;
}

double Vector2::distanceTo(const Vector2 &other) const
{
    return (*this - other).magnitude();
}
Vector2 Vector2::rotate(double angleRadians) const
{
    double cosA = std::cos(angleRadians);
    double sinA = std::sin(angleRadians);
    return Vector2(x * cosA - y * sinA, x * sinA + y * cosA);
}

void Vector2::zero()
{
    x = 0;
    y = 0;
}