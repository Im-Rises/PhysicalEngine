#include <iostream>
#include "../PhysicalEngine/Integrator/Integrator.h"
using namespace std;

int main(int argc, char *argv[]) {
    cout << argc << endl;

    Integrator integ;
	integ.boucle();
    

    return 0;
}
