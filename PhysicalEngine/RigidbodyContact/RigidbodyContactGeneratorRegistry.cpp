#include "RigidbodyContactGeneratorRegistry.h"

#include "../Scene/GameObject.h"

RigidbodyContactGeneratorRegistry::RigidbodyContactGeneratorRegistry() {
}
void RigidbodyContactGeneratorRegistry::checkForContact(RigidbodyPrimitiveCollider* rigidbodySphereCollider1, RigidbodyPrimitiveCollider* rigidbodySphereCollider2) {
    //    calculateContact((RigidbodySphereCollider*)rigidbodySphereCollider1, (RigidbodySphereCollider*)rigidbodySphereCollider2);
}

void RigidbodyContactGeneratorRegistry::calculateContact(RigidbodySphereCollider* rigidbodySphereCollider1, RigidbodySphereCollider* rigidbodySphereCollider2) {
    Vector3d position1 = rigidbodySphereCollider1->getGameObject()->transform.getPosition();
    Vector3d position2 = rigidbodySphereCollider2->getGameObject()->transform.getPosition();

    if (pow(position1.distance(position2), 2) < (rigidbodySphereCollider1->getRadius() + rigidbodySphereCollider2->getRadius()))
        return;

    std::cout << "Sphere to sphere contact between " << rigidbodySphereCollider1->getGameObject()->getName() << " and " << rigidbodySphereCollider2->getGameObject()->getName() << std::endl;

    // Todo: Create contact
    //  COLLISION

    //        Rigidbody* rigidbody1 = rigidbodySphereCollider1->getGameObject()->getComponent<Rigidbody>();
    //        Rigidbody* rigidbody2 = rigidbodySphereCollider2->getGameObject()->getComponent<Rigidbody>();

    //        RigidbodyContact* rigidbodyContact = new RigidbodyContact(rigidbody1, rigidbody2, 0, 0, Vector3d(0, 0, 0));
    //        rigidbodyContact->resolveContact();
}
