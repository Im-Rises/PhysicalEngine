#ifndef RIGIDBODYCUBOIDCUBOIDCONTACT_H
#define RIGIDBODYCUBOIDCUBOIDCONTACT_H
#include "../RigidbodyContact.h"
#include <vector>


class RigidbodyCuboidCuboidContact : RigidbodyContact{

	public: 
		std::vector<Vector3d> points;
        std::vector<float> Interpenetration;
        Vector3d normal;

		RigidbodyCuboidCuboidContact(Rigidbody* rb1, Rigidbody* rb2) : RigidbodyContact(rb1,rb2) {

		}
		

		
};



#endif // RIGIDBODYCUBOIDCUBOIDCONTACT_H
