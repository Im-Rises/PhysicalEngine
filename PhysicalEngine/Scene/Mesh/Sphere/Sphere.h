#ifndef SPHERE_H
#define SPHERE_H

#include "../Mesh.h"

class Sphere : public Mesh {

private:
    void generatePointsNormales(float radius, int rings, int sectors);

    void generateTriangles(float radius, int rings, int sectors);

public:
    Sphere(float radius, int rings, int sectors);
};

#endif // !SPHERE_H
