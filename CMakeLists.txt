cmake_minimum_required(VERSION 3.10)
project(JogoDasCores)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.4
)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG master
)

FetchContent_MakeAvailable(glfw glm)

# stb_image opcional (se carregar imagens)
FetchContent_Declare(
  stb
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_TAG master
)

FetchContent_MakeAvailable(stb)

# Verifica se glad.c está no lugar certo
set(GLAD_C_FILE "${CMAKE_SOURCE_DIR}/common/glad.c")
if (NOT EXISTS ${GLAD_C_FILE})
    message(FATAL_ERROR "Arquivo glad.c não encontrado! Baixe em https://glad.dav1d.de/")
endif()

# Cria o executável
add_executable(JogoDasCores 
    src/main.cpp
    ${GLAD_C_FILE}
)

target_include_directories(JogoDasCores PRIVATE 
    include
    include/glad
    ${glm_SOURCE_DIR}
    ${stb_SOURCE_DIR}
)

# Linka as libs
if(WIN32)
    target_link_libraries(JogoDasCores glfw opengl32)
elseif(APPLE)
    find_library(OpenGL_LIBRARY OpenGL)
    target_link_libraries(JogoDasCores glfw ${OpenGL_LIBRARY})
else()
    find_package(OpenGL REQUIRED)
    target_link_libraries(JogoDasCores glfw ${OPENGL_gl_LIBRARY})
endif()

target_link_libraries(JogoDasCores glm::glm)