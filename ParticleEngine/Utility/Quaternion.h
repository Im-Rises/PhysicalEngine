#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3d.h"
#include <cmath>

class Quaternion {

private:
    float m_value[4];

public:
    /// <summary>
    /// Constructeur avec uniquement des 0
    /// </summary>
    Quaternion();

    /// <summary>
    /// Constructeur de copy
    /// </summary>
    /// <param name="quaternion"></param>
    Quaternion(const Quaternion& quaternion);

    /// <summary>
    /// Constructeur avec une vecteur : {0,Vector3d}
    /// </summary>
    /// <param name="vec"></param>
    Quaternion(const Vector3d& vec);

    /// <summary>
    /// norm d'un quaternion
    /// </summary>
    /// <returns></returns>
    float norm();

    /// <summary>
    /// normalize le quaternion
    /// </summary>
    void normalize();

    /// <summary>
    /// Constructeur avec les 4 composantes
    /// </summary>
    /// <param name="w"></param>
    /// <param name="x"></param>
    /// <param name="y"></param>
    /// <param name="z"></param>
    Quaternion(float w, float x, float y, float z);

    Quaternion& operator=(const Quaternion& quaternion);

    /// <summary>
    /// Multiplication de quaternion selon le produit hamiltonien
    /// <param name="quaternion"></param>
    /// <returns></returns>
    Quaternion& operator*=(const Quaternion& quaternion);

    /// <summary>
    /// Multiplication de quaternion selon le produit hamiltonien methode constante
    /// </summary>
    /// <param name="quaternion"></param>
    /// <returns></returns>
    Quaternion operator*(const Quaternion& quaternion);

    /// <summary>
    /// mutliplication par un float
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
    Quaternion operator*(float n);

    /// <summary>
    /// somme de quaternion
    /// </summary>
    /// <param name="quaternion"></param>
    /// <returns></returns>
    Quaternion operator+(const Quaternion& quaternion);

    Quaternion operator+=(const Quaternion& quaternion);

    /// <summary>
    /// Geteur des composantes de quaternion
    /// </summary>
    /// <param name="i"></param>
    /// <returns></returns>
    float operator[](int i) const;

    /// <summary>
    /// Seteur d'une composante de queternion
    /// </summary>
    /// <param name="i"></param>
    void set(int i);

    /// <summary>
    /// Effectue la rotation d'un quaternion en suivant un vecteur de rotation
    /// </summary>
    /// <param name="vector"></param>
    void rotateByVector(const Vector3d& vector);

    /// <summary>
    /// Effectue la rotation du quaternion selon les vitesse angulaire correspondant au 3 degrés de liberté définit dans le Vectord3D
    /// pendant un temps time
    /// </summary>
    /// <param name="vector"></param>
    /// <param name="time"></param>
    void updateByAngularSpeed(const Vector3d& vector, float time);

    friend std::ostream& operator<<(std::ostream& stream, const Quaternion& quaternion) {
        stream << "Quaternion : " << quaternion.m_value[0] << " " << quaternion.m_value[1] << " "
               << quaternion.m_value[2] << " " << quaternion.m_value[3]
               << std::endl;
        return stream;
    }


    ~Quaternion();

    float* getValues();
};

#endif // !QUATERNION_H
