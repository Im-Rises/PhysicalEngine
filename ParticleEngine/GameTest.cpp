#include "GameTest.h"

#include "Scene/GameObject.h"
#include "Scene/Components/Mesh/Sphere/Sphere.h"
#include "Scene/Scene.h"
#include "Scene/Components/Particule/Particule.h"
#include "Scene/Components/Rigidbody/Rigidbody.h"
#include "Scene/Components/Collider/Collider.h"

GameTest::GameTest() {
	//    m_p = new Particule();
}

GameTest::~GameTest() {
	//    delete m_p;
}


void GameTest::start(Scene* scene) {
	GameObject* gameobject = new GameObject(Sphere(1, 20, 20));
	scene->addGameObject(gameobject);
	m_p = new Particule(gameobject, Vector3d(0, 0, 0), 1);
	gameobject->addComponent(m_p);
	//    gameobject->addComponent(new Collider());
	//    gameobject->addComponent(new Particule());
}




float* GameTest::getPtrSpeed() {
	return &m_speed;
}
