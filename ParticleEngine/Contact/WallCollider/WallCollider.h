#ifndef WALL_COLLIDER_H
#define WALL_COLLIDER_H

#include "../../Scene/Components/Component.h"
#include "../../Utility/Vector3d.h"

class WallCollider  : public Component {
private:
	float m_lengthX; 
	float m_heightY;
	float m_widthZ;

public:
	WallCollider(GameObject* gameobject, float lengthX, float heightY,float widthZ);

	void update(float time);

	void drawGui();

	std::string getName() const;

	void setLengthX(float lengthX);
	void setWidthZ(float widthZ);
	void setHeightY(float heightY);
	

	bool isInsideWithOfset(const Vector3d& point, float sizeOffset);
	bool isInside(const Vector3d & point);
	

	Vector3d& getMaxDiagonalPoint();
	Vector3d& getMinDiagonalPoint();
	
};

#endif // !WALL_COLLIDER_H
