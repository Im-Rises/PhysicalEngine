#include "Scene.h"

Scene::Scene() {
    gameObjects.push_back(new GameObject());
//    gameObjects.push_back(new GameObject(std::vector<float>{
//            -0.5f, -0.5f, 0.0f,
//            0.5f, -0.5f, 0.0f,
//            0.0f, 0.5f, 0.0f
//    }));
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
