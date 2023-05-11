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
        /// Add an entity to the world
        /// </summary>
        virtual void AddEntityToWorld(IEntity* e) = 0;

        /// <summary>
        /// Method for drawing the world and its children
        /// </summary>
        virtual void Draw() = 0;

        /// <summary>
        /// Returns the type of cell
        /// </summary>
        virtual CellInfo GetCellInfo(Coordinate c) = 0;

        /// <summary>
        /// Get a center world position from a coordinate
        /// </summary>
        virtual Vector2D GetCenteredPositionFromCoordinate(Coordinate c) = 0;

        /// <summary>
        /// Get a coordinate from a world position
        /// </summary>
        virtual Coordinate GetCoordinateFromPosition(Vector2D v) = 0;

        /// <summary>
        /// Returns the coordinate of a cell based on a linear index
        /// </summary>
        virtual Coordinate GetCoordinateFromCellIndex(int index) = 0;

        /// <summary>
        /// Returns the array index from the given coordinate
        /// </summary>
        virtual int GetIndexFromCoordinate(Coordinate coordinate) = 0;

        /// <summary>
        /// Returns the size of the world
        /// </summary>
        virtual Coordinate GetWorldSize() = 0;

        /// <summary>
        /// Sets the type of cell
        /// </summary>
        virtual void SetCellType(Coordinate c, CellInfo info) = 0;

        /// <summary>
        /// Sets the size of the world
        /// </summary>
        virtual void  SetWorldSize(Coordinate size) = 0;
    };
}