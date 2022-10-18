#include "Particule.h"

#include "imgui/imgui.h"
#include "../../GameObject.h"

Particule::Particule(GameObject *gameObject) : m_speed(0, 0, 0), m_acceleration(0, 0, 0),
                                               Rigidbody(gameObject, "Particule") {
    gameObject->transform.setPosition(Vector3d(0, 0, 0));
    m_mass = 0;
}

//Particule::Particule(float x, float y, float z, float m) : m_speed(0, 0, 0), m_acceleration(0, 0, 0),
//                                                           Rigidbody("Particule") {
//    m_position = Vector3d(x, y, z);
//    m_mass = m;
//}

Particule::Particule(GameObject *gameObject, const Vector3d &pos, float m) : m_speed(0, 0, 0), m_acceleration(0, 0, 0),
                                                                             Rigidbody(gameObject, "Particule") {
//    m_position = pos;
    gameObject->transform.setPosition(pos);
    m_mass = m;
}

Particule::Particule(const Particule &particule) : Rigidbody(gameObject, "Particule") {
    m_acceleration = Vector3d(particule.m_acceleration);
    m_speed = Vector3d(particule.m_speed);
//    m_position = Vector3d(particule.m_position);
    gameObject->transform.setPosition(particule.gameObject->transform.getPosition());
    m_mass = particule.m_mass;
}

const Vector3d Particule::getPosition() const {
    return gameObject->transform.getPosition();
}

const Vector3d &Particule::getSpeed() const {
    return m_speed;
}

const Vector3d &Particule::getAcceleration() const {
    return m_acceleration;
}

void Particule::setPosition(float x, float y, float z) {
//    m_position = Vector3d(x, y, z);
    gameObject->transform.setPosition(Vector3d(x, y, z));
}

void Particule::setPosition(const Vector3d &position) {
//    m_position = position;
    gameObject->transform.setPosition(position);
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

float Particule::getMass() const { return m_mass; }

const Vector3d &Particule::getNetForce() const { return m_netForce; }

float Particule::getFriction() const { return m_friction; }

void Particule::setNetForce(Vector3d force) { m_netForce = force; }

void Particule::setFriction(float friction) { m_friction = friction; }

void Particule::calculatePosition(float time) {
//    m_position = m_position + m_speed * time;
    gameObject->transform.setPosition(gameObject->transform.getPosition() + m_speed * time);
}

void Particule::calculateSpeed(float time) {
    m_speed = m_speed + m_acceleration * time;
}

void Particule::calculateAcceleration(float time) {
    m_acceleration = m_netForce * (1 / m_mass) * time;
}

//void Particule::recalculateAll(float time) {
//    std::cout << "recalculateAll in Particule" << std::endl;
//    calculateSpeed(time);
//    calculatePosition(time);
//    calculateAcceleration(time);
//}

void Particule::update(float time) {
    calculateSpeed(time);
    calculatePosition(time);
    calculateAcceleration(time);
}

void Particule::drawGui() {
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
        ImGui::InputFloat("##ParticleAccelerationX", &m_speed.m_x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleAccelerationY", &m_speed.m_y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleAccelerationZ", &m_speed.m_z);
        ImGui::EndTable();
    }
}

float Particule::distance(const Particule &p) {
//    return (this->m_position - p.getPosition()).norm();
    return (gameObject->transform.getPosition() - p.getPosition()).norm();
}




