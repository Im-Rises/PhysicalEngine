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

void Vector3D::setx(double xcoord) {
	x = xcoord;
}
void Vector3D::sety(double ycoord) {
	y = ycoord;
}
void Vector3D::setz(double zcoord) {
	z = zcoord;
}

double Vector3D::getx() {
	return x;
}
double Vector3D::gety() {
	return y;
}
double Vector3D::getz() {
	return z;
}

Vector3D Vector3D::operator+(const Vector3D& vec) {
	return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

Vector3D& Vector3D::operator+=(const Vector3D& vec) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

Vector3D Vector3D::operator-(const Vector3D& vec) {
	return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

Vector3D& Vector3D::operator-=(const Vector3D& vec) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

Vector3D Vector3D::operator*(double s) {
	return Vector3D(x * s, y * s, z * s);
}

Vector3D& Vector3D::operator*=(double s) {
	x = x * s;
	y = y * s;
	z = z * s;
	return *this;
}

Vector3D Vector3D::operator=(const Vector3D& vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return *this;
}

double Vector3D::norm() {
	return sqrt(x * x + y * y + z * z);
}

Vector3D Vector3D::normalize() {
	double n = this->norm();
	if (n != 0) {
		return Vector3D(x / n, y / n, z / n);
	}
	else {
		printf("cannot normalize null vector");
		exit(1);
	}
}

double Vector3D::dot(const Vector3D& vec) {
	return x * vec.x + y * vec.y + z * vec.z;
}

Vector3D Vector3D::cross(const Vector3D& vec) {
	double a, b, c;
	a = y * vec.z - z * vec.y;
	b = z * vec.x - x * vec.z;
	c = x * vec.y - y * vec.x;
	return Vector3D(a, b, c);
}

void Vector3D::disp_vector() {
	std::cout << "(" << x << "," << y << "," << z << ")";
}
