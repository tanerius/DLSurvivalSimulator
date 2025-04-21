#pragma once
#include <random>

namespace DLSim
{
    extern thread_local std::mt19937_64 tls_engine;
    unsigned int randomUInt(const uint min, const int max);
}