#include "PhysicalComponent.h"

#include "../../GameObject.h"
#include <imgui/imgui.h>
#include "../../../Utility/imGuiUtility.h"

float PhysicalComponent::distance(const PhysicalComponent &p) {
    return (m_gameObject->transform.getPosition() - p.m_gameObject->transform.getPosition()).norm();
}

Vector3d PhysicalComponent::getPosition() const {
    return m_gameObject->transform.getPosition();
}

const Vector3d &PhysicalComponent::getNetForce() const {
    return m_forceAccum;
}

void PhysicalComponent::setNetForce(const Vector3d &force) {
    m_forceAccum = force;
}

float PhysicalComponent::getMass() const {
    return m_mass;
}

Vector3d PhysicalComponent::getLinearSpeed() const {
    return linearSpeed;
}

void PhysicalComponent::setPosition(const Vector3d &position) {
    m_gameObject->transform.setPosition(position);
}

void PhysicalComponent::setLinearSpeed(const Vector3d &linearSpeed) {
    PhysicalComponent::linearSpeed = linearSpeed;
}


void PhysicalComponent::addForce(ForceGenerator *forceGenerator) {
    forceGeneratorsList.push_back(forceGenerator);
}

void PhysicalComponent::addForceByName(const std::string &forceName) {
    addForce(ForceGenerator::createForceGenerator(forceName, m_gameObject));
}

ForceGenerator *PhysicalComponent::getForceByName(const std::string &name) const {
    for (auto &force: forceGeneratorsList) {
        if (force->getName() == name)
            return static_cast<ForceGenerator *>(force);
    }
    return nullptr;
}

bool PhysicalComponent::hasForce(const std::string &name) const {
    return std::any_of(forceGeneratorsList.begin(), forceGeneratorsList.end(), [&name](ForceGenerator *forceGenerator) {
        return forceGenerator->getName() == name;
    });
}

void PhysicalComponent::drawGui() {
    // Is kinematic
    ImGui::Text("Is kinematic");
    ImGui::Checkbox("##ParticleKinematic", &isKinematic);

    // Weight
    ImGui::Text("Weight");
    ImGui::DragFloat("##ParticleWeight", &m_mass, 0.1f, 0.0f, 100.0f);

    // Gravity
    gravity.drawGui(m_gameObject->getScenePtr());

    // linearSpeed, acceleration
    ImGui::Text("linearSpeed");
    if (ImGui::BeginTable("ParticlelinearSpeed", 3)) {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticlelinearSpeedX", &linearSpeed.x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticlelinearSpeedY", &linearSpeed.y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticlelinearSpeedZ", &linearSpeed.z);
        ImGui::EndTable();
    }
    ImGui::Text("Acceleration");
    if (ImGui::BeginTable("ParticleAcceleration", 3)) {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleAccelerationX", &linearAcceleration.x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleAccelerationY", &linearAcceleration.y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleAccelerationZ", &linearAcceleration.z);
        ImGui::EndTable();
    }
    ImGui::NewLine();
}

void PhysicalComponent::drawGuiForceGenerators() {
    std::string forcesListText = "Forces list";
    std::string addForcesText = "Add forces";
    std::string deleteForcesText = "Delete forces";
    // Forces list and add force
    ImGuiUtility::AlignForWidth((ImGuiUtility::CalculateTextWidth(forcesListText.c_str()) +
                                 ImGuiUtility::CalculateTextWidth(addForcesText.c_str()) +
                                 ImGuiUtility::CalculateTextWidth(deleteForcesText.c_str())));

    // Forces list
    if (ImGui::Button(forcesListText.c_str())) {
        ImGui::OpenPopup("ParticleForcesList##popup");
    }
    if (ImGui::BeginPopup("ParticleForcesList##popup")) {
        if (forceGeneratorsList.empty())
            ImGui::Text("Empty");
        else
            for (auto &forceGenerator: forceGeneratorsList) {
                forceGenerator->drawGui(m_gameObject->getScenePtr());
            }
        ImGui::EndPopup();
    }

    ImGui::SameLine();

    // Add force
    if (ImGui::Button(addForcesText.c_str())) {
        ImGui::OpenPopup("ParticleAddForce##popup");
    }
    if (ImGui::BeginPopup("ParticleAddForce##popup")) {
        for (auto &forcesName: ForceGenerator::forcesNamesList) {
            if (ImGui::MenuItem(forcesName)) {
                addForce(ForceGenerator::createForceGenerator(forcesName, m_gameObject));
            }
        }
        ImGui::EndPopup();
    }

    ImGui::SameLine();

    // Delete force
    if (ImGui::Button(deleteForcesText.c_str())) {
        ImGui::OpenPopup("ParticleDeleteForce##ParticleDeleteForcePopup");
    }
    if (ImGui::BeginPopup("ParticleDeleteForce##ParticleDeleteForcePopup")) {
        for (auto &forceGenerator: forceGeneratorsList) {
            if (ImGui::MenuItem(forceGenerator->getName().c_str())) {
                deleteForceByClass(forceGenerator);
            }
        }
        ImGui::EndPopup();
    }
}
