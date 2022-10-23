#include "ParticuleCollide.h"


int ParticuleCollide::addContact(ParticuleContact* particuleContact, unsigned int limit, unsigned int current)  {
	for (int i = 0; i < m_colliders.size(); i++) {
		for (int j = i + 1; j < m_colliders.size(); j++) {
			if (current < limit) {
				Particule* particule0 = m_colliders[i].getParticule();
				Particule* particule1 = m_colliders[j].getParticule();
				float distance = particule0->getPosition().distance(particule1->getPosition());
				float sumRadius = m_colliders[i].getRadius() + m_colliders[j].getRadius();
				if (distance < sumRadius) {
					particuleContact[current].setPenetration(sumRadius - distance);
					particuleContact[current].setElasticity(elasticity);
					Vector3d normalParticule = particule0->getPosition() - particule1->getPosition();
					particuleContact[current].setContactNormal(normalParticule);
					current += 1;
				}
			}
			else {
				return current;
			}
				
		}
	}
	return current;
}

