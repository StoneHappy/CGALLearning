cmake_minimum_required(VERSION 3.0)
project(CGALLearning)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# vcpkg include目录
set(VCPKG_INCLUDE_DIR E:/softwares/vcpkg/installed/x64-windows-static/include)
if(MSVC)
    message("Compiler: MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /source-charset:utf-8 /execution-charset:gbk /std:c++17")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    # 在Release模式下 不显示后台
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /subsystem:windows /entry:mainCRTStartup")
endif()

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules;${CMAKE_MODULE_PATH}")
INCLUDE(AddCGALExecutable)
######################### Add VENDORS_DIR #####################
set(VENDORS_DIR ${CMAKE_SOURCE_DIR}/Vendors)

########################## QT #################################
find_package(Qt5 COMPONENTS Widgets OpenGL)
if(Qt5_FOUND)
    message("FOUND QT")
else()
    message("NOT FOUND QT")
endif()
# 寻找让MOC找到ui文件
set(CMAKE_AUTOUIC_SEARCH_PATHS "${VCPKG_INCLUDE_DIR}/CGAL/Qt/resources")
# 定义CGAL数据地址
add_definitions(-DCGAL_DATA_DIR="E:/learning/cgal/Data/data")
#CGAL_Qt5 is needed for the drawing.
find_package(CGAL REQUIRED OPTIONAL_COMPONENTS Qt5 Core)
if(CGAL_Qt5_FOUND)
  message("CGAL QT FOUND")
endif()
# Editor static lib
add_subdirectory(Examples)