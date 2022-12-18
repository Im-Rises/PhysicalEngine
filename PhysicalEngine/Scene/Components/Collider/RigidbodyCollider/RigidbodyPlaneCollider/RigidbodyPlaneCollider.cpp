#include "RigidbodyPlaneCollider.h"
#include "../../../../../Utility/Matrix33.h"
#include "../../../../GameObject.h"
#include "../../../Transform/Transform.h"

#include <imgui/imgui.h>

RigidbodyPlaneCollider::RigidbodyPlaneCollider(GameObject* gameObject, float width, float depth) : RigidbodyPrimitiveCollider(gameObject) {
    m_width = width;
    m_depth = depth;
}

void RigidbodyPlaneCollider::drawGui() {
    ImGui::DragFloat("Width", &m_width, 0.1f, 0.0f, 100.0f);
    ImGui::DragFloat("Depth", &m_depth, 0.1f, 0.0f, 100.0f);
}

std::string RigidbodyPlaneCollider::getName() const {
    return this->COMPONENT_TYPE;
}

RigidbodyPrimitiveColliderType RigidbodyPlaneCollider::getColliderType() const {
    return this->COLLIDER_TYPE;
}

Vector3d RigidbodyPlaneCollider::getNormalVector() const {
    Matrix33 rotationMatrix;
    rotationMatrix.setOrientation(m_gameObject->transform.rotation);
    return rotationMatrix * Vector3d(0, 1, 0);
}
void RigidbodyPlaneCollider::update(float time) {
}

float RigidbodyPlaneCollider::getRadius() const {
    return sqrt(m_width * m_width + m_depth * m_depth) / 2;
}

float RigidbodyPlaneCollider::getWidth() const {
    return m_width;
}

void RigidbodyPlaneCollider::setWidth(float width) {
    m_width = width;
}
float RigidbodyPlaneCollider::getDepth() const {
    return m_depth;
}

void RigidbodyPlaneCollider::setDepth(float depth) {
    m_depth = depth;
}
