#ifndef RIGIDBODYCONTACT_H
#define RIGIDBODYCONTACT_H

#include "../Scene/Components/PhysicalComponent/Rigidbody/Rigidbody.h"

class RigidbodyContact {
private:
    Rigidbody* m_rigidbodies[2];

    float m_collision_elasticity = 0;

    float m_penetration = 0;

    Vector3d m_contactNormal;

public:
    RigidbodyContact(Rigidbody* rb1, Rigidbody* rb2, float collision_elasticity, float penetration, Vector3d contactNormal);

    void resolveContact();

private:
    void updateAttributes();

    void resolveSpeed();

    void resolveInterpenetration();

};



#endif // RIGIDBODYCONTACT_H
