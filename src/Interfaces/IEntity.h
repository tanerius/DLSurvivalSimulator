#pragma once

#include "Helpers.h"
namespace DLS
{
    /// <summary>
    /// An entity that can exist in the world
    /// </summary>
    class IEntity
    {
    public:
        virtual EntityType Type() const = 0;
        virtual Vector2D PositionVector() const = 0;
    };
}
