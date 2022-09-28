#ifndef FORCEGENERATOR_H
#define FORCEGENERATOR_H

#include "../Particule/Particule.h"

class ForceGenerator {
	virtual void updateForce(Particule *particule, float duration)=0;
};

#endif /* FORCEGENERATOR_H */
