#ifndef INTEGRABLE_H
#define INTEGRABLE_H

#include "../../../Vector3d/Vector3d.h"
#include "../Component.h"

class Rigidbody : public Component {

protected:
    Vector3d m_position;

public:
    Rigidbody();

    Rigidbody(std::string name);

    void recalculateAll(float time);

    void update() override;

    void drawGui() override;

    const Vector3d &getPosition() const;
};

#endif // !INTEGRABLE_H
