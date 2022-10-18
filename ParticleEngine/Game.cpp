#include "Game.h"

#include "Scene/GameObject.h"
#include "Scene/Components/Mesh/Sphere/Sphere.h"
#include "Scene/Scene.h"
#include "Scene/Components/Particule/Particle.h"
#include "Scene/Components/Rigidbody/Rigidbody.h"
#include "Scene/Components/Collider/Collider.h"

Game::Game() {
//    m_p = new Particle();
}

Game::~Game() {
//    delete m_p;
}

//void Game::setSpeed(float speed) {
//    m_speed = speed;
//}

void Game::start(Scene *scene) {
    GameObject *gameobject = new GameObject(Sphere(1, 20, 20));
    scene->addGameObject(gameobject);
    m_p = new Particle(gameobject, Vector3d(0, 0, 0), 1);
    gameobject->addComponent(m_p);
//    gameobject->addComponent(new Collider());
//    gameobject->addComponent(new Particle());

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

void Game::setSpeed(float speed) {
    m_speed = speed;
}

float *Game::getPtrSpeed() {
    return &m_speed;
}
