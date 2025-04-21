#include "Random.hpp"

namespace DLSim
{
    thread_local std::mt19937_64 tls_engine{std::random_device{}()};

    unsigned int randomUInt(const uint min, const int max)
    {
        std::uniform_int_distribution<unsigned int> dist(min, max);
        return dist(tls_engine);
    }
}