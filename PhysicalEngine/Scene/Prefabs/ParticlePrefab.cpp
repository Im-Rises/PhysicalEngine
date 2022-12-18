#include "ParticlePrefab.h"
#include "../Components/Collider/ParticleCollider/ParticleCollider.h"
#include "../Components/Mesh/Sphere/Sphere.h"
#include "../Components/PhysicalComponent/Particle/Particle.h"
#include "../PhysicalEngine/Force/AnchoredSpring.h"
#include "../Scene.h"


ParticlePrefab::ParticlePrefab(Scene* scene) : GameObject(scene, new Sphere(1, 20, 20)) {
    gameObjectName = "Particle";
    auto* particle = new Particle(this);
    particle->addForceToList(new AnchoredSpring({ 0, 0, 0 }, 0.5f, 0.5f));
    addComponent(particle);
    //    scene->addParticleCollider(new ParticleCollider(this, 1));
}

ParticlePrefab::~ParticlePrefab() {
}
