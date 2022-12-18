#include "RigidbodyContact.h"

RigidbodyContact::RigidbodyContact(Rigidbody* rb1) {
    m_rigidbodies[0] = rb1;
    m_rigidbodies[1] = nullptr;
}

RigidbodyContact::RigidbodyContact(Rigidbody* rb1, Rigidbody* rb2) {
    m_rigidbodies[0] = rb1;
    m_rigidbodies[1] = rb2;
}

void RigidbodyContact::resolveContact() {
}

void RigidbodyContact::updateAttributes() {
}

void RigidbodyContact::resolveSpeed() {
}

void RigidbodyContact::resolveInterpenetration() {
}
