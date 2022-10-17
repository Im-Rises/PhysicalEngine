#include "Component.h"

Component::Component(std::string name, GameObject *gameObject) {
    this->name = name;
    this->gameObject = gameObject;
}

Component::~Component() {

}

std::string Component::getName() const {
    return name;
}
