cmake_minimum_required(VERSION 3.24)

project(GrandpaDemon)

if (NOT DEFINED ENV{GEODE_SDK})
    # Если сервер не передал путь, используем стандартную подгрузку через Geode
    find_package(Geode REQUIRED)
else()
    # Прямое подключение SDK без капризных поисков файлов конфигурации
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
