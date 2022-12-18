#include "Cube.h"

Cube::Cube(float longueur) : CuboidRectangle(longueur, longueur, longueur) {
    color = glm::vec4(0.1f, 0.8f, 0.0f, 1.0f);
}
