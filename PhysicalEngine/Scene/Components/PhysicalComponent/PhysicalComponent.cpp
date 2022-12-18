#include "PhysicalComponent.h"

#include "../../../Utility/imGuiUtility.h"
#include "../../GameObject.h"
#include <imgui/imgui.h>

PhysicalComponent::~PhysicalComponent() {
    for (auto& forceGenerator : forceGeneratorsList)
    {
        delete forceGenerator;
    }
}

float PhysicalComponent::distance(const PhysicalComponent& p) {
    return (m_gameObject->transform.getPosition() - p.m_gameObject->transform.getPosition()).norm();
}

Vector3d PhysicalComponent::getPosition() const {
    return m_gameObject->transform.getPosition();
}

const Vector3d& PhysicalComponent::getNetForce() const {
    return m_forceAccum;
}

void PhysicalComponent::setNetForce(const Vector3d& force) {
    m_forceAccum = force;
}

float PhysicalComponent::getMass() const {
    return m_mass;
}

Vector3d PhysicalComponent::getLinearSpeed() const {
    return linearSpeed;
}

void PhysicalComponent::setPosition(const Vector3d& position) {
    m_gameObject->transform.setPosition(position);
}

void PhysicalComponent::setLinearSpeed(const Vector3d& linearSpeed) {
    PhysicalComponent::linearSpeed = linearSpeed;
}


void PhysicalComponent::addForceToList(ForceGenerator* forceGenerator) {
    forceGeneratorsList.push_back(forceGenerator);
}

void PhysicalComponent::addForceByName(const std::string& forceName) {
    addForceToList(ForceGenerator::createForceGenerator(forceName, m_gameObject));
}

ForceGenerator* PhysicalComponent::getForceByName(const std::string& name) const {
    for (auto& force : forceGeneratorsList)
    {
        if (force->getName() == name)
            return static_cast<ForceGenerator*>(force);
    }
    return nullptr;
}

bool PhysicalComponent::hasForce(const std::string& name) const {
    return std::any_of(forceGeneratorsList.begin(), forceGeneratorsList.end(), [&name](ForceGenerator* forceGenerator) {
        return forceGenerator->getName() == name;
    });
}

void PhysicalComponent::drawGui() {
    // Is kinematic
    ImGui::Text("Is kinematic");
    ImGui::Checkbox("##PhysicalComponentKinematic", &isKinematic);

    // Weight
    ImGui::Text("Weight");
    ImGui::DragFloat("##PhysicalComponentWeight", &m_mass, 0.1f, 0.0f, 100.0f);

    // Gravity
    gravity.drawGui(m_gameObject->getScenePtr());

    ImGui::NewLine();

    // linearSpeed, acceleration
    ImGui::Text("linear Speed");
    if (ImGui::BeginTable("PhysicalComponentlinearSpeed", 3))
    {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##PhysicalComponentlinearSpeedX", &linearSpeed.x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##PhysicalComponentlinearSpeedY", &linearSpeed.y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##PhysicalComponentlinearSpeedZ", &linearSpeed.z);
        ImGui::EndTable();
    }
    ImGui::Text("Linear Acceleration");
    if (ImGui::BeginTable("PhysicalComponentAcceleration", 3))
    {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##PhysicalComponentAccelerationX", &linearAcceleration.x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##PhysicalComponentAccelerationY", &linearAcceleration.y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##PhysicalComponentAccelerationZ", &linearAcceleration.z);
        ImGui::EndTable();
    }
    ImGui::NewLine();
}

void PhysicalComponent::drawGuiForceGenerators() {
    std::string forcesListText = "Forces list##PhysicalComponentForcesListButton";
    std::string addForcesText = "Add forces##PhysicalComponentAddForceButton";
    std::string deleteForcesText = "Delete forces##PhysicalComponentDeleteForceButton";
    // Forces list and add force
    ImGuiUtility::AlignForWidth((ImGuiUtility::CalculateTextWidth(forcesListText.c_str()) +
                                 ImGuiUtility::CalculateTextWidth(addForcesText.c_str()) +
                                 ImGuiUtility::CalculateTextWidth(deleteForcesText.c_str())));

    // Forces list
    if (ImGui::Button(forcesListText.c_str()))
    {
        ImGui::OpenPopup("##PhysicalForceListPopup");
    }
    if (ImGui::BeginPopup("##PhysicalForceListPopup"))
    {
        if (forceGeneratorsList.empty())
            ImGui::Text("Empty");
        else
            for (auto& forceGenerator : forceGeneratorsList)
            {
                forceGenerator->drawGui(m_gameObject->getScenePtr());
            }
        ImGui::EndPopup();
    }

    ImGui::SameLine();

    // Add force
    if (ImGui::Button(addForcesText.c_str()))
    {
        ImGui::OpenPopup("##PhysicalAddForcePopup");
    }
    if (ImGui::BeginPopup("##PhysicalAddForcePopup"))
    {
        for (auto& forcesName : ForceGenerator::forcesNamesList)
        {
            if (ImGui::MenuItem(forcesName))
            {
                addForceToList(ForceGenerator::createForceGenerator(forcesName, m_gameObject));
            }
        }
        ImGui::EndPopup();
    }

    ImGui::SameLine();

    // Delete force
    if (ImGui::Button(deleteForcesText.c_str()))
    {
        ImGui::OpenPopup("##PhysicalDeleteForcePopup");
    }
    if (ImGui::BeginPopup("##PhysicalDeleteForcePopup"))
    {
        for (auto& forceGenerator : forceGeneratorsList)
        {
            if (ImGui::MenuItem(forceGenerator->getName().c_str()))
            {
                deleteForceByClass(forceGenerator);
            }
        }
        ImGui::EndPopup();
    }
}

bool PhysicalComponent::getIsKinematic() const {
    return isKinematic;
}
