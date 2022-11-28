#include "Mesh.h"

#include "imgui/imgui.h"

using namespace std;

void Mesh::drawGui() {
    ImGui::Text(verticesUseIndices ? "Vertices use indices" : "Vertices don't use indices");
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
