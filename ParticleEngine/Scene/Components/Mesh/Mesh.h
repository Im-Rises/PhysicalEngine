#ifndef MESH_H
#define MESH_H

#include "../../../Utility/Vector3d.h"
#include "../Component.h"
#include "../DefaultComponent.h"
#include <iostream>
#include <vector>

#include <string>

class Mesh : private DefaultComponent {
private:
    static constexpr const char *COMPONENT_TYPE = "Mesh";

protected:
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<float> normals;
    bool verticesUseIndices = true;

public:
    void drawGui() override;

#pragma region Getter

    const std::vector<float> &getVertices();

    const std::vector<unsigned int> &getIndices();

    const std::vector<float> &getNormals();

    const bool &getVerticesUseIndices() const;

    std::string getName() const override;

#pragma endregion

};

#endif // !MESH_H
