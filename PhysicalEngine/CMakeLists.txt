### New CMakeLists.txt to compile from .lib or package installed

include_directories("${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/imgui")
include_directories("${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/glfw/include")
include_directories("${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/glad/include")

set(HEADERS_IMGUI "imgui/imconfig.h" "imgui/imgui.h" "imgui/imgui_internal.h" "imgui/imstb_rectpack.h" "imgui/imstb_textedit.h" "imgui/imstb_truetype.h" "imgui/imgui_impl_glfw.h" "imgui/imgui_impl_opengl3.cpp")
set(SRCS_IMGUI "imgui/imgui.cpp" "imgui/imgui_demo.cpp" "imgui/imgui_draw.cpp" "imgui/imgui_tables.cpp" "imgui/imgui_widgets.cpp" "imgui/imgui_impl_glfw.cpp" "imgui/imgui_impl_opengl3.h" "imgui/imgui_impl_opengl3_loader.h")

set(HEADERS_GLAD "glad/include/glad/glad.h" "glad/include/KHR/khrplatform.h")
set(SRCS_GLAD "glad/src/glad.c")

set(SRCS "main.cpp" "PhysicalEngine.cpp" "Shader/Shader.cpp" "Mesh.cpp")
set(HEADERS "PhysicalEngine.h" "Shader/Shader.h" "Mesh.h")

add_executable(${PROJECT_NAME} ${SRCS} ${SRCS_IMGUI} ${SRCS_GLAD} ${HEADERS} ${HEADERS_IMGUI})

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


### Old CMakeLists.txt to compile from GLFW source
#[[
set(SRCS "main.cpp")
set(HEADERS)

include_directories("${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/glfw/include")
include_directories("${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/imgui")

add_subdirectory("glfw")

set(HEADERS_IMGUI "imgui/imconfig.h" "imgui/imgui.h" "imgui/imgui_internal.h" "imgui/imstb_rectpack.h" "imgui/imstb_textedit.h" "imgui/imstb_truetype.h" "imgui/imgui_impl_glfw.h" "imgui/imgui_impl_opengl3.cpp")
set(SRCS_IMGUI "imgui/imgui.cpp" "imgui/imgui_demo.cpp" "imgui/imgui_draw.cpp" "imgui/imgui_tables.cpp" "imgui/imgui_widgets.cpp" "imgui/imgui_impl_glfw.cpp" "imgui/imgui_impl_opengl3.h" "imgui/imgui_impl_opengl3_loader.h")

find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME} ${SRCS} ${SRCS_IMGUI} ${HEADERS} ${HEADERS_IMGUI})

target_link_libraries(${PROJECT_NAME} "glfw")

target_link_libraries(${PROJECT_NAME} OpenGL::GL)
]]
#
