#pragma once

/// <summary>
/// An Agent interface which describes actions available to an agent
/// </summary>
class IAgent
{
public: 
    /// <summary>
    /// Method to move north
    /// </summary>
    virtual void GoN() = 0; 

    /// <summary>
    /// Method to move west
    /// </summary>
    virtual void GoW() = 0;

    /// <summary>
    /// Method to move south
    /// </summary>
    virtual void GoS() = 0;

    /// <summary>
    /// Method to move south
    /// </summary>
    virtual void GoE() = 0;

    /// <summary>
    /// Method to check if agent is alive
    /// </summary>
    /// <returns>True == alive otherwise false</returns>
    virtual bool IsAlive() = 0;

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