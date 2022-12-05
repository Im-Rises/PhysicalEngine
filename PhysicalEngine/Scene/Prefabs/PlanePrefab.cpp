#include "PlanePrefab.h"
#include "../Components/Mesh/Cuboid/CuboidRectangle.h"

PlanePrefab::PlanePrefab(Scene* scene, float width, float height) : GameObject(scene, new CuboidRectangle(width, 1, height)) {
    gameObjectName = "Plane";
    transform.positionY = -10;
}

PlanePrefab::~PlanePrefab() {
}
