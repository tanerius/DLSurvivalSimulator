cmake_minimum_required(VERSION 3.25)

project(DLSim 
    VERSION			1.0.0
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
    GIT_TAG 2.5.1
)

FetchContent_MakeAvailable(SFML)

add_executable(DLSim
    "main.cpp"
    "src/Network.h"
    "src/Interfaces/Helpers.h"
    "src/graphics/Entity.h"
    "src/graphics/Entity.cpp"
    "src/Interfaces/IWorld.h" 
    "src/models/World.h" "src/models/World.cpp")

target_compile_features(DLSim PRIVATE cxx_std_20)

target_include_directories(DLSim 
        PUBLIC ./
        PRIVATE ./src/Interfaces
        PRIVATE ./src/graphics
        PRIVATE ./src/models
        )

# Link external libs we need
target_link_libraries(DLSim
    sfml-graphics
)