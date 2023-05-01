#define _USE_MATH_DEFINES
#include "Agent.h"
#include <cmath>
#include <vector>

DLS::Agent::Agent(DLS::Vector2D position) :
    m_position(position)
{
    m_forward.r = 1;
    m_forward.theta = 0;
    m_sensor = new Sensor(this);
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
    forward.y = forward.y * (1 + m_currentSpeed);

    m_position.x = m_position.x + forward.x;
    m_position.y = m_position.y + forward.y;
}

std::vector<DLS::Vector2D> DLS::Agent::GetSensorVectors()
{
    return m_sensor->GetRays();
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
    m_currentSpeed += m_accelleration - m_friction;
    if (m_currentSpeed > m_maxSpeed)
        m_currentSpeed = m_maxSpeed;

    DLS::Vector2D forward = GetForwardVector();
    forward.x = forward.x * (1 + m_currentSpeed);
    forward.y = forward.y * (1 + m_currentSpeed);

    m_position.x = m_position.x - forward.x;
    m_position.y = m_position.y - forward.y;
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

    m_sensor->Update();
}