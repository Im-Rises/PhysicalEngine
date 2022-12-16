#include "RigidbodyPrefab.h"

#include "../Components/Mesh/Cuboid/Cube.h"
#include "../Components/Mesh/Cuboid/CuboidRectangle.h"
#include "../Components/Mesh/Cylinder/Cylinder.h"
#include "../Components/PhysicalComponent/Rigidbody/Rigidbody.h"

RigidbodyPrefab::RigidbodyPrefab(Scene* scene) : GameObject(scene, new CuboidRectangle(2, 1, 1)) {
    // RigidbodyPrefab::RigidbodyPrefab(Scene* scene) : GameObject(scene, new Cylinder(2, 4, 10)) {
    //  RigidbodyPrefab::RigidbodyPrefab(Scene *scene) : GameObject(scene, new Cube(1)) {
    gameObjectName = "Rigidbody";
    auto* rigidbody = new Rigidbody(this);
    addComponent(rigidbody);
}



RigidbodyPrefab::RigidbodyPrefab(Scene* scene, Mesh* mesh) : GameObject(scene, mesh) {
    gameObjectName = "Rigidbody";
    auto* rigidbody = new Rigidbody(this);
    addComponent(rigidbody);
}


RigidbodyPrefab::~RigidbodyPrefab() {
}
