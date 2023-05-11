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

        const   float       m_maxSpeed          { 4.0 };
        const   float       m_maxReverseSpeed   { -2.0 };
        const   float       m_friction          { 0.02 };
        const   float       m_accelleration     { 0.2 };
        const   EntityType  m_entityType        { EntityType::Agent };
                float       m_currentSpeed      { 0.0 };
                bool        m_isAlive           { true };
                bool        m_isCollided        { false };

                Vector2D    m_position;
                Polar       m_forward;
                Sensor*     m_sensor            { nullptr };
        
        public:
        Agent(Vector2D position);

        // Methods from IEntity start here
        EntityType Type() const override { return m_entityType; }
        Vector2D PositionVector() const override { return m_position; };

        virtual bool HasCollided() const override { return m_isCollided; }
        virtual bool ComputeCollision() override;
        virtual void SignalCollision() override { m_isCollided = true; }
        virtual void Update() override;
                
        float MaxSpeed() const { return m_maxSpeed; }

        void Accelerate() override;
        Vector2D GetForwardVector() const override;
        float GetOrientationAngle() const override { return m_forward.theta; };
        std::vector<Vector2D> GetSensorVectors();
        int GetSensorRayCount() const { return m_sensor->GetRayCount(); }
        float GetSpeed() const override;
        void RotateLeft() override;
        void RotateRight() override;
        void SetPosition(const Vector2D& pos) override;
        void Reverse() override;
        void Stop() override;
        virtual bool IsAlive() const override { return m_isAlive; };
    };
}