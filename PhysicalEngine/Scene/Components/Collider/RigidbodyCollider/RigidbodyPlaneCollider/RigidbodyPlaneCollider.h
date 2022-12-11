#ifndef RIGIDBODYPLANECOLLIDER_H
#define RIGIDBODYPLANECOLLIDER_H

#include "../RigidbodyPrimitiveCollider.h"

class RigidbodyPlaneCollider : public RigidbodyPrimitiveCollider {
public:
    explicit RigidbodyPlaneCollider(GameObject* gameObject);

    void drawGui() override;

    std::string getName() const override;

    RigidbodyPrimitiveColliderType getColliderType() const override;

    Vector3d getNormalVector() const override;

private:
    static constexpr const char* COMPONENT_TYPE = RIGIDBODY_PLANE_COLLIDER;

    static constexpr const RigidbodyPrimitiveColliderType COLLIDER_TYPE = RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_PLANE;
};



#endif // RIGIDBODYPLANECOLLIDER_H
