#include "AnchoredSpring.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "imgui/imgui.h"

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

void AnchoredSpring::addForce(Particle *particle, float duration) {
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

void AnchoredSpring::drawGui() {
    if (ImGui::CollapsingHeader(getName().c_str())) {
        ImGui::Text("Anchor: ");
//        ImGui::SameLine();
//        ImGui::Text(m_anchor));
        ImGui::Text("K: ");
        ImGui::SameLine();
        ImGui::Text("%s", std::to_string(m_k).c_str());
        ImGui::Text("Rest Length: ");
        ImGui::SameLine();
        ImGui::Text("%s", std::to_string(m_restLength).c_str());
    }
}
