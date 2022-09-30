#ifndef TRANSFORM_H
#define TRANSFORM_H


class Transform {
private:
    float x, y, z;
    float rotationX, rotationY, rotationZ;
    float scaleX, scaleY, scaleZ;

public:
    Transform();

    ~Transform();
};


#endif //TRANSFORM_H
