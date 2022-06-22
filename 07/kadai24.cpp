#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point
{
    double x;
    double y;
};
double distance(Point a, Point b)
{
    return std::hypot(a.x - b.x, a.y - b.y);
}
struct Circle
{
    Point center;
    double radius;
    bool contains(Point p)
    {
        if (distance(p, center) <= radius)
            return true;
        else
            return false;
    }
};

Circle circumcircle(Point a, Point b, Point c) // この関数は正しい
{
    double a_lencgh = distance(b, c);
    double b_lencgh = distance(c, a);
    double c_lencgh = distance(a, b);
    double w_a = std::pow(a_lencgh, 2) * ((-1) * std::pow(a_lencgh, 2) + std::pow(b_lencgh, 2) + std::pow(c_lencgh, 2));
    double w_b = std::pow(b_lencgh, 2) * (std::pow(a_lencgh, 2) + (-1) * std::pow(b_lencgh, 2) + std::pow(c_lencgh, 2));
    double w_c = std::pow(c_lencgh, 2) * (std::pow(a_lencgh, 2) + std::pow(b_lencgh, 2) + (-1) * std::pow(c_lencgh, 2));

    Circle result;
    result.center.x = (w_a * a.x + w_b * b.x + w_c * c.x) / (w_a + w_b + w_c);
    result.center.y = (w_a * a.y + w_b * b.y + w_c * c.y) / (w_a + w_b + w_c);

    result.radius = (a_lencgh * b_lencgh * c_lencgh) / sqrt((a_lencgh + b_lencgh + c_lencgh) * ((-1) * a_lencgh + b_lencgh + c_lencgh) * (a_lencgh - b_lencgh + c_lencgh) * (a_lencgh + b_lencgh - c_lencgh));
    return result;
}

int num_empty_ciecle_triangles(std::vector<Point> &points)
{
    int empty_circle = 0;
    for (auto i = 0u; i < points.size(); i++)
    {
        for (auto j = i + 1; j < points.size(); j++)
        {
            for (auto k = j + 1; k < points.size(); k++)
            {
                Circle gaisetsu = circumcircle(points[i], points[j], points[k]); // 外接円を作る
                int pnt_in_ciecle = 0;                                           // 内円点の数

                for (auto l = 0u; l < points.size(); l++)
                {
                    if (i == l || j == l || k == l)
                        continue;
                    // 三角形を構成する点も含めて順番に外接円の内部に存在する点があるか判定
                    if (gaisetsu.contains(points[l]))
                    {
                        ++pnt_in_ciecle;
                    }
                }
                // 内円点の数がゼロならば、points[i], points[j], points[k]からなる三角形は空円三角形
                if (pnt_in_ciecle == 0)
                {
                    ++empty_circle;
                }
            }
        }
    }
    return empty_circle;
}

int main()
{
    int num_of_points;
    std::cout << "Enter the number of points:\n";
    std::cin >> num_of_points;
    std::vector<Point> points;
    points.resize(num_of_points);

    std::cout << "Enter the points:\n";
    for (Point &val : points)
    {
        std::cin >> val.x >> val.y;
    }
    std::cout << "# empty-circle triangle: " << num_empty_ciecle_triangles(points) << "\n";
}
/*実行結果
./kadai24
Enter the number of points:
4
Enter the points:
-0.5 0.0 1.0 0.0 1.0 1.0 0.0 1.0
# empty-circle triangle: 2

./kadai24
Enter the number of points:
5
Enter the points:
-0.5 0.0 1 0 1 1 0 1 0.5 0.51
# empty-circle triangle: 4

 ./kadai24
Enter the number of points:
7
Enter the points:
0 0 1 4 2 2 3 6 5 2.01 9 0 9 6
# empty-circle triangle: 7
*/