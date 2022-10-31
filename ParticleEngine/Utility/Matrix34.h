#ifndef MATRIX34_H
#define MATRIX34_H


#include "Vector3d.h"
#include "Quaternion.h"

class Matrix34 {

private:
	float m_value[12];

public:


	Matrix34 operator*(const Matrix34& other) const;

	Vector3d operator*(const Vector3d& other) const;

	Matrix33 inverse();

	Matrix33 Transpose();

	void setOrientationAndPosition(const Quaternion& quaternion,const Vector3d & vec);

	Vector3d TransformPosition(const Vector3d vec);

	Vector3d TransformDirection(const Vector3d vec);



};


#endif // !1
