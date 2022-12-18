#include <iostream>

#include "../PhysicalEngine/Utility/Matrix34.h"

int testConstructor() {
    Matrix34 m1;
    float values[12] = { 1.0f, 2.0f, 3.0f, 10.0f, 4.0f, 5.0f, 6.0f, 10.0f, 7.0f, 8.0f, 9.0f, 10.0f };
    Matrix34 m2(values);
    Matrix34 m3(m2);
    Matrix34 m4 = m2;

    if (!(m1(0, 0) == 0.0f && m1(0, 1) == 0.0f && m1(0, 2) == 0.0f && m1(0, 3) == 0.0f &&
            m1(1, 0) == 0.0f && m1(1, 1) == 0.0f && m1(1, 2) == 0.0f && m1(1, 3) == 0.0f &&
            m1(2, 0) == 0.0f && m1(2, 1) == 0.0f && m1(2, 2) == 0.0f && m1(2, 3) == 0.0f &&
            m2(0, 0) == 1.0f && m2(0, 1) == 2.0f && m2(0, 2) == 3.0f && m2(0, 3) == 10.0f &&
            m2(1, 0) == 4.0f && m2(1, 1) == 5.0f && m2(1, 2) == 6.0f && m2(1, 3) == 10.0f &&
            m2(2, 0) == 7.0f && m2(2, 1) == 8.0f && m2(2, 2) == 9.0f && m2(2, 3) == 10.0f &&
            m3(0, 0) == 1.0f && m3(0, 1) == 2.0f && m3(0, 2) == 3.0f && m3(0, 3) == 10.0f &&
            m3(1, 0) == 4.0f && m3(1, 1) == 5.0f && m3(1, 2) == 6.0f && m3(1, 3) == 10.0f &&
            m3(2, 0) == 7.0f && m3(2, 1) == 8.0f && m3(2, 2) == 9.0f && m3(2, 3) == 10.0f &&
            m4(0, 0) == 1.0f && m4(0, 1) == 2.0f && m4(0, 2) == 3.0f && m4(0, 3) == 10.0f &&
            m4(1, 0) == 4.0f && m4(1, 1) == 5.0f && m4(1, 2) == 6.0f && m4(1, 3) == 10.0f &&
            m4(2, 0) == 7.0f && m4(2, 1) == 8.0f && m4(2, 2) == 9.0f && m4(2, 3) == 10.0f))
    {
        std::cout << "- Constructor fail!\n";
        return 1;
    }

    return 0;
}

int testMatrixMultiplication() {
    float values[12] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f };
    float values2[12] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
    Matrix34 m0(values);
    Matrix34 m1(values2);
    Matrix34 m2 = m0 * m1;
    if (!(
            m2(0, 0) == 6.0f && m2(0, 1) == 6.0f && m2(0, 2) == 6.0f && m2(0, 3) == 10.0f &&
            m2(1, 0) == 18.0f && m2(1, 1) == 18.0f && m2(1, 2) == 18.0f && m2(1, 3) == 26.0f &&
            m2(2, 0) == 30.0f && m2(2, 1) == 30.0f && m2(2, 2) == 30.0f && m2(2, 3) == 42.0f

            ))
    {
        std::cout << "- Matrix multplication fail!\n";
        return 2;
    }
    return 0;
}

int testMatrixInverse() {
    float values[12] = { 1.0f, 1.0f, 2.0f, 10.0f, 1.0f, 2.0f, 1.0f, 11.0f, 2.0f, 1.0f, 1.0f, 12.0f };
    Matrix34 m1(values);
    Matrix34 m2 = m1.inverse();
    Matrix34 id2 = m2 * m1;
    if (!(id2(0, 0) == 1.0f && id2(0, 1) == 0.0f && id2(0, 2) == 0.0f && id2(0, 3) == 0.0f &&
            id2(1, 0) == 0.0f && id2(1, 1) == 1.0f && id2(1, 2) == 0.0f && id2(1, 3) == 0.0f &&
            id2(2, 0) == 0.0f && id2(2, 1) == 0.0f && id2(2, 2) == 1.0f && id2(2, 3) == 0.0f))
    {

        std::cout << "-Inverse Matrix 34 fail !\n";
        return 4;
    }
    return 0;
}

int testSetOrientationAndPosition() {
    Quaternion q1 = Quaternion(1.0f, 0.0f, 0.0f, 0.0f);
    Matrix34 m1;
    m1.setOrientationAndPosition(q1, Vector3d(1, 2, 3));
    if (!(m1(0, 0) == 1.0f && m1(0, 1) == 0.0f && m1(0, 2) == 0.0f && m1(0, 3) == 1.0f &&
            m1(1, 0) == 0.0f && m1(1, 1) == 1.0f && m1(1, 2) == 0.0f && m1(1, 3) == 2.0f &&
            m1(2, 0) == 0.0f && m1(2, 1) == 0.0f && m1(2, 2) == 1.0f && m1(2, 3) == 3.0f))
    {

        std::cout << "-Set orientation fail quaternion 1 0 0 0 vector3d 1 2 3 !\n";
        return 8;
    }
    Quaternion q2 = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
    Matrix34 m2;
    m2.setOrientationAndPosition(q2, Vector3d(4, 5, 6));
    if (!(m2(0, 0) == -1.0f && m2(0, 1) == 0.0f && m2(0, 2) == 0.0f && m2(0, 3) == 4.0f &&
            m2(1, 0) == 0.0f && m2(1, 1) == -1.0f && m2(1, 2) == 0.0f && m2(1, 3) == 5.0f &&
            m2(2, 0) == 0.0f && m2(2, 1) == 0.0f && m2(2, 2) == 1.0f && m2(2, 3) == 6.0f))
    {
        std::cout << "-Set orientation fail quaternion 0 0 0 1 vector3d 4 5 6!\n";
        return 8;
    }

    Quaternion q3 = Quaternion(0.5f, 0.5f, 0.5f, 0.5f);
    Matrix34 m3;
    m3.setOrientationAndPosition(q3, Vector3d(1, 2, 3));
    if (!(m3(0, 0) == 0.0f && m3(0, 1) == 0.0f && m3(0, 2) == 1.0f && m3(0, 3) == 1.0f &&
            m3(1, 0) == 1.0f && m3(1, 1) == 0.0f && m3(1, 2) == 0.0f && m3(1, 3) == 2.0f &&
            m3(2, 0) == 0.0f && m3(2, 1) == 1.0f && m3(2, 2) == 0.0f && m3(2, 3) == 3.0f))
    {
        std::cout << "-Set orientation fail quaternion 0.5 0.5 0.5 0.5 vector3d 1 2 3! \n";
        return 8;
    }
    return 0;
}

int testTransformeDirectionAndRotation() {
    float values[12] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 1.0f, 3.0f };
    Matrix34 m1(values);
    Vector3d v1(3.0f, 2.0f, 1.0f);
    Vector3d v2 = m1.transformPosition(v1);
    Vector3d v3 = m1.transformDirection(v1);
    if (!(v2.x == 4.0f && v2.y == 4.0f && v2.z == 4.0f))
    {
        std::cout << "transforme position fail!\n";
        return 16;
    }
    if (!(v3.x == 3.0f && v3.y == 2.0f && v3.z == 1.0f))
    {
        std::cout << "transforme direction fail !\n";
        return 16;
    }

    float values2[12] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 2.0f, 0.0f, 0.0f, -1.0f, 3.0f };
    Matrix34 m2(values2);
    Vector3d v5(3.0f, 2.0f, 1.0f);
    Vector3d v6 = m2.transformPosition(v1);
    Vector3d v7 = m2.transformDirection(v1);
    if (!(v7.x == 3.0f && v7.y == -2.0f && v7.z == -1.0f))
    {
        std::cout << "transforme direction fail !\n";
        return 16;
    }
    if (!(v6.x == 4.0f && v6.y == 0.0f && v6.z == 2.0f))
    {
        std::cout << "transforme position fail!\n";
        return 16;
    }

    return 0;
}


int main() {
    std::cout << "Matrix33 Test\n";

    int result = 0;
    result += testConstructor();
    result += testMatrixMultiplication();
    result += testMatrixInverse();
    result += testSetOrientationAndPosition();
    result += testTransformeDirectionAndRotation();
    if (result == 0)
        std::cout << "All tests passed!\n";
    else
        std::cout << "Some tests failed!\n";

    std::cout << "Error code: " << result << " : " << std::hex << "0x" << result << "\n\n";

    return result;
}
