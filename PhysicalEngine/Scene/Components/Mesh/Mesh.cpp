#include "Mesh.h"

using namespace std;

const vector<float> &Mesh::getPoints() {
    return m_points;
}

const vector<unsigned int> &Mesh::getTriangles() {
    return m_triangles;
}

const vector<float> &Mesh::getNormales() {
    return m_normales;
}

const bool &Mesh::getVerticesUseIndices() const {
    return verticesUseIndices;
}


