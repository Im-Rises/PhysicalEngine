#include "Integrator.h"

void Integrator::AddIntegrable(Particule& integrable) {
	m_integrableList.push_back(integrable);
}

void Integrator::UpdateAll(float time) {

	for (Particule integrable : m_integrableList) {
		integrable.recalculateAll(time);
	}
}

void Integrator::boucle() {
	float deltaTime=0;
	while (!m_StopPhysics) {
		
		auto start = std::chrono::high_resolution_clock::now();


		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::milli> float_ms = end - start;
		

	}
}
