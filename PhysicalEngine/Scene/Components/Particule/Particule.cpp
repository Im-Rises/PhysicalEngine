#include "Particule.h"

#include "imgui/imgui.h"

Particule::Particule() : m_speed(0, 0, 0), m_acceleration(0, 0, 0), Rigidbody("Particule") {
     m_position = Vector3d(0, 0, 0);
	 m_mass = 0;
};

Particule::Particule(float x, float y, float z, float m) : m_speed(0, 0, 0), m_acceleration(0, 0, 0), Rigidbody("Particule") {
    m_position = Vector3d(x, y, z);
	m_mass = m;
}

Particule::Particule(const Vector3d &pos, float m) : m_speed(0, 0, 0), m_acceleration(0, 0, 0), Rigidbody("Particule") {
    m_position = pos;
	m_mass = m;
}

Particule::Particule(const Particule &particule) {
    m_acceleration = Vector3d(particule.m_acceleration);
    m_speed = Vector3d(particule.m_speed);
    m_position = Vector3d(particule.m_position);
	m_mass = particule.m_mass;
}

const Vector3d& Particule::getPosition() const {
	return m_position;
}

const Vector3d& Particule::getSpeed() const {
    return m_speed;
}

const Vector3d &Particule::getAcceleration() const {
    return m_acceleration;
}

void Particule::setPosition(float x, float y, float z) {
    m_position = Vector3d(x, y, z);
}

void Particule::setPosition(const Vector3d &position) {
    m_position = position;
}

void Particule::setSpeed(float x, float y, float z) {
    m_speed = Vector3d(x, y, z);
}

void Particule::setSpeed(const Vector3d &speed) {
    m_speed = speed;
}

void Particule::setAcceleration(float x, float y, float z) {
    m_acceleration = Vector3d(x, y, z);
}

void Particule::setAcceleration(const Vector3d &acceleration) {
    m_acceleration = acceleration;
}

float Particule::getMass() const { return m_mass; };

const Vector3d &Particule::getNetForce() const { return m_netForce; };

float Particule::getFriction() const { return m_friction; };

void Particule::setNetForce(Vector3d force) { m_netForce = force; };

void Particule::setFriction(float friction) { m_friction = friction; };

void Particule::calculatePosition(float time) {
    m_position = m_position + m_speed * time;
}

void Particule::calculateSpeed(float time) {
    m_speed = m_speed + m_acceleration * time;
}

void Particule::calculateAcceleration(float time) {
	m_acceleration = m_netForce * (1/m_mass) * time;
}

void Particule::recalculateAll(float time) {

    calculateSpeed(time);
    calculatePosition(time);
	calculateAcceleration(time);
}

}


