#include "Particule.h"

Particule::Particule(const Particule &particule) {
    m_acceleration = Vector3D(particule.m_acceleration);
    m_speed = Vector3D(particule.m_speed);
    m_position = Vector3D(particule.m_position);
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
