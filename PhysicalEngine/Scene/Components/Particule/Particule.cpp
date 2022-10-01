#include "Particule.h"

#include "imgui/imgui.h"

Particule::Particule(const Particule &particule) {
    name = particule.name;
    m_acceleration = Vector3d(particule.m_acceleration);
    m_speed = Vector3d(particule.m_speed);
    m_position = Vector3d(particule.m_position);
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
