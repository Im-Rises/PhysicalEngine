#include "PhysicHandler.h"
#include <iostream>
#include <iterator>
#include <chrono>
#include "Components/Rigidbody/Rigidbody.h"

PhysicHandler::PhysicHandler() {

}

void PhysicHandler::addIntegrable(Rigidbody *integrable) {
    m_integrableList.push_back(integrable);
}


void PhysicHandler::updateAll(float time) {
    m_fixedDeltaTime += static_cast<float>(time);
    m_timeToAdjustFrameRate += static_cast<float>(time);
    if (m_timeToAdjustFrameRate > 1 / m_fixeFrameRate) {
        for (Rigidbody *integrable: m_integrableList) {
            integrable->recalculateAll(m_fixedDeltaTime);
        }


        m_timeToAdjustFrameRate -= 1 / m_fixeFrameRate;
        if (m_timeToAdjustFrameRate > 1) {
            m_timeToAdjustFrameRate -= 1;
        }
        m_fixedDeltaTime = 0;
    }

}

void PhysicHandler::boucle() {
    //double deltaTime=0;
    //int numbTest = 0;
    //while (!m_StopPhysics) {
    //
    //	auto start = std::chrono::high_resolution_clock::now();
    //	if (deltaTime != 0) {
    //		UpdateAll(deltaTime);
    //	}
    //	using namespace std::chrono_literals;
    //	std::this_thread::sleep_for(2000ms);
    //	auto end = std::chrono::high_resolution_clock::now();


    //	deltaTime =std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    //	deltaTime *= 0.000000001;
    //	printf("time = %f \n", deltaTime);
    //
    //	if (numbTest >= 5) {
    //		m_StopPhysics = true;
    //	}
    //	numbTest += 1;
    //}
}
