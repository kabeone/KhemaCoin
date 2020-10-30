cmake_minimum_required(VERSION 3.16)
project(blockchain)

set(CMAKE_CXX_STANDARD 17)

SET(GXX_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
SET(GXX_COVERAGE_LINK_FLAGS    "")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GXX_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GXX_COVERAGE_LINK_FLAGS}")

add_executable(blockchain Src/main.cpp Src/Block.cpp Src/Chain.cpp Src/Transaction.cpp Src/hash/Hasher.cpp Src/hash/Sha.cpp)
target_link_libraries(blockchain "-lcrypto")