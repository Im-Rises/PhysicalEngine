#ifndef RIGIDBODYPRIMITIVECOLLIDER_H
#define RIGIDBODYPRIMITIVECOLLIDER_H

#include "../../Component.h"

#define RIGIDBODY_PRIMITIVE_COLLIDER "RigidbodyPrimitiveColliderComponent"

class RigidbodyPrimitiveCollider : public Component {
public:
    explicit RigidbodyPrimitiveCollider(GameObject* gameObject);

    void drawGui() override = 0;

    std::string getName() const override = 0;

private:
    static constexpr const char* COMPONENT_TYPE = RIGIDBODY_PRIMITIVE_COLLIDER;
};

#endif // RIGIDBODYPRIMITIVECOLLIDER_H
