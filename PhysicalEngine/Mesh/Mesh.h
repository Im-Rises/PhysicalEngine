#ifndef MESH_H
#define MESH_H

#include "../Vector3D/Vector3d.h"
#include <iostream>
#include <vector>


class Mesh {

protected:
    std::vector<float> m_points;
    std::vector<float> m_triangles;
    std::vector<float> m_normales;

public:

#pragma region Getter

    const std::vector<float> &getPoints();

    const std::vector<float> &getTriangles();

    const std::vector<float> &getNormales();

#pragma endregion

};

#endif // !MESH_H
