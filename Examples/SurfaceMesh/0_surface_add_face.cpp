#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>

typedef CGAL::Simple_cartesian<double> K;
typedef CGAL::Surface_mesh<K::Point_3> Mesh;
typedef Mesh::Vertex_index vertex_descriptor;
typedef Mesh::Face_index face_descriptor;

int main()
{
    Mesh m;

    vertex_descriptor u = m.add_vertex(K::Point_3(0,1,0));
    vertex_descriptor v = m.add_vertex(K::Point_3(0,0,0));
    vertex_descriptor w = m.add_vertex(K::Point_3(1,1,0));
    vertex_descriptor x = m.add_vertex(K::Point_3(1,0,0));

    std::cout << "u = " << u.idx() << std::endl;
    std::cout << "v = " << v.idx() << std::endl;
    std::cout << "w = " << w.idx() << std::endl;
    std::cout << "x = " << x.idx() << std::endl;

    m.add_face(u,v,w);

    face_descriptor f = m.add_face(u,v,x);
    
    if(f == Mesh::null_face())
    {
        std::cerr<<"The face could not be added because of an orientation error."<<std::endl;
        f = m.add_face(u,x,v);
        assert(f != Mesh::null_face());
    }
    return 0;
}