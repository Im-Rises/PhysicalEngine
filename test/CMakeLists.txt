set(SRCS_TEST "particuleTest.cpp" "integratorTest.cpp")

set(HEADERS "../PhysicalEngine/Vector3d/Vector3d.h" "../PhysicalEngine/Particule/Particule.h" "TestParticule/TestParticule.h" "../PhysicalEngine/Integrator/Integrator.h" "../PhysicalEngine/Integrable/Integrable.h")
set(SRCS "../PhysicalEngine/Vector3d/Vector3d.cpp" "../PhysicalEngine/Particule/Particule.cpp" "TestParticule/TestParticule.cpp" "../PhysicalEngine/Integrator/Integrator.cpp")

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${HEADERS} ${SRCS})
    add_test(${testName} ${testName})
endforeach ()
