#include "TestParticule.h"

TestParticule::TestParticule() {
    m_testParticule = Particule(1, 1, 1, 0);
}

int TestParticule::TestCalculePosition() {
    m_testParticule.setSpeed(2, 0, 0);
    Vector3d speedTest = m_testParticule.getSpeed();
    if (!(speedTest.getx() == 2 && speedTest.gety() == 0 && speedTest.getz() == 0)) {
        printf("setSpeed dosn't work expected (2,0,0), but obtained ");
        return 1;
    }
    m_testParticule.calculatePosition(2);
    Vector3d positionTest = m_testParticule.getPosition();
    if (!(positionTest.getx() == 5 && positionTest.gety() == 1 && positionTest.getz() == 1)) {
        printf("calculatePosition dosn't work expected (5,1,1), but obtained ");
        return 1;
    }

    printf("testParticule Ok");
    return 0;
}
