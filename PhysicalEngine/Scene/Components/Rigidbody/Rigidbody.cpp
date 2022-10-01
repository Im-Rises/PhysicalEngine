#include "Rigidbody.h"

#include "imgui/imgui.h"

Rigidbody::Rigidbody() : Component("Rigidbody") {
    m_position = Vector3d(0, 0, 0);
}

Rigidbody::Rigidbody(std::string name) : Component(name) {
    m_position = Vector3d(0, 0, 0);
}

void Rigidbody::recalculateAll(float time) {

}

void Rigidbody::update() {

}

void Rigidbody::drawGui() {
    ImGui::Text("Rigidbody");
};

const Vector3d &Rigidbody::getPosition() const {
    return m_position;
}


