cmake_minimum_required(VERSION 3.23)
project(untitled6 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled6 main.c)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

TARGET_LINK_LIBRARIES(untitled6 ${GTK3_LIBRARIES})