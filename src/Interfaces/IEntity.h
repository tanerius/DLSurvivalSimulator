#pragma once

#include "Helpers.h"
namespace DLS
{
    class IWorld;

    /// <summary>
    /// An entity that can exist in the world
    /// </summary>
    class IEntity
    {
    private:
        Vector2D m_colliderHeightWidth { 10.f, 10.f }; // height and widfth of collider
        IWorld* m_world = nullptr;
        int m_id = 0;

    public:
        /// <summary>
        /// Method to check if entity has collided with something
        /// </summary>
        /// <returns>True == agent has collided otherwise false</returns>
        virtual bool HasCollided() const = 0;
        virtual bool ComputeCollision() = 0;
        virtual void SignalCollision() = 0;
        virtual Vector2D PositionVector() const = 0;
        virtual EntityType Type() const = 0;
        virtual void SetPosition(const Vector2D& pos) = 0;

        int GetId() const { return m_id; }
        void SetId(const int id) { m_id = id; }

        void SetHeightWidth(const Vector2D& hw)
        {
            m_colliderHeightWidth.x = hw.x;
            m_colliderHeightWidth.y = hw.y;
        }

        Vector2D GetHeightWidth() const { return m_colliderHeightWidth; }

        Box GetCollisionBox() const
        {
            Box ret;
            ret.TopLeft = { PositionVector().x - (GetHeightWidth().x / 2), PositionVector().y - (GetHeightWidth().y / 2) };
            ret.BottomRight = { PositionVector().x + (GetHeightWidth().x / 2), PositionVector().y + (GetHeightWidth().y / 2) };
            return ret;
        }

        void AddToWorld(IWorld* world)
        {
            m_world = world;
        }

        void RemoveFromWorld()
        {
            m_world = nullptr;
        }

        bool ExistsInWorld() const { return m_world != nullptr; }

        IWorld* GetWorld() { return m_world; }

        /// <summary>
        /// Method to be called on each frame which will update enity values
        /// </summary>
        virtual void Update() = 0;
    };
}
