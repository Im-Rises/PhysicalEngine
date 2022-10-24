#ifndef PHYSICALCOMPONENT_H
#define PHYSICALCOMPONENT_H

#include "../Component.h"

class PhysicalComponent : public virtual Component {
protected:
    PhysicalComponent() = default;

private:
    static constexpr const char *COMPONENT_TYPE = "PhysicalComponent";

    void update(float time) override = 0;

    void drawGui() override = 0;

    std::string getName() const override = 0;


};


#endif //PHYSICALCOMPONENT_H
