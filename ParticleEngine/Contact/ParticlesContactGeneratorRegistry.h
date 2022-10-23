#ifndef PARTICLE_CONTACT_GENERATOR_REGISTRY_H
#define PARTICLE_CONTACT_GENERATOR_REGISTRY_H

#include "ContactGenerator/ParticleContactGenerator.h"
#include <vector>

class ParticleContactGeneratorRegistry {

private:
    std::vector<ParticleContactGenerator *> m_particlesContactGenerators;
    ParticleContact *m_allContact;

public:

    explicit ParticleContactGeneratorRegistry(int maxSize);

    void addParticleGenerator(ParticleContactGenerator *particleContactGenerator);

    std::vector<ParticleContactGenerator *> GetParticlesContactGenerators() const;

    ParticleContact *generateAllContacts(unsigned int max_size);

    ~ParticleContactGeneratorRegistry();

};

#endif // !PARTICLE_CONTACT_GENERATOR_REGISTRY_H
