#include "ParticlePrefab.h"
#include "../Components/Mesh/Sphere/Sphere.h"
#include "../Components/PhysicalComponent/Particle/Particle.h"
#include "../ParticleEngine/Force/AnchoredSpring.h"
#include "../Scene.h"

ParticlePrefab::ParticlePrefab(Scene *scene) : GameObject(scene, new Sphere(1, 20, 20)) {
    gameObjectName = "Particle";
    auto *particle = new Particle(this);
    particle->addForce(new AnchoredSpring({0, 0, 0}, 0.5f, 0.5f));
    addComponent(particle);
}

ParticlePrefab::~ParticlePrefab() {
}

