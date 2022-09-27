#include "Scene.h"

#include "GameObject.h"
#include "Mesh/Mesh.h"
#include "Mesh/Cuboid/Cube.h"
#include "Mesh/Cuboid/CuboidRectangle.h"
#include "Mesh/Cuboid/MyCube.h"
#include "Mesh/Sphere/Sphere.h"
#include "Mesh/Cuboid/MyCubeUseIndice.h"

Scene::Scene() {
//    gameObjects.push_back(new GameObject(MyCube(1)));
//    gameObjects.push_back(new GameObject(Sphere(1, 20, 20)));
//    gameObjects.push_back(new GameObject(MyCube()));
//    gameObjects.push_back(new GameObject(MyCubeUseIndice()));
}

Scene::~Scene() {
    for (auto &gameObject: gameObjects) {
        delete gameObject;
    }
}

void Scene::update() {
    for (GameObject *gameObject: gameObjects) {
        gameObject->update();
    }
}

void Scene::updatePhysics(float time) {
    m_integrator.UpdateAll(time);
}

void Scene::addPhysicalComponent() {
    for (GameObject *gameObject: gameObjects) {
        if (gameObject->hasRigidbody()) {
            m_integrator.AddIntegrable(gameObject->getRigidBody());
        }
    }
}

void Scene::draw(int display_w, int display_h) {
    for (GameObject *gameObject: gameObjects) {
        gameObject->draw(display_w, display_h, camera.getViewMatrix(), camera.getFov());
    }
}

void Scene::translateCamera(Vector3d vector3D) {
    camera.translate(vector3D);
}

void Scene::rotateCamera(Vector3d vector3D, float angle) {
    camera.rotate(vector3D, angle);
}

size_t Scene::getNbGameObjects() {
    return gameObjects.size();
}

std::string Scene::getGameObjectName(int index) {
    return gameObjects[index]->getName();
}

void Scene::addGameObject(GameObject *gameObject) {
    gameObjects.push_back(gameObject);
}

bool *Scene::getWireFrameStatePtr() {
    if (wireFrame) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    return &wireFrame;
}

