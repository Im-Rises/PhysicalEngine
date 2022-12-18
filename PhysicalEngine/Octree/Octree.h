#ifndef OCTREE_H
#define OCTREE_H

#include "../RigidbodyContact/RigidbodyContactGeneratorRegistry.h"
#include "../Scene/Components/Collider/RigidbodyCollider/RigidbodyPrimitiveCollider.h"
#include "../Utility/Vector3d.h"

struct Object {
    Vector3d center;     // Center point for object
    float radius;        // Radius of object bounding sphere
    Object* pNextObject; // Pointer to next object when linked into list
    RigidbodyPrimitiveCollider* Collider;
};

// Octree node data structure
struct Node {
    Vector3d center;            // Center point of octree node
    float halfWidth;            // Half the width of the node volume
    Node* pChild[8];            // Pointers to the eight children nodes
    Object* pObjList = nullptr; // Linked list of objects contained at this node
};

class Octree {

private:
    RigidbodyContactGeneratorRegistry contactRegistry;

public:
    Octree(RigidbodyContactGeneratorRegistry ContactRegistry);

    Node* root;

    // Preallocates an octree down to a specific depth
    Node* BuildOctree(Vector3d center, float halfWidth, int stopDepth) {
        if (stopDepth < 0)
            return nullptr;
        else
        {
            // Construct and fill in ’root’ of this subtree
            Node* pNode = new Node;
            pNode->center = center;
            pNode->halfWidth = halfWidth;
            pNode->pObjList = nullptr;
            // Recursively construct the eight children of the subtree
            Vector3d offset;
            float step = halfWidth * 0.5f;
            for (int i = 0; i < 8; i++)
            {
                offset.x = ((i & 1) ? step : -step);
                offset.y = ((i & 2) ? step : -step);
                offset.z = ((i & 4) ? step : -step);
                pNode->pChild[i] = BuildOctree(center + offset, step, stopDepth - 1);
            }
            return pNode;
        }
    }


    void CleanOctree(Node* Tree) {
        if (Tree == nullptr)
            return;
        else
        {
            /*
            Object* nextObj = Tree->pObjList;
            while (nextObj != nullptr)
            {
                Object* maj = nextObj->pNextObject;
                delete nextObj;
                nextObj = maj;
            }
            */

            if (Tree->pObjList != nullptr)
            {
                // std::cout << Tree->center << std::endl;
            }
            Tree->pObjList = nullptr;
            for (int i = 0; i < 8; i++)
            {
                CleanOctree(Tree->pChild[i]);
            }
        }
    }

    void InsertObject(Node* pTree, Object* pObject) {
        int index = 0, straddle = 0;
        // Compute the octant number [0..7] the object sphere center is in
        // If straddling any of the dividing x, y, or z planes, exit directly
        for (int i = 0; i < 3; i++)
        {
            float delta = 0;
            if (i == 0)
                delta = pObject->center.getx() - pTree->center.getx();
            if (i == 1)
                delta = pObject->center.gety() - pTree->center.gety();
            if (i == 2)
                delta = pObject->center.getz() - pTree->center.getz();

            if (abs(delta) < pObject->radius || pTree->halfWidth < abs(delta) + pObject->radius)
            {
                straddle = 1;
                break;
            }
            if (delta > 0.0f)
                index |= (1 << i); // ZYX
        }
        if (!straddle && pTree->pChild[index])
        {
            // Fully contained in existing child node; insert in that subtree
            InsertObject(pTree->pChild[index], pObject);
        }
        else
        {
            // Straddling, or no child node to descend into, so
            // link object into linked list at this node
            pObject->pNextObject = pTree->pObjList;
            pTree->pObjList = pObject;
        }
    }

    // Tests all objects that could possibly overlap due to cell ancestry and coexistence
    // in the same cell. Assumes objects exist in a single cell only, and fully inside it
    void TestAllCollisions(Node* pTree) {
        // Keep track of all ancestor object lists in a stack
        const int MAX_DEPTH = 40;
        static Node* ancestorStack[MAX_DEPTH];
        static int depth = 0; // ’Depth == 0’ is invariant over calls
        // Check collision between all objects on this level and all
        // ancestor objects. The current level is included as its own
        // ancestor so all necessary pairwise tests are done
        ancestorStack[depth++] = pTree;
        for (int n = 0; n < depth; n++)
        {
            Object *pA, *pB;
            for (pA = ancestorStack[n]->pObjList; pA; pA = pA->pNextObject)
            {
                for (pB = pTree->pObjList; pB; pB = pB->pNextObject)
                {
                    // Avoid testing both A->B and B->A
                    if (pA == pB)
                        break;
                    // Now perform the collision test between pA and pB in some manner
                    // std::cout << "Potentiel collision" << std::endl;
                    contactRegistry.calculateContact(pA->Collider, pB->Collider);
                }
            }
        }
        // Recursively visit all existing children
        for (int i = 0; i < 8; i++)
            if (pTree->pChild[i])
                TestAllCollisions(pTree->pChild[i]);
        // Remove current node from ancestor stack before returning
        depth--;
    }
};





#endif /* OCTREE_H */
