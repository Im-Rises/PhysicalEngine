#include <iostream>

#include "../PhysicalEngine/Utility/Matrix33.h"

bool floatEqual(float a, float b) {
    return (a - b) < 0.0001f;
}

int testConstructor() {
    Matrix33 m1;
    float values[9] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f };
    Matrix33 m2(values);
    Matrix33 m3(m2);
    Matrix33 m4 = m2;

    if (!(m1(0, 0) == 0.0f && m1(0, 1) == 0.0f && m1(0, 2) == 0.0f &&
            m1(1, 0) == 0.0f && m1(1, 1) == 0.0f && m1(1, 2) == 0.0f &&
            m1(2, 0) == 0.0f && m1(2, 1) == 0.0f && m1(2, 2) == 0.0f &&
            m2(0, 0) == 1.0f && m2(0, 1) == 2.0f && m2(0, 2) == 3.0f &&
            m2(1, 0) == 4.0f && m2(1, 1) == 5.0f && m2(1, 2) == 6.0f &&
            m2(2, 0) == 7.0f && m2(2, 1) == 8.0f && m2(2, 2) == 9.0f &&
            m3(0, 0) == 1.0f && m3(0, 1) == 2.0f && m3(0, 2) == 3.0f &&
            m3(1, 0) == 4.0f && m3(1, 1) == 5.0f && m3(1, 2) == 6.0f &&
            m3(2, 0) == 7.0f && m3(2, 1) == 8.0f && m3(2, 2) == 9.0f &&
            m4(0, 0) == 1.0f && m4(0, 1) == 2.0f && m4(0, 2) == 3.0f &&
            m4(1, 0) == 4.0f && m4(1, 1) == 5.0f && m4(1, 2) == 6.0f &&
            m4(2, 0) == 7.0f && m4(2, 1) == 8.0f && m4(2, 2) == 9.0f))
    {
        std::cout << "- Constructor fail!\n";
        return 1;
    }

    return 0;
}

/*
int testMatrixAddition() {
    float values1[9] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
    float values2[9] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
    Matrix33 m1(values1);
    Matrix33 m2(values2);
    Matrix33 m3 = m1 + m2;

    if (!(m3(0, 0) == 2.0f && m3(0, 1) == 4.0f && m3(0, 2) == 6.0f &&
          m3(1, 0) == 8.0f && m3(1, 1) == 10.0f && m3(1, 2) == 12.0f &&
          m3(2, 0) == 14.0f && m3(2, 1) == 16.0f && m3(2, 2) == 18.0f)) {
        std::cout << "- Matrix Addition fail!\n";
        return 2;
    }

    return 0;
}

int testMatrixSubtraction() {
    float values1[9] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
    float values2[9] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
    Matrix33 m1(values1);
    Matrix33 m2(values2);
    Matrix33 m3 = m1 - m2;

    if (!(m3(0, 0) == 0.0f && m3(0, 1) == 0.0f && m3(0, 2) == 0.0f &&
          m3(1, 0) == 0.0f && m3(1, 1) == 0.0f && m3(1, 2) == 0.0f &&
          m3(2, 0) == 0.0f && m3(2, 1) == 0.0f && m3(2, 2) == 0.0f)) {
        std::cout << "- Matrix Subtraction fail!\n";
        return 3;
    }

    return 0;
}
*/

int testMatrixMultiplication() {
    float values1[9] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f };
    float values2[9] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f };
    Matrix33 m1(values1);
    Matrix33 m2(values2);
    Matrix33 m3 = m1 * m2;

    if (!(m3(0, 0) == 30.0f && m3(0, 1) == 36.0f && m3(0, 2) == 42.0f &&
            m3(1, 0) == 66.0f && m3(1, 1) == 81.0f && m3(1, 2) == 96.0f &&
            m3(2, 0) == 102.0f && m3(2, 1) == 126.0f && m3(2, 2) == 150.0f))
    {
        std::cout << "- Matrix Multiplication fail!\n";
        return 8;
    }

    return 0;
}

int testMatrixVectorMultiplication() {
    float values1[9] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f };
    Matrix33 m1(values1);
    Vector3d vec1 = Vector3d(1, 2, 3);
    Vector3d vec2 = m1 * vec1;
    if (!(vec2.x == 1.0f + 4.0f + 9.0f && vec2.y == 4.0f + 10.0f + 18.0f && vec2.z == 7.0f + 16.0f + 27.0f))
    {
        std::cout << "- Matrix Vector3d Multiplication fail!\n";
        return 16;
    }
    return 0;
}

int testMatrixInverse() {
    float values1[9] = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f };
    Matrix33 m1(values1);
    Matrix33 m2 = m1.inverse();
    Matrix33 id1 = m2 * m1;
    if (!(id1(0, 0) == 1.0f && id1(0, 1) == 0.0f && id1(0, 2) == 0.0f &&
            id1(1, 0) == 0.0f && id1(1, 1) == 1.0f && id1(1, 2) == 0.0f &&
            id1(2, 0) == 0.0f && id1(2, 1) == 0.0f && id1(2, 2) == 1.0f))
    {

        std::cout << "-Inverse Matrix fail diagonal inverse!\n";
        return 32;
    }
    float values2[9] = { 1.0f, 1.0f, 2.0f, 1.0f, 2.0f, 1.0f, 2.0f, 1.0f, 1.0f };
    Matrix33 m3(values2);
    Matrix33 m4 = m3.inverse();
    Matrix33 id2 = m3 * m4;
    if (!(id2(0, 0) == 1.0f && id2(0, 1) == 0.0f && id2(0, 2) == 0.0f &&
            id2(1, 0) == 0.0f && id2(1, 1) == 1.0f && id2(1, 2) == 0.0f &&
            id2(2, 0) == 0.0f && id2(2, 1) == 0.0f && id2(2, 2) == 1.0f))
    {

        std::cout << "-Inverse Matrix fail id + matrice 111!\n";
        return 32;
    }
    return 0;
}

int testMatrixTranspose() {
    float values1[9] = { 1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f };
    Matrix33 m1(values1);
    Matrix33 m2 = m1.transpose();
    if (!(m2(0, 0) == 1.0f && m2(0, 1) == 4.0f && m2(0, 2) == 7.0f &&
            m2(1, 0) == 2.0f && m2(1, 1) == 5.0f && m2(1, 2) == 8.0f &&
            m2(2, 0) == 3.0f && m2(2, 1) == 6.0f && m2(2, 2) == 9.0f))
    {

        std::cout << "-Transpose Matrix fail diagonal inverse!\n";
        return 64;
    }
    return 0;
}

int testMatrixScalarMultiplication() {
    float values1[9] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f };
    Matrix33 m1(values1);
    /* Matrix33 m2 = m1 * 2.0f;

    if (!(m2(0, 0) == 2.0f && m2(0, 1) == 4.0f && m2(0, 2) == 6.0f &&
          m2(1, 0) == 8.0f && m2(1, 1) == 10.0f && m2(1, 2) == 12.0f &&
          m2(2, 0) == 14.0f && m2(2, 1) == 16.0f && m2(2, 2) == 18.0f)) {
        std::cout << "- Matrix Scalar Multiplication fail!\n";
        return 5;
    }
    */

    return 0;
}

int TestSetOrientation() {
    Quaternion q1 = Quaternion(1.0f, 0.0f, 0.0f, 0.0f);
    Matrix33 m1;
    m1.setOrientation(q1);
    if (!(m1(0, 0) == 1.0f && m1(0, 1) == 0.0f && m1(0, 2) == 0.0f &&
            m1(1, 0) == 0.0f && m1(1, 1) == 1.0f && m1(1, 2) == 0.0f &&
            m1(2, 0) == 0.0f && m1(2, 1) == 0.0f && m1(2, 2) == 1.0f))
    {

        std::cout << "-Set orientation fail quaternion 1 0 0 0!\n";
        return 128;
    }
    Quaternion q2 = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
    Matrix33 m2;
    m2.setOrientation(q2);
    if (!(m2(0, 0) == -1.0f && m2(0, 1) == 0.0f && m2(0, 2) == 0.0f &&
            m2(1, 0) == 0.0f && m2(1, 1) == -1.0f && m2(1, 2) == 0.0f &&
            m2(2, 0) == 0.0f && m2(2, 1) == 0.0f && m2(2, 2) == 1.0f))
    {
        std::cout << "-Set orientation fail quaternion 0 0 0 1!\n";
        return 128;
    }

    Quaternion q3 = Quaternion(0.5f, 0.5f, 0.5f, 0.5f);
    Matrix33 m3;
    m3.setOrientation(q3);
    if (!(m3(0, 0) == 0.0f && m3(0, 1) == 0.0f && m3(0, 2) == 1.0f &&
            m3(1, 0) == 1.0f && m3(1, 1) == 0.0f && m3(1, 2) == 0.0f &&
            m3(2, 0) == 0.0f && m3(2, 1) == 1.0f && m3(2, 2) == 0.0f))
    {
        std::cout << "-Set orientation fail quaternion 0.5 0.5 0.5 0.5!\n";
        return 128;
    }
    return 0;
}


int main() {
    std::cout << "Matrix33 Test\n";

    int result = 0;
    result += testConstructor();
    result += testMatrixMultiplication();
    result += testMatrixVectorMultiplication();
    result += testMatrixInverse();
    result += testMatrixTranspose();
    result += TestSetOrientation();
    if (result == 0)
        std::cout << "All tests passed!\n";
    else
        std::cout << "Some tests failed!\n";

    std::cout << "Error code: " << result << " : " << std::hex << "0x" << result << "\n\n";

    return result;
}
