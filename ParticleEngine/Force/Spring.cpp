#include "Spring.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "../Scene/GameObject.h"
#include "../Scene/Scene.h"
#include "../Utility/imGuiUtility.h"
#include "imgui/imgui.h"


Spring::Spring(GameObject* gameObject) : ForceGenerator(gameObject) {
    m_k = 0;
    m_restLength = 0;
}

Spring::Spring(GameObject* gameObject, float k, float restLength) : ForceGenerator(gameObject) {
    m_k = k;
    m_restLength = restLength;
}

// Spring::Spring(Particle *otherParticle, float k, float restLength) {
//     m_otherParticle = otherParticle;
//     m_k = k;
//     m_restLength = restLength;
// }
//
// Spring::Spring(const Spring &spring) {
//     m_otherParticle = spring.m_otherParticle;
//     m_k = spring.m_k;
//     m_restLength = spring.m_restLength;
//}

Spring::~Spring() {
}

void Spring::addForce(PhysicalComponent* physicalComponent) {
    // Get particle component from other game object
    PhysicalComponent* otherPhysicalComponent = nullptr;
    if (m_otherGameObject == nullptr)
        return;
    m_otherGameObject->getComponentByClass(otherPhysicalComponent);
    if (otherPhysicalComponent == nullptr)
        return;

    // Calculate force from this particle to other particle
    calculateForce(physicalComponent, otherPhysicalComponent);
    calculateForce(otherPhysicalComponent, physicalComponent);
}


void Spring::calculateForce(PhysicalComponent* physicalComponent, PhysicalComponent* otherPhysicalComponent) {
    float delta = otherPhysicalComponent->distance(*physicalComponent);

    Vector3d F;
    if (delta > m_restLength)
    {
        Vector3d vec1 = physicalComponent->getPosition();
        Vector3d vec2 = otherPhysicalComponent->getPosition();
        F = (vec1 - vec2).normalize() * (-m_k) * (delta - m_restLength);
    }

    Vector3d initialForce = physicalComponent->getNetForce();
    physicalComponent->setNetForce(initialForce + F);
}

Vector3d Spring::getForceValue(PhysicalComponent* physicalComponent) {
    // Get particle component from other game object
    PhysicalComponent* otherPhysicalComponent = nullptr;
    if (m_otherGameObject == nullptr)
        return Vector3d();
    m_otherGameObject->getComponentByClass(otherPhysicalComponent);
    if (otherPhysicalComponent == nullptr)
        return Vector3d();

    // Calculate force from this particle to other particle
    float delta = otherPhysicalComponent->distance(*physicalComponent);

    Vector3d F;
    if (delta > m_restLength)
    {
        Vector3d vec1 = physicalComponent->getPosition();
        Vector3d vec2 = otherPhysicalComponent->getPosition();
        F = (vec1 - vec2).normalize() * (-m_k) * (delta - m_restLength);
    }
    return F;
}

void Spring::drawGui(Scene* scene) {
    if (ImGui::CollapsingHeader(SPRING_FORCE))
    {
        ImGui::Text("K: ");
        ImGui::SameLine();
        ImGui::InputFloat("##SpringK", &m_k);
        ImGui::Text("Rest Length: ");
        ImGui::SameLine();
        ImGui::InputFloat("##SpringRestLength", &m_restLength);

        ImGui::Text("Select Particle: ");
        if (ImGuiUtility::ButtonCenteredOnLine("Select other particle", 0.5f))
        {
            ImGui::OpenPopup("Add spring##SpringPopup");
        }
        ImGui::Text("%s", m_otherGameObject != nullptr ? ("Selected: " + m_otherGameObject->getName()).c_str()
                                                       : "Selected: None");
        if (ImGui::BeginPopup("Add spring##SpringPopup"))
        {
            for (auto& selectableOtherGameObject : scene->getGameObjects())
            {
                bool hasParticle = selectableOtherGameObject->hasComponentByName(PARTICLE_COMPONENT);
                if (hasParticle && selectableOtherGameObject != parentGameObject)
                {
                    std::string nameLabel =
                        selectableOtherGameObject->getName() + "##Spring" + selectableOtherGameObject->getName();
                    ImGui::Selectable(nameLabel.c_str(), m_otherGameObject == selectableOtherGameObject);
                    if (ImGui::IsItemClicked())
                    {
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
void Spring::setOtherGameObject(GameObject* otherGameObject) {
    m_otherGameObject = otherGameObject;
}
