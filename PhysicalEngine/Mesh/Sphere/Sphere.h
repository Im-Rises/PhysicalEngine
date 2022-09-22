#ifndef SPHERE_H
#define SPHERE_H

#include "../Mesh.h"
class Sphere : public Mesh {

private:
	void generatePointsNormales(double radius, int rings, int sectors);
	void generateTriangles(double radius, int rings, int sectors);

public:
	Sphere(double radius, int rings, int sectors, Vector3D centre = Vector3D(0, 0, 0));
};

#endif // !SPHERE_H
