#include "Octree.h"

Octree::Octree(RigidbodyContactGeneratorRegistry ContactRegistry) {
    contactRegistry = ContactRegistry;
    root = NULL;
}
