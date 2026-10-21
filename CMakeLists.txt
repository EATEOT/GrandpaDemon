cmake_minimum_required(VERSION 3.24)

project(GrandpaDemon)

# Принудительно подключаем Geode SDK
if (NOT DEFINED ENV{GEODE_SDK})
    find_package(Geode REQUIRED)
    list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK}/cmake")
else()
    add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)
    list(APPEND CMAKE_MODULE_PATH "$ENV{GEODE_SDK}/cmake")
endif()

# Активируем встроенные макросы Geode (включая add_geode_mod)
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
