set(SRCS_TEST "mainTest.cpp" "mainTest2.cpp" "../PhysicalEngine/Vector3D/Vector3d.cpp")

set(HEADERS "../PhysicalEngine/Vector3D/Vector3d.h")
set(SRCS)

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${HEADERS} ${SRCS})
    add_test(${testName} ${testName})
endforeach ()
