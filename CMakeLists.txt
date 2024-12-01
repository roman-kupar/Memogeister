cmake_minimum_required(VERSION 3.26)

# Project name and version
project(MEMOGEISTER VERSION 1.0)

# Set C++ standard to C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files list
set(SOURCE_FILES
    memogeister_rep/source/main.cpp
    memogeister_rep/source/game.cpp
    memogeister_rep/source/entity.cpp
    memogeister_rep/source/collision.cpp
    memogeister_rep/source/configuration.cpp
    memogeister_rep/source/ghost.cpp
    memogeister_rep/source/player.cpp
    memogeister_rep/source/plant.cpp
    memogeister_rep/source/potion.cpp
    memogeister_rep/source/random.cpp
    memogeister_rep/source/resourceManager.cpp
    memogeister_rep/source/world.cpp
)

# Include directories
include_directories(
    memogeister_rep/include
)

# Set the output directory for the final binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Option to build shared or static libraries (default is static)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Fetch SFML from GitHub
include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

# Copy resource files to the build output directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/memogeister_rep/resources/ DESTINATION ${CMAKE_BINARY_DIR}/bin/resources)

# Add the executable target
add_executable(MEMOGEISTER ${SOURCE_FILES})

# Link SFML libraries to your game
target_link_libraries(MEMOGEISTER PRIVATE sfml-graphics sfml-window sfml-system)

# Set compiler features to ensure C++14 is used
target_compile_features(MEMOGEISTER PRIVATE cxx_std_14)

# Optional: Install target
install(TARGETS MEMOGEISTER DESTINATION bin)
