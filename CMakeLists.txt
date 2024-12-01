cmake_minimum_required(VERSION 3.26)
project(MEMOGEISTER)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES memogeister_rep/source/main.cpp
        memogeister_rep/source/game.cpp
        memogeister_rep/include/game.h
        memogeister_rep/source/entity.cpp
        memogeister_rep/include/entity.h
        memogeister_rep/source/collision.cpp
        memogeister_rep/include/collision.h
        memogeister_rep/source/configuration.cpp
        memogeister_rep/include/configuration.h
        memogeister_rep/source/ghost.cpp
        memogeister_rep/include/ghost.h
        memogeister_rep/source/player.cpp
        memogeister_rep/include/player.h
        memogeister_rep/source/plant.cpp
        memogeister_rep/include/plant.h
        memogeister_rep/source/potion.cpp
        memogeister_rep/include/potion.h
        memogeister_rep/source/random.cpp
        memogeister_rep/include/random.h
        memogeister_rep/source/resourceManager.cpp
        memogeister_rep/include/resourceManager.h
        memogeister_rep/source/world.cpp
        memogeister_rep/include/world.h
)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/memogeister_rep/resources/ DESTINATION ${CMAKE_BINARY_DIR}/bin/resources)

add_executable(MEMOGEISTER ${SOURCE_FILES})
target_link_libraries(MEMOGEISTER PRIVATE sfml-graphics)
target_compile_features(MEMOGEISTER PRIVATE cxx_std_14)

install(TARGETS MEMOGEISTER)
