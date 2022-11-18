#include "Rigidbody.h"

#include <utility>

#include "imgui/imgui.h"
#include "../../../GameObject.h"

Rigidbody::Rigidbody(GameObject *gameObject) : Component(gameObject) {
    m_mass = 0;
    m_angularDamping = 0;
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);
}

void Rigidbody::AddForce(const Vector3d &force) {
    m_forceAccum += force;
}

void Rigidbody::AddForceAtPoint(const Vector3d &force, const Vector3d worldPoint) {
    Vector3d point = worldPoint - m_gameObject->transform.getPosition();
    m_forceAccum += force;
    m_torqueAccum += point.cross(force);
}

void Rigidbody::AddForceAtBodyPoint(const Vector3d &force, const Vector3d &LocalPoint) {
    m_forceAccum += force;
//    Vector3d point = m_gameObject->transform.getRotation().getMatrix() * LocalPoint;
    m_gameObject->transform.getRotation().RotateByVector(LocalPoint);
    m_torqueAccum += m_gameObject->transform.getRotation()..cross(force);
}

void Rigidbody::ClearAccumulator() {
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);
}

void Rigidbody::update(float time) {
    // Update linear position
    Vector3d position = m_gameObject->transform.getPosition();
    position += m_velocity * time;
    m_gameObject->transform.setPosition(position);

    // Update angular position
    Quaternion rotation = m_gameObject->transform.getRotation();
    rotation += m_gameObject->transform.rotation * time;
    m_gameObject->transform.setRotation(rotation);

    // Calculate linear velocity
    Vector3d resultingAcc = m_forceAccum * m_mass;
//    m_velocity += resultingAcc * time;

    // Calculate angular velocity
    Vector3d angularAcc = m_torqueAccum * m_mass;
//    m_rotation += angularAcc * time;

    // Impose drag
//    m_velocity *= pow(m_linearDamping, time);
//    m_rotation *= pow(m_angularDamping, time);

    // Clear accumulators
    ClearAccumulator();
}

void Rigidbody::drawGui() {
    ImGui::Text("Rigidbody");

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
}

std::string Rigidbody::getName() const {
    return COMPONENT_TYPE;
}

