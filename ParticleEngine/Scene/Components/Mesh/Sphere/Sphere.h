#ifndef SPHERE_H
#define SPHERE_H

#include "../Mesh.h"

class Sphere : public Mesh {
private:
    float radius;

private:
    void generatePointsNormales(float radius, int rings, int sectors);

    void generateTriangles(float radius, int rings, int sectors);

public:
    Sphere(float radius, int rings, int sectors);

    Matrix33 getInertiaTensor(float mass) const override;
};

#endif // !SPHERE_H
