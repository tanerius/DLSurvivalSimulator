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

void DLS::Agent::SetPosition(const Vector2D& pos) 
{
    m_position.x = pos.x;
    m_position.y = pos.y;
}

void DLS::Agent::Stop()
{
    m_currentSpeed = 0;
}

bool DLS::Agent::HasCollided()
{
    DLS::Box thisBox = GetCollisionBox();

        /*
    bool doOverlap(Point l1, Point r1, Point l2, Point r2)
    {
        // if rectangle has area 0, no overlap
        if (l1.x == r1.x || l1.y == r1.y || r2.x == l2.x || l2.y == r2.y)
            return false;

        // If one rectangle is on left side of other
        if (l1.x > r2.x || l2.x > r1.x)
            return false;

        // If one rectangle is above other
        if (r1.y > l2.y || r2.y > l1.y)
            return false;

        return true;
    }
    */

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