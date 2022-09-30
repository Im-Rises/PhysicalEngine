#include "Scene.h"

#include "GameObject.h"
#include "Mesh/Mesh.h"
#include "Mesh/Cuboid/Cube.h"
#include "Mesh/Cuboid/CuboidRectangle.h"
#include "Mesh/Cuboid/MyCube.h"
#include "Mesh/Sphere/Sphere.h"
#include "Mesh/Cuboid/MyCubeUseIndice.h"

Scene::Scene(int windowWidth, int windowHeight) {
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
//    gameObjects.push_back(new GameObject(MyCube(1)));
//    gameObjects.push_back(new GameObject(Sphere(1, 20, 20)));
//    gameObjects.push_back(new GameObject(MyCube()));
//    gameObjects.push_back(new GameObject(MyCubeUseIndice()));
    create();
}

void Scene::create() {
    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    unsigned int textureColorbuffer;
    glGenTextures(1, &textureColorbuffer);
    glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, windowWidth, windowHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureColorbuffer, 0);

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

void Scene::updateViewport(int width, int height) {
    windowWidth = width;
    windowHeight = height;
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

unsigned int Scene::getFrameBufferId() {
    return fbo;
}



