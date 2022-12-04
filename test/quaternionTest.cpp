#include "../PhysicalEngine/Utility/Quaternion.h"
#include <iostream>


int constructorTest() {
    Quaternion q0;
    if (!(q0[0] == 1.0f && q0[1] == 0.0f && q0[2] == 0.0f && q0[3] == 0.0f))
    {
        std::cout << "- default Constructor fail Quaternion !\n";
        return 1;
    }
    Quaternion q1 = Quaternion(1, 2, 3, 4);
    if (!(q1[0] == 1 && q1[1] == 2 && q1[2] == 3.0f && q1[3] == 4.0f))
    {
        std::cout << "- Constructor fail Quaternion 1 2 3 4!\n";
        return 1;
    }

    Quaternion q3 = Quaternion(Vector3d(1, 2, 3));
    if (!(q3[0] == 0.0f && q3[1] == 1.0f && q3[2] == 2.0f && q3[3] == 3.0f))
    {
        std::cout << "- Constructor fail Quaternion Vector3d!\n";
        return 1;
    }
    return 0;
}


int normTest() {
    Quaternion q0 = Quaternion(0, 2, 3, 6);
    float n0 = q0.norm();
    if (!(n0 == 7))
    {
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
        return 4;
    }
    return 0;
}


int multTest() {
    Quaternion q0 = Quaternion(1, 1, 1, 1);
    q0.normalize();
    Quaternion q1 = Quaternion(1, 0, 0, 0);
    Quaternion q2 = Quaternion(0, 1, 0, 0);
    Quaternion q3 = Quaternion(0, 0, 1, 0);
    Quaternion q4 = Quaternion(0, 0, 0, 1);

    Quaternion qt1 = q0 * q1;
    Quaternion qt2 = q0 * q2;
    Quaternion qt3 = q3 * q0;
    Quaternion qt4 = q4 * q0;
    if (!(qt1[0] == 0.5f && qt1[1] == 0.5f && qt1[2] == 0.5f && qt1[3] == 0.5f))
    {
        std::cout << "- multiplication fail 1 1 1 1 * 1 0 0 0 !\n";
        return 8;
    }
    if (!(qt2[0] == -0.5f && qt2[1] == 0.5f && qt2[2] == 0.5f && qt2[3] == -0.5f))
    {
        std::cout << "- multiplication fail 1 1 1 1 * 0 1 0 0 !\n";
        return 8;
    }
    if (!(qt3[0] == -0.5f && qt3[1] == 0.5f && qt3[2] == 0.5f && qt3[3] == -0.5f))
    {
        std::cout << "- multiplication fail 0 0 1 0 * 1 1 1 1  !\n";
        return 8;
    }
    if (!(qt4[0] == -0.5f && qt4[1] == -0.5f && qt4[2] == 0.5f && qt4[3] == 0.5f))
    {
        std::cout << "- multiplication fail 0 0 0 1 * 1 1 1 1 !\n";
        return 8;
    }
    return 0;
}


int rotateByVectorTest() {
    Quaternion qt2 = Quaternion(1, 1, 1, 1);
    Quaternion qt3 = Quaternion(1, 1, 1, 1);
    Quaternion qt4 = Quaternion(1, 1, 1, 1);
    qt2.normalize();
    qt3.normalize();
    qt4.normalize();
    qt2.rotateByVector(Vector3d(1, 0, 0));
    qt3.rotateByVector(Vector3d(0, 1, 0));
    qt4.rotateByVector(Vector3d(0, 0, 1));
    if (!(qt2[0] == -0.5f && qt2[1] == 0.5f && qt2[2] == 0.5f && qt2[3] == -0.5f))
    {
        std::cout << "- rotation fail 1 1 1 1 * 1 0 0 !\n";
        return 16;
    }

    if (!(qt3[0] == -0.5f && qt3[1] == -0.5f && qt3[2] == 0.5f && qt3[3] == 0.5f))
    {
        std::cout << "- rotation fail 1 1 1 1 * 0 1 0  !\n";
        return 16;
    }
    if (!(qt4[0] == -0.5f && qt4[1] == 0.5f && qt4[2] == -0.5f && qt4[3] == 0.5f))
    {
        std::cout << "- rotation fail fail 1 1 1 1 * 0 0 1 !\n";
        return 16;
    }
    return 0;
}


int updateByAngularSpeedTest() {
    Quaternion q0 = Quaternion(1, 2, 3, 4);
    Quaternion q1 = Quaternion(0.0f, 2.5f, 1.0f, 5.5f);
    q0.updateByAngularSpeed(Vector3d(1, 0, 0), 1);

    q1.normalize();
    if (!(q0[0] == q1[0] && q0[1] == q1[1] && q0[2] == q1[2] && q0[3] == q1[3]))
    {
        std::cout << "- rotatebyangularspeed fail 1 2 3 4 rotation speed: 1 0 0 pendant une seconde !\n";
        return 32;
    }
    return 0;
}


int main() {
    std::cout << "Quaternion Test\n";

    int result = 0;
    result += constructorTest();
    result += normTest();
    result += normalizeTest();
    result += multTest();
    result += rotateByVectorTest();
    result += updateByAngularSpeedTest();
    if (result == 0)
        std::cout << "All tests passed!\n";
    else
        std::cout << "Some tests failed!\n";

    std::cout << "Error code: " << result << " : " << std::hex << "0x" << result << "\n\n";

    return result;
}
