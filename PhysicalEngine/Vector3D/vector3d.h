#ifndef VECTOR3D_H 
#define VECTOR3D_H

#include<math.h>
#include<iostream>

class Vector3D {
private:
	double m_x, m_y, m_z;

public:
	/// Constructeur par défaut
	/// Vecteur zéro (0,0,0)
	Vector3D();

	/// Constructeur
	/// Vecteur (x,y,z)
	Vector3D(double xcoord, double ycoord, double zcoord);

	///Constructeur de copie
	Vector3D(const Vector3D& v);

	///Destructeur
	~Vector3D();

	///setters
	void setx(double xcoord);
	void sety(double ycoord);
	void setz(double zcoord);

	///getters
	double getx();
	double gety();
	double getz();

	///Addition
	Vector3D operator+(const Vector3D& vec);
	Vector3D& operator+=(const Vector3D& vec); 

	///Soustraction
	Vector3D operator-(const Vector3D& vec);
	Vector3D& operator-=(const Vector3D& vec);

	///Multiplication par un scalaire
	Vector3D operator*(double s); 
	Vector3D& operator*=(double s); 

	///Prend la valeur du vecteur
	Vector3D operator=(const Vector3D& vec);

	///Calcul de la norme
	double norm();

	///Normalisation
	Vector3D normalize();

	///Produit Scalaire
	double dot(const Vector3D& vec);

	///Produit Vectoriel
	Vector3D cross(const Vector3D& vec);

	///Affichage du vecteur
	void dispVector();
};

#endif /* VECTOR3D_H */
