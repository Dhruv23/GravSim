#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
    double x, y;

    Vector2();
    Vector2(double x, double y);

    Vector2 operator+(const Vector2 &other) const;
    Vector2 operator-(const Vector2 &other) const;
    Vector2 operator*(double scalar) const;
    Vector2 operator/(double scalar) const;

    Vector2 &operator+=(const Vector2 &other);
    Vector2 &operator-=(const Vector2 &other);
    Vector2 &operator*=(double scalar);
    Vector2 &operator/=(double scalar);

    bool operator==(const Vector2 &other) const;

    double magnitude() const;
    Vector2 normalize() const;
    double dot(const Vector2 &other) const;
    double distanceTo(const Vector2 &other) const;
    Vector2 rotate(double angleRadians) const;

    static Vector2 zeroObj() { return Vector2(0, 0); }
    void zero();
};

#endif
