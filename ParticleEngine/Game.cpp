#include "Game.h"

#include "Scene/GameObject.h"
#include "Scene/Components/Mesh/Sphere/Sphere.h"
#include "Scene/Scene.h"
#include "Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "Scene/Components/Collider/Collider.h"

Game::Game() {
}

Game::~Game() {
}

void Game::start(Scene *scene) {
    GameObject *gameObject = new GameObject(Sphere(1, 20, 20));
    scene->addGameObject(gameObject);
    m_p = new Particle(gameObject, Vector3d(0, 0, 0), 1);
    gameObject->addComponent(m_p);
//    gameObject->addComponentByName(new Collider());
//    gameObject->addComponentByName(new Particle());

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

void Game::applyGravity() {
    m_G.addForce(m_p, 1);
}

void Game::applySpring() {
    m_S.addForce(m_p, 1);
}

float *Game::getPtrSpeed() {
    return &m_speed;
}
