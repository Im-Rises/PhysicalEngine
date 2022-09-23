#ifndef CUBOID_RECTANGLE_H
#define CUBOID_RECTANGLE_H

#include "../Mesh.h"

class CuboidRectangle : Mesh {

public:

    CuboidRectangle(double longueur, double hauteur, double profondeur, const Vector3D &position = Vector3D(0, 0, 0));

};

#endif // !CUBOID_RECTANGLE_H
