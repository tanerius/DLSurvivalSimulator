#define _USE_MATH_DEFINES
#include "Agent.h"
#include <cmath>

DLS::Agent::Agent(DLS::Vector2D position) :
    m_position(position)
{
    m_forward.r = 1;
    m_forward.theta = 0;
}

DLS::Vector2D DLS::Agent::GetForwardVector() const 
{
    return m_forward.ToCartesian();
}

float DLS::Agent::GetSpeed() const 
{
    return m_currentSpeed;
}

void DLS::Agent::Accelerate() 
{
    m_currentSpeed += m_accelleration - m_friction;
    if (m_currentSpeed > m_maxSpeed)
        m_currentSpeed = m_maxSpeed;

    DLS::Vector2D forward = GetForwardVector();
    forward.x = forward.x * (1 + m_currentSpeed);
    forward.x = forward.y * (1 + m_currentSpeed);

    m_position.x = m_position.x + forward.x;
    m_position.y = m_position.y + forward.y;
}

void DLS::Agent::RotateRight()
{
    m_forward.theta += m_accelleration / 2;
    if(m_forward.theta > (2 * M_PI))
        m_forward.theta = m_forward.theta - (2 * M_PI); // prevent overflows
}

void DLS::Agent::RotateLeft()
{
    m_forward.theta -= m_accelleration / 2;
    if(m_forward.theta < -(2 * M_PI))
        m_forward.theta = m_forward.theta + (2 * M_PI); // prevent overflows
}

void DLS::Agent::Reverse()
{
    m_currentSpeed -= m_accelleration - m_friction;

    if (m_currentSpeed < m_maxReverseSpeed)
        m_currentSpeed = m_maxReverseSpeed;

    auto forward = GetForwardVector();

    if(m_currentSpeed < 0)
    {
        forward.x = -forward.x * (1 + m_currentSpeed);
        forward.x = -forward.y * (1 + m_currentSpeed);
    }
    else
    {
        forward.x = forward.x * (1 + m_currentSpeed);
        forward.x = forward.y * (1 + m_currentSpeed);
    }

    m_position.x = m_position.x + forward.x;
    m_position.y = m_position.y + forward.y;
}

void DLS::Agent::Stop()
{
    m_currentSpeed = 0;
}

bool DLS::Agent::HasCollided()
{
    return false;
}

void DLS::Agent::Update()
{
    if(m_currentSpeed > 0)
        m_currentSpeed -= m_friction;
    
    if(m_currentSpeed < 0)
        m_currentSpeed += m_friction;

    if(std::abs(m_currentSpeed) < m_friction)
        m_currentSpeed = 0;
}

void DLS::Agent::Draw()
{
    // Implemented tor test instancing
}