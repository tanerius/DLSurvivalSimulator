#pragma once
#include "Helpers.h"
#include "IAgent.h"
#include <unordered_set>

namespace DLS
{
    /// <summary>
    /// A world interface which describes actions available to an agent
    /// </summary>
    class IWorld
    {
    public:
        virtual std::unordered_set<IEntity*> WorldEntities() const = 0;
        /// <summary>
        /// Add an entity to the world
        /// </summary>
        virtual void AddEntityToWorld(IEntity* e) = 0;

        /// <summary>
        /// Remove an entity to the world
        /// </summary>
        virtual void RemoveEntityFromWorld(IEntity* e) = 0;

        /// <summary>
        /// Method for drawing the world and its children
        /// </summary>
        virtual void Draw() = 0;

        /// <summary>
        /// Returns the type of cell
        /// </summary>
        virtual CellInfo GetCellInfo(const Coordinate& c) const = 0;

        /// <summary>
        /// Get a center world position from a coordinate
        /// </summary>
        virtual Vector2D GetCenteredPositionFromCoordinate(const Coordinate& c) const = 0;

        /// <summary>
        /// Get a coordinate from a world position
        /// </summary>
        virtual Coordinate GetCoordinateFromPosition(const Vector2D& v) const = 0;

        /// <summary>
        /// Returns the coordinate of a cell based on a linear index
        /// </summary>
        virtual Coordinate GetCoordinateFromCellIndex(const int index) const = 0;

        /// <summary>
        /// Returns the array index from the given coordinate
        /// </summary>
        virtual int GetIndexFromCoordinate(const Coordinate& coordinate) const = 0;

        /// <summary>
        /// Returns the size of the world
        /// </summary>
        virtual Coordinate GetWorldSize() const = 0;

        /// <summary>
        /// Sets the type of cell
        /// </summary>
        virtual void SetCellType(const Coordinate& c, const CellInfo& info) = 0;

        /// <summary>
        /// Get the x,y size of a cell
        /// </summary>
        virtual Vector2D GetCellSize() const = 0;

        /// <summary>
        /// Sets the size of the world
        /// </summary>
        virtual void SetWorldSize(const Coordinate& size) = 0;
    };
}