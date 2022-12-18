#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3d {
public:
    float x, y, z;

    /// Constructeur
    /// Vecteur (x,y,z)
    Vector3d(float xCoord = 0, float yCoord = 0, float zCoord = 0);

    /// Constructeur de copie
    Vector3d(const Vector3d& vec);

    //    Vector3d(Vector3d&& vec) noexcept;

    /// Destructeur
    ~Vector3d();

    // getters
    float getx() const;

    float gety() const;

    float getz() const;

    /// setters
    void setx(float xCoord);

    void sety(float yCoord);

    void setz(float zCoord);

    /// Addition
    Vector3d operator+(const Vector3d& vec) const;

    Vector3d& operator+=(const Vector3d& vec);

    /// Soustraction
    Vector3d operator-(const Vector3d& vec) const;

    Vector3d& operator-=(const Vector3d& vec);

    /// Multiplication par un scalaire
    Vector3d operator*(float scalar) const;

    Vector3d& operator*=(float scalar);

    /// Division par un scalaire
    Vector3d operator/(float scalar) const;

    Vector3d& operator/=(float scalar);

    /// Prend la valeur du vecteur
    Vector3d& operator=(const Vector3d& vec);
    //    Vector3d& operator=(Vector3d&& vec) noexcept;

    /// Test d'�galit�
    bool operator==(const Vector3d& vec) const;

    /// Test de diff�rence
    bool operator!=(const Vector3d& vec) const;

    /// Calcul de la norme
    float norm() const;

    /// Normalisation
    Vector3d normalize() const;

    /// Produit Scalaire
    float dot(const Vector3d& vec) const;

    /// Produit Vectoriel
    Vector3d cross(const Vector3d& vec) const;

    /// Distance entre deux vecteurs
    float distance(const Vector3d& vec) const;

    /// Affichage du vecteur
    friend std::ostream& operator<<(std::ostream& stream, const Vector3d& vec) {
        return stream << "(" << vec.getx() << "," << vec.gety() << "," << vec.getz() << ")";
    }
};

#endif /* VECTOR3D_H */
