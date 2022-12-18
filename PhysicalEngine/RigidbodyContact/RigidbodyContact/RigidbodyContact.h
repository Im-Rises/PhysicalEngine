#ifndef RIGIDBODYCONTACT_H
#define RIGIDBODYCONTACT_H

#include "../../Scene/Components/PhysicalComponent/Rigidbody/Rigidbody.h"
#include <vector>
class RigidbodyContact {
protected:
    Rigidbody* m_rigidbodies[2];

    //    Vector3d m_contactNormal;

public:
    std::vector<Vector3d> m_points;
    std::vector<float> m_interpenetration;
    Vector3d m_normal;

    RigidbodyContact(Rigidbody* rb1);

    RigidbodyContact(Rigidbody* rb1, Rigidbody* rb2);

    void resolveContact();

private:
    void updateAttributes();

    void resolveSpeed();

    void resolveInterpenetration();


public:
    friend std::ostream& operator<<(std::ostream& stream, const RigidbodyContact contactInfo) {
        Vector3d n = contactInfo.m_normal;
            stream << "  -normal: "
                      << "(" << n.getx() << "," << n.gety() << "," << n.getz() << ")" << std::endl;
            for (int i = 0; i < contactInfo.m_points.size(); i++) {
                Vector3d pContact = contactInfo.m_points[i];
                float interp = contactInfo.m_interpenetration[i];

                stream << "  Point " << (i + 1) << " : "
                          << "(" << pContact.getx() << "," << pContact.gety() << "," << pContact.getz() << ")" << std::endl;
                stream << "  Interpenetration "<< (i+1) <<" : "<< interp << std::endl;
            }
            return stream;
    }
};



#endif // RIGIDBODYCONTACT_H
