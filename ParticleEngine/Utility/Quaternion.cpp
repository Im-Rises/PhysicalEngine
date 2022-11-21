#include "Quaternion.h"

Quaternion::Quaternion() {
    m_value[0] = 1;
    m_value[1] = 0;
    m_value[2] = 0;
    m_value[3] = 0;
}


Quaternion::Quaternion(const Quaternion &quaternion) {
    for (int i = 0; i < 4; i++) {
        m_value[i] = quaternion.m_value[i];
    }
}

Quaternion::Quaternion(const Vector3d &vec) : Quaternion(0, vec.x, vec.y, vec.z) {
}

float Quaternion::norm() {
    float sumSquar = 0;
    for (int i = 0; i < 4; i++) {
        sumSquar += m_value[i] * m_value[i];
    }
    return sqrt(sumSquar);
}

void Quaternion::normalize() {
    float n = norm();
    if (n != 0) {
        m_value[0] /= n;
        m_value[1] /= n;
        m_value[2] /= n;
        m_value[3] /= n;
    } else {
    }
}

Quaternion::Quaternion(float w, float x, float y, float z) {
    m_value[0] = w;
    m_value[1] = x;
    m_value[2] = y;
    m_value[3] = z;
}

Quaternion &Quaternion::operator=(const Quaternion &quaternion) {
    m_value[0] = quaternion.m_value[0];
    m_value[1] = quaternion.m_value[1];
    m_value[2] = quaternion.m_value[2];
    m_value[3] = quaternion.m_value[3];
    return *this;
}


Quaternion &Quaternion::operator*=(const Quaternion &quaternion) {
    float w, x, y, z;
    float w1 = m_value[0], x1 = m_value[1], y1 = m_value[2], z1 = m_value[3];
    float w2 = quaternion.m_value[0], x2 = quaternion.m_value[1], y2 = quaternion.m_value[2], z2 = quaternion.m_value[3];
    w = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2;
    x = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2;
    y = w1 * y2 + y1 * w2 + z1 * x2 - x1 * z2;
    z = w1 * z2 + z1 * w2 + x1 * y2 - y1 * x2;
    m_value[0] = w;
    m_value[1] = x;
    m_value[2] = y;
    m_value[3] = z;
    return *this;
}


Quaternion Quaternion::operator*(const Quaternion &quaternion) {
    Quaternion res(*this);
    res *= quaternion;
    return res;
}

Quaternion Quaternion::operator*(float n) {
    return Quaternion(n * m_value[0], n * m_value[1], n * m_value[2], n * m_value[3]);
}


Quaternion Quaternion::operator+(const Quaternion &quaternion) {
    return Quaternion(m_value[0] + quaternion.m_value[0], m_value[1] + quaternion.m_value[1],
                      m_value[2] + quaternion.m_value[2], m_value[3] + quaternion.m_value[3]);
}

Quaternion Quaternion::operator+=(const Quaternion &quaternion) {
    m_value[0] += quaternion.m_value[0];
    m_value[1] += quaternion.m_value[1];
    m_value[2] += quaternion.m_value[2];
    m_value[3] += quaternion.m_value[3];
    return *this;
}

float Quaternion::operator[](int i) const {
    return m_value[i];
}

void Quaternion::set(int i) {
    m_value[i] = i;
    normalize();
}


void Quaternion::rotateByVector(const Vector3d &vector) {
    *this *= Quaternion(vector);
    normalize();
}


void Quaternion::updateByAngularSpeed(const Vector3d &vector, float time) {
    Quaternion updateQuaternion = *this + Quaternion(vector) * *this * (time / 2);
    for (int i = 0; i < 4; i++) {
        m_value[i] = updateQuaternion[i];
    }
    normalize();
}

/// <summary>
/// destructeur de Quaternion
/// </summary>
Quaternion::~Quaternion() {
    //hdelete[] m_value;
}

float *Quaternion::getValues() {
    return m_value;
}



