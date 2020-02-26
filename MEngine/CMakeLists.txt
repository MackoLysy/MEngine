cmake_minimum_required(VERSION 3.5)
set(CMAKE_BUILD_TYPE Debug)
project(MEngine)
file(GLOB SOURCES 
    "src/MEngine/*.cpp"
    "src/MEngine/Components/*.cpp"
    "src/MEngine/Event/*.cpp"
    "src/MEngine/Mesh/*.cpp"
    "src/OpenGl/*.cpp"
    "src/OpenGl/Shaders/*.cpp"
    "src/Vendor/glm/*.cpp"
    "src/Vendor/stb_image/*.cpp"
    "src/*.cpp"
    )
add_library(${PROJECT_NAME} STATIC ${SOURCES})

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} "src/Vendor")
