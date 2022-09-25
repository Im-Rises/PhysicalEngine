#include "Vector3d.h"

using namespace std;

Vector3D::Vector3D() {
    m_x = 0;
    m_y = 0;
    m_z = 0;
}

Vector3D::Vector3D(float xcoord, float ycoord, float zcoord) {
    m_x = xcoord;
    m_y = ycoord;
    m_z = zcoord;
}

Vector3D::Vector3D(const Vector3D &vec) {
    m_x = vec.m_x;
    m_y = vec.m_y;
    m_z = vec.m_z;
}

Vector3D::~Vector3D() {
}

void Vector3D::setx(float xcoord) {
    m_x = xcoord;
}

void Vector3D::sety(float ycoord) {
    m_y = ycoord;
}

void Vector3D::setz(float zcoord) {
    m_z = zcoord;
}

float Vector3D::getx() const {
    return m_x;
}

float Vector3D::gety() const {
    return m_y;
}

float Vector3D::getz() const {
    return m_z;
}

Vector3D Vector3D::operator+(const Vector3D &vec) {
    return Vector3D(m_x + vec.m_x, m_y + vec.m_y, m_z + vec.m_z);
}

Vector3D &Vector3D::operator+=(const Vector3D &vec) {
    m_x += vec.m_x;
    m_y += vec.m_y;
    m_z += vec.m_z;
    return *this;
}

Vector3D Vector3D::operator-(const Vector3D &vec) {
    return Vector3D(m_x - vec.m_x, m_y - vec.m_y, m_z - vec.m_z);
}

Vector3D &Vector3D::operator-=(const Vector3D &vec) {
    m_x -= vec.m_x;
    m_y -= vec.m_y;
    m_z -= vec.m_z;
    return *this;
}

Vector3D Vector3D::operator*(float s) {
    return Vector3D(m_x * s, m_y * s, m_z * s);
}

Vector3D &Vector3D::operator*=(float s) {
    m_x = m_x * s;
    m_y = m_y * s;
    m_z = m_z * s;
    return *this;
}

Vector3D Vector3D::operator=(const Vector3D &vec) {
    m_x = vec.m_x;
    m_y = vec.m_y;
    m_z = vec.m_z;
    return *this;
}

bool Vector3D::operator==(const Vector3D &vec) {
    return (m_x == vec.m_x && m_y == vec.m_y && m_z == vec.m_z);
}

float Vector3D::norm() {
    return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

Vector3D Vector3D::normalize() {
    float n = this->norm();
    if (n != 0) {
        return Vector3D(m_x / n, m_y / n, m_z / n);
    } else {
        printf("cannot normalize null vector");
        exit(1);
    }
}

float Vector3D::dot(const Vector3D &vec) {
    return m_x * vec.m_x + m_y * vec.m_y + m_z * vec.m_z;
}

Vector3D Vector3D::cross(const Vector3D &vec) {
    float a, b, c;
    a = m_y * vec.m_z - m_z * vec.m_y;
    b = m_z * vec.m_x - m_x * vec.m_z;
    c = m_x * vec.m_y - m_y * vec.m_x;
    return Vector3D(a, b, c);
}

float Vector3D::distance(const Vector3D &vec) {
    return (*this - vec).norm();
}


