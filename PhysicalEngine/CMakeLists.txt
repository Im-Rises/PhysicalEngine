include_directories("${CMAKE_SOURCE_DIR}/dependencies/glad/include")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/glfw/include")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/glm")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/imgui")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/stb")

file(GLOB SRCS_HEADERS_IMGUI "${CMAKE_SOURCE_DIR}/dependencies/imgui/*.cpp" "${CMAKE_SOURCE_DIR}/dependencies/imgui/*.h")
file(GLOB SRCS_HEADERS_GLAD "${CMAKE_SOURCE_DIR}/dependencies/glad/**/*.c" "${CMAKE_SOURCE_DIR}/dependencies/glad/**/*.h")

set(SRCS main.cpp PhysicalEngine.cpp Scene/Scene.cpp Scene/Camera.cpp Scene/InputManager.cpp Scene/GameObject.cpp Scene/Shader/Shader.cpp Vector3D/Vector3d.cpp Scene/Mesh/Mesh.cpp Scene/Mesh/Sphere/Sphere.cpp Scene/Mesh/Cuboid/Cube.cpp Scene/Mesh/Cuboid/CuboidRectangle.cpp Scene/Mesh/Cuboid/MyCube.cpp "Scene/Mesh/Cuboid/MyCubeUseIndice.cpp")
set(HEADERS PhysicalEngine.h Scene/Scene.h Scene/Camera.h Scene/InputManager.h Scene/GameObject.h Scene/Shader/Shader.h Vector3D/Vector3d.h Scene/Mesh/Mesh.h Scene/Mesh/Sphere/Sphere.h Scene/Mesh/Cuboid/Cube.h Scene/Mesh/Cuboid/CuboidRectangle.h Scene/Mesh/Cuboid/MyCube.h "Scene/Mesh/Cuboid/MyCubeUseIndice.h")

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS} ${SRCS_HEADERS_IMGUI} ${SRCS_HEADERS_GLAD})

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/dependencies/glfw/lib-vc2019/glfw3.lib")
elseif (UNIX)
    find_package(glfw3 3.3 REQUIRED)
    target_link_libraries(${PROJECT_NAME} glfw ${CMAKE_DL_LIBS})
else ()
    message(FATAL_ERROR "OS not configured in CMakeLists.txt")
endif ()
