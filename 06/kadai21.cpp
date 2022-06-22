#include<iostream>
#include<vector>
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
void closest_pair(std::vector<Point>& points, int& idx1, int& idx2, double& dist) {
    idx1 = 0;
    idx2 = 1;
    dist = distance(points[0], points[1]);
    for (int i = 0;i < points.size();++i) {
        for (int j = i + 1;j < points.size();++j) {
            if (distance(points[i], points[j]) < dist){
                dist = distance(points[i], points[j]);
                idx1 = i;
                idx2 = j;
            }
        }
    }
}

struct Rectangle {
    Point left;
    Point right;
};

bool intersect (Circle c, Rectangle rec) {
    if ((c.center.x >= rec.left.x)&&(c.center.x <= rec.right.x)&&(c.center.y <= rec.right.y + c.radius)&&(c.center.y >= rec.left.y - c.radius)){
        return true;
    }
    else if ((c.center.x >= rec.left.x - c.radius)&&(c.center.x <= rec.right.x + c.radius)&&(c.center.y >= rec.left.y)&&(c.center.y <= rec.right.y)){
        return true;
    }
    else if (std::pow(rec.left.x-c.center.x,2)+std::pow(rec.left.y-c.center.y,2) <= std::pow(c.radius,2)){
        return true;
    }
    else if (std::pow(rec.left.x-c.center.x,2)+std::pow(rec.right.y-c.center.y,2) <= std::pow(c.radius,2)){
        return true;
    }
    else if (std::pow(rec.right.x-c.center.x,2)+std::pow(rec.left.y-c.center.y,2) <= std::pow(c.radius,2)) {
        return true;
    }
    else if (std::pow(rec.right.x-c.center.x,2)+std::pow(rec.right.y-c.center.y,2) <= std::pow(c.radius,2)) {
        return true;
    }
    else return false;
}

int main(){
    int n;
    Circle c;
    std::vector<Point> pts = {};
    std::cout << std::boolalpha;

    std::cout << "Enter a circle:\n";

    std::cin >> c.center.x >> c.center.y >> c.radius;

    std::cout << "Enter a rectangle:\n";

    Rectangle rec;
    std::cin >> rec.left.x >> rec.left.y >> rec.right.x >> rec.right.y;
    std::cout << "intersect?: " << intersect(c, rec) << "\n";
}

/*実行結果
./kadai21
Enter a circle:
-1.0 -1.0 1.5
Enter a rectangle:
0.0 0.0 2.0 1.0
intersect?: true

./kadai21
Enter a circle:
1.5 2.0 0.5
Enter a rectangle:
0.0 0.0 2.0 1.0
intersect?: false

./kadai21
Enter a circle:
1.5 0.5 2.0
Enter a rectangle:
0.0 0.0 2.0 1.0
intersect?: true
*/