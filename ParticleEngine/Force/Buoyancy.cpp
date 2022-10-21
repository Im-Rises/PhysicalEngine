#include "Buoyancy.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "imgui/imgui.h"

Buoyancy::Buoyancy() {
    m_maxDepth = 0;
    m_volume = 0;
    m_waterHeight = 0;
    m_liquidDensity = 0;
}

Buoyancy::Buoyancy(float maxDepth, float volume, float waterHeight, float liquidDensity) {
    m_maxDepth = maxDepth;
    m_volume = volume;
    m_waterHeight = waterHeight;
    m_liquidDensity = liquidDensity;
}

Buoyancy::Buoyancy(const Buoyancy &buoyancy) {
    m_maxDepth = buoyancy.m_maxDepth;
    m_volume = buoyancy.m_volume;
    m_waterHeight = buoyancy.m_waterHeight;
    m_liquidDensity = buoyancy.m_liquidDensity;
}

void Buoyancy::addForce(Particle *particle, float duration) {
    float d = (particle->getPosition().gety() - m_waterHeight - m_maxDepth) / 2 * m_maxDepth;
    Vector3d F(0, 1, 0);
    if (d <= 0) {
        F * 0;
    } else if (d >= 1) {
        F * m_volume * m_liquidDensity;
    } else {
        F * d * m_volume * m_liquidDensity;
    }
    Vector3d initialForce = particle->getNetForce();
    particle->setNetForce(initialForce + F);
}

void Buoyancy::drawGui() {
    if (ImGui::CollapsingHeader(BUOYANCY_FORCE)) {

    }
}

std::string Buoyancy::getName() const {
    return FORCE_TYPE;
}
