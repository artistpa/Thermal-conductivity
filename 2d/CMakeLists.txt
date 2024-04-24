cmake_minimum_required (VERSION 3.6)

set(CMAKE_CXX_FLAGS "-std=c++20 -O2 -g")

#-fsanitize=address,undefined

project (ThermalConductivity)

find_package(SFML COMPONENTS graphics window system audio REQUIRED)

add_library(Lib SHARED 
    src/func.cc
    src/particle.cc
    src/pressure_map.cc
    src/pressure_map_cell.cc
)

add_executable(MyProj src/main.cc)

target_include_directories(MyProj PUBLIC include/)
target_include_directories(Lib PUBLIC include/) #for includes
target_include_directories(Lib PUBLIC /opt/homebrew/include/) #for sfml

target_link_libraries(Lib sfml-graphics sfml-window sfml-system)
target_link_libraries(MyProj sfml-graphics sfml-window sfml-system sfml-audio Lib)
