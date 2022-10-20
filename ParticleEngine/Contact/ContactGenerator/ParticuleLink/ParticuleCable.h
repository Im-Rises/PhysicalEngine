#ifndef PARTICULECABLE_H
#define PARTICULECABLE_H

#include "ParticuleLink.h"

class ParticuleCable : public ParticuleLink {
	
	private:
	float m_maxLength;
	float m_restitution;

	public:

	void addContact(ParticuleContact* particuleContact, int size) const = 0;
};

#endif // !PARTICULECABLE
