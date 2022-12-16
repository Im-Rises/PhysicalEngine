#ifndef RIGIDBODYCUBOIDRECTANGLECOLLIDER_H
#define RIGIDBODYCUBOIDRECTANGLECOLLIDER_H

#include "../RigidbodyPrimitiveCollider.h"

class RigidbodyCuboidRectangleCollider : public RigidbodyPrimitiveCollider {
public:
    float m_halfwidth = 0;
    float m_halfheight = 0;
    float m_halfdepth = 0;

    RigidbodyCuboidRectangleCollider(GameObject* gameObject, float width, float height, float depth);

    void drawGui() override;

    std::string getName() const override;

    RigidbodyPrimitiveColliderType getColliderType() const override;

    Vector3d getNormalVector() const override;

    void getAllPoints(Vector3d points[8]);

    void update(float time) override;

    float getRadius() const override;

private:
    static constexpr const char* COMPONENT_TYPE = RIGIDBODY_CUBOID_RECTANGLE_COLLIDER;

    static constexpr const RigidbodyPrimitiveColliderType COLLIDER_TYPE = RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_BOX;
};



#endif // RIGIDBODYCUBOIDRECTANGLECOLLIDER_H
