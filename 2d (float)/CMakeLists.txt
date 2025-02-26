cmake_minimum_required (VERSION 2.8)

project (Thermal-Conductivity)


if (NOT METHOD)
    set(METHOD 0)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g -DMETHOD=${METHOD}")
set(CMAKE_CXX_STANDARD 17)

find_package(OpenMP REQUIRED)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

if(UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(WIN32)
    message("This is a Windows System")
endif()



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
