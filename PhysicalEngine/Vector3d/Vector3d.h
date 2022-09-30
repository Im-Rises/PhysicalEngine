#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>
#include <iostream>

class Vector3d {
public:
    float m_x, m_y, m_z;

public:
    /// Constructeur par d�faut
    /// Vecteur z�ro (0,0,0)
    Vector3d();

    /// Constructeur
    /// Vecteur (x,y,z)
    Vector3d(float xcoord, float ycoord, float zcoord);

    ///Constructeur de copie
    Vector3d(const Vector3d &v);

    ///Destructeur
    ~Vector3d();

    //getters
    float getx() const;

    float gety() const;

    float getz() const;

    ///setters
    void setx(float xcoord);

    void sety(float ycoord);

    void setz(float zcoord);

    ///Addition
    Vector3d operator+(const Vector3d &vec);

    Vector3d &operator+=(const Vector3d &vec);

    ///Soustraction
    Vector3d operator-(const Vector3d &vec);

    Vector3d &operator-=(const Vector3d &vec);

    ///Multiplication par un scalaire
    Vector3d operator*(float s);

    Vector3d &operator*=(float s);

    ///Prend la valeur du vecteur
    Vector3d operator=(const Vector3d &vec);

    ///Test d'�galit�
    bool operator==(const Vector3d &vec);

    ///Calcul de la norme
    float norm();

    ///Normalisation
    Vector3d normalize();

    ///Produit Scalaire
    float dot(const Vector3d &vec);

    ///Produit Vectoriel
    Vector3d cross(const Vector3d &vec);

    ///Distance entre deux vecteurs
    float distance(const Vector3d &vec);

    ///Affichage du vecteur
    friend std::ostream &operator<<(std::ostream &os, Vector3d vec) {
        return os << "(" << vec.getx() << "," << vec.gety() << "," << vec.getz() << ")";
    }
};

#endif /* VECTOR3D_H */
