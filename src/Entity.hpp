#pragma once

#include "Types.hpp"

namespace DLSim
{
    class Entity
    {
        public:
        unsigned int Id;
        EntityType Type;

        
        Entity(unsigned int id, EntityType type) : Id(id), Type(type) {}
        Entity() = delete;
    };
}
