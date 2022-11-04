#ifndef GRAVITY_H
#define GRAVITY_H

#include "RigidbodyForceGenerator.h"
#include "../Utility/Vector3d.h"

class GravityForceGenerator : public RigidbodyForceGenerator 
{
private:
	Vector3d m_gravity;
public:
    explicit GravityForceGenerator(const Vector3d &g = Vector3d(0.0f, -9.81f, 0.0f));
	GravityForceGenerator(const GravityForceGenerator &grav);
	void UpdateForce(Rigibody* rigidBody) override;
};

#endif /* GRAVITYFORCEGENERATOR_H */
