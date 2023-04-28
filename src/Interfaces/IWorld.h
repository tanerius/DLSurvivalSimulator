#pragma once
#include "Helpers.h"
#include "IAgent.h"

namespace DLS
{
    /// <summary>
    /// A world interface which describes actions available to an agent
    /// </summary>
    class IWorld
    {
    public:
        /// <summary>
        /// Method for drawing the world and its children
        /// </summary>
        virtual void Draw() = 0;

        /// <summary>
        /// Get a center world position from a coordinate
        /// </summary>
        virtual Vector2D GetCenteredPositionFromCoordinate(Coordinate c) = 0;

        /// <summary>
        /// Get a coordinate from a world position
        /// </summary>
        virtual Coordinate GetCoordinateFromPosition(Vector2D v) = 0;

        /// <summary>
        /// Add an agent to a random position in the world
        /// </summary>
        virtual Coordinate AddAgentToWorld(IAgent* agent) = 0;
        
        /// <summary>
        /// Returns the type of cell
        /// </summary>
        virtual CellInfo GetCellType(Coordinate c) = 0;

        /// <summary>
        /// Sets the type of cell
        /// </summary>
        virtual void SetCellType(Coordinate c, CellInfo info) = 0;

        /// <summary>
        /// Returns the coordinate of a cell based on a linear index
        /// </summary>
        virtual Coordinate GetCoordinateFromCellIndex(int index) = 0;

        /// <summary>
        /// Returns the size of the world
        /// </summary>
        virtual Coordinate GetWorldSize() = 0;

        /// <summary>
        /// Sets the size of the world
        /// </summary>
        virtual void  SetWorldSize(Coordinate size) = 0;

        /// <summary>
        /// Update method
        /// </summary>
        virtual void Update() = 0;
    };
}