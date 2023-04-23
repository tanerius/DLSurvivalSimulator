#pragma once

/// <summary>
/// An Agent interface which describes actions available to an agent
/// </summary>
class IAgent
{
public: 
    /// <summary>
    /// Method to move agent forward
    /// </summary>
    void Accelerate() = 0; 

    /// <summary>
    /// Method to stop agent
    /// </summary>
    void Deccelerate() = 0;

    /// <summary>
    /// Method to modify the agents' forward vector orientaiton
    /// </summary>
    /// <param name="deg">The compass direction to turn to in degrees</param>
    void TurnTo(float deg) = 0;

    /// <summary>
    /// Method to check if agent is alive
    /// </summary>
    /// <returns>True == alive otherwise false</returns>
    bool IsAlive() = 0;

    /// <summary>
    /// Method to check if agent has collided with something
    /// </summary>
    /// <returns>True == agent has collided otherwise false</returns>
    bool HasCollided() = 0;
};