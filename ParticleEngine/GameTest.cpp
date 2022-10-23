#include "GameTest.h"

#include "Scene/GameObject.h"
#include "Scene/Components/Mesh/Sphere/Sphere.h"
#include "Scene/Scene.h"
#include "Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "Scene/Prefabs/ParticlePrefab.h"

GameTest::GameTest() {
	// Generate particles here
}

GameTest::~GameTest() {
}

void GameTest::start(Scene* scene) {
	auto* particlePrefab = new ParticlePrefab();
	scene->addGameObject(particlePrefab);
	particlePrefab->getComponentByClass(m_p);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; ++j) {
			auto* particlePrefabNew = new ParticlePrefab();
			particlePrefabNew->transform.setPosition({ (float)i * 2, (float)j * 2, 0 });
			scene->addGameObject(particlePrefabNew);
		}
	}
}

void GameTest::goLeft() {
	m_p->setSpeed(-m_speed, 0, 0);
}

void GameTest::goRight() {
	m_p->setSpeed(m_speed, 0, 0);
}

void GameTest::goUp() {
	m_p->setSpeed(0, m_speed, 0);
}

void GameTest::goDown() {
	m_p->setSpeed(0, -m_speed, 0);
}

float* GameTest::getPtrSpeed() {
	return &m_speed;
}
