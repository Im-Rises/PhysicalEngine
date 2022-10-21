#include "Game.h"

#include "Scene/GameObject.h"
#include "Scene/Components/Mesh/Sphere/Sphere.h"
#include "Scene/Scene.h"
#include "Scene/Components/PhysicalComponent/Particle/Particle.h"

Game::Game() {
    // Generate particles here
}

Game::~Game() {
}

void Game::start(Scene *scene) {
    auto *gameObject = new GameObject(Sphere(1, 20, 20));
    scene->addGameObject(gameObject);
    m_p = new Particle(gameObject, 1);
    gameObject->addComponent(m_p);
}

void Game::goLeft() {
    m_p->setSpeed(-m_speed, 0, 0);
}

void Game::goRight() {
    m_p->setSpeed(m_speed, 0, 0);
}

void Game::goUp() {
    m_p->setSpeed(0, m_speed, 0);
}

void Game::goDown() {
    m_p->setSpeed(0, -m_speed, 0);
}

float *Game::getPtrSpeed() {
    return &m_speed;
}
