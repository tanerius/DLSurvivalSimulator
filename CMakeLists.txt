cmake_minimum_required(VERSION 3.25)

project(DLSim 
    VERSION			2.0.0
    DESCRIPTION		"Deep Learning Survival Simulator"
    LANGUAGES		CXX	C
)

# include CMake fetching module
include(FetchContent)

# Signal that we will statically link sfml
set(BUILD_SHARED_LIBS OFF)

#Get SFML lib
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
)

FetchContent_MakeAvailable(SFML)

add_executable(DLSim
    "src/main.cpp"
    "src/Random.hpp"
    "src/Random.cpp"
    "src/graphics/Renderer.hpp"
    "src/graphics/Renderer.cpp"
    "src/Types.hpp"
    "src/World.hpp"
    "src/World.cpp"
)

target_compile_features(DLSim PRIVATE cxx_std_20)

target_include_directories(DLSim 
        PUBLIC ./src
        PRIVATE ./src/graphics
        )

# Link external libs we need
target_link_libraries(DLSim
    sfml-graphics
)