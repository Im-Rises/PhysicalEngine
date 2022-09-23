#ifndef MESH_H
#define MESH_H

#include "../Vector3D/Vector3d.h"
#include <iostream>
#include <vector>

using namespace std;

class Mesh {

protected:
    vector<float> m_points;
    vector<float> m_triangles;
    vector<float> m_normales;
    Vector3D m_position;

public:

#pragma region Getter

    const vector<float> &getPoints();

    const vector<float> &getTriangles();

    const vector<float> &getNormales();

    const Vector3D &getPosition();

#pragma endregion

};

#endif // !MESH_H
