cmake_minimum_required(VERSION 3.10)
project(PGCCHIB)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.4
)
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 0.9.9.8
)
FetchContent_Declare(
  stb_image
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_TAG master
)
FetchContent_MakeAvailable(glfw glm stb_image)

set(GLAD_C_FILE "${CMAKE_SOURCE_DIR}/common/glad.c")
if (NOT EXISTS ${GLAD_C_FILE})
    message(FATAL_ERROR "Arquivo glad.c não encontrado! Baixe a GLAD manualmente em https://glad.dav1d.de/ e coloque glad.h em include/glad/ e glad.c em common/")
endif()

if(WIN32)
    set(OPENGL_LIBS opengl32)
elseif(APPLE)
    find_library(OpenGL_LIBRARY OpenGL)
    set(OPENGL_LIBS ${OpenGL_LIBRARY})
else()
    find_package(OpenGL REQUIRED)
    set(OPENGL_LIBS ${OPENGL_gl_LIBRARY})
endif()

add_executable(main
    src/main.cpp
    src/Sprite.cpp
    ${GLAD_C_FILE}
)

target_include_directories(main PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/common
    ${glm_SOURCE_DIR}
    ${stb_image_SOURCE_DIR}
)

target_link_libraries(main PRIVATE glfw ${OPENGL_LIBS} glm::glm)

if(MSVC)
    target_compile_options(main PRIVATE /W4 /permissive-)
else()
    target_compile_options(main PRIVATE -Wall -Wextra -pedantic)
endif()