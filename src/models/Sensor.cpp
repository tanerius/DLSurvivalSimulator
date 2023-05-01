#define _USE_MATH_DEFINES
#include "Sensor.h"
#include <cmath>

DLS::Sensor::Sensor(IAgent* owner)
{
    m_owner = owner;
    m_rays.reserve(m_rayCount);
    // populate once
    for (int i = 0; i < m_rayCount; i++)
    {
        m_rays.push_back({0, 0});
    }
    m_raySpread = M_PI / 4;
}

void DLS::Sensor::Update()
{
    float agentAngle = m_owner->GetOrientationAngle();
    Vector2D agentForward = m_owner->GetForwardVector();
    for (int i = 0; i < m_rayCount; i++)
    {
        auto rayAngle = std::lerp(
            m_raySpread / 2,
            -m_raySpread / 2,
            (float)i / (m_rayCount - 1)
        ) - agentAngle - (M_PI / 2);

        auto startPoint = m_owner->GetPositionVector();
        Vector2D endPoint = {
            startPoint.x - static_cast<float>(std::sin(rayAngle)) * m_range,
            startPoint.y - static_cast<float>(std::cos(rayAngle)) * m_range
        };
        m_rays[i] = endPoint;
    }
}