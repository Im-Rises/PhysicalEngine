#include "PhysicHandler.h"
#include <iostream>
#include "Components/Rigidbody/Rigidbody.h"
#include "GameObject.h"

PhysicHandler::PhysicHandler() {

}

void PhysicHandler::updateAll(float time) {
    fixedDeltaTime += static_cast<float>(time);
    timeToAdjustFrameRate += static_cast<float>(time);
    if (timeToAdjustFrameRate > 1.0f / fixeFrameRate) {
        for (Rigidbody *integrable: m_integrableList) {
            integrable->recalculateAll(fixedDeltaTime);
            std::cout << "recalculateAll" << std::endl;
        }

        timeToAdjustFrameRate -= 1.0f / fixeFrameRate;
        if (timeToAdjustFrameRate > 1) {
            timeToAdjustFrameRate -= 1;
        }
        fixedDeltaTime = 0;
    }
}

void PhysicHandler::update(float time, GameObject *gameObject) {
    fixedDeltaTime += static_cast<float>(time);
    timeToAdjustFrameRate += static_cast<float>(time);
    if (timeToAdjustFrameRate > 1.0f / fixeFrameRate) {
        gameObject->->recalculateAll(fixedDeltaTime);
        timeToAdjustFrameRate -= 1.0f / fixeFrameRate;
        if (timeToAdjustFrameRate > 1) {
            timeToAdjustFrameRate -= 1;
        }
        fixedDeltaTime = 0;
    }

}

void PhysicHandler::addRigidbody(Rigidbody *rigidbody) {

}
