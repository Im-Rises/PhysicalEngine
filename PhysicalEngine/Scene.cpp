#include "Scene.h"

Scene::Scene() {
    gameObjects.push_back(new GameObject());
    gameObjects.push_back(new GameObject(std::vector<float>{
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    }));
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

void Scene::draw() {
    for (GameObject *gameObject: gameObjects) {
        gameObject->draw();
    }
}
