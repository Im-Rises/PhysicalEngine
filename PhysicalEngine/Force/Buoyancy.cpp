#include "Buoyancy.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "imgui/imgui.h"
#include "../Scene/Scene.h"

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

void Buoyancy::addForce(PhysicalComponent *physicalComponent) {
    float d = (physicalComponent->getPosition().gety() - m_waterHeight - m_maxDepth) / 2 * m_maxDepth;
    Vector3d F(0, 1, 0);
    if (d <= 0) {
        F * 0;
    } else if (d >= 1) {
        F * m_volume * m_liquidDensity;
    } else {
        F * d * m_volume * m_liquidDensity;
    }
    Vector3d initialForce = physicalComponent->getNetForce();
    physicalComponent->setNetForce(initialForce + F);
}

void Buoyancy::drawGui(Scene *scene) {
    if (ImGui::CollapsingHeader(BUOYANCY_FORCE)) {
        ImGui::Text("Max Depth: ");
        ImGui::SameLine();
        ImGui::InputFloat("##BuyoncyMaxDepth", &m_maxDepth);
        ImGui::Text("Volume: ");
        ImGui::SameLine();
        ImGui::InputFloat("##BuyoncyVolume", &m_volume);
        ImGui::Text("Water height: ");
        ImGui::SameLine();
        ImGui::InputFloat("##BuyoncyWaterHeight", &m_waterHeight);
        ImGui::Text("Liquid Density: ");
        ImGui::SameLine();
        ImGui::InputFloat("##BuyoncyLiquidDensity", &m_liquidDensity);

    }
}

std::string Buoyancy::getName() const {
    return FORCE_TYPE;
}
