#include "Rigidbody.h"

#include <utility>

#include "imgui/imgui.h"
#include "../../../GameObject.h"

#include "../../../../Force/ForceGenerator.h"
#include "../../../../Force/AnchoredSpring.h"
#include "../../../../Utility/imGuiUtility.h"

Rigidbody::Rigidbody(GameObject *gameObject) : Component(gameObject) {
    m_mass = 1;
    m_angularDamping = 0;
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);

    pointForceGeneratorsList.emplace_back(ForcePoint{new AnchoredSpring(), Vector3d(5, 0, 0)});
}

void Rigidbody::addForce(const Vector3d &force) {
    m_forceAccum += force;
}

//void Rigidbody::addForceAtPoint(const Vector3d &force, const Vector3d worldPoint) {
//    Vector3d point = worldPoint - m_gameObject->transform.getPosition();
//    m_forceAccum += force;
//    m_torqueAccum += point.cross(force);
//}

void Rigidbody::addForceAtBodyPoint(const Vector3d &force, const Vector3d &LocalPoint) {
    m_forceAccum += force;
    m_gameObject->transform.getRotation().rotateByVector(LocalPoint);
    m_torqueAccum += m_gameObject->transform.getPosition().cross(force);
//    m_torqueAccum = Vector3d(10, 0, 0);
}

void Rigidbody::clearAccumulator() {
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);
}

void Rigidbody::update(float time) {
    // Update sum of forces
    if (isKinematic) {
        gravity.addForce(this);

        for (ForceGenerator *forceGenerator: forceGeneratorsList) {
            forceGenerator->addForce(this);
        }

        for (ForcePoint &forcePoint: pointForceGeneratorsList) {
            Vector3d before = m_forceAccum;
            forcePoint.force->addForce(this);
            Vector3d forceValue = m_forceAccum - before;
            addForceAtBodyPoint(forceValue, forcePoint.point);
        }
    }

    // Update acceleration, speed and position
    calculateAcceleration();
    calculateSpeed(time);

    // Clear accumulators
    clearAccumulator();
}

void Rigidbody::drawGui() {
    PhysicalComponent::drawGui();
    // Angular Damping
    ImGui::Text("Angular Damping");
    ImGui::DragFloat("##ParticleAngularDamping", &m_angularDamping, 0.1f, 0.0f, 100.0f);

    // Angular Speed
    ImGui::Text("Angular Speed");
    ImGui::DragFloat3("##ParticleAngularSpeed", &angularSpeed.x, 0.1f, 0.0f, 100.0f);

    // Angular Acceleration
    ImGui::Text("Angular Acceleration");
    ImGui::DragFloat3("##ParticleAngularAcceleration", &angularAcceleration.x, 0.1f, 0.0f, 100.0f);

    ImGui::NewLine();
    ImGui::Text("Force Generators");
    PhysicalComponent::drawGuiForceGenerators();

    ImGui::NewLine();
    ImGui::Text("Force Generators at Point");
    drawGuiForceGeneratorsAtPoint();
}

void Rigidbody::drawGuiForceGeneratorsAtPoint() {
    std::string forcesListText = "Forces list";
    std::string addForcesText = "Add forces";
    std::string deleteForcesText = "Delete forces";

    // Forces list and add force
    ImGuiUtility::AlignForWidth((ImGuiUtility::CalculateTextWidth(forcesListText.c_str()) +
                                 ImGuiUtility::CalculateTextWidth(addForcesText.c_str()) +
                                 ImGuiUtility::CalculateTextWidth(deleteForcesText.c_str())));

    // Forces list
    if (ImGui::Button(forcesListText.c_str())) {
        ImGui::OpenPopup("RigidbodyForcesList##popup");
    }
    if (ImGui::BeginPopup("RigidbodyForcesList##popup")) {
        if (pointForceGeneratorsList.empty())
            ImGui::Text("Empty");
        else
            for (auto &forceGenerator: pointForceGeneratorsList) {
                forceGenerator.force->drawGui(m_gameObject->getScenePtr());
                ImGui::DragFloat3("Point", &forceGenerator.point.x);
            }
        ImGui::EndPopup();
    }

    ImGui::SameLine();

    // Add force
    if (ImGui::Button(addForcesText.c_str())) {
        ImGui::OpenPopup("RigidbodyForcesAddForce##popup");
    }
    if (ImGui::BeginPopup("RigidbodyForcesAddForce##popup")) {
        for (auto &forcesName: ForceGenerator::forcesNamesList) {
            if (ImGui::MenuItem(forcesName)) {
//                addForceAtBodyPoint(ForceGenerator::createForceGenerator(forcesName, m_gameObject), Vector3d(0, 0, 0));
            }
        }
        ImGui::EndPopup();
    }

    ImGui::SameLine();

    // Delete force
    if (ImGui::Button(deleteForcesText.c_str())) {
        ImGui::OpenPopup("RigidbodyForcesDeleteForce##RigidbodyForcesDeleteForcePopup");
    }
    if (ImGui::BeginPopup("RigidbodyForcesDeleteForce##RigidbodyForcesDeleteForcePopup")) {
        for (auto &forceGenerator: pointForceGeneratorsList) {
//            if (ImGui::MenuItem(forceGenerator->getName().c_str())) {
//                deleteForceByClass(forceGenerator);
//            }
        }
        ImGui::EndPopup();
    }
}

std::string Rigidbody::getName() const {
    return COMPONENT_TYPE;
}

void Rigidbody::calculateAcceleration() {
    linearAcceleration = m_forceAccum / m_mass;
    angularAcceleration = m_torqueAccum / m_mass;
}

void Rigidbody::calculateSpeed(float time) {
    linearSpeed = linearSpeed + linearAcceleration * time;
    angularSpeed = angularSpeed + angularAcceleration * time;
}

Vector3d Rigidbody::getAngularSpeed() const {
    return angularSpeed;
}

