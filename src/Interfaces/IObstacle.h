#pragma once
#include "Helpers.h"
#include "IEntity.h"

namespace DLS
{
    /// <summary>
    /// An obstacle in case we heed specifics later
    /// </summary>
    class IObstacle : public IEntity
    {
        public:
        virtual Coordinate GetCoordinate() const = 0;
        virtual void SetCoordinate(const Coordinate& c) = 0;
    };
}