#include "CuboidCollider.h"

CuboidCollider::CuboidCollider(GameObject* gameObject, float width, float height, float depth) : Collider(gameObject) {
    m_width = width;
    m_height = height;
    m_depth = depth;
    m_gameObject = gameObject;
}

void CuboidCollider::update(float time) {
}
void CuboidCollider::drawGui() {
}


std::string CuboidCollider::getName() const {
    return COMPONENT_TYPE;
}

float CuboidCollider::getWidth() const {
    return m_width;
}

float CuboidCollider::getHeight() const {
    return m_height;
}

float CuboidCollider::getDepth() const {
    return m_depth;
}

void CuboidCollider::setWidth(float width) {
    this->m_width = width;
}

void CuboidCollider::setHeight(float height) {
    this->m_height = height;
}

void CuboidCollider::setDepth(float depth) {
    this->m_depth = depth;
}
