cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(ChristianMod VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED
    # Main
    src/main.cpp

    # Christian Mod Layer
    src/ChristianModLayer/ChristianModLayer.cpp
    src/ChristianModLayer/ChristianModLayer.hpp

    # Christian Mod Scene
    src/ChristianModScene/ChristianModScene.cpp
    src/ChristianModScene/ChristianModScene.hpp

    # HAYFT Popup
    src/HAYFT_Popup/HAYFT_Popup.cpp
    src/HAYFT_Popup/HAYFT_Popup.hpp

    # Hooks
    src/Hooks/CustomCreatorLayer/CustomCreatorLayer.cpp

    # Utils
    src/Utils/Utils.hpp
    
)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

setup_geode_mod(${PROJECT_NAME})
