#include <iostream>

#include "../PhysicalEngine/Vector3d/Vector3d.h"

int main() {
    Vector3d v1(1, 2, 3);
    Vector3d v2(4, 5, 6);

    Vector3d v3 = v1 + v2;
    if (v3.m_x != 5 || v3.m_y != 7 || v3.m_z != 9) {
        std::cout << "Error in Vector3d::operator+" << std::endl;
        return 1;
    } else {
        std::cout << "Vector3d::operator+ OK" << std::endl;
    }

    Vector3d v4 = v1 - v2;

    if (v4.m_x != -3 || v4.m_y != -3 || v4.m_z != -3) {
        std::cout << "Error in Vector3d::operator-" << std::endl;
        return 1;
    } else {
        std::cout << "Vector3d::operator- OK" << std::endl;
    }

    Vector3d v7 = v1 * 2;

    if (v7.m_x != 2 || v7.m_y != 4 || v7.m_z != 6) {
        std::cout << "Error in Vector3d::operator*" << std::endl;
        return 1;
    } else {
        std::cout << "Vector3d::operator* OK" << std::endl;
    }

    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
    bool equalityTest = (v1 == v2);
    if (equalityTest) {
        std::cout << "Error in Vector3d::operator==" << std::endl;
        return 1;
    } else {
        std::cout << "Vector3d::operator== OK" << std::endl;
    }

    bool inequalityTest = (v1 != v2);
    if (!inequalityTest) {
        std::cout << "Error in Vector3d::operator!=" << std::endl;
        return 1;
    } else {
        std::cout << "Vector3d::operator!= OK" << std::endl;
    }

    std::cout << "All tests passed" << std::endl;
    return 0;
}
