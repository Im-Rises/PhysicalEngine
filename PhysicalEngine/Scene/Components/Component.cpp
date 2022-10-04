#include "Component.h"

Component::Component(std::string name) {
    this->name = name;
}

Component::~Component() {

}

std::string Component::getName() const {
    return name;
}
