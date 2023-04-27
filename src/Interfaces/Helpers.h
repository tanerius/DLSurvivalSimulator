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
    };

    struct Vector2D
    {
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