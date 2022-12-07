#include "RigidbodyCuboidRectangleCollider.h"

RigidbodyCuboidRectangleCollider::RigidbodyCuboidRectangleCollider(GameObject* gameObject, float width, float height, float depth) : RigidbodyPrimitiveCollider(gameObject) {
    m_width = width;
    m_height = height;
    m_depth = depth;
}

void RigidbodyCuboidRectangleCollider::drawGui() {
}

std::string RigidbodyCuboidRectangleCollider::getName() const {
    return this->COMPONENT_TYPE;
}
