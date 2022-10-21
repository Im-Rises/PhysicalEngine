#include "Particle.h"

#include "imgui/imgui.h"
#include "../../../GameObject.h"
#include "../../../../Force/ForceGenerator.h"
#include "../../../../Utility/imGuiUtility.h"

Particle::Particle(GameObject *gameObject) : m_speed(0, 0, 0), m_acceleration(0, 0, 0),
                                             Component(gameObject) {
    gameObject->transform.setPosition(Vector3d(0, 0, 0));
    m_mass = 0;
}

//Particle::Particle(float x, float y, float z, float m) : m_speed(0, 0, 0), m_acceleration(0, 0, 0),
//                                                           Rigidbody("Particle") {
//    m_position = Vector3d(x, y, z);
//    m_mass = m;
//}

Particle::Particle(GameObject *gameObject, const Vector3d &pos, float m) : m_speed(0, 0, 0), m_acceleration(0, 0, 0),
                                                                           Component(gameObject) {
    gameObject->transform.setPosition(pos);
    m_mass = m;
}

Particle::Particle(const Particle &particle) : Component(particle.m_gameObject) {
    m_acceleration = Vector3d(particle.m_acceleration);
    m_speed = Vector3d(particle.m_speed);
    m_gameObject->transform.setPosition(particle.m_gameObject->transform.getPosition());
    m_mass = particle.m_mass;
}

Vector3d Particle::getPosition() const {
    return m_gameObject->transform.getPosition();
}

const Vector3d &Particle::getSpeed() const {
    return m_speed;
}

const Vector3d &Particle::getAcceleration() const {
    return m_acceleration;
}

void Particle::setPosition(float x, float y, float z) {
    m_gameObject->transform.setPosition(Vector3d(x, y, z));
}

void Particle::setPosition(const Vector3d &position) {
    m_gameObject->transform.setPosition(position);
}

void Particle::setSpeed(float x, float y, float z) {
    m_speed = Vector3d(x, y, z);
}

void Particle::setSpeed(const Vector3d &speed) {
    m_speed = speed;
}

void Particle::setAcceleration(float x, float y, float z) {
    m_acceleration = Vector3d(x, y, z);
}

void Particle::setAcceleration(const Vector3d &acceleration) {
    m_acceleration = acceleration;
}

float Particle::getMass() const { return m_mass; }

const Vector3d &Particle::getNetForce() const { return m_netForce; }

//float Particle::getFriction() const { return m_friction; }

void Particle::setNetForce(const Vector3d &force) { m_netForce = force; }

//void Particle::setFriction(float friction) { m_friction = friction; }

void Particle::calculatePosition(float time) {
    m_gameObject->transform.setPosition(m_gameObject->transform.getPosition() + m_speed * time);
}

void Particle::calculateSpeed(float time) {
    m_speed = m_speed + m_acceleration * time;
}

void Particle::calculateAcceleration(float time) {
    m_acceleration = m_netForce * (1 / m_mass) * time;
}

//void Particle::recalculateAll(float time) {
//    std::cout << "recalculateAll in Particle" << std::endl;
//    calculateSpeed(time);
//    calculatePosition(time);
//    calculateAcceleration(time);
//}

void Particle::update(float deltaTime) {
    // Update sum of forces
    m_netForce = Vector3d();
    if (isKinematic) {
        gravity.addForce(this, deltaTime);
    }

    // Update state
    calculateSpeed(deltaTime);
    calculatePosition(deltaTime);
    calculateAcceleration(deltaTime);
}

void Particle::drawGui() {
    // Is kinematic
    ImGui::Text("Is kinematic");
    ImGui::Checkbox("##ParticleKinematic", &isKinematic);

    // Weight
    ImGui::Text("Weight");
    ImGui::DragFloat("##ParticleWeight", &m_mass, 0.1f, 0.0f, 100.0f);

    // Gravity
    ImGui::Text("Gravity");
    if (ImGui::BeginTable("ParticleGravity", 3)) {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleWeight", &gravity.getGravityRef().m_x);
        ImGui::SameLine();
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleWeight", &gravity.getGravityRef().m_y);
        ImGui::SameLine();
        ImGui::TableNextColumn();
        ImGui::SameLine();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleWeight", &gravity.getGravityRef().m_z);
        ImGui::EndTable();
    }

    // Speed, acceleration
    ImGui::Text("Speed");
    if (ImGui::BeginTable("ParticleSpeed", 3)) {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleSpeedX", &m_speed.m_x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleSpeedY", &m_speed.m_y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleSpeedZ", &m_speed.m_z);
        ImGui::EndTable();
    }
    ImGui::Text("Acceleration");
    if (ImGui::BeginTable("ParticleAcceleration", 3)) {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleAccelerationX", &m_acceleration.m_x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleAccelerationY", &m_acceleration.m_y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleAccelerationZ", &m_acceleration.m_z);
        ImGui::EndTable();
    }

    // Add force
    if (ButtonCenteredOnLine("Add Force", 0.5f)) {
        ImGui::OpenPopup("ParticleAddForce##popup");
    }
    if (ImGui::BeginPopup("ParticleAddForce##popup")) {

        ImGui::EndPopup();
    }
}

float Particle::distance(const Particle &p) {
    return (m_gameObject->transform.getPosition() - p.getPosition()).norm();
}


std::string Particle::getName() const {
    return COMPONENT_TYPE;
}
