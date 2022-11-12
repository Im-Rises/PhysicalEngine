#include "Collider.h"

#include "imgui/imgui.h"

Collider::Collider(GameObject* gameObject) : Component(gameObject) {
    //    m_mass = 0;
    //    m_friction = 0;
    //    m_restitution = 0;
}

// void Collider::update(float time){
// };
//
// void Collider::drawGui() {
//     /*   ImGui::Text("Mass");
//        if (ImGui::BeginTable("Position", 3)) {
//
//            ImGui::EndTable();
//        }*/
// }
//
//
// std::string Collider::getName() const {
//     return COMPONENT_TYPE;
// }



// Collider::Collider(GameObject* gameObject, float mass, float friction, float restitution) : Component(gameObject) {
//     this->m_mass = mass;
//     this->m_friction = friction;
//     this->m_restitution = restitution;
// }
//
// void Collider::update(float time) {
// }
//
// float Collider::getMass() const {
//     return m_mass;
// }
//
// float Collider::getFriction() const {
//     return m_friction;
// }
//
// float Collider::getRestitution() const {
//     return m_restitution;
// }
//
// void Collider::setMass(float mass) {
//     this->m_mass = mass;
// }
//
// void Collider::setFriction(float friction) {
//     this->m_friction = friction;
// }
//
// void Collider::setRestitution(float restitution) {
//     this->m_restitution = restitution;
// }
