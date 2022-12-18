#include "Game.h"

#include "Force/Spring.h"
#include "Scene/Components/Mesh/Cylinder/Cylinder.h"
#include "Scene/Components/Mesh/Sphere/Sphere.h"
#include "Scene/Components/PhysicalComponent/Particle/Particle.h"
#include "Scene/GameObject.h"
#include "Scene/Prefabs/ParticlePrefab.h"
#include "Scene/Prefabs/PlanePrefab.h"
#include "Scene/Prefabs/RigidbodyPrefab.h"
#include "Scene/Scene.h"

Game::Game() = default;

Game::~Game() = default;

void Game::start(Scene* s) {
    this->scene = s;

    /* Simple rigidbody */
    //    auto* rigidbodyPrefab = new RigidbodyPrefab(scene);
    //    scene->addGameObject(rigidbodyPrefab);
    //    Rigidbody* rigidbody;
    //    rigidbodyPrefab->getComponentByClass(rigidbody);
    //    rigidbody->addForceToPointList(new AnchoredSpring(Vector3d(0, 12, 0), 3, 3), Vector3d(5, 0, 0));
    //
    //    auto* rigidbodyPrefab2 = new RigidbodyPrefab(scene, new Cylinder(8, 12, 10));
    //    rigidbodyPrefab2->transform.positionX = -20;
    //    scene->addGameObject(rigidbodyPrefab2);
    //    Rigidbody* rigidbody2;
    //    rigidbodyPrefab2->getComponentByClass(rigidbody2);
    //    auto* spring = new Spring(nullptr, 3, 3);
    //    rigidbody2->addForceToPointList(spring, Vector3d(5, 0, 0));
    //    spring->setOtherGameObject(rigidbody->getGameObject());
    //
    //    auto* plan = new PlanePrefab(scene, 100, 100);
    //    scene->addGameObject(plan);


    /* Particles collisions */
    //        for (int i = 0; i < 20; i++) {
    //            for (int j = 0; j < 25; ++j) {
    //                auto *particlePrefabNew = new ParticlePrefab(scene);
    //                particlePrefabNew->transform.setPosition({(float) i * 2, (float) j * 2, 0});
    //                scene->addGameObject(particlePrefabNew);
    //            }
    //        }


    /* Plane and box collisions*/
    auto* plan = new PlanePrefab(scene, 10, 10);
    scene->addGameObject(plan);
    plan->addComponent(new RigidbodyPlaneCollider(plan, 10, 10));

    auto* sphere = new RigidbodyPrefab(scene, new Sphere(1));
    sphere->addComponent(new RigidbodySphereCollider(sphere, 1));
    sphere->transform.setPosition({ -4, 0, 0 });
    scene->addGameObject(sphere);

    auto* rigidbodyPrefab = new RigidbodyPrefab(scene);
    rigidbodyPrefab->mesh->setColor({ 1.0f, 0.0f, 0, 1.0f });
    scene->addGameObject(rigidbodyPrefab);
    rigidbodyPrefab->transform.positionX = -1.5;
    rigidbodyPrefab->transform.positionY = 3;
    rigidbodyPrefab->transform.positionZ = 0;
    Rigidbody* rigidbody;
    rigidbodyPrefab->getComponentByClass(rigidbody);
    rigidbody->setAngularSpeed({ 0, 1, 0 });
    RigidbodyCuboidRectangleCollider* rigidbodyCuboidRectangleCollider = new RigidbodyCuboidRectangleCollider(rigidbodyPrefab, 1, 0.5f, 0.5f);
    rigidbodyPrefab->addComponent(rigidbodyCuboidRectangleCollider);

    auto* rigidbodyPrefab2 = new RigidbodyPrefab(scene);
    rigidbodyPrefab2->mesh->setColor({ 0, 0.0f, 0.8f, 1.0f });
    rigidbodyPrefab2->transform.positionX = 1.5;
    rigidbodyPrefab2->transform.positionY = 3;
    rigidbodyPrefab2->transform.positionZ = -3;
    scene->addGameObject(rigidbodyPrefab2);
    Rigidbody* rigidbody2;
    rigidbodyPrefab2->getComponentByClass(rigidbody2);
    rigidbody2->setAngularSpeed({ 0, 0, -1 });
    RigidbodyCuboidRectangleCollider* rigidbodyCuboidRectangleCollider2 = new RigidbodyCuboidRectangleCollider(rigidbodyPrefab2, 1, 0.5f, 0.5f);
    rigidbodyPrefab2->addComponent(rigidbodyCuboidRectangleCollider2);

    auto* rigidbodyPrefab3 = new RigidbodyPrefab(scene);
    rigidbodyPrefab3->mesh->setColor({ 0, 0.8f, 0, 1.0f });
    rigidbodyPrefab3->transform.positionX = 3;
    rigidbodyPrefab3->transform.positionY = 3;
    rigidbodyPrefab3->transform.positionZ = 0;
    scene->addGameObject(rigidbodyPrefab3);
    Rigidbody* rigidbody3;
    rigidbodyPrefab3->getComponentByClass(rigidbody3);
    rigidbody3->setAngularSpeed({ 2, 0, 0 });
    RigidbodyCuboidRectangleCollider* rigidbodyCuboidRectangleCollider3 = new RigidbodyCuboidRectangleCollider(rigidbodyPrefab3, 1, 0.5f, 0.5f);
    rigidbodyPrefab3->addComponent(rigidbodyCuboidRectangleCollider3);
}

// void Game::goLeft() {
//     //    m_p->setSpeed(-m_speed, 0, 0);
//
//     for (auto& gameObject : scene->getGameObjects())
//     {
//         auto* particle = dynamic_cast<Particle*>(gameObject->getComponentByName(PARTICLE_COMPONENT));
//         if (particle != nullptr)
//         {
//             AnchoredSpring* anchoredSpring;
//             particle->getForceByClass(anchoredSpring);
//             if (anchoredSpring != nullptr)
//             {
//                 anchoredSpring->translate({ -m_speed, 0, 0 });
//             }
//         }
//     }
// }
//
// void Game::goRight() {
//     //    m_p->setSpeed(m_speed, 0, 0);
//
//     for (auto& gameObject : scene->getGameObjects())
//     {
//         auto* particle = dynamic_cast<Particle*>(gameObject->getComponentByName(PARTICLE_COMPONENT));
//         if (particle != nullptr)
//         {
//             AnchoredSpring* anchoredSpring;
//             particle->getForceByClass(anchoredSpring);
//             if (anchoredSpring != nullptr)
//             {
//                 anchoredSpring->translate({ m_speed, 0, 0 });
//             }
//         }
//     }
// }
//
// void Game::goUp() {
//     //    m_p->setSpeed(0, m_speed, 0);
//
//     for (auto& gameObject : scene->getGameObjects())
//     {
//         auto* particle = dynamic_cast<Particle*>(gameObject->getComponentByName(PARTICLE_COMPONENT));
//         if (particle != nullptr)
//         {
//             AnchoredSpring* anchoredSpring;
//             particle->getForceByClass(anchoredSpring);
//             if (anchoredSpring != nullptr)
//             {
//                 anchoredSpring->translate({ 0, m_speed, 0 });
//             }
//         }
//     }
// }
//
// void Game::goDown() {
//     //    m_p->setSpeed(0, -m_speed, 0);
//
//     for (auto& gameObject : scene->getGameObjects())
//     {
//         auto* particle = dynamic_cast<Particle*>(gameObject->getComponentByName(PARTICLE_COMPONENT));
//         if (particle != nullptr)
//         {
//             AnchoredSpring* anchoredSpring;
//             particle->getForceByClass(anchoredSpring);
//             if (anchoredSpring != nullptr)
//             {
//                 anchoredSpring->translate({ 0, -m_speed, 0 });
//             }
//         }
//     }
// }

// float* Game::getPtrSpeed() {
//     return &m_speed;
// }
