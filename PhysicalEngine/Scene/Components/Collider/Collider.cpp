#include "Collider.h"

#include "imgui/imgui.h"

Collider::Collider(GameObject *gameObject) : Component("Collider", gameObject) {
    mass = 0;
    friction = 0;
    restitution = 0;
}

Collider::Collider(GameObject *gameObject, float mass, float friction, float restitution) : Component("Collider",
                                                                                                      gameObject) {
    mass = mass;
    friction = friction;
    restitution = restitution;
}

void Collider::update() {

}

float Collider::getMass() const {
    return mass;
}

float Collider::getFriction() const {
    return friction;
}

float Collider::getRestitution() const {
    return restitution;
}

void Collider::setMass(float mass) {
    mass = mass;
}

void Collider::setFriction(float friction) {
    friction = friction;
}

void Collider::setRestitution(float restitution) {
    restitution = restitution;
}

void Collider::drawGui() {
    ImGui::Text("Mass");
    if (ImGui::BeginTable("Position", 3)) {

        ImGui::EndTable();
    }
}
