#include "Spring.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "imgui/imgui.h"
#include "../Utility/imGuiUtility.h"
#include "../Scene/GameObject.h"
#include "../Scene/Scene.h"


Spring::Spring() {
    m_k = 0;
    m_restLength = 0;
}

//Spring::Spring(Particle *otherParticle, float k, float restLength) {
//    m_otherParticle = otherParticle;
//    m_k = k;
//    m_restLength = restLength;
//}
//
//Spring::Spring(const Spring &spring) {
//    m_otherParticle = spring.m_otherParticle;
//    m_k = spring.m_k;
//    m_restLength = spring.m_restLength;
//}

Spring::~Spring() {
}

void Spring::addForce(Particle *particle, float duration) {
    Particle *otherParticle = nullptr;
    m_otherGameObject->getComponentByClass(otherParticle);

    if (otherParticle == nullptr)
        return;

    calculateForce(particle, otherParticle, duration);
    calculateForce(otherParticle, particle, duration);
}

void Spring::calculateForce(Particle *particle, Particle *otherParticle, float duration) {
    float delta = otherParticle->distance(*particle);

    Vector3d F;
    if (delta > m_restLength) {
        Vector3d vec1 = particle->getPosition();
        Vector3d vec2 = otherParticle->getPosition();
        F = (vec1 - vec2).normalize() * (-m_k) * (delta - m_restLength);
    }

    Vector3d initialForce = particle->getNetForce();
    particle->setNetForce(initialForce + F);
}


void Spring::drawGui(Scene *scene) {
    if (ImGui::CollapsingHeader(SPRING_FORCE)) {
        ImGui::Text("K: ");
        ImGui::SameLine();
        ImGui::InputFloat("##SpringK", &m_k);
        ImGui::Text("Rest Length: ");
        ImGui::SameLine();
        ImGui::InputFloat("##SpringRestLength", &m_restLength);

        ImGui::Text("Select Particle: ");
        if (ImGuiUtility::ButtonCenteredOnLine("Select other particle", 0.5f)) {
            ImGui::OpenPopup("Add component##popup");
        }
        ImGui::Text("%s", m_otherGameObject != nullptr ? ("Selected: " + m_otherGameObject->getName()).c_str()
                                                       : "Selected: None");
        if (ImGui::BeginPopup("Add component##popup")) {
            for (auto &gameObject: scene->getGameObjects()) {
                if (gameObject->hasComponentByName(PARTICLE_COMPONENT)) {
                    ImGui::Selectable(gameObject->getName().c_str(), m_otherGameObject == gameObject);
                    if (ImGui::IsItemClicked()) {
                        m_otherGameObject = gameObject;
                    }
                }
            }
            ImGui::EndPopup();
        }
    }
}

std::string Spring::getName() const {
    return SPRING_FORCE;
}
