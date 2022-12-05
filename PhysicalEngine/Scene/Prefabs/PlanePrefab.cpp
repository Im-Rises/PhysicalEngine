#include "PlanePrefab.h"
#include "../Components/Mesh/Cuboid/CuboidRectangle.h"

PlanePrefab::PlanePrefab(Scene* scene, float width, float height) : GameObject(scene, new CuboidRectangle(width, 1, height)) {
    gameObjectName = "Plane";
    transform.positionY = -10;
    color = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);
}

PlanePrefab::~PlanePrefab() {
}
