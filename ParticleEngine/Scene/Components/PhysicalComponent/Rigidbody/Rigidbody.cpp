#include "Rigidbody.h"

#include <utility>

#include "imgui/imgui.h"
#include "../../../GameObject.h"

Rigidbody::Rigidbody(GameObject* gameObject) : Component(gameObject) {
    m_speed = { 0, 0, 0 };
    m_acceleration = { 0, 0, 0 };
    m_mass = 1;
    m_rotation = { 0, 0, 0 };
    m_inertiaTensor = Matrix33();
    m_transformMatrix = Matrix34();
    m_orientation = Quaternion();
    m_angularSpeed = Vector3d(0, 0, 0);
    m_angularAcceleration = Vector3d(0, 0, 0);
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);
}

Rigidbody::Rigidbody(GameObject* gameObject, float m) : Component(gameObject) {
    m_speed = { 0, 0, 0 };
    m_acceleration = { 0, 0, 0 };
    m_mass = m;
    m_rotation = { 0, 0, 0 };
    m_inertiaTensor = Matrix33();
    m_transformMatrix = Matrix34();
    m_orientation = Quaternion();
    m_angularSpeed = Vector3d(0, 0, 0);
    m_angularAcceleration = Vector3d(0, 0, 0);
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);
}

Rigidbody::Rigidbody(const Rigidbody& rigidbody) : Component(rigidbody.m_gameObject) {
    m_acceleration = Vector3d(rigidbody.m_acceleration);
    m_speed = Vector3d(rigidbody.m_speed);
    m_gameObject->transform.setPosition(rigidbody.m_gameObject->transform.getPosition());
    m_mass = rigidbody.m_mass;
    m_rotation = Vector3d(rigidbody.m_rotation);
    m_inertiaTensor = Matrix33(rigidbody.m_inertiaTensor);
    m_transformMatrix = Matrix34(rigidbody.m_transformMatrix);
    m_orientation = Quaternion(Quaternion(rigidbody.m_orientation));
    m_angularSpeed = Vector3d(rigidbody.m_angularSpeed);
    m_angularAcceleration = Vector3d(rigidbody.m_angularAcceleration);
    m_forceAccum = Vector3d(rigidbody.m_forceAccum);
    m_torqueAccum = Vector3d(rigidbody.m_torqueAccum);
}

Rigidbody::~Rigidbody() {
}

void Rigidbody::update(float time) {
    // Update sum of forces


    // Update acceleration (angular and linear), speed and position
    calculateAcceleration();
    calculateAngularAcceleration();
    calculateSpeed(time); // pas sûre pour le time

    // Reset the forceAccum and torqueAccum for the next frame
    ClearAccumulator();
}

void Rigidbody::drawGui() {

}
std::string Rigidbody::getName() const {
    return COMPONENT_TYPE;
}


void Rigidbody::calculateSpeed(float time) {
    m_speed = m_speed + m_acceleration * time;
}

void Rigidbody::calculateAcceleration() {
    m_acceleration = m_forceAccum / m_mass;
}

void Rigidbody::calculateAngularSpeed(float time) {
    m_angularSpeed = m_angularSpeed + m_angularAcceleration * time;
}

void Rigidbody::calculateAngularAcceleration() {
    m_angularAcceleration = m_inertiaTensor.inverse() * m_torqueAccum;
}

void Rigidbody::calculateOrientation(float deltaTime) {
    m_orientation = m_orientation + Quaternion(0, m_angularSpeed.getx(), m_angularSpeed.gety(), m_angularSpeed.getz()) * (deltaTime / 2) * m_orientation;
}

void Rigidbody::calculateDerivedData() {
    m_transformMatrix.setOrientationAndPosition(m_orientation, getPosition());

    // set inertia -> m_inertiaTensor = dépend de Sphère/cube/cylindre
}

void Rigidbody::addForce(const Vector3d& force) {
    // add force sur le centre de masse
}

void Rigidbody::addForceAtPoint(const Vector3d& force, const Vector3d worldPoint) {
    // add force sur un point en coordonées mondes
}

void Rigidbody::addForceAtBodyPoint(const Vector3d& force, const Vector3d& LocalPoint) {
    // add force sur un point en coordonées locales à l'objet
}

bool Rigidbody::hasForce(const std::string& name) const {
    return false;
}

void Rigidbody::ClearAccumulator() {
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);
}

Vector3d Rigidbody::getPosition() const {
    return m_gameObject->transform.getPosition();
}

const Vector3d& Rigidbody::getSpeed() const {
    return m_speed;
}

const Vector3d& Rigidbody::getAcceleration() const {
    return m_acceleration;
}

void Rigidbody::setPosition(float x, float y, float z) {
    m_gameObject->transform.setPosition(Vector3d(x, y, z));
}

void Rigidbody::setPosition(const Vector3d& position) {
    m_gameObject->transform.setPosition(position);
}

void Rigidbody::setSpeed(float x, float y, float z) {
    m_speed = Vector3d(x, y, z);
}

void Rigidbody::setSpeed(const Vector3d& s) {
    this->m_speed = s;
}

void Rigidbody::setAcceleration(float x, float y, float z) {
    m_acceleration = Vector3d(x, y, z);
}

void Rigidbody::setAcceleration(const Vector3d& acceleration) {
    this->m_acceleration = acceleration;
}

float Rigidbody::getMass() const {
    return m_mass;
}

const Vector3d& Rigidbody::getForceAcc() const {
    return m_forceAccum;
}

void Rigidbody::setForceAcc(const Vector3d& force) {
    m_forceAccum = force;
}

// const Vector3d &Rigidbody::getPosition() const {
//     return m_position;
// }
