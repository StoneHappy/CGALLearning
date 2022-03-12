cmake_minimum_required(VERSION 3.0)
project(HelloWorld)

add_executable(hw_0_PointsSegment
                                0_PointsSegment.cpp 
            )

target_link_libraries(hw_0_PointsSegment
                    PUBLIC
                                CGAL::CGAL CGAL::CGAL_Core
)
# target_include_directories(${PROJECT_NAME} PUBLIC
#                                 ${CMAKE_CURRENT_SOURCE_DIR}
#              )
