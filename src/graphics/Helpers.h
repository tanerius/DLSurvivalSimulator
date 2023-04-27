#pragma once
#include <cmath>

namespace DLS
{
    struct Vector2D
    {
        Vector2D() : x(0), y(0) { }
        Vector2D(float x, float y) : x(x), y(y) { }
        float x;
        float y;

        float Magnitude()
        {
            return sqrt(x*x + y*y);
        }

        static Vector2D Normalize(Vector2D v)
        {
            float mag = v.Magnitude();
            return Vector2D(v.x/mag, v.y/mag);
        }
    };
}