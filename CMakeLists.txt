cmake_minimum_required(VERSION 3.16)
project(HelloModernCXX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# この引数を変更する
add_executable(class src/practice/class.cpp)