#include <iostream> // std::cout, std::boolalpha

struct Point
{
    double x;
    double y;
};
bool operator==(Point p, Point q)
{
    return p.x == q.x && p.y == q.y;
}
void swap(int &x, int &y)
{
    std::cout << "整数" << x << "と整数" << y << "を交換\n";
    int tmp = x;
    x = y;
    y = tmp;
}
void swap(double &x, double &y)
{
    std::cout << "実数" << x << "と実数" << y << "を交換\n";
    double tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    Point a = {0.2, 0.3};
    Point b = a;
    swap(a.x, a.y);
    std::cout << std::boolalpha;
    std::cout << "a==b: " << (a == b) << "\n";
}