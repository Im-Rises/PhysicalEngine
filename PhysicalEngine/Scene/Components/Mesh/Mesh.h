#ifndef MESH_H
#define MESH_H

#include "../../../Utility/Matrix33.h"
#include "../../../Utility/Vector3d.h"
#include "../Component.h"
#include "../DefaultComponent.h"
#include "glm/vec4.hpp"
#include <iostream>
#include <vector>

#include <string>

#define MESH_COMPONENT "Mesh"

class Mesh : private DefaultComponent {
private:
    static constexpr const char* COMPONENT_TYPE = MESH_COMPONENT;

private:
    static constexpr const char* MESH_TYPE = MESH_COMPONENT;

public:
    static const char* meshNamesList[3];

protected:
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<float> normals;
    bool verticesUseIndices = true;

    glm::vec4 color = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);

public:
    void drawGui() override;

#pragma region Getter

    const std::vector<float>& getVertices();

    const std::vector<unsigned int>& getIndices();

    const std::vector<float>& getNormals();

    const bool& getVerticesUseIndices() const;

    std::string getName() const override;

    virtual Matrix33 getInertiaTensor(float mass) const = 0;

    glm::vec4 getColor() const;

    void setColor(glm::vec4 color);

    static Mesh* createMesh(const char* meshType);

    virtual const char* getMeshType() const;

#pragma endregion
};

#endif // !MESH_H
