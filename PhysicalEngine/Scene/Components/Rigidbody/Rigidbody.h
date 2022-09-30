#ifndef INTEGRABLE_H
#define INTEGRABLE_H

#include "../../../Vector3d/Vector3d.h"
#include "../Component.h"

class Rigidbody {

protected:
    Vector3d m_position;

public:
    const Vector3d &getPosition() const { return m_position; };

    virtual void recalculateAll(float time) {};
};

#endif // !INTEGRABLE_H