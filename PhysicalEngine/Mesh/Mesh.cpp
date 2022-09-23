#include "Mesh.h"

const vector<float> &Mesh::getPoints() {
    return m_points;
}

const vector<float> &Mesh::getTriangles() {
    return m_triangles;
}

const vector<float> &Mesh::getNormales() {
    return m_normales;
}

const Vector3D &Mesh::getPosition() {
    return m_position;
}

