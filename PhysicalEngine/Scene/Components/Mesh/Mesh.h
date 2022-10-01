#ifndef MESH_H
#define MESH_H

#include "../../../Vector3d/Vector3d.h"
#include <iostream>
#include <vector>

#include <string>

class Mesh {
private:
    std::string name = "Mesh";

protected:
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<float> normals;
    bool verticesUseIndices = true;

public:
    void drawGui();

#pragma region Getter

    const std::vector<float> &getVertices();

    const std::vector<unsigned int> &getIndices();

    const std::vector<float> &getNormals();

    const bool &getVerticesUseIndices() const;

    const std::string &getName() const;

#pragma endregion

};

#endif // !MESH_H
