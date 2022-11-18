#include "RigidbodyPrefab.h"

#include "../Components/PhysicalComponent/Rigidbody/Rigidbody.h"
#include "../Components/Mesh/Cuboid/Cube.h"

RigidbodyPrefab::RigidbodyPrefab(Scene *scene) : GameObject(scene, new Cube(4)) {
    gameObjectName = "Rigidbody";
    auto *rigidbody = new Rigidbody(this);
    addComponent(rigidbody);
}

RigidbodyPrefab::~RigidbodyPrefab() {

}
