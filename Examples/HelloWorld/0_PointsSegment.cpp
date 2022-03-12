#include <iostream>
#include <CGAL/Simple_cartesian.h>
typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point_2;
typedef Kernel::Segment_2 Segment_2;

int main()
{
    Point_2 p(1, 1), q(10, 10);

    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q.x() << " " << q.y() << std::endl;

    std::cout << "sqdist(p, q) = " << CGAL::squared_distance(p, q) << std::endl;

    Segment_2 s(p, q);
    Point_2 m(5, 9);

    std::cout << "m = " << m << std::endl;
    std::cout << "sqdist(Segment_2(p, q), m) = " << CGAL::squared_distance(s, m) << std::endl;

    switch (CGAL::orientation(p, q, m))
    {
    case CGAL::COLLINEAR:
        std::cout << "are collinear\n";
      break;
    case CGAL::LEFT_TURN:
        std::cout << "are LEFT_TURN\n";
      break;
    case CGAL::RIGHT_TURN:
        std::cout << "are RIGHT_TURN\n";
      break;
    
    default:
      break;
    }

    std::cout << "midpoint = " << CGAL::midpoint(p, q) << std::endl;
}