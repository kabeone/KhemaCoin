cmake_minimum_required(VERSION 3.16)
project(blockchain)

set(CMAKE_CXX_STANDARD 17)

add_executable(blockchain Src/main.cpp Src/Block.cpp Src/Chain.cpp Inc/Chain.hpp Src/Transaction.cpp Inc/Transaction.hpp)