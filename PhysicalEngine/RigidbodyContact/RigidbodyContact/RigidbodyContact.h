#ifndef RIGIDBODYCONTACT_H
#define RIGIDBODYCONTACT_H

#include "../../Scene/Components/PhysicalComponent/Rigidbody/Rigidbody.h"
#include <vector>
class RigidbodyContact {
protected:
    Rigidbody* m_rigidbodies[2];

    //    Vector3d m_contactNormal;

public:
    std::vector<Vector3d> m_points;
    std::vector<float> m_interpenetration;
    Vector3d m_normal;

    RigidbodyContact(Rigidbody* rb1);

    RigidbodyContact(Rigidbody* rb1, Rigidbody* rb2);

    void resolveContact();

private:
    void updateAttributes();

    void resolveSpeed();

    void resolveInterpenetration();
};



#endif // RIGIDBODYCONTACT_H
