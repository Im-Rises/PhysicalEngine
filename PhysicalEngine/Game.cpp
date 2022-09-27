#include "Game.h"

#include "Scene/GameObject.h"
#include "Scene/Mesh/Sphere/Sphere.h"
#include "Scene/Scene.h"
#include "Scene/Components/Particule/Particule/Particule.h"

Game::Game() {
    m_p = new Particule();
}

Game::~Game() {
    delete m_p;
}

void Game::setSpeed(float speed) {
    m_speed = speed;
}

void Game::start(Scene *scene) {
    GameObject *gameobject = new GameObject(Sphere(1, 20, 20));
    scene->addGameObject(gameobject);
    gameobject->AddRigidbody(m_p);
    scene->addPhysicalComponent();
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
