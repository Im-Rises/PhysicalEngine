#include "CuboidRectangle.h"

#include <cmath>

CuboidRectangle::CuboidRectangle(float width, float height, float length) {
    this->width = width;
    this->height = height;
    this->length = length;

    verticesUseIndices = true;

    float l2 = width / 2;
    float h2 = height / 2;
    float p2 = length / 2;


    vertices = {
        l2,
        h2,
        p2,
        l2,
        h2,
        -p2,
        l2,
        -h2,
        p2,
        l2,
        -h2,
        -p2,
        -l2,
        h2,
        p2,
        -l2,
        h2,
        -p2,
        -l2,
        -h2,
        p2,
        -l2,
        -h2,
        -p2,
    };

    auto norm = static_cast<float>(std::sqrt(std::pow(l2, 2) + std::pow(h2, 2) + std::pow(p2, 2)));
    for (auto& normalized : vertices)
        normals.push_back(normalized / norm);

    indices = {
        0, 1, 3,
        0, 2, 3,
        0, 4, 6,
        0, 6, 2,
        0, 1, 5,
        0, 4, 5,
        7, 6, 4,
        7, 4, 5,
        7, 1, 3,
        7, 1, 5,
        7, 2, 6,
        7, 2, 3
    };

    color = glm::vec4(0.1f, 0.8f, 0.0f, 1.0f);
}
Matrix33 CuboidRectangle::getInertiaTensor(float mass) const {
    float values[9] = { (1.0f / 12) * mass * (height * height + length * length), 0.0f, 0.0f,
        0.0f, (1.0f / 12) * mass * (width * width + length * length), 0.0f,
        0.0f, 0.0f, (1.0f / 12) * mass * (width * width + height * height) };
    return Matrix33(values);
}
const char* CuboidRectangle::getMeshType() const {
    return MESH_TYPE;
}
