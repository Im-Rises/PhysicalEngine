#include "RigidbodyPrefab.h"

#include "../Components/PhysicalComponent/Rigidbody/Rigidbody.h"
#include "../Components/Mesh/Cuboid/Cube.h"
#include "../Components/Mesh/Cuboid/CuboidRectangle.h"

RigidbodyPrefab::RigidbodyPrefab(Scene *scene) : GameObject(scene, new CuboidRectangle(12, 8, 4)) {
//RigidbodyPrefab::RigidbodyPrefab(Scene *scene) : GameObject(scene, new Cube(1)) {
    gameObjectName = "Rigidbody";
    auto *rigidbody = new Rigidbody(this);
    addComponent(rigidbody);
}

RigidbodyPrefab::~RigidbodyPrefab() {

}
