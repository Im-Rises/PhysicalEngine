#include "Gravity.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "imgui/imgui.h"

Gravity::Gravity(const Vector3d &g) {
    m_gravity = g;
}

Gravity::Gravity(const Gravity &grav) {
    m_gravity = grav.m_gravity;
}

void Gravity::addForce(Particle *particle, float duration) {
    Vector3d F = m_gravity * particle->getMass();
    Vector3d initialForce = particle->getNetForce();
    particle->setNetForce(initialForce + F);
}

void Gravity::drawGui() {
    ImGui::Text("Gravity");
    if (ImGui::BeginTable("Gravity", 3)) {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##GravityX", &m_gravity.m_x);
        ImGui::SameLine();
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##GravityY", &m_gravity.m_y);
        ImGui::SameLine();
        ImGui::TableNextColumn();
        ImGui::SameLine();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##GravityZ", &m_gravity.m_z);
        ImGui::EndTable();
    }
}

std::string Gravity::getName() const {
    return FORCE_TYPE;
}

Vector3d &Gravity::getGravityRef() {
    return m_gravity;
}
