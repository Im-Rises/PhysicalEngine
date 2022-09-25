#include "Integrator.h"
#include <chrono>
#include <thread>
Integrator::Integrator() {

}

void Integrator::AddIntegrable(Particule& integrable) {
	m_integrableList.push_back(integrable);
}

void Integrator::UpdateAll(double time) {

	for (Particule integrable : m_integrableList) {
		integrable.recalculateAll(time);
	}
}

void Integrator::boucle() {
	double deltaTime=0;
	int numbTest = 0;
	while (!m_StopPhysics) {
		
		auto start = std::chrono::high_resolution_clock::now();
		if (deltaTime != 0) {
			UpdateAll(deltaTime);
		}
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(2000ms);
		auto end = std::chrono::high_resolution_clock::now();


		deltaTime =std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		deltaTime *= 0.000000001;
		printf("time = %f \n", deltaTime);
		
		if (numbTest >= 5) {
			m_StopPhysics = true;
		}
		numbTest += 1;
	}
}
