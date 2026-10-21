cmake_minimum_required(VERSION 3.24)

project(GrandpaDemon)

# Включаем современную интеграцию с Geode без использования сторонних менеджеров закачек
if (NOT DEFINED ENV{GEODE_SDK})
    find_package(Geode REQUIRED)
else()
    add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)
endif()

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
