#include "ParticlesContactGeneratorRegistry.h"

ParticleContactGeneratorRegistry::ParticleContactGeneratorRegistry(unsigned int maxSize) {
    m_allContact = new ParticleContact[maxSize];
    m_maxSize = maxSize;
}

void ParticleContactGeneratorRegistry::addParticleGenerator(ParticleContactGenerator* particleContactGenerator) {
    m_particlesContactGenerators.push_back(particleContactGenerator);
}

std::vector<ParticleContactGenerator*> ParticleContactGeneratorRegistry::GetParticlesContactGenerators() const {
    return m_particlesContactGenerators;
}

unsigned int ParticleContactGeneratorRegistry::getSize() {
    return m_size;
}

ParticleContactGeneratorRegistry::~ParticleContactGeneratorRegistry() {
    delete[] m_allContact;

    // for (auto& particleContactGenerator : m_particlesContactGenerators) {
    //     delete particleContactGenerator;
    // }
}

ParticleContact* ParticleContactGeneratorRegistry::generateAllContacts() {
    unsigned int current = 0;
    for (int i = 0; i < m_particlesContactGenerators.size() && current < m_maxSize; i++)
    {
        current = m_particlesContactGenerators[i]->addContact(m_allContact, m_maxSize, current);
    }
    m_size = current;
    return m_allContact;
}
