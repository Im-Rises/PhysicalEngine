#include "Mesh.h"

const vector<Vector3D>& Mesh::getPoints() {
	return m_points;
}

const vector<int[3]>& Mesh::getTriangles() {
	return m_triangles;
}

const vector<Vector3D>& Mesh::getNormales() {
	return m_normales;
}
const Vector3D& Mesh::getPosition() {
	return m_position ;
}

Mesh& Mesh::translate(const Vector3D& trans) {
	// TODO: insérer une instruction return ici
	m_position = m_position + trans;
	return *this;
}

