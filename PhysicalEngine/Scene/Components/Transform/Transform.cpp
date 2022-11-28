#include "Transform.h"

#include "../../../Utility/Vector3d.h"
#include "imgui/imgui.h"

Transform::Transform() {
    positionX = 0;
    positionY = 0;
    positionZ = 0;
    scaleX = 1;
    scaleY = 1;
    scaleZ = 1;
}

Transform::~Transform() {
}

void Transform::drawGui() {
    ImGui::Text("Position");
    if (ImGui::BeginTable("transformPosition", 3))
    {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##TransformPositionX", &positionX);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##TransformPositionY", &positionY);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##TransformPositionZ", &positionZ);
        ImGui::EndTable();
    }
    ImGui::Text("Rotation");
    if (ImGui::BeginTable("TransformRotation", 4))
    {
        float* values = rotation.getValues();
        ImGui::TableNextColumn();
        ImGui::Text("W:");
        ImGui::SameLine();
        ImGui::InputFloat("##TransformRotationA", &values[0]);
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##TransformRotationB", &values[1]);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##TransformRotationC", &values[2]);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##TransformRotationD", &values[3]);
        ImGui::EndTable();
    }
    ImGui::Text("Scale");
    if (ImGui::BeginTable("TransformScale", 3))
    {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##TransformScaleX", &scaleX);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##TransformScaleY", &scaleY);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##TransformScaleZ", &scaleZ);
        ImGui::EndTable();
    }
}

void Transform::setPosition(float x, float y, float z) {
    positionX = x;
    positionY = y;
    positionZ = z;
}

void Transform::setPosition(const Vector3d& position) {
    positionX = position.getx();
    positionY = position.gety();
    positionZ = position.getz();
}

Vector3d Transform::getPosition() const {
    return { positionX, positionY, positionZ };
}

void Transform::setRotation(const Quaternion& rotation) {
    this->rotation = rotation;
}

Quaternion Transform::getRotation() const {
    return rotation;
}

std::string Transform::getName() const {
    return COMPONENT_TYPE;
}

Matrix34 Transform::getMatrix() const {
    Matrix34 matrix;
    matrix.setOrientationAndPosition(rotation, Vector3d(positionX, positionY, positionZ));
    return matrix;
}
