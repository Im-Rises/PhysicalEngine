#include "CuboidRectangle.h"

CuboidRectangle::CuboidRectangle(double longueur, double hauteur, double profondeur, const Vector3D &position) {

    m_position = position;
    float l2 = longueur / 2;
    float h2 = hauteur / 2;
    float p2 = profondeur / 2;


    m_points = {
            l2, h2, p2,
            l2, h2, -p2,
            l2, -h2, p2,
            l2, -h2, -p2,
            -l2, h2, p2,
            -l2, h2, -p2,
            -l2, -h2, p2,
            -l2, -h2, -p2,
    };

    m_triangles = {
            0, 1, 3,
            0, 2, 3,
            0, 4, 6,
            0, 6, 2,
            0, 1, 5,
            0, 4, 5,
            7, 6, 4,
            7, 4, 5,
            7, 1, 3,
            7, 1, 5,
            7, 2, 6,
            7, 2, 3
    };
}
