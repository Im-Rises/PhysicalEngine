include_directories("${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/imgui")
include_directories("${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/glfw/include")
include_directories("${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/glad/include")
include_directories("${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/glm")

file(GLOB SRCS_HEADERS_IMGUI "imgui/*.cpp" "imgui/*.h")
file(GLOB SRCS_HEADERS_GLAD "glad/**/*.c" "glad/**/*.h")

set(SRCS "main.cpp" "PhysicalEngine.cpp" "Shader/Shader.cpp")
set(HEADERS "PhysicalEngine.h" "Shader/Shader.h")

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS} ${SRCS_HEADERS_IMGUI} ${SRCS_HEADERS_GLAD})

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/glfw/lib-vc2019/glfw3.lib")
elseif (UNIX)
    find_package(glfw3 3.3 REQUIRED)
    target_link_libraries(${PROJECT_NAME} glfw ${CMAKE_DL_LIBS})
else ()
    message(FATAL_ERROR "OS not configured in CMakeLists.txt")
endif ()
