#ifndef CYLINDER_H
#define CYLINDER_H

#include "../Mesh.h"

#define MESHTYPE_CYLINDER "Cylinder"

class Cylinder : public Mesh {
private:
    static constexpr const char* MESH_TYPE = MESHTYPE_CYLINDER;

private:
    float radius;
    float height;

public:
    //    Cylinder(float radius, float height);
    Cylinder(float radius = 1, float height = 1, int rings = 16);

    void generatePointsNormales(float radius, float height, int rings);
    void generateTriangles(float radius, float height, int rings);

    Matrix33 getInertiaTensor(float mass) const override;

    const char* getMeshType() const;
};



#endif // CYLINDER_H
