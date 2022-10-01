#include "Mesh.h"

#include "imgui/imgui.h"

using namespace std;

void Mesh::drawGui() {
    ImGui::Text(verticesUseIndices ? "Vertices use indices" : "Vertices don't use indices");
    if (ImGui::BeginTable("", 3)) {
        ImGui::TableNextColumn();
        ImGui::Text("X");
        ImGui::TableNextColumn();
        ImGui::Text("Y");
        ImGui::TableNextColumn();
        ImGui::Text("Z");
//        for (int i = 0; i < m_points.size(); i += 3) {
//            ImGui::TableNextColumn();
//            ImGui::Text("%f", m_points[i]);
//            ImGui::TableNextColumn();
//            ImGui::Text("%f", m_points[i + 1]);
//            ImGui::TableNextColumn();
//            ImGui::Text("%f", m_points[i + 2]);
//        }
        ImGui::EndTable();
    }
}

const vector<float> &Mesh::getPoints() {
    return m_points;
}

const vector<unsigned int> &Mesh::getTriangles() {
    return m_triangles;
}

const vector<float> &Mesh::getNormales() {
    return m_normales;
}

const bool &Mesh::getVerticesUseIndices() const {
    return verticesUseIndices;
}

const std::string &Mesh::getName() const {
    return name;
}

