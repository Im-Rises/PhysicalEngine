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

}

void Rigidbody::AddForceAtPoint(const Vector3d &force, const Vector3d worldPoint) {
}

void Rigidbody::AddForceAtBodyPoint(const Vector3d &force, const Vector3d &LocalPoint) {
}

void Rigidbody::ClearAccumulator() {
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);
}

void Rigidbody::update(float time) {

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

}

std::string Rigidbody::getName() const {
    return COMPONENT_TYPE;
}

//const Vector3d &Rigidbody::getPosition() const {
//    return m_position;
//}


