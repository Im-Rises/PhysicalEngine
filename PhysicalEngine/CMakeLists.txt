include_directories("${CMAKE_SOURCE_DIR}/dependencies/imgui")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/glfw/include")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/glad/include")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/glm")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/stb")

file(GLOB SRCS_HEADERS_IMGUI "${CMAKE_SOURCE_DIR}/dependencies/imgui/*.cpp" "${CMAKE_SOURCE_DIR}/dependencies/imgui/*.h")
file(GLOB SRCS_HEADERS_GLAD "${CMAKE_SOURCE_DIR}/dependencies/glad/**/*.c" "${CMAKE_SOURCE_DIR}/dependencies/glad/**/*.h")

#file(GLOB SRCS "./**/*.cpp" "./*.cpp")
#file(GLOB HEADERS "$./**/*.h" "./*.h")

set(SRCS main.cpp PhysicalEngine.cpp Scene.cpp Camera.cpp GameObject.cpp Shader/Shader.cpp Vector3D/Vector3d.cpp Mesh/Mesh.cpp Mesh/Sphere/Sphere.cpp Mesh/Cuboid/Cube.cpp Mesh/Cuboid/CuboidRectangle.cpp)
set(HEADERS PhysicalEngine.h Scene.h Camera.h GameObject.h Shader/Shader.h Vector3D/Vector3d.h Mesh/Mesh.h Mesh/Sphere/Sphere.h Mesh/Cuboid/Cube.h Mesh/Cuboid/CuboidRectangle.h)

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
