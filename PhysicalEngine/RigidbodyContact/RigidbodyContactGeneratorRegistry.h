#ifndef RIGIDBODYCONTACTGENERATORREGISTRY_H
#define RIGIDBODYCONTACTGENERATORREGISTRY_H

#include "../Scene/Components/Collider/RigidbodyCollider/RigidbodyPrimitiveCollider.h"
#include "../Scene/Components/Collider/RigidbodyCollider/RigidbodySphereCollider/RigidbodySphereCollider.h"
#include "../Scene/Components/PhysicalComponent/Rigidbody/Rigidbody.h"

class RigidbodyContactGeneratorRegistry {
    // private:
    //     RigidbodyContactGenerator* m_rigidbodyContactGenerators[100];
    //     int m_rigidbodyContactGeneratorsCount = 0;

public:
    RigidbodyContactGeneratorRegistry();

    void checkForContact(RigidbodyPrimitiveCollider* rigidbodySphereCollider1, RigidbodyPrimitiveCollider* rigidbodySphereCollider2);


private:
    void calculateContact(RigidbodySphereCollider* rigidbodySphereCollider1, RigidbodySphereCollider* rigidbodySphereCollider2);

//    void calculateContact(RigidbodySphereCollider* rigidbodySphereCollider, RigidbodyBoxCollider* rigidbodyBoxCollider);
//
//    void calculateContact(RigidbodyBoxCollider* rigidbodyBoxCollider, RigidbodySphereCollider* rigidbodySphereCollider);

};



#endif // RIGIDBODYCONTACTGENERATORREGISTRY_H
