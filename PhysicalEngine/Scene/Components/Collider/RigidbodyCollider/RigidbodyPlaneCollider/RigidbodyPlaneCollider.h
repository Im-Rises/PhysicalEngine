#ifndef RIGIDBODYPLANECOLLIDER_H
#define RIGIDBODYPLANECOLLIDER_H

#include "../RigidbodyPrimitiveCollider.h"

class RigidbodyPlaneCollider : public RigidbodyPrimitiveCollider {
private:
    float m_width;
    float m_depth;

public:
    explicit RigidbodyPlaneCollider(GameObject* gameObject, float width = 1, float depth = 1);

    void drawGui() override;

    std::string getName() const override;

    RigidbodyPrimitiveColliderType getColliderType() const override;

    Vector3d getNormalVector() const override;

    void update(float time) override;

    float getRadius() const override;

private:
    static constexpr const char* COMPONENT_TYPE = RIGIDBODY_PLANE_COLLIDER;

    static constexpr const RigidbodyPrimitiveColliderType COLLIDER_TYPE = RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_PLANE;

public:
    float getWidth() const;

    void setWidth(float width);

    float getDepth() const;

    void setDepth(float depth);
};



#endif // RIGIDBODYPLANECOLLIDER_H
