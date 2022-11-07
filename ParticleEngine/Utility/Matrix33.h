#ifndef MATRIX33_H
#define MATRIX33_H

#include "Vector3d.h"
#include "Quaternion.h"

class Matrix33 {

private:
	float m_value[9];

public:
	Matrix33(float values[9]);

	Matrix33 operator*(const Matrix33& other);

	Vector3d operator*(const Vector3d& other);

	Matrix33 inverse();

	Matrix33 Transpose();

	void setOrientation(const Quaternion& quaternion);


};

#endif // !MATRIX33_H
