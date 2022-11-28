#include "Vector3d.h"

#include <cmath>

using namespace std;

Vector3d::Vector3d(float xCoord, float yCoord, float zCoord) {
    x = xCoord;
    y = yCoord;
    z = zCoord;
}

Vector3d::Vector3d(const Vector3d& vec) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

// Vector3d::Vector3d(Vector3d&& vec) noexcept {
//     x = vec.x;
//     y = vec.y;
//     z = vec.z;
// }

Vector3d::~Vector3d() = default;

void Vector3d::setx(float xCoord) {
    x = xCoord;
}

void Vector3d::sety(float yCoord) {
    y = yCoord;
}

void Vector3d::setz(float zCoord) {
    z = zCoord;
}

float Vector3d::getx() const {
    return x;
}

float Vector3d::gety() const {
    return y;
}

float Vector3d::getz() const {
    return z;
}

Vector3d Vector3d::operator+(const Vector3d& vec) const {
    return { x + vec.x, y + vec.y, z + vec.z };
}

Vector3d& Vector3d::operator+=(const Vector3d& vec) {
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

Vector3d Vector3d::operator-(const Vector3d& vec) const {
    return { x - vec.x, y - vec.y, z - vec.z };
}

Vector3d& Vector3d::operator-=(const Vector3d& vec) {
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}

Vector3d Vector3d::operator*(float scalar) const {
    return { x * scalar, y * scalar, z * scalar };
}

Vector3d& Vector3d::operator*=(float scalar) {
    x = x * scalar;
    y = y * scalar;
    z = z * scalar;
    return *this;
}

Vector3d Vector3d::operator/(float scalar) const {
    return { x / scalar, y / scalar, z / scalar };
}

Vector3d& Vector3d::operator/=(float scalar) {
    x = x / scalar;
    y = y / scalar;
    z = z / scalar;
    return *this;
}

Vector3d& Vector3d::operator=(const Vector3d& vec) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}

// Vector3d& Vector3d::operator=(Vector3d&& vec) noexcept {
//     return *this;
// }

bool Vector3d::operator==(const Vector3d& vec) const {
    return (x == vec.x && y == vec.y && z == vec.z);
}

bool Vector3d::operator!=(const Vector3d& vec) const {
    return !(*this == vec);
}

float Vector3d::norm() const {
    return sqrt(x * x + y * y + z * z);
}

Vector3d Vector3d::normalize() const {
    float n = this->norm();
    if (n != 0)
    {
        return { x / n, y / n, z / n };
    }
    else
    {
        //        std::cerr << "Error: cannot normalize null vector" << std::endl;
        //        exit(1);
        return { 0, 0, 0 };
    }
}

float Vector3d::dot(const Vector3d& vec) const {
    return x * vec.x + y * vec.y + z * vec.z;
}

Vector3d Vector3d::cross(const Vector3d& vec) const {
    float a, b, c;
    a = y * vec.z - z * vec.y;
    b = z * vec.x - x * vec.z;
    c = x * vec.y - y * vec.x;
    return { a, b, c };
}

float Vector3d::distance(const Vector3d& vec) const {
    return (*this - vec).norm();
}
