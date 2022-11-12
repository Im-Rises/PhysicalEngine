#include "RigidbodyForceGenerator.h"
#include "../Scene/Components/PhysicalComponent/Rigidbody/Rigidbody.h"
#include "../Scene/GameObject.h"

RigidbodyForceGenerator::~RigidbodyForceGenerator() {

}

RigidbodyForceGenerator::RigidbodyForceGenerator(GameObject *gameObject) {
    parentGameObject = gameObject;
}
