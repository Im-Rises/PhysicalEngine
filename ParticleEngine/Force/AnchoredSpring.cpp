#include "AnchoredSpring.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "imgui/imgui.h"
#include "../Scene/Scene.h"

AnchoredSpring::AnchoredSpring() {
    m_anchor = Vector3d(0, 0, 0);
    m_k = 0;
    m_restLength = 0;
}

AnchoredSpring::~AnchoredSpring() {
}

AnchoredSpring::AnchoredSpring(const Vector3d &anchor, float k, float restLength) {
    m_anchor = anchor;
    m_k = k;
    m_restLength = restLength;
}

AnchoredSpring::AnchoredSpring(const AnchoredSpring &aSpring) {
    m_anchor = aSpring.m_anchor;
    m_k = aSpring.m_k;
    m_restLength = aSpring.m_restLength;
}

void AnchoredSpring::addForce(Particle *particle) {
    Vector3d pos = particle->getPosition();
    float delta = pos.distance(m_anchor);
    Vector3d F;
    if (delta > m_restLength) {
        F = (pos - m_anchor).normalize() * (-m_k) * (delta - m_restLength);
    }
    Vector3d initialForce = particle->getNetForce();
    particle->setNetForce(initialForce + F);
}

std::string AnchoredSpring::getName() const {
    return FORCE_TYPE;
}

void AnchoredSpring::drawGui(Scene *scene) {
    if (ImGui::CollapsingHeader(getName().c_str())) {
        if (ImGui::BeginTable("Anchor", 3)) {
            ImGui::TableNextColumn();
            ImGui::Text("X:");
            ImGui::SameLine();
            ImGui::InputFloat("##AnchorX", &m_anchor.m_x);
            ImGui::TableNextColumn();
            ImGui::Text("Y:");
            ImGui::SameLine();
            ImGui::InputFloat("##AnchorY", &m_anchor.m_y);
            ImGui::TableNextColumn();
            ImGui::Text("Z:");
            ImGui::SameLine();
            ImGui::InputFloat("##AnchorZ", &m_anchor.m_z);
            ImGui::EndTable();
        }
        ImGui::Text("K: ");
        ImGui::SameLine();
        ImGui::InputFloat("##AnchorKCoeff", &m_k);
        ImGui::Text("Rest Length: ");
        ImGui::SameLine();
        ImGui::InputFloat("##AnchorRestLengtgh", &m_restLength);
    }
}

void AnchoredSpring::translate(const Vector3d &translation) {
    m_anchor = m_anchor + translation;
}
