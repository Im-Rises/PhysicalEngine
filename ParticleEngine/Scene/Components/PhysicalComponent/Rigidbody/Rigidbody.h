#ifndef INTEGRABLE_H
#define INTEGRABLE_H

#include <vector>
#include "../../../../Utility/Vector3d.h"
#include "../../Component.h"
#include "../PhysicalComponent.h"
#include "../../../../Force/Gravity.h"

class ForceGenerator;

struct ForcePoint {
    ForceGenerator *force;
    Vector3d point;
};

class Rigidbody : public PhysicalComponent {
private:
    static constexpr const char *COMPONENT_TYPE = RIGIDBODY_COMPONENT;

protected:
    float m_angularDamping;
    Vector3d m_torqueAccum;

    Vector3d angularSpeed;
    Vector3d angularAcceleration;

    std::vector<ForcePoint> pointForceGeneratorsList;

public:
    explicit Rigidbody(GameObject *gameObject);

    ~Rigidbody() override;

private:
//    void addForceAtPoint(const Vector3d &force, Vector3d worldPoint);

    void addForceAtBodyPoint(const Vector3d &force, const Vector3d &LocalPoint);

    void calculateAcceleration();

    void calculateSpeed(float time);

    void clearAccumulator();

//    void addForceAtPointToList(ForceGenerator *forceGenerator, const Vector3d &point);

public:
    void update(float time) override;

    void drawGui() override;

    void drawGuiForceGeneratorsAtPoint();

    std::string getName() const override;

    Vector3d getAngularSpeed() const;

    template<class T>
    void deleteForceAtPointByClass(T *&comp) {
        for (auto it = pointForceGeneratorsList.begin(); it != pointForceGeneratorsList.end(); ++it) {
            if (dynamic_cast<T *>(*it->force) != nullptr) {
                pointForceGeneratorsList.erase(it);
                return;
            }
        }
    }

};

#endif // !INTEGRABLE_H
