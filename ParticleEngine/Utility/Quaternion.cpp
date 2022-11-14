#include "Quaternion.h"

Quaternion::Quaternion()
{
	m_value[0] = 0;
	m_value[1] = 0;
	m_value[2] = 0;
	m_value[3] = 0;
}

/// <summary>
/// Constructeur de copy
/// </summary>
/// <param name="quaternion"></param>
Quaternion::Quaternion(const Quaternion& quaternion)
{
	for (int i = 0; i < 4; i++) {
		m_value[i] = quaternion.m_value[i];
	}
}
/// <summary>
/// Constructeur avec une vecteur : {0,Vector3d}
/// </summary>
/// <param name="vec"></param>
Quaternion::Quaternion(const Vector3d& vec): Quaternion(0,vec.x,vec.y,vec.z)
{
}
/// <summary>
/// norm d'un quaternion
/// </summary>
/// <returns></returns>
float Quaternion::norm()
{
	float sumSquar=0;
	for (int i = 0; i < 4; i++) {
		sumSquar += m_value[i] * m_value[i];
	}
	return sqrt(sumSquar);
}
/// <summary>
/// normalize le quaternion
/// </summary>
void Quaternion::normalize()
{
	float n = norm();
	if (n != 0)
	{
		m_value[0] /= n;
		m_value[1] /= n;
		m_value[2] /= n;
		m_value[3] /= n;
	}
	else
	{
	}
}
/// <summary>
/// Constructeur avec les 4 composantes
/// </summary>
/// <param name="w"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
Quaternion::Quaternion(float w,float x, float y, float z)
{
	m_value[0] = w;
	m_value[1] = x;
	m_value[2] = y;
	m_value[3] = z;
}
/// <summary>
/// Multiplication de quaternion selon le produit hamiltonien
/// <param name="quaternion"></param>
/// <returns></returns>
Quaternion Quaternion::operator*=(const Quaternion& quaternion)
{
	float w, x, y, z;
	float w1 = m_value[0], x1 = m_value[1], y1 = m_value[2], z1 = m_value[3];
	float w2 = quaternion.m_value[0], x2 = quaternion.m_value[1], y2 = quaternion.m_value[2], z2 = quaternion.m_value[3];
	w = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2;
	x = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2;
	y = w1 * y2 + y1 * w2 + z1 * x2 - x1 * z2;
	z = w1 * z2 + z1 * w2 + x1 * y2 - y1 * x2;
	m_value[0] = w;
	m_value[1] = x;
	m_value[2] = y;
	m_value[3] = z;
	return *this;
}


/// <summary>
/// Multiplication de quaternion selon le produit hamiltonien methode constante
/// </summary>
/// <param name="quaternion"></param>
/// <returns></returns>
Quaternion & Quaternion::operator*(const Quaternion& quaternion)
{
	Quaternion res(*this);
	res *= quaternion;
	return res;
}
/// <summary>
/// mutliplication par un float
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
Quaternion& Quaternion::operator*(float n)
{
	return Quaternion(n * m_value[0], n * m_value[1], n * m_value[2], n * m_value[3]);
}

/// <summary>
/// somme de quaternion
/// </summary>
/// <param name="quaternion"></param>
/// <returns></returns>
Quaternion& Quaternion::operator+(const Quaternion& quaternion)
{
	return Quaternion(m_value[0] + quaternion.m_value[0], m_value[1] + quaternion.m_value[1],
		m_value[2] + quaternion.m_value[2], m_value[3] + quaternion.m_value[3]);
}
/// <summary>
/// Geteur des composantes de quaternion
/// </summary>
/// <param name="i"></param>
/// <returns></returns>
float Quaternion::operator[](int i) const
{
	return m_value[i];
}
/// <summary>
/// Seteur d'une composante de queternion
/// </summary>
/// <param name="i"></param>
void Quaternion::set(int i)
{
	m_value[i] = i;
	normalize();
}

/// <summary>
/// Effectue la rotation d'un quaternion en suivant un vecteur de rotation
/// </summary>
/// <param name="vector"></param>
void Quaternion::RotateByVector(const Vector3d& vector)
{
	*this *= Quaternion(vector);
}


/// <summary>
/// Effectue la rotation du quaternion selon les vitesse angulaire correspondant au 3 degrés de liberté définit dans le Vectord3D 
/// pendant un temps time
/// </summary>
/// <param name="vector"></param>
/// <param name="time"></param>
void Quaternion::UpdateByAngularSpeed(const Vector3d& vector, float time)
{
	Quaternion updateQuaternion = *this + Quaternion(vector) * *this * (time / 2);
	for (int i = 0; i < 4; i++) {
		m_value[i] = updateQuaternion[i];
	}

}
/// <summary>
/// destructeur de Quaternion
/// </summary>
Quaternion::~Quaternion()
{
	delete[] m_value;
}
