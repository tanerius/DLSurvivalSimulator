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
        /// <summary>
        /// Method to check if entity has collided with something
        /// </summary>
        /// <returns>True == agent has collided otherwise false</returns>
        virtual bool HasCollided() = 0;
        virtual Vector2D PositionVector() const = 0;
        virtual EntityType Type() const = 0;
        /// <summary>
        /// Method to be called on each frame which will update enity values
        /// </summary>
        virtual void Update() = 0;
    };
}
