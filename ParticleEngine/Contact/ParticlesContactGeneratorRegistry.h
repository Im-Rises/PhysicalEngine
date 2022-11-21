#ifndef PARTICLE_CONTACT_GENERATOR_REGISTRY_H
#define PARTICLE_CONTACT_GENERATOR_REGISTRY_H

#include "ContactGenerator/ParticleContactGenerator.h"
#include <vector>

class ParticleContactGeneratorRegistry {

private:
    std::vector<ParticleContactGenerator *> m_particlesContactGenerators;
    ParticleContact *m_allContact;
    unsigned int m_maxSize;
    unsigned int m_size = 0;

public:

    explicit ParticleContactGeneratorRegistry(unsigned int maxSize);

    void addParticleGenerator(ParticleContactGenerator *particleContactGenerator);

    std::vector<ParticleContactGenerator *> GetParticlesContactGenerators() const;

    unsigned int getSize();

    ParticleContact *generateAllContacts();

    ~ParticleContactGeneratorRegistry();

};

#endif // !PARTICLE_CONTACT_GENERATOR_REGISTRY_H
