#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>
#include <iostream>

class Vector3D {
private:
    float m_x, m_y, m_z;

public:
    /// Constructeur par d�faut
    /// Vecteur z�ro (0,0,0)
    Vector3D();

    /// Constructeur
    /// Vecteur (x,y,z)
    Vector3D(float xcoord, float ycoord, float zcoord);

    ///Constructeur de copie
    Vector3D(const Vector3D &v);

    ///Destructeur
    ~Vector3D();

    //getters
    float getx() const;

    float gety() const;

    float getz() const;

    ///setters
    void setx(float xcoord);

    void sety(float ycoord);

    void setz(float zcoord);

    ///Addition
    Vector3D operator+(const Vector3D &vec);

    Vector3D &operator+=(const Vector3D &vec);

    ///Soustraction
    Vector3D operator-(const Vector3D &vec);

    Vector3D &operator-=(const Vector3D &vec);

    ///Multiplication par un scalaire
    Vector3D operator*(float s);

    Vector3D &operator*=(float s);

    ///Prend la valeur du vecteur
    Vector3D operator=(const Vector3D &vec);

    ///Test d'�galit�
    bool operator==(const Vector3D &vec);

    ///Calcul de la norme
    float norm();

    ///Normalisation
    Vector3D normalize();

    ///Produit Scalaire
    float dot(const Vector3D &vec);

    ///Produit Vectoriel
    Vector3D cross(const Vector3D &vec);

    ///Distance entre deux vecteurs
    float distance(const Vector3D &vec);

    ///Affichage du vecteur
    friend std::ostream &operator<<(std::ostream &os, Vector3D vec) {
        return os << "(" << vec.getx() << "," << vec.gety() << "," << vec.getz() << ")";
    }
};

#endif /* VECTOR3D_H */
