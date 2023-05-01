#pragma once
#include "IEntity.h"

namespace DLS
{
    class Vector2D; 
    /// <summary>
    /// An Agent interface which describes actions available to an agent
    /// </summary>
    class IAgent : public IEntity
    {
    public:
        virtual void Accelerate() = 0;
        virtual float GetSpeed() const = 0;
        virtual float GetOrientationAngle() const = 0;
        virtual void RotateLeft() = 0;
        virtual void RotateRight() = 0;
        virtual void Reverse() = 0;
        virtual void Stop() = 0;
        virtual Vector2D GetForwardVector() const = 0;

        /// <summary>
        /// Method to check if agent is alive
        /// </summary> 
        /// <returns>True == alive otherwise false</returns>
        virtual bool IsAlive() const = 0;
    };
}