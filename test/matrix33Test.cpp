#include <iostream>

#include "../ParticleEngine/Utility/Matrix33.h"

bool floatEqual(float a, float b) {
    return (a - b) < 0.0001f;
}

int testConstructor() {
    Matrix33 m1;
    float values[9] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
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
          m4(2, 0) == 7.0f && m4(2, 1) == 8.0f && m4(2, 2) == 9.0f)) {
        std::cout << "- Constructor fail!\n";
        return 1;
    }

    return 0;
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
