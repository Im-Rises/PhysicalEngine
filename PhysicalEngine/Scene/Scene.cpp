#include "Scene.h"

#include "Mesh/Mesh.h"
#include "Mesh/Cuboid/Cube.h"
#include "Mesh/Cuboid/CuboidRectangle.h"

Scene::Scene() {
//    gameObjects.push_back(new GameObject(CuboidRectangle(1.0f, 1.0f, 1.0f)));
    gameObjects.push_back(new GameObject(Cube(1.0f)));
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

void Scene::draw(int display_w, int display_h) {
    for (GameObject *gameObject: gameObjects) {
        gameObject->draw(display_w, display_h, camera.getViewMatrix());
    }
}

void Scene::translateCamera() {
    camera.translate();
}

size_t Scene::getNbGameObjects() {
    return gameObjects.size();
}

std::string Scene::getGameObjectName(int index) {
    return gameObjects[index]->getName();
}
