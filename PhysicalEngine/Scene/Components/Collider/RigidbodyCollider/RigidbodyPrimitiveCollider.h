#ifndef RIGIDBODYPRIMITIVECOLLIDER_H
#define RIGIDBODYPRIMITIVECOLLIDER_H

#include "../../../../Utility/Vector3d.h"
#include "../../Component.h"
#include "../../../GameObject.h"

#define RIGIDBODY_PRIMITIVE_COLLIDER "Rigidbody_Primitive_Collider"

enum RigidbodyPrimitiveColliderType {
    RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_NONE = 0,
    RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_SPHERE = 1,
    RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_BOX = 2,
    //    RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_CAPSULE,
    //    RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_CYLINDER,
    //    RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_CONE,
    RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_PLANE = 3,
    //    RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_MESH
};

// enum RigidbodyCollisionType {
//     RIGIDBODY_COLLISION_TYPE_SPHERE_SPHERE = 0,
//     RIGIDBODY_COLLISION_TYPE_SPHERE_PLANE = 1,
//     RIGIDBODY_COLLISION_TYPE_BOX_PLANE = 2,
//     RIGIDBODY_COLLISION_TYPE_BOX_SPHERE = 3,
//     RIGIDBODY_COLLISION_TYPE_BOX_BOX = 4
// };

class RigidbodyPrimitiveCollider : public Component {
public:
    explicit RigidbodyPrimitiveCollider(GameObject* gameObject);

    void drawGui() override = 0;

    virtual std::string getName() const = 0;

    virtual RigidbodyPrimitiveColliderType getColliderType() const = 0;

    virtual Vector3d getNormalVector() const = 0;

    virtual float getRadius() const = 0;

    Vector3d getCenter();

private:
    static constexpr const char* COMPONENT_TYPE = RIGIDBODY_PRIMITIVE_COLLIDER;

    static constexpr const RigidbodyPrimitiveColliderType COLLIDER_TYPE = RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_NONE;
};

#endif // RIGIDBODYPRIMITIVECOLLIDER_H
