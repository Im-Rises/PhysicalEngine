#ifndef TRIANGLE3D_H
#define TRIANGLE3D_H
#include "../../Vector3D/vector3d.h"

class Triangle3D {

	private:
	Vector3D m_p1, m_p2, m_p3;
	

	public:

	Triangle3D();
	Triangle3D(const Vector3D& p1, const Vector3D& p2, const Vector3D& p3);
	
	#pragma region Getter

	const Vector3D& getP1();
	const Vector3D& getP2();
	const Vector3D& getP3();


	#pragma endregion

	#pragma region public Methode

	Triangle3D& translation(const Vector3D& vectorTranslation); 
		
	#pragma endregion


		
};


#endif // !TRIANGLE3D_H
