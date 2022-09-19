#include <iostream>
#include "TestParticule/TestParticule.h"
using namespace std;

int main(int argc, char *argv[]) {
    cout << argc << endl;

    int returnValue=0;

    TestParticule t=TestParticule();
	returnValue = t.TestCalculePosition();

    return returnValue;


}
