#ifndef PHYSICALCOMPONENT_H
#define PHYSICALCOMPONENT_H

#include <vector>
#include "../../../Utility/Vector3d.h"
#include "../Component.h"
#include "../../../Force/Gravity.h"
#include "../../../Force/ForceGenerator.h"

class PhysicalComponent : public virtual Component {
protected:
    PhysicalComponent() = default;

    bool isKinematic = true;

    Vector3d m_forceAccum;
    float m_mass;

    // Velocity and acceleration
    Vector3d linearSpeed;
    Vector3d linearAcceleration;

    // Forces
    Gravity gravity;
    std::vector<ForceGenerator *> forceGeneratorsList;

private:
    static constexpr const char *COMPONENT_TYPE = "PhysicalComponent";

public:
    void update(float time) override = 0;

    float distance(const PhysicalComponent &p);

    Vector3d getPosition() const;

    void setPosition(const Vector3d &position);

    const Vector3d &getNetForce() const;

    void setNetForce(const Vector3d &force);

    float getMass() const;

    Vector3d getLinearSpeed() const;

    void setLinearSpeed(const Vector3d &linearSpeed);

    void drawGui() override;

    void drawGuiForceGenerators();

    std::string getName() const override = 0;


    void addForce(ForceGenerator *forceGenerator);

    void addForceByName(const std::string &forceName);

    template<typename T>
    void addForceByClass(T *&comp) {
        comp = new T(this);
        if (comp != nullptr) {
            forceGeneratorsList.push_back(comp);
        }
    }

    ForceGenerator *getForceByName(const std::string &name) const;

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

};


#endif //PHYSICALCOMPONENT_H
