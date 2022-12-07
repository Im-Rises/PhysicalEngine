#ifndef RIGIDBODYPLANECOLLIDER_H
#define RIGIDBODYPLANECOLLIDER_H

#include "../RigidbodyPrimitiveCollider.h"

class RigidbodyPlaneCollider : public RigidbodyPrimitiveCollider {
public:
    explicit RigidbodyPlaneCollider(GameObject* gameObject);

    void drawGui() override;

    std::string getName() const override;

private:
    static constexpr const char* COMPONENT_TYPE = RIGIDBODY_PLANE_COLLIDER;
};



#endif // RIGIDBODYPLANECOLLIDER_H
