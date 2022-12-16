#include "RigidbodyContactGeneratorRegistry.h"

#include "../Scene/GameObject.h"

RigidbodyContactGeneratorRegistry::RigidbodyContactGeneratorRegistry() {
}

void RigidbodyContactGeneratorRegistry::checkForContact(RigidbodyPrimitiveCollider* rpc1, RigidbodyPrimitiveCollider* rpc2) {
    //    calculateContact((RigidbodySphereCollider*)rigidbodySphereCollider1, (RigidbodySphereCollider*)rigidbodySphereCollider2);
}

void RigidbodyContactGeneratorRegistry::calculateContact(RigidbodyPrimitiveCollider* rpc1, RigidbodyPrimitiveCollider* rpc2) {
    switch (rpc1->getColliderType())
    {
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_NONE:
        std::cerr << "Collision issue, type is NONE" << std::endl;
        break;
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_SPHERE:
        calculateContactSphere(dynamic_cast<RigidbodySphereCollider*>(rpc1), rpc2);
        break;
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_BOX:
        calculateContactCuboid(dynamic_cast<RigidbodyCuboidRectangleCollider*>(rpc1), rpc2);
        break;
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_PLANE:
        calculateContactPlane(dynamic_cast<RigidbodyPlaneCollider*>(rpc1), rpc2);
        break;
    default:
        std::cerr << "Collision issue, unknown collider type" << std::endl;
        break;
    }
}

void RigidbodyContactGeneratorRegistry::calculateContactSphere(RigidbodySphereCollider* rsc, RigidbodyPrimitiveCollider* other) {
    switch (other->getColliderType())
    {
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_SPHERE: {
        Vector3d position1 = rsc->getGameObject()->transform.getPosition();
        auto* otherSphereCollider = dynamic_cast<RigidbodySphereCollider*>(other);
        Vector3d position2 = otherSphereCollider->getGameObject()->transform.getPosition();
        if (pow(position1.distance(position2), 2) < (rsc->getRadius() + otherSphereCollider->getRadius()))
        {
            std::cout << "Sphere to sphere contact between " << rsc->getGameObject()->getName() << " and " << otherSphereCollider->getGameObject()->getName() << std::endl;
        }
        break;                
    }
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_PLANE: {
        auto* planeCollider = dynamic_cast<RigidbodyPlaneCollider*>(other);

        float distance = distanceToPlane(rsc1->getGameObject()->transform.getPosition(),planeCollider);

        if (distance <= 0)
        {
            std::cout << "Sphere to plane contact between " << rsc->getGameObject()->getName() << " and " << planeCollider->getGameObject()->getName() << std::endl;
        }
        break;
    }
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_BOX: {
        break;
    }
    default:
        std::cerr << "Collision issue in Sphere collision function" << std::endl;
        break;
    }
}

void RigidbodyContactGeneratorRegistry::calculateContactCuboid(RigidbodyCuboidRectangleCollider* rcrc, RigidbodyPrimitiveCollider* other) {
    switch (other->getColliderType())
    {
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_SPHERE: {
        break;
    }
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_PLANE: {
        break;
    }
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_BOX: {
        break;
    }
    default:
        std::cerr << "Collision issue in Cuboid collision function" << std::endl;
        break;
    }
}

void RigidbodyContactGeneratorRegistry::calculateContactPlane(RigidbodyPlaneCollider* rpc, RigidbodyPrimitiveCollider* other) {
    switch (other->getColliderType())
    {
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_SPHERE: {
        break;
    }
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_PLANE: {
        break;
    }
    case RIGIDBODY_PRIMITIVE_COLLIDER_TYPE_BOX: {
        break;
    }
    default:
        std::cerr << "Collision issue in Cuboid collision function" << std::endl;
        break;
    }
}

float RigidbodyContactGeneratorRegistry::distanceToPlane(Vector3d point, RigidbodyPlaneCollider* plane) {
    return point.dot(plane->getNormalVector()) - plane->getCenter().dot(plane->getNormalVector());
}
