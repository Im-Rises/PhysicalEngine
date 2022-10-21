#include "ForceGenerator.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "imgui/imgui.h"

void ForceGenerator::drawGui() {
    ImGui::Text("%s", getName().c_str());
}

std::string ForceGenerator::getName() const {
    return FORCE_TYPE;
}
