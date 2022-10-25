#include "Game.h"

#include "Scene/GameObject.h"
#include "Scene/Components/Mesh/Sphere/Sphere.h"
#include "Scene/Scene.h"
#include "Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "Scene/Prefabs/ParticlePrefab.h"

Game::Game() {
    // Generate particles here
}

Game::~Game() {
}

void Game::start(Scene *s) {
    this->scene = s;

//    auto *particlePrefab = new ParticlePrefab(scene);
//    scene->addGameObject(particlePrefab);
//    particlePrefab->getComponentByClass(m_p);
//    auto *particlePrefabNew = new ParticlePrefab(scene);
//    scene->addGameObject(particlePrefabNew);

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 25; ++j) {
            auto *particlePrefabNew = new ParticlePrefab(scene);
            particlePrefabNew->transform.setPosition({(float) i * 2, (float) j * 2, 0});
            scene->addGameObject(particlePrefabNew);
        }
    }
}

void Game::goLeft() {
//    m_p->setSpeed(-m_speed, 0, 0);

    for (auto &gameObject: scene->getGameObjects()) {
        auto *particle = dynamic_cast<Particle *>(gameObject->getComponentByName(PARTICLE_COMPONENT));
        if (particle != nullptr) {
            AnchoredSpring *anchoredSpring;
            particle->getForceByClass(anchoredSpring);
            if (anchoredSpring != nullptr) {
                anchoredSpring->translate({-m_speed, 0, 0});
            }
        }
    }
}

void Game::goRight() {
//    m_p->setSpeed(m_speed, 0, 0);

    for (auto &gameObject: scene->getGameObjects()) {
        auto *particle = dynamic_cast<Particle *>(gameObject->getComponentByName(PARTICLE_COMPONENT));
        if (particle != nullptr) {
            AnchoredSpring *anchoredSpring;
            particle->getForceByClass(anchoredSpring);
            if (anchoredSpring != nullptr) {
                anchoredSpring->translate({m_speed, 0, 0});
            }
        }
    }
}

void Game::goUp() {
//    m_p->setSpeed(0, m_speed, 0);

    for (auto &gameObject: scene->getGameObjects()) {
        auto *particle = dynamic_cast<Particle *>(gameObject->getComponentByName(PARTICLE_COMPONENT));
        if (particle != nullptr) {
            AnchoredSpring *anchoredSpring;
            particle->getForceByClass(anchoredSpring);
            if (anchoredSpring != nullptr) {
                anchoredSpring->translate({0, m_speed, 0});
            }
        }
    }
}

void Game::goDown() {
//    m_p->setSpeed(0, -m_speed, 0);

    for (auto &gameObject: scene->getGameObjects()) {
        auto *particle = dynamic_cast<Particle *>(gameObject->getComponentByName(PARTICLE_COMPONENT));
        if (particle != nullptr) {
            AnchoredSpring *anchoredSpring;
            particle->getForceByClass(anchoredSpring);
            if (anchoredSpring != nullptr) {
                anchoredSpring->translate({0, -m_speed, 0});
            }
        }
    }
}

float *Game::getPtrSpeed() {
    return &m_speed;
}
