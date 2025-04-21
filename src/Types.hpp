#pragma once
#include <random>
#include <limits>

namespace DLSim
{
    using uint = unsigned int;

    enum class EntityType : unsigned int
    {
        Wall = 1,
        Agent = 1000
    };

    struct Coordinate
    {
        uint X;
        uint Y;

        Coordinate(unsigned int x, unsigned int y) : X(x), Y(y) {}
        Coordinate() : X(0), Y(0) {}

        bool IsValid() const
        {
            return X >= 0 && Y >= 0;
        }
    };

    // Each thread gets its own engine, seeded once.
    // No mutexes, no contention.
    thread_local std::mt19937_64 tls_engine{std::random_device{}()};

    /**
     * @brief Returns a uniformly distributed random unsigned int in [min, max].
     *        Thread‑safe thanks to thread_local engine.
     */
    unsigned int randomUInt(const uint min, const int max)
    {
        std::uniform_int_distribution<unsigned int> dist(min, max);
        return dist(tls_engine);
    }

}