cmake_minimum_required(VERSION 3.28)
project(Ocean)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
    include
    include/basic
    include/exceptions
    include/utils
    include/interface/terminal
    include/interface/gui)

# add_library(GlobalConfig
#     src/global.cpp)

#add_definitions(-DTERMINAL)
add_library(Logics 
    src/basic/object.cpp
    src/basic/algae.cpp
    src/basic/cell.cpp
    src/basic/fish.cpp
    src/basic/position.cpp
    src/basic/ocean.cpp
    src/basic/sand.cpp
    src/exceptions/double_insertion.cpp
    )

add_library(terminalInterface
        src/interface/terminal/terminal_ocean.cpp
        )

add_library(GUI
        src/interface/gui/gui_ocean.cpp
        src/interface/gui/gui_cell.cpp
        )

add_library(Logging
        src/utils/logger.cpp
        )

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Using GCC compiler")
    add_compile_options(-Wall -Wextra -O2)
endif()


add_executable(Ocean src/main.cpp)
set_target_properties(Ocean PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)

target_link_libraries(Ocean GUI terminalInterface Logics Logging)
target_link_libraries(Ocean sfml-graphics sfml-window sfml-system)