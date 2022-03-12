cmake_minimum_required(VERSION 3.0)
project(HelloWorld)


############# hw_0_PointsSegment ################
AddCGALExecutable(hw_0_PointsSegment 0_PointsSegment.cpp)

############# hw_1_ArrayConvexHull ################
AddCGALExecutable(hw_1_1_ArrayConvexHull 1_1_ArrayConvexHull.cpp)

############# hw_1_2_VectorConvexHull ################
AddCGALExecutable(hw_1_2_VectorConvexHull 1_2_VectorConvexHull.cpp)

# target_include_directories(${PROJECT_NAME} PUBLIC
#                                 ${CMAKE_CURRENT_SOURCE_DIR}
#              )
