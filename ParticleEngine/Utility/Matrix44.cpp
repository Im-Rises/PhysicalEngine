#include "Matrix44.h"

Matrix44::Matrix44(float values[16])
{
	for (int i= 0; i< 16; i++) {
		m_value[i] = values[i];
	}
}

float Matrix44::operator()(int i, int j) const
{
	return m_value[4*i+j];
}

float Matrix44::operator[](int i) const
{
	return m_value[i];
}

Matrix44& Matrix44::operator*(Matrix44& const matrix)
{
	Matrix44 res = Matrix44();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				res.m_value[4 * i + j] = m_value[4 * i + k] * matrix.m_value[4 * k + j];
			}
		}
	}
	return res;
}

Matrix44::~Matrix44()
{
	delete[] m_value;
}