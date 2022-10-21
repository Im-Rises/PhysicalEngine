#include "Scene.h"

#include "GameObject.h"
#include "Components/Mesh/Mesh.h"
#include "Components/Mesh/Cuboid/MyCube.h"
#include "Components/Mesh/Cuboid/Cube.h"
#include "Components/Mesh/Cuboid/CuboidRectangle.h"
#include "Components/Mesh/Sphere/Sphere.h"

#include "glad/glad.h"
#include "Components/PhysicalComponent/Particle/Particle.h"
#include "Components/Collider/Collider.h"

Scene::Scene(int windowWidth, int windowHeight) {
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
//    gameObjects.push_back(new GameObject(Cube(1)));
//    gameObjects.push_back(new GameObject(Sphere(1, 20, 20)));
//    gameObjects.push_back(new GameObject(MyCube(1)));
    create();
}

void Scene::create() {
    // Create the framebuffer
    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    // Create the placeholder texture
    unsigned int textureColorbuffer;
    glGenTextures(1, &textureColorbuffer);
    glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, windowWidth, windowHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureColorbuffer, 0);

    // Create the placeholder render buffer
    unsigned int rbo;
    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, windowWidth, windowHeight);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER,
                              rbo);
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Scene::~Scene() {
    for (auto &gameObject: gameObjects) {
        delete gameObject;
    }
    destroy();
}

void Scene::destroy() {
    glDeleteFramebuffers(1, &fbo);
}

void Scene::update(float deltaTime) {
    // Update the game objects
    for (GameObject *gameObject: gameObjects) {
        gameObject->update(deltaTime);
    }

//    //Method 1
//    Particle *particle = dynamic_cast<Particle *>(gameObjects[0]->getComponentByName("Particle"));
//
////    // Method 2
////    Collider *particle = nullptr;
////    gameObjects[0]->getComponentByClass<Collider>(particle);
//
//    std::cout << particle->getSpeed() << std::endl;

    // Update the physic handler
//    physicHandler.updateAll(deltaTime);
//    physicHandler.update(deltaTime, gameObjects);
}

void Scene::draw(int display_w, int display_h) {
    // Draw the gameObjects
    for (GameObject *gameObject: gameObjects) {
        gameObject->draw(display_w, display_h, camera.getViewMatrix(), camera.getFov());
    }
    // Draw the axis
    if (showAxis)
        axis.draw(display_w, display_h, camera.getViewMatrix(), camera.getFov());
}

void Scene::updateViewport(int width, int height) {
    windowHeight = height;
    windowWidth = width;
}

void Scene::addGameObject(GameObject *gameObject) {
    gameObjects.push_back(gameObject);
}

//void Scene::translateCamera(Vector3d vector3D) {
//    camera.translate(vector3D);
//}
//
//void Scene::rotateCamera(Vector3d vector3D, float angle) {
//    camera.rotate(vector3D, angle);
//}

unsigned int Scene::getFrameBufferId() const {
    return fbo;
}

std::vector<GameObject *> &Scene::getGameObjects() {
    return gameObjects;
}

bool *Scene::getPtrWireFrameState() {
    if (wireFrame) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    return &wireFrame;
}

bool *Scene::getPtrShowAxis() {
    return &showAxis;
}

GameObject *Scene::getPtrGameObjectByIndex(int index) const {
    return gameObjects[index];
}

