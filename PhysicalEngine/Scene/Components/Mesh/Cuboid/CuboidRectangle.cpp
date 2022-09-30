#include "CuboidRectangle.h"

#include <cmath>

CuboidRectangle::CuboidRectangle(float longueur, float hauteur, float profondeur) {
    verticesUseIndices = true;
    
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

    auto norm = static_cast<float>(std::sqrt(std::pow(l2, 2) + std::pow(h2, 2) + std::pow(p2, 2)));
    for (auto &normalized: m_points)
        m_normales.push_back(normalized / norm);

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
