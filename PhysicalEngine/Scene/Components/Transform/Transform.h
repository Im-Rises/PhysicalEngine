#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../../../Utility/Matrix34.h"
#include "../../../Utility/Matrix44.h"
#include "../../../Utility/Quaternion.h"
#include "../../../Utility/Vector3d.h"
#include "../Component.h"
#include "../DefaultComponent.h"
#include <string>

class Transform : private DefaultComponent {
private:
    static constexpr const char *COMPONENT_TYPE = "Transform";

public:
    float positionX, positionY, positionZ;
    float scaleX, scaleY, scaleZ;
    Quaternion rotation;

public:
    Transform();

    ~Transform();

public:
    void drawGui() override;

    void setPosition(float x, float y, float z);

    void setPosition(const Vector3d &position);

    void setRotation(const Quaternion &rotation);

    [[nodiscard]] auto getRotation() const -> Quaternion;

    [[nodiscard]] auto getPosition() const -> Vector3d;

    [[nodiscard]] auto getMatrix() const -> Matrix34;

    [[nodiscard]] auto getName() const -> std::string override;

    //    virtual Vector3d getForward() const =0;
};


#endif // TRANSFORM_H
