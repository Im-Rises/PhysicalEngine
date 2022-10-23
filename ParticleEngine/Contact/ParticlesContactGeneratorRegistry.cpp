#include "ParticlesContactGeneratorRegistry.h"

ParticleContactGeneratorRegistry::ParticleContactGeneratorRegistry(float maxSize) {
    m_allContact = new ParticleContact[maxSize];
}

void ParticleContactGeneratorRegistry::addParticleGenerator(ParticleContactGenerator *particleContactGenerator) {
    m_particulesContactGenerators.push_back(particleContactGenerator);
}

std::vector<ParticleContactGenerator *> ParticleContactGeneratorRegistry::GetParticlesContactGenerators() const {
    return m_particulesContactGenerators;
}

ParticleContactGeneratorRegistry::~ParticleContactGeneratorRegistry() {
    delete m_allContact;
}

ParticleContact *ParticleContactGeneratorRegistry::generateAllContacts(unsigned int max_size) {
    unsigned int current = 0;
    for (int i = 0; i < m_particulesContactGenerators.size() && current < max_size; i++) {
        current = m_particulesContactGenerators[i]->addContact(m_allContact, max_size, current);
    }
    return m_allContact;
}
