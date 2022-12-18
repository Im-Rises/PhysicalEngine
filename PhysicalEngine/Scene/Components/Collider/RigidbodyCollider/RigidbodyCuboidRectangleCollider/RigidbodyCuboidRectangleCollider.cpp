#include "RigidbodyCuboidRectangleCollider.h"

#include <imgui/imgui.h>

RigidbodyCuboidRectangleCollider::RigidbodyCuboidRectangleCollider(GameObject* gameObject, float width, float height, float depth) : RigidbodyPrimitiveCollider(gameObject) {
    m_halfwidth = width;
    m_halfheight = height;
    m_halfdepth = depth;
}

void RigidbodyCuboidRectangleCollider::drawGui() {
    ImGui::Text("Width  :");
    ImGui::SameLine();
    ImGui::DragFloat("##Width", &m_halfwidth, 0.1f, 0.0f, 0.0f, "%.1f");
    ImGui::Text("Height :");
    ImGui::SameLine();
    ImGui::DragFloat("##Height", &m_halfheight, 0.1f, 0.0f, 0.0f, "%.1f");
    ImGui::Text("Depth  :");
    ImGui::SameLine();
    ImGui::DragFloat("##Depth", &m_halfdepth, 0.1f, 0.0f, 0.0f, "%.1f");
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

void RigidbodyCuboidRectangleCollider::getAllPoints(Vector3d points[8]) {
    
    for (int i = 0;i<=1;i++)
    {
        int j = (i == 0) ? 1 : -1;
        points[i*4] = Vector3d(j*m_halfwidth,m_halfheight,m_halfdepth);
        points[i*4 + 1] = Vector3d(j*m_halfwidth, m_halfheight, -m_halfdepth);
        points[i*4 + 2] = Vector3d(j*m_halfwidth, -m_halfheight, m_halfdepth);
        points[i*4 + 3] = Vector3d(j*m_halfwidth, -m_halfheight, -m_halfdepth);
    }
}



void RigidbodyCuboidRectangleCollider::update(float time) {
}

float RigidbodyCuboidRectangleCollider::getRadius() const {
    return sqrt(m_halfwidth * m_halfwidth + m_halfheight * m_halfheight + m_halfdepth * m_halfdepth);
}
