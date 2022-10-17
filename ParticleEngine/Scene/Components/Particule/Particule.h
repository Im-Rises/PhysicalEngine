#ifndef PARTICULE_H
#define PARTICULE_H

#include "../Rigidbody/Rigidbody.h"
#include"../../../Vector3d/Vector3d.h"


class Particule : public Rigidbody {
private:
//    Vector3d m_position;
    Vector3d m_speed;
    Vector3d m_acceleration;
    float m_mass;
    Vector3d m_netForce;
    float m_friction;

public:
#pragma region Constructeur

    Particule(GameObject *gameObject);

    /// <summary>
    /// Constructeur de particule
    ///  vitesse et acceleration � 0 par default
    /// </summary>
    /// <param name="x"></param>
    /// <param name="y"></param>
    /// <param name="z"></param>
    /// <param name="m"></param>
//    Particule(float x, float y, float z, float m);

    /// <summary>
    /// Constructeur de particule
    ///  vitesse et acceleration � 0 par default
    /// </summary>
    /// <param name="pos">: la Position</param>
    Particule(GameObject *gameObject, const Vector3d &pos, float m);

    /// <summary>
    /// Constructeur de copie de Particule
    /// </summary>
    /// <param name="particule"></param>
    Particule(const Particule &particule);

#pragma endregion
#pragma region Getter Setter

    const Vector3d &getPosition() const;

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

    float getFriction() const;

    void setNetForce(Vector3d force);

    void setFriction(float friction);

#pragma endregion

#pragma region Methode


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
    void calculateAcceleration(float time);

    /// <summary>
    /// Calcule toutes les variable d�pendante du temps sauf l'acceleration
    /// </summary>
    /// <param name="time"></param>
//    void recalculateAll(float time);

    void update(float time) override;

    void drawGui() override;

    /// <summary>
    /// Calcule la distance entre deux particules
    /// </summary>
    /// <param name="p"></param>
    float distance(const Particule &p);

#pragma endregion

};


#endif
