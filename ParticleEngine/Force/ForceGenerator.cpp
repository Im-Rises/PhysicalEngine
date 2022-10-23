#include "ForceGenerator.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "imgui/imgui.h"
#include "Spring.h"
#include "AnchoredSpring.h"
#include "Drag.h"
#include "Buoyancy.h"
#include "../Scene/Scene.h"

const char *ForceGenerator::forcesNamesList[] = {DRAG_FORCE, ANCHORED_SPRING_FORCE,
                                                 BUOYANCY_FORCE, SPRING_FORCE};

void ForceGenerator::drawGui(Scene *scene) {
    ImGui::CollapsingHeader(getName().c_str());
}

std::string ForceGenerator::getName() const {
    return FORCE_TYPE;
}

ForceGenerator *ForceGenerator::createForceGenerator(const std::string &name) {
    int index = 0;

    for (auto &forceName: ForceGenerator::forcesNamesList) {
        if (forceName == name) {
            switch (index) {
                case 0:
                    return new Drag();
                case 1:
                    return new AnchoredSpring();
                case 2:
                    return new Buoyancy();
                case 3:
                    return new Spring();
                default: {
                    std::cerr << "Component::createComponent: Unknown component name" << std::endl;
                    return nullptr;
                }
            }
        }
        index++;
    }
    std::cerr << "Component::createComponent: Unknown component name" << std::endl;
    return nullptr;
}
