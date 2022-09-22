#include "CuboidRectangle.h"

CuboidRectangle::CuboidRectangle(double longueur, double hauteur, double profondeur,const Vector3D& position) {

	m_position = position;
	double l2 = longueur / 2;
	double h2 = hauteur / 2;
	double p2 = profondeur / 2;


	m_points.push_back(Vector3D(l2, h2, p2));
	m_normales.push_back(Vector3D(l2, h2, p2));

	m_points.push_back(Vector3D(l2, h2, -p2));
	m_normales.push_back(Vector3D(l2, h2, -p2));

	m_points.push_back(Vector3D(l2, -h2, p2));
	m_normales.push_back(Vector3D(l2, -h2, p2));

	m_points.push_back(Vector3D(l2, -h2, -p2));
	m_normales.push_back(Vector3D(l2, -h2, -p2));

	m_points.push_back(Vector3D(-l2, h2, p2));
	m_normales.push_back(Vector3D(-l2, h2, p2));

	m_points.push_back(Vector3D(-l2, h2, -p2));
	m_normales.push_back(Vector3D(-l2, h2, -p2));

	m_points.push_back(Vector3D(-l2, -h2, p2));
	m_normales.push_back(Vector3D(-l2, -h2, p2));

	m_points.push_back(Vector3D(-l2, -h2, -p2));
	m_normales.push_back(Vector3D(-l2, -h2, -p2));
	/*
	m_triangles.push_back({ 0,1,3 });
	m_triangles.push_back({ 0,2,3 });
	m_triangles.push_back({ 0,4,6 });
	m_triangles.push_back({ 0,6,2 });
	m_triangles.push_back({ 0,1,5 });
	m_triangles.push_back({ 0,4,5 });
	m_triangles.push_back({ 7,6,4 });
	m_triangles.push_back({ 7,4,5 });
	m_triangles.push_back({ 7,1,3 });
	m_triangles.push_back({ 7,1,5 });
	m_triangles.push_back({ 7,2,6 });
	m_triangles.push_back({ 7,2,3 });*/
}
