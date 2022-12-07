#ifndef RIGIDBODYCONTACT_H
#define RIGIDBODYCONTACT_H

#include "../../Scene/Components/PhysicalComponent/Rigidbody/Rigidbody.h"

class RigidbodyContact {
protected:
    Rigidbody* m_rigidbodies[2];

    //    Vector3d m_contactNormal;

public:
    RigidbodyContact(Rigidbody* rb1, Rigidbody* rb2);

    void resolveContact();

private:
    void updateAttributes();

    void resolveSpeed();

    void resolveInterpenetration();
};



#endif // RIGIDBODYCONTACT_H
