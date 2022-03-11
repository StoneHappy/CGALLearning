cmake_minimum_required(VERSION 3.0)
project(DrawSurface)
file(GLOB PROJECT_SOURCES           ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
                                    )

add_executable(${PROJECT_NAME}
                                ${PROJECT_SOURCES} 
            )


target_include_directories(${PROJECT_NAME} PUBLIC
                                ${CMAKE_CURRENT_SOURCE_DIR}
             )
target_link_libraries(${PROJECT_NAME}
                            PUBLIC
                Qt5::Widgets
                Qt5::OpenGL
                CGAL::CGAL_Basic_viewer
)