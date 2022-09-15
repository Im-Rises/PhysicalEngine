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
