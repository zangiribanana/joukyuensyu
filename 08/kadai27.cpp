#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct PointOnEarth
{
    double lat; // 緯度（単位は度、北緯は正、南緯は負）
    double lon; // 経度（単位は度、東経は正、西経は負）
};
std::istream &operator>>(std::istream &in, PointOnEarth &p)
{
    in >> p.lat >> p.lon;
    return in;
}
double deg_to_rad(double deg)
{
    double pi = std::acos(-1.0);
    return deg * pi / 180;
}
double geodesic_distance(PointOnEarth a, PointOnEarth b)
{
    double pi = std::acos(-1.0);
    double g = std::pow(sin(std::abs(a.lat - b.lat) / 2), 2);
    double h = cos(a.lat) * cos(b.lat) * std::pow((sin(std::abs(a.lon - b.lon) / 2)), 2);
    return 40000 * std::asin(sqrt(g + h)) / pi;
}

int main()
{
    PointOnEarth a, b;
    std::cout << "Enter two points on the Earth:" << std::endl;
    std::cin >> a >> b;
    a.lat = deg_to_rad(a.lat);
    a.lon = deg_to_rad(a.lon);
    b.lat = deg_to_rad(b.lat);
    b.lon = deg_to_rad(b.lon);
    std::cout << "Geodesic distance: " << geodesic_distance(a, b) << " km" << std::endl;
}

/*実行結果
echo 35.65861 139.74556 34.65254 135.50632 | ./kadai27
Enter two points on the Earth:
Geodesic distance: 400.964 km

echo 35.65861 139.74556 00.00000 139.74556 | ./kadai27   
Enter two points on the Earth:
Geodesic distance: 3962.07 km

echo 35.65861 139.74556 -35.65861 -40.25444 | ./kadai27  
Enter two points on the Earth:
Geodesic distance: 20000 km
*/