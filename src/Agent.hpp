#pragma once
#include "Types.hpp"

namespace DLSim
{
    class Agent : public Entity
    {
    public:
        Agent(const unsigned int id, const EntityType type) : Entity{id, type} {};
        Agent() = delete;
        ~Agent() = default;
    };
}