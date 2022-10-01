#include "Particule.h"

#include "imgui/imgui.h"

Particule::Particule() : m_speed(0, 0, 0), m_acceleration(0, 0, 0), Rigidbody("Particule") {
    m_position = Vector3d(0, 0, 0);
};

Particule::Particule(float x, float y, float z) : m_speed(0, 0, 0), m_acceleration(0, 0, 0), Rigidbody("Particule") {
    m_position = Vector3d(x, y, z);
}

Particule::Particule(const Vector3d &pos) : m_speed(0, 0, 0), m_acceleration(0, 0, 0), Rigidbody("Particule") {
    m_position = pos;
}

Particule::Particule(const Particule &particule) {
    m_acceleration = Vector3d(particule.m_acceleration);
    m_speed = Vector3d(particule.m_speed);
    m_position = Vector3d(particule.m_position);
}

const Vector3d &Particule::getSpeed() const {
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

void Particule::update() {

}

void Particule::drawGui() {
    ImGui::Text("Speed");
    if (ImGui::BeginTable("Speed", 3)) {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticuleSpeedX", &m_speed.m_x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticuleSpeedY", &m_speed.m_y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticuleSpeedZ", &m_speed.m_z);
        ImGui::EndTable();
    }
    ImGui::Text("Acceleration");
    if (ImGui::BeginTable("Acceleration", 3)) {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticuleAccelerationX", &m_acceleration.m_x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticuleAccelerationY", &m_acceleration.m_y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticuleAccelerationZ", &m_acceleration.m_z);
        ImGui::EndTable();
    }
}


