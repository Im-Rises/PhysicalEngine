#include "vector3d.h"


Vector3D::Vector3D() {
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

Vector3D::Vector3D(double xcoord, double ycoord, double zcoord) {
	m_x = xcoord;
	m_y = ycoord;
	m_z = zcoord;
}

Vector3D::Vector3D(const Vector3D& vec) {
	m_x = vec.m_x;
	m_y = vec.m_y;
	m_z = vec.m_z;
}

Vector3D::~Vector3D() {
}

void Vector3D::setx(double xcoord) {
	m_x = xcoord;
}

void Vector3D::sety(double ycoord) {
	m_y = ycoord;
}

void Vector3D::setz(double zcoord) {
	m_z = zcoord;
}

double Vector3D::getx() const {
    return m_x;
}

double Vector3D::gety() const {
    return m_y;
}

double Vector3D::getz() const {
    return m_z;
}

Vector3D Vector3D::operator+(const Vector3D& vec) {
	return Vector3D(m_x + vec.m_x, m_y + vec.m_y, m_z + vec.m_z);
}

Vector3D& Vector3D::operator+=(const Vector3D& vec) {
	m_x += vec.m_x;
	m_y += vec.m_y;
	m_z += vec.m_z;
	return *this;
}

Vector3D Vector3D::operator-(const Vector3D& vec) {
	return Vector3D(m_x - vec.m_x, m_y - vec.m_y, m_z - vec.m_z);
}

Vector3D& Vector3D::operator-=(const Vector3D& vec) {
	m_x -= vec.m_x;
	m_y -= vec.m_y;
	m_z -= vec.m_z;
	return *this;
}

Vector3D Vector3D::operator*(double s) {
	return Vector3D(m_x * s, m_y * s, m_z * s);
}

Vector3D& Vector3D::operator*=(double s) {
	m_x = m_x * s;
	m_y = m_y * s;
	m_z = m_z * s;
	return *this;
}

Vector3D Vector3D::operator=(const Vector3D& vec) {
	m_x = vec.m_x;
	m_y = vec.m_y;
	m_z = vec.m_z;
	return *this;
}

bool Vector3D::operator==(const Vector3D& vec) {
	return (m_x == vec.m_x && m_y == vec.m_y && m_z == vec.m_z);
}

double Vector3D::norm() {
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

Vector3D Vector3D::normalize() {
	double n = this->norm();
	if (n != 0) {
		return Vector3D(m_x / n, m_y / n, m_z / n);
	}
	else {
		printf("cannot normalize null vector");
		exit(1);
	}
}

double Vector3D::dot(const Vector3D& vec) {
	return m_x * vec.m_x + m_y * vec.m_y + m_z * vec.m_z;
}

Vector3D Vector3D::cross(const Vector3D& vec) {
	double a, b, c;
	a = m_y * vec.m_z - m_z * vec.m_y;
	b = m_z * vec.m_x - m_x * vec.m_z;
	c = m_x * vec.m_y - m_y * vec.m_x;
	return Vector3D(a, b, c);
}

double Vector3D::distance(const Vector3D& vec) {
	return (*this-vec).norm();
}


