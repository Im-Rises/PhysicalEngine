#ifndef ANCHOREDSPRING_H
#define ANCHOREDSPRING_H

#include "ForceGenerator.h"

class AnchoredSpring : ForceGenerator {
private:
	Vector3d* m_anchor;
	float m_k;
	float m_restLength;

public:
	AnchoredSpring();
	~AnchoredSpring();
	AnchoredSpring(Vector3d* anchor, float k, float restLength);
	AnchoredSpring(const AnchoredSpring& aSpring);
	void addForce(Particule* particule, float duration);
};

#endif /* ANCHOREDSPRING_H */
