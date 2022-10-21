#ifndef PARTICULE_H
#define PARTICULE_H

#include <vector>

#include"../../../../Utility/Vector3d.h"
#include "../PhysicalComponent.h"
#include "../../../../Force/Gravity.h"

class ForceGenerator;

class Particle : public Component {
private:
    static constexpr const char *COMPONENT_TYPE = "Particle";

private:
    // State
    float mass;
    bool isKinematic = true;
//    float m_friction;

    // Resulting force
    Vector3d netForce;

    // Velocity and acceleration
    Vector3d speed;
    Vector3d acceleration;

    // Forces
    Gravity gravity;
    std::vector<ForceGenerator *> forceGeneratorsList;

public:
#pragma region Constructeur

    explicit Particle(GameObject *gameObject);

    /// <summary>
    /// Constructeur de particule
    ///  vitesse et acceleration � 0 par default
    /// </summary>
    /// <param name="pos">: la Position</param>
    Particle(GameObject *gameObject, const Vector3d &pos, float m);

    /// <summary>
    /// Constructeur de copie de Particle
    /// </summary>
    /// <param name="particle"></param>
    Particle(const Particle &particle);

#pragma endregion
#pragma region Methode

    void update(float deltaTime) override;

    float distance(const Particle &p);

    /// <summary>
    /// Calcule la nouvelle position � partir de la vitesse de la particule
    /// et du temps en argument
    /// </summary>
    /// <param name="time"></param>
    void calculatePosition(float time);

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

    void drawGui() override;

#pragma endregion
#pragma region Getter Setter

    std::string getName() const override;

    Vector3d getPosition() const;

    const Vector3d &getSpeed() const;

    const Vector3d &getAcceleration() const;

    void setPosition(float x, float y, float z);

    void setPosition(const Vector3d &position);

    void setSpeed(float x, float y, float z);

    void setSpeed(const Vector3d &speed);

    void setAcceleration(float x, float y, float z);

    void setAcceleration(const Vector3d &acceleration);

    float getMass() const;

    const Vector3d &getNetForce() const;

    void setNetForce(const Vector3d &force);

#pragma endregion

};

#endif
