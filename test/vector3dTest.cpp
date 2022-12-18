#include <iostream>

#include "../PhysicalEngine/Utility/Vector3d.h"

bool floatEqual(float a, float b) {
    return (a - b) < 0.0001f;
}

int testConstructor() {
    Vector3d v1;
    Vector3d v2(1.0f, 2.0f, 3.0f);
    Vector3d v3(v2);
    Vector3d v4 = v2;

    if (v1.x == 0.0f && v1.y == 0.0f && v1.z == 0.0f &&
        v2.x == 1.0f && v2.y == 2.0f && v2.z == 3.0f &&
        v3.x == 1.0f && v3.y == 2.0f && v3.z == 3.0f &&
        v4.x == 1.0f && v4.y == 2.0f && v4.z == 3.0f)
    {
        std::cout << "- Constructor ok!\n";
        return 0;
    }
    std::cout << "- Constructor fail!\n";
    return 1;
}

int testVectorAddition() {
    Vector3d v1(1.0f, 2.0f, 3.0f);
    Vector3d v2(4.0f, 5.0f, 6.0f);
    Vector3d v3 = v1 + v2;

    if (v3.x == 5.0f && v3.y == 7.0f && v3.z == 9.0f)
    {
        std::cout << "- Vector Addition ok!\n";
        return 0;
    }
    std::cout << "- Vector Addition fail!\n";
    return 2;
}

int testVectorSubtraction() {
    Vector3d v1(1.0f, 2.0f, 3.0f);
    Vector3d v2(4.0f, 5.0f, 6.0f);
    Vector3d v3 = v1 - v2;

    if (v3.x == -3.0f && v3.y == -3.0f && v3.z == -3.0f)
    {
        std::cout << "- Vector Subtraction ok!\n";
        return 0;
    }
    std::cout << "- Vector Subtraction fail!\n";
    return 4;
}

int testVectorMultiplication() {
    Vector3d v1(1.0f, 2.0f, 3.0f);
    Vector3d v2 = v1 * 2.0f;

    if (v2.x == 2.0f && v2.y == 4.0f && v2.z == 6.0f)
    {
        std::cout << "- Vector Multiplication ok!\n";
        return 0;
    }
    std::cout << "- Vector Multiplication fail!\n";
    return 8;
}

int testVectorDivision() {
    Vector3d v1(1.0f, 2.0f, 3.0f);
    Vector3d v2 = v1 / 2.0f;

    if (v2.x == 0.5f && v2.y == 1.0f && v2.z == 1.5f)
    {
        std::cout << "- Vector Division ok!\n";
        return 0;
    }
    std::cout << "- Vector Division fail!\n";
    return 16;
}

int testScalarMultiplication() {
    Vector3d v1(1.0f, 2.0f, 3.0f);
    Vector3d v2 = v1 * 2.0f;

    if (v2.x == 2.0f && v2.y == 4.0f && v2.z == 6.0f)
    {
        std::cout << "- Scalar Multiplication ok!\n";
        return 0;
    }
    std::cout << "- Scalar Multiplication fail!\n";
    return 32;
}

int testScalarDivision() {
    Vector3d v1(1.0f, 2.0f, 3.0f);
    Vector3d v2 = v1 / 2.0f;

    if (v2.x == 0.5f && v2.y == 1.0f && v2.z == 1.5f)
    {
        std::cout << "- Scalar Division ok!\n";
        return 0;
    }
    std::cout << "- Scalar Division fail!\n";
    return 64;
}

int testNorm() {
    Vector3d v1(1.0f, 2.0f, 3.0f);
    float norm = v1.norm();

    if (floatEqual(norm, 3.74166f))
    {
        std::cout << "- Norm ok!\n";
        return 0;
    }
    std::cout << "- Norm fail!\n";
    return 128;
}

int testNormalize() {
    Vector3d v1(1.0f, 2.0f, 3.0f);
    Vector3d v2 = v1.normalize();

    if (floatEqual(v2.x, 0.26726f) && floatEqual(v2.y, 0.53452f) && floatEqual(v2.z, 0.80178f))
    {
        std::cout << "- Normalize ok!\n";
        return 0;
    }

    std::cout << "- Normalize fail!\n";
    return 256;
}

int testDistance() {
    Vector3d v1(1.0f, 2.0f, 3.0f);
    Vector3d v2(4.0f, 5.0f, 6.0f);
    float distance = v1.distance(v2);

    if (distance == 5.196152f)
    {
        std::cout << "- Distance ok!\n";
        return 0;
    }
    std::cout << "- Distance fail!\n";
    return 512;
}

int main() {
    std::cout << "Vector3d Test\n";

    int result = 0;
    result += testConstructor();
    result += testVectorAddition();
    result += testVectorSubtraction();
    result += testVectorMultiplication();
    result += testVectorDivision();
    result += testScalarMultiplication();
    result += testScalarDivision();
    result += testNormalize();
    result += testNorm();
    result += testDistance();

    if (result == 0)
        std::cout << "All tests passed!\n";
    else
        std::cout << "Some tests failed!\n";

    std::cout << "Error code: " << result << " : " << std::hex << "0x" << result << "\n\n";

    return result;
}
