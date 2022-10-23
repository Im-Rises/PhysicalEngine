#ifndef PARTICULE_CONTACT_GENERATOR_REGISTRY_H
#define PARTICULE_CONTACT_GENERATOR_REGISTRY_H

#include "ContactGenerator/ParticleContactGenerator.h"
#include <vector>

class ParticleContactGeneratorRegistry {

private:
    std::vector<ParticleContactGenerator *> m_particulesContactGenerators;
    ParticleContact *m_allContact;

public:

    explicit ParticleContactGeneratorRegistry(float maxSize);

    void addParticleGenerator(ParticleContactGenerator *particleContactGenerator);

    std::vector<ParticleContactGenerator *> GetParticlesContactGenerators() const;

    ParticleContact *generateAllContacts(unsigned int maxSize);

    ~ParticleContactGeneratorRegistry();

};

#endif // !PARTICULE_CONTACT_REGISTRY_H
