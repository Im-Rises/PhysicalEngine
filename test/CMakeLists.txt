include_directories("${CMAKE_SOURCE_DIR}/dependencies")
set(SRCS_TEST "vector3dTest.cpp" "matrix33Test.cpp" "quaternionTest.cpp")

set(SRCS "../ParticleEngine/Utility/Vector3d.cpp")

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${HEADERS} ${SRCS})
    add_test(${testName} ${testName})
endforeach ()

