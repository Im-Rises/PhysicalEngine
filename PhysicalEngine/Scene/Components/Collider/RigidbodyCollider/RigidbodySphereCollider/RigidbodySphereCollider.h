#ifndef RIGIDBODYSPHERECOLLIDER_H
#define RIGIDBODYSPHERECOLLIDER_H

#include "../RigidbodyPrimitiveCollider.h"

class RigidbodySphereCollider : public RigidbodyPrimitiveCollider {
public:
    float m_radius = 0;

    RigidbodySphereCollider(GameObject* gameObject, float radius);

    void drawGui() override;

    std::string getName() const override;

    RigidbodyPrimitiveColliderType getColliderType() const override;

    Vector3d getNormalVector() const override;

    void update(float time) override;

private:
    static constexpr const char* COMPONENT_TYPE = RIGIDBODY_SPHERE_COLLIDER;

    static constexpr const RigidbodyPrimitiveColliderType COLLIDER_TYPE = RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_SPHERE;

public:
    float getRadius() const override;
};



#endif // RIGIDBODYSPHERECOLLIDER_H
