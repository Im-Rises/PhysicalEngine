#ifndef MATRIX34_H
#define MATRIX34_H


#include "Vector3d.h"
#include "Quaternion.h"
#include "Matrix33.h"
#include "Matrix44.h"

class Matrix34 {

private:
	float m_value[12];

public:

	/// <summary>
	/// Constructeur avec que de 0 dans la matrice
	/// </summary>
	Matrix34();
	/// <summary>
	/// Constructeur de Matrix Ligne par ligne (0-3) ligne 1 ,(4-7) ligne 2 ...) 
	/// </summary>
	/// <param name="values"></param>
	Matrix34(float values[12]);

	/// <summary>
	/// Extrait la matrice 33 en haut à gauche de la matrice de transformation affine soit la matrice de rotation
	/// </summary>
	/// <returns></returns>
	Matrix33& extractMatrix33() const;

	/// <summary>
	/// génère la matrice 34 à partir de sa matrice de rotation et son vecteur de translation
	/// </summary>
	/// <param name="rotationMatrix"></param>
	/// <param name="translation"></param>
	void setFromRotationTranslation(Matrix33& const rotationMatrix, Vector3d& const translation);
	/// <summary>
	/// énère la matrice 34 à partir de sa matrice de rotation et son vecteur de translation
	/// </summary>
	/// <param name="rotationMatrix"></param>
	/// <param name="translation"></param>
	/// <returns></returns>
	Matrix34& matrix34FromRotationTranslation(Matrix33& const rotationMatrix, Vector3d& const translation) const;

	/// <summary>
	/// Produit Matriciel
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Matrix34 operator*(const Matrix34& other) const;

	/// <summary>
	/// inverse de la Matrice const 
	/// </summary>
	/// <returns></returns>
	Matrix34 inverse() const;

	/// <summary>
	/// inverse la matrice
	/// </summary>
	void inverseMat();
	/// <summary>
	/// Transforme une matrice 44 de transformation affine en matrix 3 4 (const)
	/// </summary>
	/// <param name="mat44"></param>
	/// <returns></returns>
	Matrix34& transformationAffineMatrixToMatrix34(Matrix44 & const mat44) const;

	/// <summary>
	/// Genere la matrix 44 de transformation affine à partir de *this
	/// </summary>
	/// <returns></returns>
	Matrix44& transformationAffineMatrix() const;
	/// <summary>
	/// Génère la matrice de transformation avec une orientation et une position
	/// </summary>
	/// <param name="quaternion"></param>
	/// <param name="vec"></param>
	void setOrientationAndPosition(Quaternion& const quaternion,Vector3d & const translation);


	/// <summary>
	/// Effectue un changement de base d'un point suivant la matrice de Transformation this
	/// </summary>
	/// <param name="vec"></param>
	/// <returns></returns>
	Vector3d TransformPosition(const Vector3d vec) const;
	/// <summary>
	/// Effectue un changement de base d'un vecteur suivant la matrice de Transformation this en ignorant la translation
	/// </summary>
	/// <param name="vec"></param>
	/// <returns></returns>
	Vector3d TransformDirection(const Vector3d vec) const;

	
	~Matrix34();
};


#endif // !1
