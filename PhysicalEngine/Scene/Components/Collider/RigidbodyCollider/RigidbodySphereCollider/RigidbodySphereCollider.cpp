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

RigidbodyPrimitiveColliderType RigidbodySphereCollider::getColliderType() const {
    return this->COLLIDER_TYPE;
}

Vector3d RigidbodySphereCollider::getNormalVector() const { // TODO: implement this
    return { 0, 0, 0 };
}

void RigidbodySphereCollider::update(float time) {

}
