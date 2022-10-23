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

ParticleContact *ParticleContactGeneratorRegistry::generateAllContacts(unsigned int maxSize) {
    unsigned int current = 0;
    for (int i = 0; i < m_particulesContactGenerators.size() && current < maxSize; i++) {
        current = m_particulesContactGenerators[i]->addContact(m_allContact, maxSize, current);
    }
    return m_allContact;
}
