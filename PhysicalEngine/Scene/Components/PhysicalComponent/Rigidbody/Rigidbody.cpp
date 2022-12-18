#include "Rigidbody.h"

#include <utility>

#include "../../../GameObject.h"
#include "imgui/imgui.h"

#include "../../../../Force/AnchoredSpring.h"
#include "../../../../Force/ForceGenerator.h"
#include "../../../../Utility/imGuiUtility.h"

#include "../../../Components/Mesh/Cuboid/CuboidRectangle.h"

Rigidbody::Rigidbody(GameObject* gameObject) : Component(gameObject) {
    //    m_speed = { 0, 0, 0 };
    //    m_acceleration = { 0, 0, 0 };
    m_mass = 1;
    m_rotation = { 0, 0, 0 };
    m_inertiaTensor = Matrix33();
    m_transformMatrix = Matrix34();
    m_orientation = Quaternion();
    m_angularSpeed = Vector3d(0, 0, 0);
    m_angularAcceleration = Vector3d(0, 0, 0);
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);
}

Rigidbody::~Rigidbody() {
//    for (ForceGenerator* forceGenerator : forceGeneratorsList)
//    {
//        delete forceGenerator;
//    }
    for (ForcePoint& forcePoint : pointForceGeneratorsList)
    {
        delete forcePoint.force;
    }
}

void Rigidbody::addForceAtPoint(const Vector3d& force, const Vector3d worldPoint) {
    m_forceAccum += force;
    Vector3d point = m_gameObject->transform.getMatrix().inverse().transformPosition(worldPoint);
    m_torqueAccum += point.cross(force);
}

void Rigidbody::addForceAtBodyPoint(const Vector3d& force, const Vector3d& LocalPoint) {
    m_forceAccum += force;
    // Vector3d point = m_gameObject->transform.getMatrix().TransformPosition(LocalPoint);
    Vector3d point = LocalPoint;
    m_torqueAccum += point.cross(force);
}

void Rigidbody::clearAccumulator() {
    m_forceAccum = Vector3d(0, 0, 0);
    m_torqueAccum = Vector3d(0, 0, 0);
}

void Rigidbody::update(float time) {
    // Update sum of forces
    if (!isKinematic)
    {
        gravity.addForce(this);

        // Linear forces
        for (ForceGenerator* forceGenerator : forceGeneratorsList)
        {
            forceGenerator->addForce(this);
        }

        // Angular forces
        for (ForcePoint& forcePoint : pointForceGeneratorsList)
        {
            Vector3d forceValue = forcePoint.force->getForceValue(this);
            addForceAtBodyPoint(forceValue, forcePoint.point);
        }
    }

    // Calculate derivatives
    calculateDerivedData();

    // Update acceleration, speed and position
    calculateAcceleration();
    calculateSpeed(time);

    // Clear accumulators
    clearAccumulator();
}

void Rigidbody::calculateAcceleration() {
    linearAcceleration = m_forceAccum / m_mass;
    m_angularAcceleration = m_inertiaTensor.inverse() * m_torqueAccum;
}

void Rigidbody::calculateDerivedData() {
    m_transformMatrix.setOrientationAndPosition(m_orientation, getPosition());

    Mesh* mesh = m_gameObject->getMesh();
    if (mesh != nullptr)
    {
        m_inertiaTensor = mesh->getInertiaTensor(m_mass);
    }
    else
    {
        std::cerr << "No mesh found for rigidbody" << std::endl;
        m_inertiaTensor = Matrix33();
    }
}

void Rigidbody::calculateSpeed(float time) {
    linearSpeed = linearSpeed + linearAcceleration * time;
    m_angularSpeed = m_angularSpeed + m_angularAcceleration * time;
}

Vector3d Rigidbody::getAngularSpeed() const {
    return m_angularSpeed;
}

void Rigidbody::deleteForceAtPoint(ForceGenerator* forceGenerator) {
    for (auto it = pointForceGeneratorsList.begin(); it != pointForceGeneratorsList.end(); ++it)
    {
        if (it->force == forceGenerator)
        {
            pointForceGeneratorsList.erase(it);
            break;
        }
    }
}

void Rigidbody::addForceToPointList(ForceGenerator* forceGenerator, const Vector3d& point) {
    pointForceGeneratorsList.emplace_back(ForcePoint{ forceGenerator, point });
}

void Rigidbody::calculateOrientation(float deltaTime) {
    m_orientation = m_orientation + Quaternion(0, m_angularSpeed.getx(), m_angularSpeed.gety(), m_angularSpeed.getz()) * (deltaTime / 2) * m_orientation;
}

//     pointForceGeneratorsList.emplace_back(forceGenerator, point);
void Rigidbody::drawGuiForceGeneratorsAtPoint() {
    std::string forcesListText = "Forces list##RigidbodyForcesListButton";
    std::string addForcesText = "Add forces##RigidbodyAddForceButton";
    std::string deleteForcesText = "Delete forces##RigidbodyDeleteForceButton";

    // Forces list and add force
    ImGuiUtility::AlignForWidth((ImGuiUtility::CalculateTextWidth(forcesListText.c_str()) +
                                 ImGuiUtility::CalculateTextWidth(addForcesText.c_str()) +
                                 ImGuiUtility::CalculateTextWidth(deleteForcesText.c_str())));

    // Forces list
    if (ImGui::Button(forcesListText.c_str()))
    {
        ImGui::OpenPopup("##RigidbodyForcesListPopup");
    }
    if (ImGui::BeginPopup("##RigidbodyForcesListPopup"))
    {
        if (pointForceGeneratorsList.empty())
            ImGui::Text("Empty");
        else
            for (auto& forceGenerator : pointForceGeneratorsList)
            {
                forceGenerator.force->drawGui(m_gameObject->getScenePtr());
                ImGui::Text("Point: ");
                ImGui::SameLine();
                std::string pointText = "##RigidbodyAddForcePoint" + forceGenerator.force->getName();
                ImGui::DragFloat3(pointText.c_str(), &forceGenerator.point.x);
            }
        ImGui::EndPopup();
    }

    ImGui::SameLine();

    // Add force
    if (ImGui::Button(addForcesText.c_str()))
    {
        ImGui::OpenPopup("##RigidbodyAddForcesPopup");
    }
    if (ImGui::BeginPopup("##RigidbodyAddForcesPopup"))
    {
        for (auto& forcesName : ForceGenerator::forcesNamesList)
        {
            if (ImGui::MenuItem(forcesName))
            {
                pointForceGeneratorsList.emplace_back(
                    ForcePoint{ ForceGenerator::createForceGenerator(forcesName, m_gameObject),
                        Vector3d(0, 0, 0) });
            }
        }
        ImGui::EndPopup();
    }

    ImGui::SameLine();

    // Delete force
    if (ImGui::Button(deleteForcesText.c_str()))
    {
        ImGui::OpenPopup("##RigidbodyDeleteForcesPopup");
    }
    if (ImGui::BeginPopup("##RigidbodyDeleteForcesPopup"))
    {
        for (auto& forceGenerator : pointForceGeneratorsList)
        {
            if (ImGui::MenuItem(forceGenerator.force->getName().c_str()))
            {
                deleteForceAtPoint(forceGenerator.force);
            }
        }
        ImGui::EndPopup();
    }
}


// void Rigidbody::addForceAtPointToList(ForceGenerator *forceGenerator, const Vector3d &point) {
void Rigidbody::drawGui() {
    PhysicalComponent::drawGui();

    // linearSpeed, acceleration
    ImGui::Text("Angular Speed");
    if (ImGui::BeginTable("PhysicalComponentAngularSpeed", 3))
    {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##PhysicalComponentAngularSpeedX", &m_angularSpeed.x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##PhysicalComponentAngularSpeedY", &m_angularSpeed.y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##PhysicalComponentAngularSpeedZ", &m_angularSpeed.z);
        ImGui::EndTable();
    }
    ImGui::Text("Angular Acceleration");
    if (ImGui::BeginTable("PhysicalComponentAngularAcceleration", 3))
    {
        ImGui::TableNextColumn();
        ImGui::Text("X:");
        ImGui::SameLine();
        ImGui::InputFloat("##PhysicalComponentAngularAccelerationX", &m_angularAcceleration.x);
        ImGui::TableNextColumn();
        ImGui::Text("Y:");
        ImGui::SameLine();
        ImGui::InputFloat("##PhysicalComponentAngularAccelerationY", &m_angularAcceleration.y);
        ImGui::TableNextColumn();
        ImGui::Text("Z:");
        ImGui::SameLine();
        ImGui::InputFloat("##PhysicalComponentAngularAccelerationZ", &m_angularAcceleration.z);
        ImGui::EndTable();
    }
    ImGui::NewLine();

    ImGui::Text("Force Generators");
    PhysicalComponent::drawGuiForceGenerators();

    ImGui::NewLine();
    ImGui::Text("Force Generators at Point");
    drawGuiForceGeneratorsAtPoint();
    ImGui::NewLine();
}

std::string Rigidbody::getName() const {
    return COMPONENT_TYPE;
}

void Rigidbody::stop() {
    m_forceAccum = Vector3d();
    linearSpeed = Vector3d(0, 0, 0);
    linearAcceleration = Vector3d(0, 0, 0);

    //    m_speed = Vector3d(0, 0, 0);
    //    m_acceleration = Vector3d(0, 0, 0);

    m_angularSpeed = Vector3d(0, 0, 0);
    m_angularAcceleration = Vector3d(0, 0, 0);

    isKinematic = true;
}
void Rigidbody::setAngularSpeed(const Vector3d& angularSpeed) {
    m_angularSpeed = angularSpeed;
}
