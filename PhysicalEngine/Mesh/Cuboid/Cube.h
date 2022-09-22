#ifndef CUBE_H
#define CUBE_H

#include "CuboidRectangle.h"

class Cube : public CuboidRectangle {

public:
	Cube(double longueur,Vector3D position=Vector3D(0,0,0));
};

#endif // !CUBE_H
