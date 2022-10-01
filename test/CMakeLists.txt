set(SRCS_TEST "vector3dTest.cpp")
#"particuleTest.cpp" "physicHandlerTest.cpp"

set(HEADERS "../PhysicalEngine/Vector3d/Vector3d.h" "../PhysicalEngine/Scene/PhysicHandler.h")
set(SRCS "../PhysicalEngine/Vector3d/Vector3d.cpp" "../PhysicalEngine/Scene/PhysicHandler.cpp")

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${HEADERS} ${SRCS})
    add_test(${testName} ${testName})
endforeach ()
