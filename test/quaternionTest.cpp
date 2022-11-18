#include <iostream>
#include "../ParticleEngine/Utility/Quaternion.h"


int ConstructorTest() {
    Quaternion q0;
    if (!(q0[0] == 0.0f && q0[1] == 0.0f && q0[2] == 0.0f && q0[3] == 0.0f)) {
        std::cout << "- default Constructor fail Quaternion !\n";
        return 1;
    }
    Quaternion q1 = Quaternion(1, 2, 3, 4);
    if (!(q1[0] == 1 && q1[1] == 2 && q1[2] == 3.0f && q1[3] == 4.0f)) {
        std::cout << "- Constructor fail Quaternion 1 2 3 4!\n";
        return 1;
    }

    Quaternion q3 = Quaternion(Vector3d(1,2,3));
    if (!(q3[0] == 0.0f && q3[1] == 1.0f && q3[2] == 2.0f && q3[3] == 3.0f))
    {
        std::cout << "- Constructor fail Quaternion Vector3d!\n";
        return 1;
    }
    return 0;
}


int normTest() {
    Quaternion q0 = Quaternion(0,2, 3, 6);
    float n0=q0.norm();
    if (!(n0 == 7)) {
        std::cout << "- norm fail Quaternion 0 2 3 6!\n";
        return 2;
    }
    Quaternion q1 = Quaternion(2, 0, 3, 6);
    float n1 = q1.norm();
    if (!(n0 == 7))
    {
        std::cout << "- norm fail Quaternion 2 0 3 6!\n";
        return 2;
    }
    return 0;

}
int normalizeTest() {
    Quaternion q0 = Quaternion(2, 2, 2, 2);
    q0.normalize();
    if (!(q0[0] == 0.5f && q0[1] == 0.5f && q0[2] == 0.5f && q0[3] == 0.5f))
    {
        std::cout << "- normalize fail 2 2 2 2 !\n";
        return 1;
    }
    return 0;
}


int multTest() {
    return 0;
}

int plusTest() {
    return 0;
}
int rotateByVectorTest() {
    return 0;
}


int UpdateByAngularSpeedTest() {
    return 0;
}


int main() {
    std::cout << "Quaternion Test\n";

    int result = 0;
    result += ConstructorTest();
    result = +normTest();
    result += normalizeTest();
    result += multTest();
    result += plusTest();
    result += rotateByVectorTest();
    result += UpdateByAngularSpeedTest();
    if (result == 0)
        std::cout << "All tests passed!\n";
    else
        std::cout << "Some tests failed!\n";

    std::cout << "Error code: " << result << " : " << std::hex << "0x" << result << "\n\n";

    return result;
}
