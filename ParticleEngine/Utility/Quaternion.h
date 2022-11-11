#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3d.h"

class Quaternion {

private:
	float m_value[4];
public:

	Quaternion();

	Quaternion(const Quaternion& quaternion);

	Quaternion(const Vector3d& vec);

	float norm();

	void normalize();

	Quaternion(float w,float x,float y , float z);

	Quaternion operator*=(const Quaternion& quaternion);

	Quaternion &operator*(const Quaternion &quaternion);

	Quaternion& operator*(float n);

	Quaternion& operator+(const Quaternion& quaternion);

	float operator[](int i) const;

	void set(int i);

	void RotateByVector(const Vector3d& vector);

	void UpdateByAngularSpeed(const Vector3d& vector, float time);

	~Quaternion();
};

#endif // !QUATERNION_H
