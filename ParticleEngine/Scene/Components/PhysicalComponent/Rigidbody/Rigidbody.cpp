#include "Rigidbody.h"

#include <utility>

#include "imgui/imgui.h"
#include "../../../GameObject.h"

#include "../../../../Force/ForceGenerator.h"
#include "../../../../Utility/imGuiUtility.h"

Rigidbody::Rigidbody(GameObject *gameObject) : Component(gameObject) {
    m_mass = 0;
    m_angularDamping = 0;
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);
}

void Rigidbody::addForce(const Vector3d &force) {
    m_forceAccum += force;
}

void Rigidbody::addForceAtPoint(const Vector3d &force, const Vector3d worldPoint) {
    Vector3d point = worldPoint - m_gameObject->transform.getPosition();
    m_forceAccum += force;
    m_torqueAccum += point.cross(force);
}

void Rigidbody::addForceAtBodyPoint(const Vector3d &force, const Vector3d &LocalPoint) {
    m_forceAccum += force;
    m_gameObject->transform.getRotation().RotateByVector(LocalPoint);
    m_torqueAccum += m_gameObject->transform.getPosition().cross(force);
}

void Rigidbody::clearAccumulator() {
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);
}

void Rigidbody::update(float time) {
    // Update sum of forces
    if (isKinematic) {
//        gravity.addForce(this);

        for (ForceGenerator *forceGenerator: forceGeneratorsList) {
//            forceGenerator->addForce(this);
        }
    }

    // Update acceleration, speed and position
    calculateAcceleration();
    calculateSpeed(time);

    // Clear accumulators
    clearAccumulator();
}

void Rigidbody::drawGui() {
    ImGui::Text("Is kinematic");
    ImGui::Checkbox("##ParticleKinematic", &isKinematic);

    // Weight
    ImGui::Text("Weight");
    ImGui::DragFloat("##ParticleWeight", &m_mass, 0.1f, 0.0f, 100.0f);

    // Angular Damping
    ImGui::Text("Angular Damping");
    ImGui::DragFloat("##ParticleAngularDamping", &m_angularDamping, 0.1f, 0.0f, 100.0f);

    // Force Accumulator
    ImGui::Text("Force Accumulator");
    ImGui::DragFloat3("##ParticleForceAccumulator", &m_forceAccum.x, 0.1f, 0.0f, 100.0f);

    // Torque Accumulator
    ImGui::Text("Torque Accumulator");
    ImGui::DragFloat3("##ParticleTorqueAccumulator", &m_torqueAccum.x, 0.1f, 0.0f, 100.0f);

    // Gravity
    ImGui::Text("Gravity");
    ImGui::DragFloat3("##ParticleGravity", &gravity.getGravityRef().x, 0.1f, 0.0f, 100.0f);

    // Handle forces
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
//                addForce(ForceGenerator::createForceGenerator(forcesName, m_gameObject));
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
//                deleteForceByClass(forceGenerator);
            }
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

