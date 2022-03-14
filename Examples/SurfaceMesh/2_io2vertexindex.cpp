#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/draw_surface_mesh.h>
#include <fstream>
#include <vector>
#include <time.h>
#include <iostream>
#include "Core/Core.h"
typedef CGAL::Simple_cartesian<double>                       Kernel;
typedef Kernel::Point_3                                      Point;
typedef CGAL::Surface_mesh<Point>                            Mesh;
typedef Mesh::Face_index                                     face_descriptor;
typedef Mesh::Vertex_index                                   vertex_descriptor;
int main(int argc, char* argv[])
{
  const std::string filename = (argc>1) ? argv[1] : CGAL::data_file_path("meshes/elephant.off");
  Mesh sm;
  DWORD dwStart, dwEnd, deltaTime;
  dwStart = GetTickCount();
  auto path = g_DataPath/"scene_mesh_refine.ply";
  if(!CGAL::IO::read_polygon_mesh( path.string(), sm))
  {
    std::cerr << "Invalid input file." << std::endl;
    return EXIT_FAILURE;
  }
  dwEnd =GetTickCount();
  deltaTime = (dwEnd - dwStart) / CLOCKS_PER_SEC;
  std::cout << "The run time1 is: " << deltaTime << "s" << std::endl;
  
  dwStart = GetTickCount();
  std::vector<uint32_t> indexs;
  indexs.resize(sm.number_of_faces()*3);
  for (face_descriptor f : sm.faces())
  {
      // std::cout << f << std::endl;
      // std::cout << "v = " << std::endl;
      for(vertex_descriptor vd : CGAL::vertices_around_face(sm.halfedge(f), sm))
      {
          // std:: cout << vd << std::endl;
          indexs.push_back(vd);
      }
  }
  dwEnd =GetTickCount();
  deltaTime = (dwEnd - dwStart) / CLOCKS_PER_SEC;
  std::cout << "The run time2 is: " << deltaTime << "s" << std::endl;
  // CGAL::draw(sm);
  return EXIT_SUCCESS;
}