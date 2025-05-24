cmake_minimum_required(VERSION 3.28)
project(Ocean)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
    include
    include/basic
    include/exceptions
    include/interface/terminal
    include/interface/gui)

add_library(GlobalConfig
    src/global.cpp)

add_library(Logics 
    src/basic/object.cpp
    src/basic/algae.cpp
    src/basic/cell.cpp
    src/basic/fish.cpp
    src/basic/ocean.cpp
    src/basic/sand.cpp
    src/exceptions/double_insertion.cpp
    )

set(LOG_FILE "${CMAKE_CURRENT_BINARY_DIR}/build_log.txt")


add_library(terminalInterface
            src/interface/terminal/t_ocean.cpp
            )

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Using GCC compiler")
    add_compile_options(-Wall -Wextra -O2)
endif()


add_executable(Game src/main.cpp)
# set_target_properties(Game PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
# )

target_link_libraries(Game terminalInterface Logics GlobalConfig)
