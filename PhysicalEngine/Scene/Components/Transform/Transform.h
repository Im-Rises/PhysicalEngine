#ifndef TRANSFORM_H
#define TRANSFORM_H


class Transform {
public:
    float positionX, positionY, positionZ;
    float rotationX, rotationY, rotationZ;
    float scaleX, scaleY, scaleZ;

public:
    Transform();

    ~Transform();


};


#endif //TRANSFORM_H
