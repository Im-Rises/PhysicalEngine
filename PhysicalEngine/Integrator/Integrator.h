#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "../Particule/Particule.h"
#include <iostream>
#include <iterator>
#include <list>
#include <chrono>
class Integrator {

private:
	std::list<Particule> m_integrableList;
	bool m_StopPhysics=false;

public:
	void AddIntegrable(Particule & integrable);
	void UpdateAll(float time);
	void boucle();




};


#endif // !INTEGRATOR_H
