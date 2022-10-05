#ifndef MYCUBE_H
#define MYCUBE_H

/*
 * This class is used only for testing purposes.
 * It create a cube with a specific size without using indices.
*/

#include "../Mesh.h"

class MyCube : public Mesh {
public:
    MyCube(float size = 1);

};


#endif //MYCUBE_H
