#include "Buoyancy.h"

void Buoyancy::updateForce(Particule* particule, float duration) {
	float d = (particule->getPosition().gety() - m_waterHeight - m_maxDepth) / 2 * m_maxDepth;
	float f;
	if (d <= 0) {
		f = 0;
	}
	else if (d >= 1) {
		f = m_volume*m_liquidDensity;
	}
	else {
		f = d * m_volume * m_liquidDensity;
	}
}
