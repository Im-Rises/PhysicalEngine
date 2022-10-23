#ifndef PARTICULE_CONTACT_GENERATOR_REGISTRY_H
#define PARTICULE_CONTACT_GENERATOR_REGISTRY_H

#include "ContactGenerator/ParticuleContactGenerator.h"
#include <Vector>

class ParticuleContactGeneratorRegistry {

	private:
	std::vector<ParticuleContactGenerator*> m_particulesContactGenerators;
	ParticuleContact* m_allContact;

	public:

	ParticuleContactGeneratorRegistry(float maxSize);

	void addParticuleGenerator(ParticuleContactGenerator* particuleContactGenerator);

	std::vector<ParticuleContactGenerator*> GetParticulesContactGenerators() const;

	ParticuleContact* genereAllContacts(unsigned int max_size);

	~ParticuleContactGeneratorRegistry();

};
#endif // !PARTICULE_CONTACT_REGISTRY_H
