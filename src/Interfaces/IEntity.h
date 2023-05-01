#pragma once

namespace DLS
{
    class Vector2D;
    enum EntityType;

    /// <summary>
    /// An entity that can exist in the world
    /// </summary>
    class IEntity
    {
    public:
        virtual Vector2D PositionVector() = 0;
        virtual Vector2D PositionCoordinate() = 0;
        virtual EntityType EntityType() = 0;
    };
}