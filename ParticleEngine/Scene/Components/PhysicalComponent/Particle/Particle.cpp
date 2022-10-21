#include "Particle.h"

#include "imgui/imgui.h"
#include "../../../GameObject.h"
#include "../../../../Force/ForceGenerator.h"
#include "../../../../Utility/imGuiUtility.h"
#include "../../../../Force/AnchoredSpring.h"

Particle::Particle(GameObject *gameObject) : speed(0, 0, 0), acceleration(0, 0, 0),
                                             Component(gameObject) {
    gameObject->transform.setPosition(Vector3d(0, 0, 0));
    mass = 0;
}

Particle::Particle(GameObject *gameObject, const Vector3d &pos, float m) : speed(0, 0, 0), acceleration(0, 0, 0),
                                                                           Component(gameObject) {
    gameObject->transform.setPosition(pos);
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
    ImGui::Text("Gravity");
    if (ImGui::BeginTable("ParticleGravity", 3)) {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleWeight", &gravity.getGravityRef().m_x);
        ImGui::SameLine();
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleWeight", &gravity.getGravityRef().m_y);
        ImGui::SameLine();
        ImGui::TableNextColumn();
        ImGui::SameLine();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##ParticleWeight", &gravity.getGravityRef().m_z);
        ImGui::EndTable();
    }

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
        if (ImGui::BeginTable("ParticleForces", 2)) {
            ImGui::TableNextColumn();
            ImGui::Text("Name");
            ImGui::TableNextColumn();
            ImGui::Text("Value");
            for (ForceGenerator *forceGenerator: forceGeneratorsList) {
                ImGui::TableNextColumn();
                ImGui::Text("%s", forceGenerator->getName().c_str());
//            ImGui::TableNextColumn();
//            ImGui::Text(forceGenerator->getValue().c_str());
            }
            ImGui::EndTable();
        }
        ImGui::EndPopup();
    }

    ImGui::SameLine();

    // Add force
    if (ImGui::Button(addForcesText.c_str())) {
        ImGui::OpenPopup("ParticleAddForce##popup");
    }
    if (ImGui::BeginPopup("ParticleAddForce##popup")) {
        if (ImGui::Button("Anchor Spring")) {
            forceGeneratorsList.push_back(new AnchoredSpring());
        }
        ImGui::EndPopup();
    }
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
