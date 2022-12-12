#include "RigidbodyCuboidRectangleCollider.h"

#include <imgui/imgui.h>

RigidbodyCuboidRectangleCollider::RigidbodyCuboidRectangleCollider(GameObject* gameObject, float width, float height, float depth) : RigidbodyPrimitiveCollider(gameObject) {
    m_width = width;
    m_height = height;
    m_depth = depth;
}

void RigidbodyCuboidRectangleCollider::drawGui() {
    ImGui::Text("Width  :");
    ImGui::SameLine();
    ImGui::DragFloat("##Width", &m_width, 0.1f, 0.0f, 0.0f, "%.1f");
    ImGui::Text("Height :");
    ImGui::SameLine();
    ImGui::DragFloat("##Height", &m_height, 0.1f, 0.0f, 0.0f, "%.1f");
    ImGui::Text("Depth  :");
    ImGui::SameLine();
    ImGui::DragFloat("##Depth", &m_depth, 0.1f, 0.0f, 0.0f, "%.1f");
}

std::string RigidbodyCuboidRectangleCollider::getName() const {
    return this->COMPONENT_TYPE;
}

RigidbodyPrimitiveColliderType RigidbodyCuboidRectangleCollider::getColliderType() const {
    return this->COLLIDER_TYPE;
}

Vector3d RigidbodyCuboidRectangleCollider::getNormalVector() const { // TODO: implement this
    return { 0, 0, 0 };
}

void RigidbodyCuboidRectangleCollider::update(float time) {
}
