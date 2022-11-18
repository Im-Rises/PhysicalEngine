include_directories("${CMAKE_SOURCE_DIR}/dependencies")
set(SRCS_TEST "vector3dTest.cpp" "matrix33Test.cpp" "quaternionTest.cpp" "matrix34Test.cpp")

set(SRCS "../ParticleEngine/Utility/Vector3d.cpp" "../ParticleEngine/Utility/Matrix33.cpp" "../ParticleEngine/Utility/Matrix34.cpp" "../ParticleEngine/Utility/Matrix44.cpp" "../ParticleEngine/Utility/Quaternion.cpp")

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${HEADERS} ${SRCS})
    add_test(${testName} ${testName})
endforeach ()

