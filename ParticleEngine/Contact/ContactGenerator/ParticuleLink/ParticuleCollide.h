#ifndef PARTICULECOLLIDE_H
#define PARTICULECOLLIDE_H

#include "../ParticuleContactGenerator.h"

#include "../../ParticuleCollider/ParticuleCollider.h"

#include <vector>
class ParticuleCollide : public ParticuleContactGenerator {

	private:

	std::vector<ParticuleCollider> m_colliders;
	
	float elasticity;

	public:

		void addCollider(ParticuleCollider particuleCollider);

		int addContact(ParticuleContact* particuleContact, unsigned int limit, unsigned int current) ;


};

#endif // !PARTICULECOLLIDE_H
