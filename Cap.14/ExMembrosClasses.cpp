#include <iostream>

class Point3d
{
private:
    int m_x;
    int m_y;
    int m_z;

public:
    void setValues(int m, int y, int z)
    {
        m_x = m;
        m_y = y;
        m_z = z;
    }
    void print()
    {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">";
    }
    bool isEqual(Point3d &point)
    {
        return (point.m_x == m_x && point.m_y == m_y && point.m_z == m_z);
    }
};

int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    // point.print();
    std::cout << "Point 1 and point 2 are" << (point.isEqual(point2) ? "" : " not") << " Equal\n";

    Point3d point3;
    point3.setValues(4,5,6);
    std::cout << "Point 3 and point 1 are" << (point3.isEqual(point) ? "" : " not") << " Equal\n";

    return 0;
}