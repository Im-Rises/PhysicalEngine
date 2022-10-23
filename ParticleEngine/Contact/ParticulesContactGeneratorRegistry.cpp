#include "ParticulesContactGeneratorRegistry.h"

ParticuleContactGeneratorRegistry::ParticuleContactGeneratorRegistry(float maxSize) {
	m_allContact = new ParticuleContact[maxSize];
}

void ParticuleContactGeneratorRegistry::addParticuleGenerator(ParticuleContactGenerator* particuleContactGenerator) {
	m_particulesContactGenerators.push_back(particuleContactGenerator);
}

std::vector<ParticuleContactGenerator*> ParticuleContactGeneratorRegistry::GetParticulesContactGenerators() const {
	return m_particulesContactGenerators;
}

ParticuleContactGeneratorRegistry::~ParticuleContactGeneratorRegistry() {
	delete m_allContact;
}

ParticuleContact* ParticuleContactGeneratorRegistry::genereAllContacts(unsigned int max_size) {
	unsigned int current = 0;
	for (int i = 0; i < m_particulesContactGenerators.size() && current < max_size; i++) {
		current = m_particulesContactGenerators[i]->addContact(m_allContact, max_size, current);
	}
	return m_allContact;
}
