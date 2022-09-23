#include "Scene.h"

Scene::Scene() {
    gameObjects.push_back(new GameObject());
}

Scene::~Scene() {
    
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
