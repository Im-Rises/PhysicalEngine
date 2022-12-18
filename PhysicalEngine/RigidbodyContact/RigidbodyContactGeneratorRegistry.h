#ifndef RIGIDBODYCONTACTGENERATORREGISTRY_H
#define RIGIDBODYCONTACTGENERATORREGISTRY_H

#include "../Scene/Components/Collider/RigidbodyCollider/RigidbodyCuboidRectangleCollider/RigidbodyCuboidRectangleCollider.h"
#include "../Scene/Components/Collider/RigidbodyCollider/RigidbodyPlaneCollider/RigidbodyPlaneCollider.h"
#include "../Scene/Components/Collider/RigidbodyCollider/RigidbodyPrimitiveCollider.h"
#include "../Scene/Components/Collider/RigidbodyCollider/RigidbodySphereCollider/RigidbodySphereCollider.h"
#include "../Scene/Components/PhysicalComponent/Rigidbody/Rigidbody.h"

class RigidbodyContactGeneratorRegistry {
    // private:
    //     RigidbodyContactGenerator* m_rigidbodyContactGenerators[100];
    //     int m_rigidbodyContactGeneratorsCount = 0;

public:
    RigidbodyContactGeneratorRegistry();

    void checkForContact(RigidbodyPrimitiveCollider* rpc1, RigidbodyPrimitiveCollider* rpc2);

    void calculateContact(RigidbodyPrimitiveCollider* rpc1, RigidbodyPrimitiveCollider* rpc2);

private:
    void calculateContactSphere(RigidbodySphereCollider* rsc, RigidbodyPrimitiveCollider* other);

    void calculateContactCuboid(RigidbodyCuboidRectangleCollider* rcrc, RigidbodyPrimitiveCollider* other);


    float distanceToPlane(Vector3d point,RigidbodyPlaneCollider* plane);
    
    void calculateContactPlane(RigidbodyPlaneCollider* rpc, RigidbodyPrimitiveCollider* other);

};



#endif // RIGIDBODYCONTACTGENERATORREGISTRY_H
