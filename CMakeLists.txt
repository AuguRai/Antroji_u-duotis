cmake_minimum_required(VERSION 3.25)
project(v.2.0)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(v.2.0 ${SOURCES})