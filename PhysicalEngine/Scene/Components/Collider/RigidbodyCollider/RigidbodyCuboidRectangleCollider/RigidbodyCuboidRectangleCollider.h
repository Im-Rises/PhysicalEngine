#ifndef RIGIDBODYCUBOIDRECTANGLECOLLIDER_H
#define RIGIDBODYCUBOIDRECTANGLECOLLIDER_H

#include "../RigidbodyPrimitiveCollider.h"

class RigidbodyCuboidRectangleCollider : public RigidbodyPrimitiveCollider {
public:
    float m_width = 0;
    float m_height = 0;
    float m_depth = 0;

    RigidbodyCuboidRectangleCollider(GameObject* gameObject, float width, float height, float depth);

    void drawGui() override;

    std::string getName() const override;

private:
    static constexpr const char* COMPONENT_TYPE = RIGIDBODY_CUBOID_RECTANGLE_COLLIDER;
};



#endif // RIGIDBODYCUBOIDRECTANGLECOLLIDER_H
