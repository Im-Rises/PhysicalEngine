#ifndef PARTICULE_H
#define PARTICULE_H

#include <vector>

#include "../../../../Utility/Vector3d.h"
#include "../PhysicalComponent.h"
#include "../../../../Force/Forces/Gravity.h"

class ParticleForceGenerator;

class Particle : public PhysicalComponent {
private:
    static constexpr const char *COMPONENT_TYPE = PARTICLE_COMPONENT;

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
    std::vector<ParticleForceGenerator *> forceGeneratorsList;

public:
#pragma region Constructeur

    explicit Particle(GameObject *gameObject);

    /// <summary>
    /// Constructeur de particule
    ///  vitesse et acceleration � 0 par default
    /// </summary>
    /// <param name="pos">: la Position</param>
    Particle(GameObject *gameObject, float m);

    /// <summary>
    /// Constructeur de copie de Particle
    /// </summary>
    /// <param name="particle"></param>
    Particle(const Particle &particle);

    ~Particle() override;

#pragma endregion
#pragma region Methode

    void update(float deltaTime) override;

    float distance(const Particle &p);

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
#pragma region Add Delete Get Force

    void addForce(ParticleForceGenerator *forceGenerator);

    void addForceByName(const std::string &forceName);

    template<typename T>
    void addForceByClass(T *&comp) {
        comp = new T(this);
        if (comp != nullptr) {
            forceGeneratorsList.push_back(comp);
        }
    }

    ParticleForceGenerator *getForceByName(const std::string &name) const;

    template<class T>
    void getForceByClass(T *&c) {
        for (auto &force: forceGeneratorsList) {
            if (dynamic_cast<T *>(force) != nullptr) {
                c = dynamic_cast<T *>(force);
            }
        }
    }

    bool hasForce(const std::string &name) const;

    //    void deleteComponentByName(const std::string &name);

    template<class T>
    void deleteForceByClass(T *&comp) {
        for (auto it = forceGeneratorsList.begin(); it != forceGeneratorsList.end(); ++it) {
            if (dynamic_cast<T *>(*it) != nullptr) {
                forceGeneratorsList.erase(it);
                // delete *it;
                return;
            }
        }
    }

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
