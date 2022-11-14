#include <iostream>

#include "../ParticleEngine/Utility/Matrix33.h"

bool floatEqual(float a, float b) {
    return (a - b) < 0.0001f;
}

int testConstructor() {
    Matrix33 m1;
    Matrix33 m2(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
    Matrix33 m3(m2);
    Matrix33 m4 = m2;

//    if (m1[0]== 0.0f && m1.m12 == 0.0f && m1.m13 == 0.0f &&
//        m1.m21 == 0.0f && m1.m22 == 0.0f && m1.m23 == 0.0f &&
//        m1.m31 == 0.0f && m1.m32 == 0.0f && m1.m33 == 0.0f &&
//        m2.m11 == 1.0f && m2.m12 == 2.0f && m2.m13 == 3.0f &&
//        m2.m21 == 4.0f && m2.m22 == 5.0f && m2.m23 == 6.0f &&
//        m2.m31 == 7.0f && m2.m32 == 8.0f && m2.m33 == 9.0f &&
//        m3.m11 == 1.0f && m3.m12 == 2.0f && m3.m13 == 3.0f &&
//        m3.m21 == 4.0f && m3.m22 == 5.0f && m3.m23 == 6.0f &&
//        m3.m31 == 7.0f && m3.m32 == 8.0f && m3.m33 == 9.0f &&
//        m4.m11 == 1.0f && m4.m12 == 2.0f && m4.m13 == 3.0f &&
//        m4.m21 == 4.0f && m4.m22 == 5.0f && m4.m23 == 6.0f &&
//        m4.m31 == 7.0f && m4.m32 == 8.0f && m4.m33 == 9.0f) {
//        std::cout << "- Constructor ok!\n";
//        return 0;
//    }

    std::cout << "- Constructor fail!\n";
    return 1;
}


int main() {
    std::cout << "Matrix33 Test\n";

    int result = 0;
    result += testConstructor();

    if (result == 0)
        std::cout << "All tests passed!\n";
    else
        std::cout << "Some tests failed!\n";

    std::cout << "Error code: " << result << " : " << std::hex << "0x" << result << "\n\n";

    return result;
}
