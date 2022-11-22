#ifndef CUBE_H
#define CUBE_H

#include "CuboidRectangle.h"

class Cube : public CuboidRectangle {
private:
    int length;

public:
    Cube(float longueur);
};

#endif // !CUBE_H
