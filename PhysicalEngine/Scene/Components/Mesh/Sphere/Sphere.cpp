#include "Sphere.h"

#define _USE_MATH_DEFINES

#include <math.h>

void Sphere::generatePointsNormales(float radius, int rings, int sectors) {
    this->radius = radius;
    verticesUseIndices = true;
    float x, y, z, xy;                           // vertex position
    float nx, ny, nz, lengthInv = 1.0f / radius; // vertex normal
    // float s, t;									 // vertex texture Coordonn�es
    auto pi = static_cast<float>(M_PI);
    float sectorStep = 2 * pi / sectors;
    float ringStep = pi / rings;
    float sectorAngle, ringAngle;

    for (int i = 0; i <= rings; ++i)
    {
        ringAngle = pi / 2 - i * ringStep;
        xy = radius * cosf(ringAngle);
        z = radius * sinf(ringAngle);

        // ajoute (sectors+1) par rings
        for (int j = 0; j <= rings; ++j)
        {
            sectorAngle = j * sectorStep;

            // vertex position (x, y, z)
            x = xy * cosf(sectorAngle);
            y = xy * sinf(sectorAngle);
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);

            // vertex normal normalisé (nx, ny, nz)
            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            normals.push_back(nx);
            normals.push_back(ny);
            normals.push_back(nz);

            // coordonn�es du vertex pour les textures  (s, t) entre [0, 1]
            /*
            s = (float)j / sectors;
            t = (float)i / rings;
            texCoords.push_back(s);
            texCoords.push_back(t);
            */
        }
    }
    color = glm::vec4(1.0f, 0.5f, 0.5f, 1.0f);
}

void Sphere::generateTriangles(float radius, int rings, int sectors) {
    this->radius = radius;
    unsigned int k1, k2;
    for (int i = 0; i < rings; ++i)
    {
        k1 = i * (sectors + 1); // d�but du ring actuel
        k2 = k1 + sectors + 1;  // d�but du prochain ring

        for (int j = 0; j < sectors; ++j, ++k1, ++k2)
        {
            // 2 triangles par (secteur,ring) sauf pour le premier et dernier ring
            // k1 => k2 => k1+1
            if (i != 0)
            {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }

            // k1+1 => k2 => k2+1
            if (i != (rings - 1))
            {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }
}

Sphere::Sphere(float radius, int rings, int sectors) {
    generatePointsNormales(radius, rings, sectors);
    generateTriangles(radius, rings, sectors);
}

Matrix33 Sphere::getInertiaTensor(float mass) const {
    auto Ixx = 2.0f / 5.0f * mass * radius * radius;
    auto Iyy = Ixx;
    auto Izz = Ixx;

    float values[9] = { Ixx, 0.0f, 0.0f,
        0.0f, Iyy, 0.0f,
        0.0f, 0.0f, Izz };

    return Matrix33(values);
}
const char* Sphere::getMeshType() const {
    return MESH_TYPE;
}
