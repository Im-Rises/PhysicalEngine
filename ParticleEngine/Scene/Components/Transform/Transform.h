#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <string>
#include "../../../Vector3d/Vector3d.h"
#include "../Component.h"
#include "../DefaultComponent.h"

class Transform : private DefaultComponent {
private:
    static constexpr const char *COMPONENT_TYPE = "Transform";

public:
    float positionX, positionY, positionZ;
    float rotationX, rotationY, rotationZ;
    float scaleX, scaleY, scaleZ;

public:
    Transform();

    ~Transform();

public:
    void drawGui() override;

    void setPosition(float x, float y, float z);

    void setPosition(Vector3d position);

    Vector3d getPosition();

    std::string getName() const override;
};


#endif //TRANSFORM_H
