#ifndef SPHERECOLLIDER_H
#define SPHERECOLLIDER_H

#include "../Collider.h"

class SphereCollider : public Collider {
private:
	static constexpr const char* COMPONENT_TYPE = "SPHERE_COLLIDER_COMPONENT";
	float m_radius;

public:
	SphereCollider(GameObject* gameObject, float radius);

	void update(float time) override;

	void drawGui() override;

	std::string getName() const override;

	float getRadius() const;

	void setRadius(float radius);
};



#endif // SPHERECOLLIDER_H
