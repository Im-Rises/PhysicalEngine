set(SRCS_TEST "particuleTest.cpp" "integratorTest.cpp")

set(HEADERS "../PhysicalEngine/Vector3D/Vector3d.h" "../PhysicalEngine/Particule/Particule.h" "../trash/Integrator/Integrator.h" "TestParticule/TestParticule.h")
set(SRCS "../PhysicalEngine/Vector3D/Vector3d.cpp" "../PhysicalEngine/Particule/Particule.cpp" "TestParticule/TestParticule.cpp" "../trash/Integrator/Integrator.cpp")

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${HEADERS} ${SRCS})
    add_test(${testName} ${testName})
endforeach ()
