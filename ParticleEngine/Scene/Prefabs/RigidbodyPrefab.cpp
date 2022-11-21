#include "RigidbodyPrefab.h"

#include "../Components/Mesh/Cuboid/Cube.h"
#include "../Components/Mesh/Cuboid/CuboidRectangle.h"
#include "../Components/PhysicalComponent/Rigidbody/Rigidbody.h"

RigidbodyPrefab::RigidbodyPrefab(Scene* scene) : GameObject(scene, new CuboidRectangle(12, 4, 4)) {
    // RigidbodyPrefab::RigidbodyPrefab(Scene *scene) : GameObject(scene, new Cube(1)) {
    gameObjectName = "Rigidbody";
    auto* rigidbody = new Rigidbody(this);
    addComponent(rigidbody);
}

RigidbodyPrefab::~RigidbodyPrefab() {
}
