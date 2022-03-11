cmake_minimum_required(VERSION 3.0)
project(CGALLearning)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if(MSVC)
    message("Compiler: MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /source-charset:utf-8 /execution-charset:gbk /std:c++17")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    # 在Release模式下 不显示后台
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /subsystem:windows /entry:mainCRTStartup")
endif()

add_definitions(-DOSG_LIBRARY_STATIC)
######################### Add VENDORS_DIR #####################
set(VENDORS_DIR ${CMAKE_SOURCE_DIR}/Vendors)

########################## QT #################################
find_package(Qt5 COMPONENTS Widgets OpenGL)
if(Qt5_FOUND)
    message("FOUND QT")
else()
    message("NOT FOUND QT")
endif()

# Editor static lib
add_subdirectory(Examples)