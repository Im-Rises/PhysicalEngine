#include "Vector3d.h"

#include <cmath>

using namespace std;

Vector3d::Vector3d(float xCoord, float yCoord, float zCoord) {
    m_x = xCoord;
    m_y = yCoord;
    m_z = zCoord;
}

Vector3d::Vector3d(const Vector3d &vec) {
    m_x = vec.m_x;
    m_y = vec.m_y;
    m_z = vec.m_z;
}

Vector3d::~Vector3d() {
}

void Vector3d::setx(float xCoord) {
    m_x = xCoord;
}

void Vector3d::sety(float yCoord) {
    m_y = yCoord;
}

void Vector3d::setz(float zCoord) {
    m_z = zCoord;
}

float Vector3d::getx() const {
    return m_x;
}

float Vector3d::gety() const {
    return m_y;
}

float Vector3d::getz() const {
    return m_z;
}

Vector3d Vector3d::operator+(const Vector3d &vec) {
    return {m_x + vec.m_x, m_y + vec.m_y, m_z + vec.m_z};
}

Vector3d &Vector3d::operator+=(const Vector3d &vec) {
    m_x += vec.m_x;
    m_y += vec.m_y;
    m_z += vec.m_z;
    return *this;
}

Vector3d Vector3d::operator-(const Vector3d &vec) const {
    return {m_x - vec.m_x, m_y - vec.m_y, m_z - vec.m_z};
}

Vector3d &Vector3d::operator-=(const Vector3d &vec) {
    m_x -= vec.m_x;
    m_y -= vec.m_y;
    m_z -= vec.m_z;
    return *this;
}

Vector3d Vector3d::operator*(float s) const {
    return {m_x * s, m_y * s, m_z * s};
}

Vector3d &Vector3d::operator*=(float s) {
    m_x = m_x * s;
    m_y = m_y * s;
    m_z = m_z * s;
    return *this;
}

Vector3d Vector3d::operator/(float s) {
    return {m_x / s, m_y / s, m_z / s};
}

Vector3d &Vector3d::operator/=(float s) {
    m_x = m_x / s;
    m_y = m_y / s;
    m_z = m_z / s;
    return *this;
}

Vector3d &Vector3d::operator=(const Vector3d &vec) {
    m_x = vec.m_x;
    m_y = vec.m_y;
    m_z = vec.m_z;
    return *this;
}

bool Vector3d::operator==(const Vector3d &vec) const {
    return (m_x == vec.m_x && m_y == vec.m_y && m_z == vec.m_z);
}

bool Vector3d::operator!=(const Vector3d &vec) const {
    return !(*this == vec);
}

float Vector3d::norm() const {
    return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

Vector3d Vector3d::normalize() const {
    float n = this->norm();
    if (n != 0) {
        return Vector3d(m_x / n, m_y / n, m_z / n);
    } else {
        printf("cannot normalize null vector");
        exit(1);
    }
}

float Vector3d::dot(const Vector3d &vec) const {
    return m_x * vec.m_x + m_y * vec.m_y + m_z * vec.m_z;
}

Vector3d Vector3d::cross(const Vector3d &vec) const {
    float a, b, c;
    a = m_y * vec.m_z - m_z * vec.m_y;
    b = m_z * vec.m_x - m_x * vec.m_z;
    c = m_x * vec.m_y - m_y * vec.m_x;
    return {a, b, c};
}

float Vector3d::distance(const Vector3d &vec) {
    return (*this - vec).norm();
}



