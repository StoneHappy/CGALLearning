cmake_minimum_required(VERSION 3.0)
project(SurfaceMesh)


############# hw_0_PointsSegment ################
AddCGALExecutable(0_surface_add_face 0_surface_add_face.cpp)

############# 1_sm_iterator ################
AddCGALExecutable(1_half2index 1_half2index.cpp)

############# 1_sm_iterator ################
AddCGALExecutable(2_io2vertexindex 2_io2vertexindex.cpp)
target_link_libraries(2_io2vertexindex
                            PUBLIC
                Qt5::Widgets
                Qt5::OpenGL
                CGAL::CGAL_Basic_viewer
)