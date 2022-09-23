#ifndef MESH_H
#define MESH_H

#include "../Vector3D/Vector3d.h"
#include <iostream>
#include <vector>

using namespace std;

class Mesh {

protected:
    vector<Vector3D> m_points;
    vector<int[3]> m_triangles;
    vector<Vector3D> m_normales;
    Vector3D m_position;


public:

#pragma region Getter

    const vector<Vector3D> &getPoints();

    const vector<int[3]> &getTriangles();

    const vector<Vector3D> &getNormales();

    const Vector3D &getPosition();

#pragma endregion

#pragma region Translate

    Mesh &translate(const Vector3D &trans);

#pragma endregion


};

#endif // !MESH_H
