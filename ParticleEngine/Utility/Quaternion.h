#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3d.h"

class Quaternion {

private:
	float m_value[4];
public:
	Quaternion();

	Quaternion normalize();

	Quaternion operator*(const Quaternion &quaternion);

	void RotateByVector(const Vector3d& vector);

	void UpdateByAngularSpeed(const Vector3d& vector, float time);

	~Quaternion();
};

#endif // !QUATERNION_H
