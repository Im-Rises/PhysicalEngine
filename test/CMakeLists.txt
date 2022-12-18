include_directories("${CMAKE_SOURCE_DIR}/dependencies")
set(SRCS_TEST "vector3dTest.cpp" "matrix33Test.cpp" "quaternionTest.cpp" "matrix34Test.cpp")

set(SRCS "../PhysicalEngine/Utility/Vector3d.cpp" "../PhysicalEngine/Utility/Matrix33.cpp" "../PhysicalEngine/Utility/Matrix34.cpp" "../PhysicalEngine/Utility/Matrix44.cpp" "../PhysicalEngine/Utility/Quaternion.cpp")

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${HEADERS} ${SRCS})
    add_test(${testName} ${testName})
endforeach ()
