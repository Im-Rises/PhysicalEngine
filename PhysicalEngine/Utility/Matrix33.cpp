#include "Matrix33.h"

Matrix33::Matrix33() {
    for (int i = 0; i < 9; i++) {
        m_value[i] = 0.0f;
    }
}

Matrix33::Matrix33(const float values[9]) {
    for (int i = 0; i < 9; i++) {
        m_value[i] = values[i];
    }
}

Matrix33::Matrix33(const Matrix33 &matrixToCopyFrom) : Matrix33(matrixToCopyFrom.m_value) {
}

Matrix33 Matrix33::operator*(const Matrix33 &other) {
    Matrix33 res;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res.m_value[i * 3 + j] += m_value[i * 3 + k] * other.m_value[k * 3 + j];
            }
        }
    }
    return res;
}

Vector3d Matrix33::operator*(const Vector3d &other) {
    Vector3d res(0, 0, 0);
    res.x = m_value[0] * other.x + m_value[1] * other.y + m_value[2] * other.z;
    res.y = m_value[3] * other.x + m_value[4] * other.y + m_value[5] * other.z;
    res.z = m_value[6] * other.x + m_value[7] * other.y + m_value[8] * other.z;
    return res;

}

float Matrix33::operator()(int i, int j) const {
    return m_value[3 * i + j];
}

Matrix33 Matrix33::inverse() const {
    float determinant;
    float det1 = m_value[0] * ((m_value[3 * 1 + 1] * m_value[3 * 2 + 2]) - (m_value[3 * 2 + 1] * m_value[3 * 1 + 2]));
    float det2 = m_value[3 * 0 + 1] *
                 ((m_value[3 * 1 + 0]) * (m_value[3 * 2 + 2]) - (m_value[3 * 2 + 0] * m_value[3 * 1 + 2]));
    float det3 = m_value[3 * 0 + 2] *
                 ((m_value[3 * 1 + 0]) * (m_value[3 * 2 + 1]) - (m_value[3 * 2 + 0] * m_value[3 * 1 + 1]));
    determinant = det1 - det2 + det3;
    if (determinant == 0) {
        throw "not reversible";
    } else {
        Matrix33 res;
        res.m_value[0] =
                ((m_value[3 * 1 + 1] * m_value[3 * 2 + 2]) - (m_value[3 * 2 + 1] * m_value[3 * 1 + 2])) / determinant;
        res.m_value[1] = -((m_value[3 * 1 + 0] * m_value[3 * 2 + 2]) -
                           (m_value[3 * 2 + 0] * m_value[3 * 1 + 2])) / determinant;
        res.m_value[2] = +((m_value[3 * 1 + 0] * m_value[3 * 2 + 1]) -
                           (m_value[3 * 2 + 0] * m_value[3 * 1 + 1])) / determinant;
        res.m_value[3] = -((m_value[3 * 0 + 1] * m_value[3 * 2 + 2]) -
                           (m_value[3 * 2 + 1] * m_value[3 * 0 + 2])) / determinant;
        res.m_value[4] = +((m_value[3 * 0 + 0] * m_value[3 * 2 + 2]) -
                           (m_value[3 * 2 + 0] * m_value[3 * 0 + 2])) / determinant;
        res.m_value[5] = -((m_value[3 * 0 + 0] * m_value[3 * 2 + 1]) -
                           (m_value[3 * 2 + 0] * m_value[3 * 0 + 1])) / determinant;
        res.m_value[6] = +((m_value[3 * 0 + 1] * m_value[3 * 1 + 2]) -
                           (m_value[3 * 1 + 1] * m_value[3 * 0 + 2])) / determinant;
        res.m_value[7] = -((m_value[3 * 0 + 0] * m_value[3 * 1 + 2]) -
                           (m_value[3 * 1 + 0] * m_value[3 * 0 + 2])) / determinant;
        res.m_value[8] = +((m_value[3 * 0 + 0] * m_value[3 * 1 + 1]) -
                           (m_value[3 * 1 + 0] * m_value[3 * 0 + 1])) / determinant;
        return res;

    }
}

Matrix33 Matrix33::transpose() const {
    Matrix33 res;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res.m_value[3 * i + j] = m_value[3 * j + i];
        }
    }
    return res;
}

void Matrix33::inverseMat() {
    Matrix33 mat = inverse();
    for (int k = 0; k < 9; k++) {
        m_value[k] = mat.m_value[k];
    }
}

void Matrix33::transposeMat() {
    Matrix33 mat = transpose();
    for (int k = 0; k < 9; k++) {
        m_value[k] = mat.m_value[k];
    }
}

void Matrix33::setOrientation(const Quaternion &quaternion) {
    float w = quaternion[0], x = quaternion[1], y = quaternion[2], z = quaternion[3];
    m_value[0] = 1 - (2 * y * y +2 * z * z);
    m_value[1] = 2 * x * y - 2 * z * w;
    m_value[2] = 2 * x * z + 2 * y * w;
    m_value[3] = 2 * x * y + 2 * z * w;
    m_value[4] = 1 - (2 * x * x + 2 * z * z);
    m_value[5] = 2 * y * z - 2 * x * w;
    m_value[6] = 2 * x * z - 2 * y * w;
    m_value[7] = 2 * y * z + 2 * x * w;
    m_value[8] = 1 - (2 * x * x + 2 * y * y);
}

Matrix33::~Matrix33() {
//	delete[] m_value;
}

Matrix33 &Matrix33::operator=(const Matrix33 &other) {
    for (int i = 0; i < 9; i++) {
        m_value[i] = other.m_value[i];
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Matrix33 &matrix33) {
    os << "Matrix33: " << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            os << matrix33.m_value[3 * i + j] << " ";
        }
        os << std::endl;
    }
    return os;
}
