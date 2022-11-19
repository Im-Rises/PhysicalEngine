#include "Particle.h"

#include "imgui/imgui.h"
#include "../../../GameObject.h"
#include "../../../../Utility/imGuiUtility.h"
#include <algorithm>

Particle::Particle(GameObject *gameObject) : Component(gameObject) {
    linearSpeed = {0, 0, 0};
    linearAcceleration = {0, 0, 0};
    m_mass = 1;
}

Particle::Particle(GameObject *gameObject, float m) : Component(gameObject) {
    linearSpeed = {0, 0, 0};
    linearAcceleration = {0, 0, 0};
    m_mass = m;
}

Particle::Particle(const Particle &particle) : Component(particle.m_gameObject) {
    linearAcceleration = Vector3d(particle.linearAcceleration);
    linearSpeed = Vector3d(particle.linearSpeed);
    m_gameObject->transform.setPosition(particle.m_gameObject->transform.getPosition());
    m_mass = particle.m_mass;
}

Particle::~Particle() {
    for (auto &force: forceGeneratorsList) {
        delete force;
    }
}

void Particle::update(float deltaTime) {
    // Update sum of forces
    if (isKinematic) {
        gravity.addForce(this);

        for (ForceGenerator *forceGenerator: forceGeneratorsList) {
            forceGenerator->addForce(this);
        }
    }

    // Update acceleration, linearSpeed and position
    calculateAcceleration();
    calculateSpeed(deltaTime);

    // Reset the m_forceAccum for the next frame
    m_forceAccum = Vector3d();
}

//float Particle::distance(const Particle& p) {
//    return (m_gameObject->transform.getPosition() - p.getPosition()).norm();
//}

// void Particle::calculatePosition(float time) {
//     m_gameObject->transform.setPosition(m_gameObject->transform.getPosition() + linearSpeed * time);
// }

void Particle::calculateSpeed(float time) {
    linearSpeed = linearSpeed + linearAcceleration * time;
}

void Particle::calculateAcceleration() {
    linearAcceleration = m_forceAccum / m_mass;
}

void Particle::drawGui() {
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

void Particle::addForce(ForceGenerator *forceGenerator) {
    forceGeneratorsList.push_back(forceGenerator);
}

void Particle::addForceByName(const std::string &forceName) {
    addForce(ForceGenerator::createForceGenerator(forceName, m_gameObject));
}

ForceGenerator *Particle::getForceByName(const std::string &name) const {
    for (auto &force: forceGeneratorsList) {
        if (force->getName() == name)
            return static_cast<ForceGenerator *>(force);
    }
    return nullptr;
}

bool Particle::hasForce(const std::string &name) const {
    return std::any_of(forceGeneratorsList.begin(), forceGeneratorsList.end(), [&name](ForceGenerator *forceGenerator) {
        return forceGenerator->getName() == name;
    });
}

std::string Particle::getName() const {
    return COMPONENT_TYPE;
}

//Vector3d Particle::getPosition() const {
//    return m_gameObject->transform.getPosition();
//}

//const Vector3d &Particle::getlinearSpeed() const {
//    return linearSpeed;
//}
//
//const Vector3d &Particle::getAcceleration() const {
//    return linearAcceleration;
//}

//void Particle::setPosition(float x, float y, float z) {
//    m_gameObject->transform.setPosition(Vector3d(x, y, z));
//}
//
//void Particle::setPosition(const Vector3d &position) {
//    m_gameObject->transform.setPosition(position);
//}

//void Particle::setlinearSpeed(float x, float y, float z) {
//    linearSpeed = Vector3d(x, y, z);
//}
//
//void Particle::setlinearSpeed(const Vector3d &s) {
//    this->linearSpeed = s;
//}

//void Particle::setAcceleration(float x, float y, float z) {
//    acceleration = Vector3d(x, y, z);
//}
//
//void Particle::setAcceleration(const Vector3d &acceleration) {
//    this->acceleration = acceleration;
//}

//float Particle::getMass() const { return mass; }

//const Vector3d &Particle::getm_forceAccum() const { return m_forceAccum; }
//
//void Particle::setm_forceAccum(const Vector3d &force) { m_forceAccum = force; }
