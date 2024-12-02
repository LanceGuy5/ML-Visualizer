cmake_minimum_required(VERSION 3.16)

project(ML-Visualizer)

# Find Qt packages
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Set the UI file path
set(UI_FILES ${CMAKE_SOURCE_DIR}/ui)

# Enable automatic UIC processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# point automatic UIC processing:
set(CMAKE_AUTOUIC_SEARCH_PATHS ${UI_FILES})
qt6_wrap_ui(UI_HEADERS ${UI_FILES})

set(SOURCES
    src/main.cpp
    src/main_window.cpp
    ${UI_HEADERS}
)

set(HEADERS
    src/main_window.h
)

# Add the executable and include the UI files
add_executable(ML-Visualizer
    src/main.cpp
    src/main_window.cpp
)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/ui)
include_directories(${CMAKE_BINARY_DIR}/ML-Visualizer_autogen/build)

# Link Qt libraries
target_link_libraries(ML-Visualizer Qt6::Widgets)
