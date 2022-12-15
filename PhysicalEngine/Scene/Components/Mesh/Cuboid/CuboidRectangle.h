#ifndef CUBOID_RECTANGLE_H
#define CUBOID_RECTANGLE_H

#include "../Mesh.h"

#define MESHTYPE_CUBOID_RECTANGLE "CuboidRectangle"

class CuboidRectangle : public Mesh {
private:
    static constexpr const char* MESH_TYPE = MESHTYPE_CUBOID_RECTANGLE;

protected:
    float width;
    float height;
    float length;

public:
    CuboidRectangle(float width, float height, float length);

    Matrix33 getInertiaTensor(float mass) const override;
};

#endif // !CUBOID_RECTANGLE_H
