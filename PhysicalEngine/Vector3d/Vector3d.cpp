#include "Vector3d.h"

using namespace std;

Vector3d::Vector3d() {
    m_x = 0;
    m_y = 0;
    m_z = 0;
}

Vector3d::Vector3d(float xcoord, float ycoord, float zcoord) {
    m_x = xcoord;
    m_y = ycoord;
    m_z = zcoord;
}

Vector3d::Vector3d(const Vector3d &vec) {
    m_x = vec.m_x;
    m_y = vec.m_y;
    m_z = vec.m_z;
}

Vector3d::~Vector3d() {
}

void Vector3d::setx(float xcoord) {
    m_x = xcoord;
}

void Vector3d::sety(float ycoord) {
    m_y = ycoord;
}

void Vector3d::setz(float zcoord) {
    m_z = zcoord;
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
    return Vector3d(m_x + vec.m_x, m_y + vec.m_y, m_z + vec.m_z);
}

Vector3d &Vector3d::operator+=(const Vector3d &vec) {
    m_x += vec.m_x;
    m_y += vec.m_y;
    m_z += vec.m_z;
    return *this;
}

Vector3d Vector3d::operator-(const Vector3d &vec) {
    return Vector3d(m_x - vec.m_x, m_y - vec.m_y, m_z - vec.m_z);
}

Vector3d &Vector3d::operator-=(const Vector3d &vec) {
    m_x -= vec.m_x;
    m_y -= vec.m_y;
    m_z -= vec.m_z;
    return *this;
}

Vector3d Vector3d::operator*(float s) {
    return Vector3d(m_x * s, m_y * s, m_z * s);
}

Vector3d &Vector3d::operator*=(float s) {
    m_x = m_x * s;
    m_y = m_y * s;
    m_z = m_z * s;
    return *this;
}

Vector3d Vector3d::operator=(const Vector3d &vec) {
    m_x = vec.m_x;
    m_y = vec.m_y;
    m_z = vec.m_z;
    return *this;
}

bool Vector3d::operator==(const Vector3d &vec) {
    return (m_x == vec.m_x && m_y == vec.m_y && m_z == vec.m_z);
}

float Vector3d::norm() {
    return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

Vector3d Vector3d::normalize() {
    float n = this->norm();
    if (n != 0) {
        return Vector3d(m_x / n, m_y / n, m_z / n);
    } else {
        printf("cannot normalize null vector");
        exit(1);
    }
}

float Vector3d::dot(const Vector3d &vec) {
    return m_x * vec.m_x + m_y * vec.m_y + m_z * vec.m_z;
}

Vector3d Vector3d::cross(const Vector3d &vec) {
    float a, b, c;
    a = m_y * vec.m_z - m_z * vec.m_y;
    b = m_z * vec.m_x - m_x * vec.m_z;
    c = m_x * vec.m_y - m_y * vec.m_x;
    return Vector3d(a, b, c);
}

float Vector3d::distance(const Vector3d &vec) {
    return (*this - vec).norm();
}


