#ifndef CUBOID_RECTANGLE_H
#define CUBOID_RECTANGLE_H

#include "../Mesh.h"

class CuboidRectangle : public Mesh {
protected:
    float width;
    float height;
    float length;

public:
    CuboidRectangle(float width, float height, float length);

    Matrix33 getInertiaTensor(float mass) const override;
};

#endif // !CUBOID_RECTANGLE_H
