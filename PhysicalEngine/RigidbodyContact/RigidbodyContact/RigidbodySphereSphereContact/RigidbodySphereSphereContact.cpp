#include "RigidbodySphereSphereContact.h"

RigidbodySphereSphereContact::RigidbodySphereSphereContact(Rigidbody* rb1, Rigidbody* rb2, const Vector3d& contactNormal, const Vector3d& contactPoint) : RigidbodyContact(rb1, rb2) {
    m_rigidbodies[0] = rb1;
    m_rigidbodies[1] = rb2;
    m_contactPoint = contactPoint;
    m_contactNormal = contactNormal;
}
