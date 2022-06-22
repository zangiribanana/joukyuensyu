// 第5回宿題, 2022/05/17, 21D8101016K, 田代達彦
#include <iostream>
struct PointA {
  double x;
  double y; 
};
void translate(PointA* ptr, double dx, double dy) {
  (*ptr).x += dx;
  (*ptr).y += dy;
}
struct PointB {
  double x;
  double y;
  void translate(double dx, double dy) {
    x += dx;
    y += dy;
  }
};
int main() {
  PointA pa = {10.0, 5.0};
  translate(&pa, 5.0, -5.0);
  std::cout << "(" << pa.x << ", " << pa.y << ")\n";
  PointB pb = {10.0, 5.0};
  pb.translate(5.0, -5.0);
  std::cout << "(" << pb.x << ", " << pb.y << ")\n";
}