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

    RigidbodyPrimitiveColliderType getColliderType() const override;

    Vector3d getNormalVector() const override;

private:
    static constexpr const char* COMPONENT_TYPE = RIGIDBODY_CUBOID_RECTANGLE_COLLIDER;

    static constexpr const RigidbodyPrimitiveColliderType COLLIDER_TYPE = RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_BOX;
};



#endif // RIGIDBODYCUBOIDRECTANGLECOLLIDER_H
