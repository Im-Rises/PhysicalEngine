#include "Particle.h"

#include "imgui/imgui.h"
#include "../../../GameObject.h"
#include "../../../../Utility/imGuiUtility.h"

Particle::Particle(GameObject *gameObject) : Component(gameObject) {
    speed = {0, 0, 0};
    acceleration = {0, 0, 0};
    mass = 1;
}

Particle::Particle(GameObject *gameObject, float m) : Component(gameObject) {
    speed = {0, 0, 0};
    acceleration = {0, 0, 0};
    mass = m;
}

Particle::Particle(const Particle &particle) : Component(particle.m_gameObject) {
    acceleration = Vector3d(particle.acceleration);
    speed = Vector3d(particle.speed);
    m_gameObject->transform.setPosition(particle.m_gameObject->transform.getPosition());
    mass = particle.mass;
}

void Particle::update(float deltaTime) {
    // Update sum of forces
    netForce = Vector3d();
    if (isKinematic) {
        gravity.addForce(this, deltaTime);

        for (ForceGenerator *forceGenerator: forceGeneratorsList) {
            forceGenerator->addForce(this, deltaTime);
        }
    }

    // Update acceleration, speed and position
    calculateAcceleration();
    calculateSpeed(deltaTime);
    calculatePosition(deltaTime);
}

float Particle::distance(const Particle &p) {
    return (m_gameObject->transform.getPosition() - p.getPosition()).norm();
}

void Particle::calculatePosition(float time) {
    m_gameObject->transform.setPosition(m_gameObject->transform.getPosition() + speed * time);
}

void Particle::calculateSpeed(float time) {
    speed = speed + acceleration * time;
}

void Particle::calculateAcceleration() {
//    m_acceleration = m_netForce * (1 / m_mass) * time;
    acceleration = netForce / mass;
}

void Particle::drawGui() {
    // Is kinematic
    ImGui::Text("Is kinematic");
    ImGui::Checkbox("##ParticleKinematic", &isKinematic);

    // Weight
    ImGui::Text("Weight");
    ImGui::DragFloat("##ParticleWeight", &mass, 0.1f, 0.0f, 100.0f);

    // Gravity
    gravity.drawGui();

    // Speed, acceleration
    ImGui::Text("Speed");
    if (ImGui::BeginTable("ParticleSpeed", 3)) {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleSpeedX", &speed.m_x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleSpeedY", &speed.m_y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleSpeedZ", &speed.m_z);
        ImGui::EndTable();
    }
    ImGui::Text("Acceleration");
    if (ImGui::BeginTable("ParticleAcceleration", 3)) {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleAccelerationX", &acceleration.m_x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleAccelerationY", &acceleration.m_y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleAccelerationZ", &acceleration.m_z);
        ImGui::EndTable();
    }
    ImGui::NewLine();

    std::string forcesListText = "Forces list";
    std::string addForcesText = "Add forces";
    // Forces list and add force
    AlignForWidth((CalculateTextWidth(forcesListText.c_str()) + CalculateTextWidth(addForcesText.c_str())));

    // Forces list
    if (ImGui::Button(forcesListText.c_str())) {
        ImGui::OpenPopup("ParticleForcesList##popup");
    }
    if (ImGui::BeginPopup("ParticleForcesList##popup")) {
        if (forceGeneratorsList.empty())
            ImGui::Text("Empty");
        else
            for (auto &forceGenerator: forceGeneratorsList) {
                forceGenerator->drawGui();
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
                addForce(ForceGenerator::createForceGenerator(forcesName));
            }
        }
        ImGui::EndPopup();
    }
}

void Particle::addForce(ForceGenerator *forceGenerator) {
    forceGeneratorsList.push_back(forceGenerator);
}

std::string Particle::getName() const {
    return COMPONENT_TYPE;
}

Vector3d Particle::getPosition() const {
    return m_gameObject->transform.getPosition();
}

const Vector3d &Particle::getSpeed() const {
    return speed;
}

const Vector3d &Particle::getAcceleration() const {
    return acceleration;
}

void Particle::setPosition(float x, float y, float z) {
    m_gameObject->transform.setPosition(Vector3d(x, y, z));
}

void Particle::setPosition(const Vector3d &position) {
    m_gameObject->transform.setPosition(position);
}

void Particle::setSpeed(float x, float y, float z) {
    speed = Vector3d(x, y, z);
}

void Particle::setSpeed(const Vector3d &speed) {
    this->speed = speed;
}

void Particle::setAcceleration(float x, float y, float z) {
    acceleration = Vector3d(x, y, z);
}

void Particle::setAcceleration(const Vector3d &acceleration) {
    this->acceleration = acceleration;
}

float Particle::getMass() const { return mass; }

const Vector3d &Particle::getNetForce() const { return netForce; }


void Particle::setNetForce(const Vector3d &force) { netForce = force; }


