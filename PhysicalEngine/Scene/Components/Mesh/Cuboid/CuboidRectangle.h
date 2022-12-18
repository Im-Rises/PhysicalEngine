#ifndef CUBOID_RECTANGLE_H
#define CUBOID_RECTANGLE_H

#include "../Mesh.h"

#define MESHTYPE_CUBOID_RECTANGLE "Cuboid_Rectangle"

class CuboidRectangle : public Mesh {
private:
    static constexpr const char* MESH_TYPE = MESHTYPE_CUBOID_RECTANGLE;

protected:
    float width;
    float height;
    float length;

public:
    CuboidRectangle(float width = 1, float height = 1, float length = 1);

    Matrix33 getInertiaTensor(float mass) const override;

    const char* getMeshType() const;
};

#endif // !CUBOID_RECTANGLE_H
