#include "Mesh.h"

#include "Cuboid/CuboidRectangle.h"
#include "Cylinder/Cylinder.h"
#include "Sphere/Sphere.h"
#include "imgui/imgui.h"

#include "Cuboid/CuboidRectangle.h"
#include "Cylinder/Cylinder.h"
#include "Sphere/Sphere.h"

using namespace std;

const char* Mesh::meshNamesList[3] = { MESHTYPE_CYLINDER, MESHTYPE_SPHERE, MESHTYPE_CUBOID_RECTANGLE };

void Mesh::drawGui() {
    ImGui::Text("Mesh type: %s", getMeshType());
    ImGui::Text(verticesUseIndices ? "Vertices use indices" : "Vertices don't use indices");
    ImGui::DragFloat4("Color", &color[0], 0.01f, 0.0f, 1.0f);
    if (ImGui::BeginTable("", 3))
    {
        ImGui::TableNextColumn();
        ImGui::Text("X");
        ImGui::TableNextColumn();
        ImGui::Text("Y");
        ImGui::TableNextColumn();
        ImGui::Text("Z");
        //        for (int i = 0; i < vertices.size(); i += 3) {
        //            ImGui::TableNextColumn();
        //            ImGui::Text("%f", vertices[i]);
        //            ImGui::TableNextColumn();
        //            ImGui::Text("%f", vertices[i + 1]);
        //            ImGui::TableNextColumn();
        //            ImGui::Text("%f", vertices[i + 2]);
        //        }
        ImGui::EndTable();
    }
}

const vector<float>& Mesh::getVertices() {
    return vertices;
}

const vector<unsigned int>& Mesh::getIndices() {
    return indices;
}

const vector<float>& Mesh::getNormals() {
    return normals;
}

const bool& Mesh::getVerticesUseIndices() const {
    return verticesUseIndices;
}

std::string Mesh::getName() const {
    return COMPONENT_TYPE;
}
glm::vec4 Mesh::getColor() const {
    return color;
}
void Mesh::setColor(glm::vec4 color) {
    this->color = color;
}
Mesh* Mesh::createMesh(const char* meshType) {
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(meshType, meshNamesList[i]) == 0)
        {
            switch (i)
            {
            case 0:
                return new Cylinder();
            case 1:
                return new Sphere();
            case 2:
                return new CuboidRectangle();
            }
        }
    }
}

const char* Mesh::getMeshType() const {
    return MESH_TYPE;
}
