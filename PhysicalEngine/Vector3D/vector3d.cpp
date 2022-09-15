#include "vector3d.h"

Vector3D::Vector3D() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(double xcoord, double ycoord, double zcoord) {
	x = xcoord;
	y = ycoord;
	z = zcoord;
}

Vector3D::Vector3D(const Vector3D& vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

Vector3D::~Vector3D() {
}
