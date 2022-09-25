#ifndef PARTICULE_H
#define PARTICULE_H

#include "../Integrable/Integrable.h"
#include"../Vector3d/Vector3d.h"


class Particule : public Integrable {

private:
    Vector3d m_speed;
    Vector3d m_acceleration;

public:
#pragma region Constructeur


    Particule() : m_speed(0, 0, 0), m_acceleration(0, 0, 0) { m_position=Vector3d(0, 0, 0); };

    /// <summary>
    /// Constructeur de particule
    ///  vitesse et acceleration � 0 par default
    /// </summary>
    /// <param name="x"></param>
    /// <param name="y"></param>
    /// <param name="z"></param>
	Particule(float x, float y, float z) :  m_speed(0, 0, 0), m_acceleration(0, 0, 0) { m_position = Vector3d(x, y, z); };

    /// <summary>
    /// Constructeur de particule
    ///  vitesse et acceleration � 0 par default
    /// </summary>
    /// <param name="pos">: la Position</param>
	Particule(const Vector3d& pos) : m_speed(0, 0, 0), m_acceleration(0, 0, 0) { m_position = pos; };

    /// <summary>
    /// Constructeur de copie de Particule
    /// </summary>
    /// <param name="particule"></param>
    Particule(const Particule &particule);

#pragma endregion
#pragma region Getter Setter


    const Vector3d &getSpeed() const { return m_speed; };

    const Vector3d &getAcceleration() const { return m_acceleration; };

    void setPosition(float x, float y, float z) { m_position = Vector3d(x, y, z); };

    void setPosition(const Vector3d &position) { m_position = position; };

    void setSpeed(float x, float y, float z) { m_speed = Vector3d(x, y, z); };

    void setSpeed(const Vector3d &speed) { m_speed = speed; };

    void setAcceleration(float x, float y, float z) { m_acceleration = Vector3d(x, y, z); };

    void setAcceleration(const Vector3d &acceleration) { m_acceleration = acceleration; };
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
    /// Calcule toutes les variable d�pendante du temps sauf l'acceleration
    /// </summary>
    /// <param name="time"></param>
    void recalculateAll(float time) override;

#pragma endregion

};


#endif
