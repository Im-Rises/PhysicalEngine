#ifndef RIGIDBODYSPHERECONTACT_H
#define RIGIDBODYSPHERECONTACT_H

#include "../RigidbodyContact.h"

class RigidbodySphereSphereContact : public RigidbodyContact {
private:
    Vector3d m_contactNormal;

    Vector3d m_contactPoint;

public:
    RigidbodySphereSphereContact(Rigidbody* rb1, Rigidbody* rb2, const Vector3d& contactNormal, const Vector3d& contactPoint);

    //    void resolveContact() override;
};

#endif // RIGIDBODYSPHERECONTACT_H
