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
    void calculateContactSphere(RigidbodySphereCollider* rsc1, RigidbodyPrimitiveCollider* rsc2);

    void calculateContactCuboid(RigidbodyCuboidRectangleCollider* rcrc1, RigidbodyPrimitiveCollider* rcrc2);

    void calculateContactPlane(RigidbodyPlaneCollider* rpc1, RigidbodyPrimitiveCollider* rpc2);
};



#endif // RIGIDBODYCONTACTGENERATORREGISTRY_H
