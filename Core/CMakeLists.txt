cmake_minimum_required(VERSION 3.0)
project(Core)

file(GLOB PROJECT_SOURCES           ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
                                    )

add_library(Core 
                STATIC
                    ${PROJECT_SOURCES}
)

target_include_directories(Core PUBLIC
                    ${CMAKE_CURRENT_SOURCE_DIR}
)                   
