cmake_minimum_required(VERSION 3.24)

project(GrandpaDemon)

if(DEFINED ENV{GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")
endif()

find_package(Geode REQUIRED)

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
