#pragma once
#include <Helpers.h>
#include <IAgent.h>
#include <vector>

namespace DLS
{
    class Sensor
    {
    private:
        IAgent* m_owner = nullptr;
        const float m_range = 100.f;
        const int m_rayCount = 3;
        float m_raySpread = 0;
        std::vector<Vector2D> m_rays;

    public:
        Sensor(IAgent* owner);
        std::vector<Vector2D> GetRays() { return m_rays; }
        void Update();
        int GetRayCount() const { return m_rayCount; }
    };
}
