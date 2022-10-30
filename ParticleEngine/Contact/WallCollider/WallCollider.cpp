#include "WallCollider.h"
#include "../../Scene/GameObject.h"

WallCollider::WallCollider(GameObject* gameobject, float lengthX, float heightY, float widthZ) : Component(gameobject) {
	m_lengthX = lengthX;
	m_widthZ = widthZ;
	m_heightY = heightY;
}

void WallCollider::update(float time) {
}

void WallCollider::drawGui() {
}

std::string WallCollider::getName() const {
	return "Wall Collider";
}

void WallCollider::setLengthX(float lengthX) {
	if (lengthX > 0) {
		m_lengthX = lengthX;
	}
	else {
		std::cout<<"negative lengthX on WallCollider"<<std::endl;
	}
}
void WallCollider::setWidthZ(float widthZ) {
	if (widthZ > 0) {
		m_widthZ = widthZ;
	}
	else {
		std::cout << "negative widthZ on WallCollider" << std::endl;
	}
}

void WallCollider::setHeightY(float heightY) {
	if (heightY > 0) {
		m_heightY = heightY;
	}
	else {
		std::cout << "negative heightY on WallCollider" << std::endl;
	}
}

bool WallCollider::isInsideWithOfset(const Vector3d& point, float sizeOffset) {
	Vector3d lessMaxPoint, moreMinPoint;
	lessMaxPoint = getMaxDiagonalPoint()-point;
	moreMinPoint = point - getMinDiagonalPoint();
	bool isLessThanMax = lessMaxPoint.getx() > sizeOffset && lessMaxPoint.gety() > sizeOffset && lessMaxPoint.getz() >sizeOffset;
	bool isMoreThanMin = moreMinPoint.getx() > sizeOffset && moreMinPoint.gety() > sizeOffset && moreMinPoint.getz() > sizeOffset;
	return isMoreThanMin && isLessThanMax;
}

bool WallCollider::isInside(const Vector3d& point) {
	return isInsideWithOfset(point, 0);
	
}

Vector3d& WallCollider::getMaxDiagonalPoint() {
	Vector3d maxDiagonalPoint = m_gameObject->transform.getPosition() + Vector3d(m_lengthX / 2, m_heightY / 2,m_widthZ/2);
	return maxDiagonalPoint;
}

Vector3d& WallCollider::getMinDiagonalPoint() {
	Vector3d minDiagonalPoint = m_gameObject->transform.getPosition() - Vector3d(m_lengthX / 2, m_heightY / 2, m_widthZ / 2);
	return minDiagonalPoint;
}
