include_directories("${CMAKE_SOURCE_DIR}/dependencies")
set(SRCS_TEST "vector3dTest.cpp")
#"particuleTest.cpp" "physicHandlerTest.cpp"

set(HEADERS "../ParticleEngine/Vector3d/Vector3d.h" "../ParticleEngine/Scene/PhysicHandler.h")
set(SRCS "../ParticleEngine/Vector3d/Vector3d.cpp" "../ParticleEngine/Scene/PhysicHandler.cpp")

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${HEADERS} ${SRCS})
    add_test(${testName} ${testName})
endforeach ()

