#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

struct Rational
{
    long long numer; // 分子
    long long denom; // 分母
};
std::istream &operator>>(std::istream &in, Rational &r)
{
    in >> r.numer >> r.denom;
    return in;
}
std::ostream &operator<<(std::ostream &out, Rational r)
{
    out << r.numer << "/" << r.denom;
    return out;
}
bool operator<(Rational r1, Rational r2)
{
    long long tmp1, tmp2;
    tmp1 = r1.numer*r2.denom / std::gcd(r1.denom, r2.denom);
    tmp2 = r2.numer*r1.denom / std::gcd(r1.denom, r2.denom);
    if (tmp1 < tmp2)
        return true;
    else
        return false;

}
int main()
{
    int num_of_vals;
    std::vector<Rational> r;
    std::cout << "Enter the number of elements:" << std::endl;
    std::cin >> num_of_vals;
    std::cout << "Enter the elements:" << std::endl;
    for (int i = 0; i < num_of_vals; ++i)
    {
        Rational val;
        std::cin >> val;
        r.push_back(val);
    }
    std::sort(r.begin(), r.end());
    std::cout << "Sorted elements:" << std::endl;
    for (auto x : r)
    {
        std::cout << x << std::endl;
    }
}
/*実行結果
./kadai30
Enter the number of elements:
3
Enter the elements:
2 5 3 8 5 20
Sorted elements:
5/20
3/8
2/5

./kadai30
Enter the number of elements:
4
Enter the elements:
-1 11 4 22 -9 33 16 44
Sorted elements:
-9/33
-1/11
4/22
16/44

./kadai30
Enter the number of elements:
5
Enter the elements:
1 10 9 10 9 10 3 10 7 10
Sorted elements:
1/10
3/10
7/10
9/10
9/10
*/