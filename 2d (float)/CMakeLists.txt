cmake_minimum_required (VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_CXX_STANDARD 17)

if(UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(WIN32)
    message("This is a Windows System")
endif()

project (Thermal-Conductivity)

find_package(SFML COMPONENTS graphics window system audio REQUIRED)

add_library(Lib SHARED 
    src/cell2d.cpp
    src/Colour_master.cpp
    src/cont.cpp
    src/menu.cpp
    src/mesh2d.cpp
    src/painter.cpp
    src/Solver2d.cpp
)

add_executable(Therm_Con src/main.cpp)

target_include_directories(Therm_Con PUBLIC)
target_include_directories(Lib PUBLIC) #for includes
target_include_directories(Lib PUBLIC usr/include/SFML) #for sfml

target_link_libraries(Lib sfml-graphics sfml-window sfml-system)
target_link_libraries(Therm_Con sfml-graphics sfml-window sfml-system sfml-audio Lib)
