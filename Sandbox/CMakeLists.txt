cmake_minimum_required(VERSION 3.5)

project(Sandbox)
set(CMAKE_BUILD_TYPE Debug)

file(COPY ${CMAKE_CURRENT_BINARY_DIR}/../MEngine/libMEngine.a
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(${PROJECT_NAME} main.cpp)

include_directories( "../MEngine/src")
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_BINARY_DIR}/libMEngine.a
                                      ${OPENGL_gl_LIBRARY}
                                      ${GLUT_LIBRARIES}
                                      ${GLEW_LIBRARIES}
                                      /usr/lib/x86_64-linux-gnu/libglfw.so 
                                      )
