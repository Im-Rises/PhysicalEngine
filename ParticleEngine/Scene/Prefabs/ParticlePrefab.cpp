#include "ParticlePrefab.h"
#include "../Components/Mesh/Sphere/Sphere.h"
#include "../Components/PhysicalComponent/Particle/Particle.h"
#include "../Scene.h"
#include "../../Contact/ParticleCollider/ParticleCollider.h"


ParticlePrefab::ParticlePrefab(Scene *scene) : GameObject(scene, new Sphere(1, 20, 20)) {
    gameObjectName = "Particle";
    auto *particle = new Particle(this);
    addComponentByClass(particle);
	ParticleCollider particleCollider(particle,1);
	scene->addParticleCollider(particleCollider);
	int i = 0;

    

}

ParticlePrefab::~ParticlePrefab() {
}

