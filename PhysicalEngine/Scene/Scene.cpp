#include "Scene.h"

#include "Components/Mesh/Cuboid/Cube.h"
#include "Components/Mesh/Cuboid/CuboidRectangle.h"
#include "Components/Mesh/Mesh.h"
#include "Components/Mesh/Sphere/Sphere.h"
#include "Components/PhysicalComponent/Particle/Particle.h"
#include "GameObject.h"
#include "glad/glad.h"

Scene::Scene(int windowWidth, int windowHeight) : particleCollide(1), octree(RigidbodyContactGeneratorRegistry()) {
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    //    gameObjects.push_back(new GameObject(Cube(1)));
    //    gameObjects.push_back(new GameObject(Sphere(1, 20, 20)));
    //    gameObjects.push_back(new GameObject(MyCube(1)));
    particleContactGeneratorRegistry.addParticleGenerator(&particleCollide);

    // TODO REGLER LES PARAMETRES DE L'OCTREE
    //  Create Octree
    octree.root = octree.BuildOctree(Vector3d(0, 0, 0), 20, 4);
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
    camera.update(deltaTime);

    //    physicalUpdateTimer += deltaTime;

    // Update the game objects (particles, ...)
    for (GameObject *gameObject: gameObjects) {
        gameObject->update(deltaTime);
    }

    //    if (physicalUpdateTimer >= 1.0f / PHYSIC_UPDATE_PER_SECOND)
    //    {
    //    physicalUpdateTimer = 0;


    // Move gameObjects
    for (GameObject *gameObject: gameObjects) {
        physicHandler.update(gameObject, deltaTime);
    }

    // Detect particles collision
    collectParticleColliders();
    ParticleContact *particleContacts = particleContactGeneratorRegistry.generateAllContacts();

    // Resolve collisions
    ParticleContact test = particleContacts[0];
    particleContactResolver.resolveContact(particleContacts, particleContactGeneratorRegistry.getSize(), deltaTime);
    cleanParticleColliders();

    // Clean octree
    octree.CleanOctree(octree.root);
    // Insert all objects
    for (GameObject *gameObject: gameObjects) {
        RigidbodyPrimitiveCollider *collider = nullptr;
        gameObject->getComponentByClass(collider);
        if (collider != nullptr) {
            Object *obj = new Object{collider->getCenter(), collider->getRadius(), NULL, collider};
            octree.InsertObject(octree.root, obj);
        }
    }
    // Test collisions
    octree.TestAllCollisions(octree.root);
}

void Scene::draw(int display_w, int display_h) {
    // Draw the gameObjects
    for (GameObject *gameObject: gameObjects) {
        gameObject->draw(display_w, display_h, camera.getViewMatrix(), camera.getFov());
    }
//    // Draw the axis
//    if (showAxis)
//        axis.draw(display_w, display_h, camera.getViewMatrix(), camera.getFov());
}

void Scene::updateViewport(int width, int height) {
    windowHeight = height;
    windowWidth = width;
}

void Scene::addGameObject(GameObject *gameObject) {
    gameObjects.push_back(gameObject);
}

// void Scene::translateCamera(const Vector3d& vector3D) {
//     //    camera.translate(vector3D);
// }

// void Scene::rotateCamera(Vector3d vector3D, float angle) {
//     camera.rotate(vector3D, angle);
// }

// void Scene::setCameraPosition(const Vector3d& position) {
//     //    camera.setPosition(position);
// }

ParticleContactGeneratorRegistry Scene::getParticleContactGeneratorRegistry() {
    return particleContactGeneratorRegistry;
}

unsigned int Scene::getFrameBufferId() const {
    return fbo;
}

// void Scene::addParticleCollider(ParticleCollider* particleCollider) {
//     particleCollide.addCollider(particleCollider);
// }

std::vector<GameObject *> &Scene::getGameObjects() {
    return gameObjects;
}

#ifndef __EMSCRIPTEN__

bool *Scene::getPtrWireFrameState() {
    if (wireFrame) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    return &wireFrame;
}

#endif

//bool *Scene::getPtrShowAxis() {
//    return &showAxis;
//}

GameObject *Scene::getPtrGameObjectByIndex(int index) const {
    return gameObjects[index];
}

Camera *Scene::getCameraPtr() {
    return &camera;
}

void Scene::deleteGameObject(GameObject *gameObject) {
    for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
        if (*it == gameObject) {
            gameObjects.erase(it);
            break;
        }
    }
}

GameObject *Scene::createGameObject(std::string name) {
    for (auto &meshName: Mesh::meshNamesList) {
        if (meshName == name) {
            GameObject *gameObject = new GameObject(this, Mesh::createMesh(name.c_str()));
            gameObjects.emplace_back(gameObject);
            return gameObject;
        }
    }
}

void Scene::cleanParticleColliders() {
    particleCollide.cleanColliders();
}

void Scene::collectParticleColliders() {
    for (GameObject *gameObject: gameObjects) {
        ParticleCollider *particleCollider = nullptr;
        gameObject->getComponentByClass(particleCollider);
        if (particleCollider != nullptr) {
            particleCollide.addCollider(particleCollider);
        }
    }
}
