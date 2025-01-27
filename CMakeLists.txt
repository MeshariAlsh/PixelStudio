cmake_minimum_required(VERSION 3.10)

# Set the project name
project(PixelHouse)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Find and set SFML on the system
set(SFML_DIR "/opt/homebrew/opt/sfml")
include_directories(${SFML_DIR}/include)

# Link SFML library path
link_directories(${SFML_DIR}/lib)

# Include the ImGui folder from the project directory
include_directories(${CMAKE_SOURCE_DIR}/src/imgui)

# All source files
set(SOURCE_FILES
    src/main.cpp
    src/Grid.cpp
    src/Palette.cpp
    src/Shadow.cpp
    src/MainMenu.cpp
    src/utils.cpp
    src/imgui/imgui.cpp
    src/imgui/imgui_draw.cpp
    src/imgui/imgui_widgets.cpp
    src/imgui/imgui_tables.cpp
    src/imgui/imgui-SFML.cpp
)

# Add the executable
add_executable(pixelHouse ${SOURCE_FILES})

# Link SFML libraries and must add OpenGL framework
target_link_libraries(pixelHouse
    sfml-graphics
    sfml-window
    sfml-system
    "-framework OpenGL"  
)
