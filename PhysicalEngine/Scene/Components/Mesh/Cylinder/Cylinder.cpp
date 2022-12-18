#include "Cylinder.h"
#include "../../../../Utility/Matrix33.h"
#include "../../../../Utility/Vector3d.h"

#define _USE_MATH_DEFINES
#include <math.h>

Cylinder::Cylinder(float radius, float height, int rings) {
    this->radius = radius;
    this->height = height;

    generatePointsNormales(radius, height, rings);
    generateTriangles(radius, height, rings);

    color = glm::vec4(0.0f, 0.5f, 1.0f, 1.0f);
}

// Cylinder::Cylinder(float radius, float height) {
//     this->radius = radius;
//     this->height = height;
//
//     verticesUseIndices = true;
//
//     float r2 = radius / 2;
//     float h2 = height / 2;
//
//     vertices = {
//         r2,
//         h2,
//         0,
//         r2,
//         -h2,
//         0,
//         -r2,
//         h2,
//         0,
//         -r2,
//         -h2,
//         0,
//         0,
//         h2,
//         r2,
//         0,
//         h2,
//         -r2,
//         0,
//         -h2,
//         r2,
//         0,
//         -h2,
//         -r2,
//     };
//
//     auto norm = static_cast<float>(std::sqrt(std::pow(r2, 2) + std::pow(h2, 2)));
//     for (auto& normalized : vertices)
//         normals.push_back(normalized / norm);
//
//     indices = {
//         0, 1, 2,
//         1, 2, 3,
//         0, 1, 4,
//         1, 4, 5,
//         0, 2, 4,
//         2, 4, 6,
//         1, 3, 5,
//         3, 5, 7,
//         2, 3, 6,
//         3, 6, 7,
//         4, 5, 6,
//         5, 6, 7
//     };
// }


Matrix33 Cylinder::getInertiaTensor(float mass) const {
    auto r2 = std::pow(radius, 2);
    auto h2 = std::pow(height, 2);

    float Ixx = (1.0F / 12.0F) * mass * h2 + (1.0F / 4.0F) * mass * r2;
    float Iyy = (1.0F / 2.0F) * mass * r2;
    float Izz = (1.0F / 12.0F) * mass * h2 + (1.0F / 4.0F) * mass * r2;

    float values[9] = { Ixx, 0.0f, 0.0f,
        0.0f, Iyy, 0.0f,
        0.0f, 0.0f, Izz };

    return Matrix33(values);
}
void Cylinder::generatePointsNormales(float radius, float height, int rings) {

    float r2 = radius / 2;
    float h2 = height / 2;

    float step = 2 * M_PI / rings;
    float angle = 0;
    for (int i = 0; i < rings; i++)
    {
        float x = r2 * std::cos(angle);
        float y = r2 * std::sin(angle);
        vertices.push_back(x);
        vertices.push_back(h2);
        vertices.push_back(y);
        vertices.push_back(x);
        vertices.push_back(-h2);
        vertices.push_back(y);
        angle += step;
    }
    for (auto& normalized : vertices)
        normals.push_back(normalized / r2);
}
void Cylinder::generateTriangles(float radius, float height, int rings) {

    for (int i = 0; i < rings; i++)
    {
        int next = (i + 1) % rings;
        indices.push_back(i * 2);
        indices.push_back(i * 2 + 1);
        indices.push_back(next * 2);
        indices.push_back(i * 2 + 1);
        indices.push_back(next * 2 + 1);
        indices.push_back(next * 2);
    }
    for (int i = 0; i < rings; i++)
    {
        int next = (i + 1) % rings;
        indices.push_back(i * 2);
        indices.push_back(i * 2 + 1);
        indices.push_back(rings * 2);
        indices.push_back(i * 2 + 1);
        indices.push_back(next * 2 + 1);
        indices.push_back(rings * 2 + 1);
    }
}
const char* Cylinder::getMeshType() const {
    return MESH_TYPE;
}
