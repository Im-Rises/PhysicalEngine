#include "RigidbodySphereCollider.h"

#include "imgui/imgui.h"

RigidbodySphereCollider::RigidbodySphereCollider(GameObject* gameObject, float radius) : RigidbodyPrimitiveCollider(gameObject) {
    m_gameObject = gameObject;
    m_radius = radius;
}

void RigidbodySphereCollider::drawGui() {
    ImGui::Text("Radius:");
    ImGui::SameLine();
    ImGui::DragFloat("##Radius", &m_radius, 0.1f, 0.0f, 0.0f, "%.1f");
}
std::string RigidbodySphereCollider::getName() const {
    return this->COMPONENT_TYPE;
}
float RigidbodySphereCollider::getRadius() const {
    return m_radius;
}
