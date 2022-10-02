#include "Particule.h"

Particule::Particule(const Particule &particule) {
    m_acceleration = Vector3d(particule.m_acceleration);
    m_speed = Vector3d(particule.m_speed);
    m_position = Vector3d(particule.m_position);
	m_mass = particule.m_mass;
}

void Particule::calculatePosition(float time) {
    m_position = m_position + m_speed * time;
}

void Particule::calculateSpeed(float time) {
    m_speed = m_speed + m_acceleration * time;
}

void Particule::recalculateAll(float time) {

    calculateSpeed(time);
    calculatePosition(time);

}

float Particule::distance(const Particule& p) {
	return (this->m_position - p.getPosition()).norm();
}
