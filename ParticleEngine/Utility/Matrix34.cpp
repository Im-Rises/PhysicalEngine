#include "Matrix34.h"

Matrix34::Matrix34()
{
	for (int i = 0; i < 12; i++) {
		m_value[i] = 0;
	}
}

Matrix34::Matrix34(float values[12])
{
	for (int i = 0; i < 12; i++) {
		m_value[i] = values[i];
	}
}

Matrix34 Matrix34::operator*(const Matrix34& other) const
{
	Matrix44 tempThis = transformationAffineMatrix();
	Matrix44 tempOther = other.transformationAffineMatrix();
	Matrix34 res = transformationAffineMatrixToMatrix34(tempThis * tempOther);
	return res;
}

Matrix34::~Matrix34()
{
	delete [] m_value;
}

Matrix34& Matrix34::transformationAffineMatrixToMatrix34(Matrix44& const mat44) const
{
	Matrix34 res;
	for (int k = 0; k < 12; k++) {
		res.m_value[k] = mat44[k];
	}
	return res;
}

Matrix44& Matrix34::transformationAffineMatrix() const
{
	float values[16];
	for (int k = 0; k < 12; k++) {
		values[k] = m_value[k];
	}
	values[12] = 0;
	values[13] = 0;
	values[14] = 0;
	values[15] = 1;
	return Matrix44(values);
}
