#include "Rigidbody.h"

#include <utility>

#include "imgui/imgui.h"
#include "../../GameObject.h"

Rigidbody::Rigidbody(GameObject *gameObject, std::string name) : Component(std::move(name), gameObject) {
//    m_position = Vector3d(0, 0, 0);
    gameObject->transform.setPosition(0, 0, 0);
}

//Rigidbody::Rigidbody(std::string name) : Component(name) {
//    m_position = Vector3d(0, 0, 0);
//}

void Rigidbody::recalculateAll(float time) {

}

void Rigidbody::update() {

}

void Rigidbody::drawGui() {
    ImGui::Text("Rigidbody");
};

//const Vector3d &Rigidbody::getPosition() const {
//    return m_position;
//}


