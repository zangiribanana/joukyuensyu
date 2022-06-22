#include<iostream>
#include<cmath>
#include<algorithm>

struct Point {
    double x;
    double y;
};
double distance(Point a, Point b) {
    return std::sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
}
struct Circle {
    Point center;
    double radius;
    bool contains(Point p) {
        if (distance(p, center) <= radius) return true;
        else return false;
    }
};

int main(){
    Circle c;
    Point p;
    std::cout << std::boolalpha;
    std::cout << "Enter a circle:\n";
    std::cin >> c.center.x >> c.center.y >> c.radius;
    std::cout << "Enter a point:\n";
    std::cin >> p.x >> p.y;
    std::cout << "contain?: " << c.contains(p) << "\n";
}

/*実行結果
./kadai19
Enter a circle:
1.0 1.0 1.0
Enter a point:
0.5 0.5
contain?: true

./kadai19
Enter a circle:
0.0 0.0 5.0
Enter a point:
5.0 5.0
contain?: false

./kadai19
Enter a circle:
3.0 4.0 5.0
Enter a point:
5.0 0.0
contain?: true
*/