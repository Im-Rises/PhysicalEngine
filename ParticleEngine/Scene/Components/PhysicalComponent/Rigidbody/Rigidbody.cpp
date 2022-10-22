#include "Rigidbody.h"

#include <utility>

#include "imgui/imgui.h"
#include "../../../GameObject.h"

Rigidbody::Rigidbody(GameObject *gameObject) : Component(gameObject) {
    m_mass = 0;
}

void Rigidbody::update(float time) {

}

void Rigidbody::drawGui() {
    ImGui::Text("Rigidbody");
}

std::string Rigidbody::getName() const {
    return COMPONENT_TYPE;
}

//const Vector3d &Rigidbody::getPosition() const {
//    return m_position;
//}


