#ifndef PARTICULE_CONTACT_RESOLVER_H
#define PARTICULE_CONTACT_RESOLVER_H

#include "ParticuleContact.h"

class ParticuleContactResolver {

	private:
	unsigned int m_maxIterations;

	public:

		ParticuleContactResolver(unsigned int maxIterations);


		void resolveContact(ParticuleContact* particulesContacts, int size, float time);
};

#endif // !PARTICULE_CONTACT_RESOLVER_H
