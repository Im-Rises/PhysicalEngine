#ifndef MATRIX33_H
#define MATRIX33_H

#include "Vector3d.h"
#include "Quaternion.h"

class Matrix33 {

private:
    float m_value[9];

public:
    /// <summary>
    /// Matrice avec que des 0
    /// </summary>
    Matrix33();


    /// <summary>
    /// Constructeur de Matrix33 avec un tableau les valeurs sont lignes par lignes: 0-2 ligne 1, 3-5 ligne 2 ,...
    /// </summary>
    /// <param name="values"></param>
    explicit Matrix33(const float values[9]);

    /// <summary>
    /// Constructeur de copie
    /// </summary>
    /// <param name="matrixToCopyFrom"></param>
    Matrix33(const Matrix33 &matrixToCopyFrom);

    /// <summary>
    /// Produit Matricielle
    /// </summary>
    /// <param name="other"></param>
    /// <returns></returns>
    Matrix33 operator*(const Matrix33 &other);

    Matrix33 &operator=(const Matrix33 &other);

    /// <summary>
    /// Produit matricielle
    /// </summary>
    /// <param name="other"></param>
    /// <returns></returns>
    Vector3d operator*(const Vector3d &other);

    /// <summary>
    /// élément ligne i colonne j const
    /// </summary>
    /// <param name="i"></param>
    /// <param name="j"></param>
    /// <returns></returns>
    float operator()(int i, int j) const;

    /// <summary>
    /// Renvoie l'inverse de la matrice const
    /// </summary>
    /// <returns></returns>
    Matrix33 inverse() const;

    /// <summary>
    /// renvoie la transposition de la matrice const
    /// </summary>
    /// <returns></returns>
    Matrix33 transpose() const;

    /// <summary>
    /// inverse la matrice
    /// </summary>
    void inverseMat();

    /// <summary>
    /// transpose la matrice
    /// </summary>
    void transposeMat();

    /// <summary>
    /// Génère la matrice de rotation à partir d'un quaternion
    /// </summary>
    /// <param name="quaternion"></param>
    void setOrientation(const Quaternion &quaternion);

//    float operator[](int i) const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix33 &matrix33);

    ~Matrix33();
};

#endif // !MATRIX33_H
