#include "ParticlePrefab.h"
#include "../Components/Mesh/Sphere/Sphere.h"
#include "../Components/PhysicalComponent/Particle/Particle.h"
#include "../../Force/Forces/AnchoredSpring.h"
#include "../Scene.h"
#include "../../Contact/ParticleCollider/ParticleCollider.h"


ParticlePrefab::ParticlePrefab(Scene *scene) : GameObject(scene, new Sphere(1, 20, 20)) {
    gameObjectName = "Particle";
    auto *particle = new Particle(this);
    particle->addForce(new AnchoredSpring({0, 0, 0}, 0.5f, 0.5f));
    addComponent(particle);
    ParticleCollider particleCollider(particle, 1);
    scene->addParticleCollider(particleCollider);
}

ParticlePrefab::~ParticlePrefab() {
}

