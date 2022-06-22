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

int main(){
    int n;
    std::vector<Point> pts = {};
    std::cout << std::boolalpha;
    std::cout << "Enter the number of points:\n";
    std::cin >> n;
    std::cout << "Enter the points:\n";
    for (int i;i<n;i++){
        Point p;
        std::cin >> p.x >> p.y;
        pts.push_back(p);
    }
    int idx1, idx2;
    double dist;
    closest_pair(pts, idx1, idx2, dist);
    std::cout << "closest pair: " << idx1 << ", " << idx2 << "\n";
    std::cout << "distance: " << dist << "\n";
}

/*実行結果
./kadai20
Enter the number of points:
3
Enter the points:
2 0 2 1.5 0 1.5
closest pair: 0, 1
distance: 1.5

*/