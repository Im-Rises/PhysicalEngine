#include "Rigidbody.h"

#include <utility>

#include "imgui/imgui.h"
#include "../../../GameObject.h"

Rigidbody::Rigidbody(GameObject *gameObject) : Component(gameObject) {
    m_mass = 0;
}

void Rigidbody::AddForce(const Vector3d & force)
{

}

void Rigidbody::AddForceAtPoint(const Vector3d & force, const Vector3d worldPoint)
{
}

void Rigidbody::AddForceAtBodyPoint(const Vector3d & force, const Vector3d & LocalPoint)
{
}

void Rigidbody::ClearAccumulator()
{
    m_forceAccum = Vector3d(0,0,0);
    m_torqueAccum = Vector3d(0,0,0);
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


