cmake_minimum_required(VERSION 3.26)
project(LinkedListAnimation)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinkedListAnimation main.cpp
        LinkedList.cpp
        LinkedList.h
        Node.cpp
        Node.h
        LinkedListAnimation.cpp
        LinkedListAnimation.h)
target_link_libraries(LinkedListAnimation sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
file(COPY "arial.ttf" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})