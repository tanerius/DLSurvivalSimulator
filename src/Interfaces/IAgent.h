#pragma once

namespace DLS
{
    class Vector2D; 

    /// <summary>
    /// An Agent interface which describes actions available to an agent
    /// </summary>
    class IAgent
    {
    public:
        virtual void Accelerate() = 0;
        virtual float GetSpeed() const = 0;
        virtual void RotateLeft() = 0;
        virtual void RotateRight() = 0;
        virtual void Reverse() = 0;
        virtual void Stop() = 0;
        virtual Vector2D GetForwardVector() const = 0;
        virtual Vector2D GetPositionVector() const = 0;

        /// <summary>
        /// Method to check if agent is alive
        /// </summary> 
        /// <returns>True == alive otherwise false</returns>
        virtual bool IsAlive() const = 0;

        /// <summary>
        /// Method to check if agent has collided with something
        /// </summary>
        /// <returns>True == agent has collided otherwise false</returns>
        virtual bool HasCollided() = 0;

        /// <summary>
        /// Method to be called on each frame which will update enity values
        /// </summary>
        virtual void Update() = 0;
    };
}