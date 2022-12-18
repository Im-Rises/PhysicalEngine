#include "Particle.h"

#include "../../../../Utility/imGuiUtility.h"
#include "../../../GameObject.h"
#include "imgui/imgui.h"
#include <algorithm>

Particle::Particle(GameObject* gameObject) : Component(gameObject) {
    linearSpeed = { 0, 0, 0 };
    linearAcceleration = { 0, 0, 0 };
    m_mass = 1;
}

Particle::Particle(GameObject* gameObject, float m) : Component(gameObject) {
    linearSpeed = { 0, 0, 0 };
    linearAcceleration = { 0, 0, 0 };
    m_mass = m;
}

Particle::Particle(const Particle& particle) : Component(particle.m_gameObject) {
    linearAcceleration = Vector3d(particle.linearAcceleration);
    linearSpeed = Vector3d(particle.linearSpeed);
    m_gameObject->transform.setPosition(particle.m_gameObject->transform.getPosition());
    m_mass = particle.m_mass;
}

Particle::~Particle() {
//    for (auto& force : forceGeneratorsList)
//    {
//        delete force;
//    }
}

void Particle::update(float deltaTime) {
    // Update sum of forces
    if (!isKinematic)
    {
        gravity.addForce(this);

        for (ForceGenerator* forceGenerator : forceGeneratorsList)
        {
            forceGenerator->addForce(this);
        }
    }

    // Update acceleration, linearSpeed and position
    calculateAcceleration();
    calculateSpeed(deltaTime);

    // Reset the m_forceAccum for the next frame
    m_forceAccum = Vector3d();
}

// float Particle::distance(const Particle& p) {
//     return (m_gameObject->transform.getPosition() - p.getPosition()).norm();
// }

// void Particle::calculatePosition(float time) {
//     m_gameObject->transform.setPosition(m_gameObject->transform.getPosition() + linearSpeed * time);
// }

void Particle::calculateSpeed(float time) {
    linearSpeed = linearSpeed + linearAcceleration * time;
}

void Particle::calculateAcceleration() {
    linearAcceleration = m_forceAccum / m_mass;
}

void Particle::drawGui() {
    PhysicalComponent::drawGui();
    PhysicalComponent::drawGuiForceGenerators();
}

std::string Particle::getName() const {
    return COMPONENT_TYPE;
}

void Particle::stop() {
    linearSpeed = { 0, 0, 0 };
    linearAcceleration = { 0, 0, 0 };
    isKinematic = true;
}
