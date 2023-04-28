#pragma once
#include <cmath>

namespace DLS
{
    struct CellInfo 
    {
        float FeromoneLevel;
        float Toxicity;
        bool Clean;
    };

    struct Coordinate
    {
        int X;
        int Y;

        bool IsValid() { return (X > -1 && Y > -1); }
    };

    struct Polar
    {
        float r;
        float theta; // in radian

        Vector2D ToCartesian() const
        {
            return {r * std::cos(theta), r * std::sin(theta)};
        }
    };

    struct Vector2D
    {
        float x; // r in polar
        float y; // theta in polar

        float Magnitude()
        {
            return sqrt(x*x + y*y);
        }

        static Vector2D Normalize(Vector2D v)
        {
            float mag = v.Magnitude();
            Vector2D ret;
            ret.x = v.x/mag;
            ret.y = v.y/mag;
            return ret;
        }

        static float Distance(Vector2D v1, Vector2D v2)
        {
            return sqrt((v2.x-v1.x)*(v2.x-v1.x) + (v2.y-v1.y)*(v2.y-v1.y));
        }
    };
}