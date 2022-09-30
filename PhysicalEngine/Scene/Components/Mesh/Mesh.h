#ifndef MESH_H
#define MESH_H

#include "../../../Vector3d/Vector3d.h"
#include <iostream>
#include <vector>


class Mesh {

protected:
    std::vector<float> m_points;
    std::vector<unsigned int> m_triangles;
    std::vector<float> m_normales;
    bool verticesUseIndices = true;

public:

#pragma region Getter

    const std::vector<float> &getPoints();

    const std::vector<unsigned int> &getTriangles();

    const std::vector<float> &getNormales();

    const bool &getVerticesUseIndices() const;

#pragma endregion

};

#endif // !MESH_H