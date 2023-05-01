#pragma once
#include <Helpers.h>
#include <IAgent.h>
#include <vector>
#include <random>
#include "Sensor.h"

namespace DLS 
{
    class Agent : public IAgent
    {
        private:

        const   float       m_maxSpeed          {4.0};
        const   float       m_maxReverseSpeed   {-2.0};
        const   float       m_friction          {0.02};
        const   float       m_accelleration     {0.2};
                float       m_currentSpeed      {0.0};
                bool        m_isAlive           {true};

                Vector2D    m_position;
                Polar       m_forward;
                Sensor* m_sensor{ nullptr };
        
        public:
        Agent(Vector2D position);

        float MaxSpeed() const { return m_maxSpeed; }

        virtual void Accelerate() override;
        virtual Vector2D GetForwardVector() const override;
        virtual Vector2D GetPositionVector() const override { return m_position; };
        virtual float GetOrientationAngle() const override { return m_forward.theta; };
        std::vector<Vector2D> GetSensorVectors();
        int GetSensorRayCount() const { return m_sensor->GetRayCount(); }
        float GetSpeed() const override;
        virtual void RotateLeft() override;
        virtual void RotateRight() override;
        virtual void Reverse() override;
        virtual void Stop() override;
        virtual bool IsAlive() const override { return m_isAlive; };
        virtual bool HasCollided() override = 0;
        virtual void Update() override;
    };
}