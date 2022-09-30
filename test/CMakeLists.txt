set(SRCS_TEST "particuleTest.cpp" "physicHandlerTest.cpp")

set(HEADERS "../PhysicalEngine/Vector3d/Vector3d.h" "../PhysicalEngine/Scene/Components/Particule/Particule.h" "TestParticule/TestParticule.h" "../PhysicalEngine/Scene/PhysicHandler.h" "../PhysicalEngine/Scene/Components/Rigidbody/Rigidbody.h")
set(SRCS "../PhysicalEngine/Vector3d/Vector3d.cpp" "../PhysicalEngine/Scene/Components/Particule/Particule.cpp" "TestParticule/TestParticule.cpp" "../PhysicalEngine/Scene/PhysicHandler.cpp")

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${HEADERS} ${SRCS})
    add_test(${testName} ${testName})
endforeach ()
