#include "Spring.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "imgui/imgui.h"
#include "../Utility/imGuiUtility.h"
#include "../Scene/GameObject.h"
#include "../Scene/Scene.h"


Spring::Spring(GameObject *gameObject) : ForceGenerator(gameObject) {
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

void Spring::addForce(Particle *particle) {
    // Get particle component from other game object
    Particle *otherParticle = nullptr;
    if (m_otherGameObject == nullptr)
        return;
    m_otherGameObject->getComponentByClass(otherParticle);
    if (otherParticle == nullptr)
        return;

    // Calculate force from this particle to other particle
    calculateForce(particle, otherParticle);
    calculateForce(otherParticle, particle);
}

void Spring::calculateForce(Particle *particle, Particle *otherParticle) {
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
            ImGui::OpenPopup("Add spring##SpringPopup");
        }
        ImGui::Text("%s", m_otherGameObject != nullptr ? ("Selected: " + m_otherGameObject->getName()).c_str()
                                                       : "Selected: None");
        if (ImGui::BeginPopup("Add spring##SpringPopup")) {
            for (auto &selectableOtherGameObject: scene->getGameObjects()) {
                bool hasParticle = selectableOtherGameObject->hasComponentByName(PARTICLE_COMPONENT);
                if (hasParticle && selectableOtherGameObject != parentGameObject) {
                    std::string nameLabel =
                            selectableOtherGameObject->getName() + "##Spring" + selectableOtherGameObject->getName();
                    ImGui::Selectable(nameLabel.c_str(), m_otherGameObject == selectableOtherGameObject);
                    if (ImGui::IsItemClicked()) {
                        m_otherGameObject = selectableOtherGameObject;
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
