#ifndef RIGIDBODYSPHERECOLLIDER_H
#define RIGIDBODYSPHERECOLLIDER_H

#include "../RigidbodyPrimitiveCollider.h"

class RigidbodySphereCollider : public RigidbodyPrimitiveCollider {
public:
    float m_radius = 0;

    RigidbodySphereCollider(GameObject* gameObject, float radius);

    void drawGui() override;

    std::string getName() const override;

private:
    static constexpr const char* COMPONENT_TYPE = RIGIDBODY_SPHERE_COLLIDER;

public:
    float getRadius() const;
};



#endif // RIGIDBODYSPHERECOLLIDER_H
