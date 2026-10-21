cmake_minimum_required(VERSION 3.24)

cmake_policy(SET CMP0048 NEW)
if(POLICY CMP0169)
    cmake_policy(SET CMP0169 OLD)
endif()

project(GrandpaDemon)

if(DEFINED ENV{GEODE_SDK})
    add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)
    list(APPEND CMAKE_MODULE_PATH "$ENV{GEODE_SDK}/cmake")
else()
    find_package(Geode REQUIRED)
endif()

include(GeodeMod)

add_geode_mod(
    itzkiba.grandpa_demon
    VERSION v1.3.7
    SOURCES
        src/main.cpp
        src/ListManager.h
        src/CreatorLayer.cpp
        src/DemonFilterSelectLayer.cpp
        src/EffectsManager.h
        src/LevelBrowserLayer.cpp
        src/LevelCell.cpp
        src/LevelInfoLayer.cpp
        src/LevelSearchLayer.cpp
        src/ParticleManager.h
)
