#include<iostream>
#include<cmath>
struct Point3 {
    double x;
    double y;
    double z;
};
std::istream& operator>>(std::istream& in, Point3& p){
    in >> p.x >> p.y >> p.z;
    return in;
}
double triangle_area(Point3 a, Point3 b, Point3 c){
    Point3 tmp;
    tmp.x = (b.y-a.y)*(c.z-a.z)-(b.z-a.z)*(c.y-a.y);
    tmp.y = (b.z-a.z)*(c.x-a.x)-(b.x-a.x)*(c.z-a.z);
    tmp.z = (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    return std::hypot(tmp.x, tmp.y, tmp.z)/2;
}

int main(){
    Point3 a, b, c;

    std::cout << "Enter three points:" <<std::endl;
    std::cin >> a >> b >> c;
    std::cout << "Triangle area: " << triangle_area(a, b, c) << std::endl;


}
/*実行結果
./kadai25
Enter three points:
0.2 0 0 0 0.2 0 0 0 0.4
Triangle area: 0.06
[21D8101016K@ISE46c 08]$ ./kadai25
Enter three points:
2 3 4 1 7 1 1 1 7
Triangle area: 5.19615
[21D8101016K@ISE46c 08]$ ./kadai25
Enter three points:
1 2 3 10 20 30 100 200 300
Triangle area: 0
*/