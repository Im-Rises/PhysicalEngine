#include "Rigidbody.h"

#include <utility>

#include "imgui/imgui.h"
#include "../../../GameObject.h"

#include "../../../../Force/ForceGenerator.h"
#include "../../../../Utility/imGuiUtility.h"

Rigidbody::Rigidbody(GameObject *gameObject) : Component(gameObject) {
    m_mass = 1;
    m_angularDamping = 0;
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);

    pointForceGeneratorsList.emplace_back(ForceGenerator::createForceGenerator(DRAG_FORCE, gameObject),
                                          Vector3d(5, 0, 0));
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
        gravity.addForce(this);

        for (ForceGenerator *forceGenerator: forceGeneratorsList) {
            forceGenerator->addForce(this);
        }

        for (ForcePoint &forcePoint: pointForceGeneratorsList) {
            forcePoint.force->addForce(this, forcePoint.point);
//            addForceAtBodyPoint(forcePoint.force->, forcePoint.point);
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

    // Torque Accumulator
    ImGui::Text("Torque Accumulator");
    ImGui::DragFloat3("##ParticleTorqueAccumulator", &m_torqueAccum.x, 0.1f, 0.0f, 100.0f);

    // Angular Speed
    ImGui::Text("Angular Speed");
    ImGui::DragFloat3("##ParticleAngularSpeed", &angularSpeed.x, 0.1f, 0.0f, 100.0f);

    // Angular Acceleration
    ImGui::Text("Angular Acceleration");
    ImGui::DragFloat3("##ParticleAngularAcceleration", &angularAcceleration.x, 0.1f, 0.0f, 100.0f);

    ImGui::NewLine();

    PhysicalComponent::drawGuiForceGenerators();
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

