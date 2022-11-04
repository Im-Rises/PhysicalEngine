#ifndef INTEGRABLE_H
#define INTEGRABLE_H

#include "../../../../Utility/Vector3d.h"
#include "../../Component.h"
#include "../PhysicalComponent.h"
#include "../../../../Utility/Quaternion.h"
#include "../../../../Utility/Matrix33.h"
#include "../../../../Utility/Matrix34.h"

class Rigidbody : public PhysicalComponent {
private:
    static constexpr const char *COMPONENT_TYPE = RIGIDBODY_COMPONENT;

protected:
    float m_mass;
    Vector3d m_speed;
    Vector3d m_acceleration;
    Vector3d m_rotation;
    Matrix34 m_transformMatrix;
    Quaternion m_orientation;    
    Vector3d m_angularSpeed;
    Vector3d m_angularAcceleration;
    Vector3d m_forceAccum;
    Vector3d m_torqueAccum;
//    float m_damping;
//    float m_inverseMass;
//    float m_inverseInertiaTensor;
//    float m_gravity;
//    float m_friction;
//    float m_restitution;
//    bool isKinematic = false;

public:
    explicit Rigidbody(GameObject *gameObject);

    Rigidbody(GameObject* gameObject, float m);

    Rigidbody(const Rigidbody& rigidbody);

    ~Rigidbody() override;

    void update(float deltaTime) override;

    /// <summary>
    /// Calcule la nouvelle vitesse � partir de l'acc�l�ration de la particule
    /// et du temps en arguement
    /// </summary>
    /// <param name="time"></param>
    void calculateSpeed(float time);

    /// <summary>
    /// Calcule la nouvelle accélération � partir de la deuxième loi de Newton
    /// </summary>
    /// <param name="time"></param>
    void calculateAcceleration();

    void calculateAngularSpeed(float time);

    void calculateAngularAcceleration();

    void calculateOrientation(float deltaTime);

    void calculateDerivedData();

    void addForce(const Vector3d& force);

    void addForceAtPoint(const Vector3d& force, const Vector3d worldPoint);

    void addForceAtBodyPoint(const Vector3d& force, const Vector3d& LocalPoint);

    bool hasForce(const std::string& name) const;

    void ClearAccumulator();

    Vector3d getPosition() const;

    const Vector3d& getSpeed() const;

    const Vector3d& getAcceleration() const;

    void setPosition(float x, float y, float z);

    void setPosition(const Vector3d& position);

    void setSpeed(float x, float y, float z);

    void setSpeed(const Vector3d& s);

    void setAcceleration(float x, float y, float z);

    void setAcceleration(const Vector3d& acceleration);

    float getMass() const;

    const Vector3d& getForceAcc() const;

    void setForceAcc(const Vector3d& force);

};

#endif // !INTEGRABLE_H
