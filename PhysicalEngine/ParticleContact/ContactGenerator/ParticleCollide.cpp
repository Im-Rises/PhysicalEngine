#include "ParticleCollide.h"

#include "../../Scene/GameObject.h"

ParticleCollide::ParticleCollide(float elast) {
    elasticity = elast;
}

void ParticleCollide::addCollider(ParticleCollider* particleCollider) {
    m_colliders.push_back(particleCollider);
}

int ParticleCollide::addContact(ParticleContact* particleContact, unsigned int limit, unsigned int current) {
    for (int i = 0; i < m_colliders.size(); i++)
    {
        for (int j = i + 1; j < m_colliders.size(); j++)
        {
            if (current < limit)
            {
                // Check if the
                if (m_colliders[i] == nullptr || m_colliders[j] == nullptr)
                    continue;

                // Get the two particles
                Particle* particle0 = nullptr;
                m_colliders[i]->getGameObject()->getComponentByClass(particle0);
                Particle* particle1 = nullptr;
                m_colliders[j]->getGameObject()->getComponentByClass(particle1);

                // Check if the particles have colliders if not, skip these particles
                //                Particle* particle0 = m_colliders[i]->getParticle();
                //                Particle* particle1 = m_colliders[j]->getParticle();
                if (particle0 == nullptr || particle1 == nullptr)
                    continue;

                // Check if the particles are colliding
                float distance = particle0->getPosition().distance(particle1->getPosition());
                float sumRadius = m_colliders[i]->getRadius() + m_colliders[j]->getRadius();
                if (distance < sumRadius)
                {
                    particleContact[current].SetParticles(particle0, particle1);
                    particleContact[current].setPenetration(sumRadius - distance);
                    particleContact[current].setElasticity(elasticity);
                    Vector3d normalParticle = particle0->getPosition() - particle1->getPosition();
                    particleContact[current].setContactNormal(normalParticle);
                    current += 1;
                }
            }
            else
            {
                return current;
            }
        }
    }
    return current;
}
void ParticleCollide::cleanColliders() {
    m_colliders.clear();
}
