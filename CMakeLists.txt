cmake_minimum_required(VERSION 3.16)

project(ML-Visualizer)

# Find Qt packages
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Enable automatic Qt processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Set UI file directory for AUTOUIC
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

# Add source files
set(SOURCES
    src/main.cpp
    src/main_window.cpp
    src/renderers/model_renderer.cpp
    src/models/model.cpp
)

set(HEADERS
    src/main_window.h
    src/renderers/model_renderer.h
    src/models/model.h
)

# Add the executable
add_executable(ML-Visualizer ${SOURCES})

# Include project directories
target_include_directories(ML-Visualizer PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/renderers
    ${CMAKE_SOURCE_DIR}/src/models
    ${CMAKE_SOURCE_DIR}/ui
)

# Link Qt libraries
target_link_libraries(ML-Visualizer Qt6::Widgets)
