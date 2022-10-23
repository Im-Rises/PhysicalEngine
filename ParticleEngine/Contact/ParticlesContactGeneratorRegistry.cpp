#include "ParticlesContactGeneratorRegistry.h"

ParticleContactGeneratorRegistry::ParticleContactGeneratorRegistry(int maxSize) {
    m_allContact = new ParticleContact[maxSize];
}

void ParticleContactGeneratorRegistry::addParticleGenerator(ParticleContactGenerator *particleContactGenerator) {
    m_particlesContactGenerators.push_back(particleContactGenerator);
}

std::vector<ParticleContactGenerator *> ParticleContactGeneratorRegistry::GetParticlesContactGenerators() const {
    return m_particlesContactGenerators;
}

ParticleContactGeneratorRegistry::~ParticleContactGeneratorRegistry() {
    delete m_allContact;
}

ParticleContact *ParticleContactGeneratorRegistry::generateAllContacts(unsigned int max_size) {
    unsigned int current = 0;
    for (int i = 0; i < m_particlesContactGenerators.size() && current < max_size; i++) {
        current = m_particlesContactGenerators[i]->addContact(m_allContact, max_size, current);
    }
    return m_allContact;
}
