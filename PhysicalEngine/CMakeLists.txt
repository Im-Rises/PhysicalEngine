include_directories("${CMAKE_SOURCE_DIR}/dependencies")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/glad/include")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/glfw/include")

file(GLOB_RECURSE SRCS_HEADERS_IMGUI "${CMAKE_SOURCE_DIR}/dependencies/imgui/*.cpp" "${CMAKE_SOURCE_DIR}/dependencies/imgui/*.h")
file(GLOB_RECURSE SRCS_HEADERS_GLAD "${CMAKE_SOURCE_DIR}/dependencies/glad/*.c" "${CMAKE_SOURCE_DIR}/dependencies/glad/*.h")

set(SRCS main.cpp PhysicalEngine.cpp Scene/Scene.cpp Scene/Camera.cpp InputManager.cpp Scene/GameObject.cpp Scene/Shader/Shader.cpp Vector3d/Vector3d.cpp Scene/Mesh/Mesh.cpp Scene/Mesh/Sphere/Sphere.cpp Scene/Mesh/Cuboid/Cube.cpp Scene/Mesh/Cuboid/CuboidRectangle.cpp Scene/Mesh/Cuboid/MyCube.cpp "Scene/Mesh/Cuboid/MyCubeUseIndice.cpp" "Game.cpp" "Scene/Components/Particule/Particule.cpp" "Force/ForceGenerator.cpp" "Force/Gravity.cpp" "Force/Drag.cpp" "Force/Spring.cpp" "Force/AnchoredSpring.cpp" "Force/Buoyancy.cpp")
set(HEADERS PhysicalEngine.h Scene/Scene.h Scene/Camera.h InputManager.h Scene/GameObject.h Scene/Shader/Shader.h Vector3d/Vector3d.h Scene/Mesh/Mesh.h Scene/Mesh/Sphere/Sphere.h Scene/Mesh/Cuboid/Cube.h Scene/Mesh/Cuboid/CuboidRectangle.h Scene/Mesh/Cuboid/MyCube.h "Scene/Mesh/Cuboid/MyCubeUseIndice.h" "Game.h" "Scene/Components/Particule/Particule.h" "Force/ForceGenerator.h" "Force/Gravity.h" "Force/Drag.h" "Force/Spring.h" "Force/AnchoredSpring.h" "Force/Buoyancy.h")

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
