#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <string>
#include "../../../Vector3d/Vector3d.h"

class Transform {
private:
    std::string name = "Transform";

public:
    float positionX, positionY, positionZ;
    float rotationX, rotationY, rotationZ;
    float scaleX, scaleY, scaleZ;

public:
    Transform();

    ~Transform();

public:
    void drawGui();

    void setPosition(float x, float y, float z);

    void setPosition(Vector3d position);

    Vector3d getPosition();

};


#endif //TRANSFORM_H
