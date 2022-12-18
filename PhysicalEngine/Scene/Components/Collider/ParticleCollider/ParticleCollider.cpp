#include "ParticleCollider.h"
#include "../../../GameObject.h"
#include "../../PhysicalComponent/Particle/Particle.h"
#include <imgui/imgui.h>

ParticleCollider::ParticleCollider(GameObject* gameObject, float radius) : Component(gameObject) {
    m_radius = radius;
    //    m_particle = nullptr;
    //    gameObject->getComponentByClass(m_particle);
}

float ParticleCollider::getRadius() const {
    return m_radius;
}

// Particle* ParticleCollider::getParticle() {
//     return m_particle;
// }

std::string ParticleCollider::getName() const {
    return COMPONENT_TYPE;
}

void ParticleCollider::update(float time) {
}

void ParticleCollider::drawGui() {
    ImGui::Text("Particle Collider");
    ImGui::DragFloat("Radius", &m_radius, 0.1f, 0.0f, 100.0f);
}
