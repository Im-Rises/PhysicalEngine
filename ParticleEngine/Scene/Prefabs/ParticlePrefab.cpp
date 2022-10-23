#include "ParticlePrefab.h"
#include "../Components/Mesh/Sphere/Sphere.h"
#include "../Components/PhysicalComponent/Particle/Particle.h"

ParticlePrefab::ParticlePrefab() : GameObject(new Sphere(1, 20, 20)) {
    gameObjectName = "Particle";
    auto *particle = new Particle(this);
    addComponentByClass(particle);
}

ParticlePrefab::~ParticlePrefab() {
}

