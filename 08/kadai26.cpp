#include<iostream>
#include<cmath>
#include<numeric>

struct Rational {
    int numer;
    int denom;
    void reduce(){
        int tmp = std::gcd(numer, denom);
        numer /= tmp;
        denom /= tmp;
    }
};
std::istream& operator>>(std::istream& in, Rational& r){
    in >> r.numer >> r.denom;
    return in;
}
std::ostream& operator<<(std::ostream& out, Rational r){
    out << r.numer << "/" << r.denom;
    return out;
}
Rational operator+(Rational r1, Rational r2){
    Rational tmp;
    tmp.numer = r1.numer * r2.denom + r2.numer * r1.denom;
    tmp.denom = r1.denom * r2.denom;
    tmp.reduce();
    return  tmp;
}
Rational operator-(Rational r1, Rational r2){
    Rational tmp;
    tmp.numer = r1.numer * r2.denom - r2.numer * r1.denom;
    tmp.denom = r1.denom * r2.denom;
    tmp.reduce();
    if (tmp.denom<0){
        tmp.numer *= -1;
        tmp.denom *= -1;
    }
    return  tmp;
}
Rational operator*(Rational r1, Rational r2){
    Rational tmp;
    tmp.numer = r1.numer * r2.numer;
    tmp.denom = r1.denom * r2.denom;
    tmp.reduce();
    if (tmp.denom<0){
        tmp.numer *= -1;
        tmp.denom *= -1;
    }
    return  tmp;
}
Rational operator/(Rational r1, Rational r2){
    Rational tmp;
    tmp.numer = r1.numer * r2.denom;
    tmp.denom = r1.denom * r2.numer;
    tmp.reduce();
    if (tmp.denom<0){
        tmp.numer *= -1;
        tmp.denom *= -1;
    }
    return  tmp;
}
int main(){
    Rational r1, r2;
    std::cout << "Enter two rational numbers x and y:" << std::endl;
    std::cin >> r1 >> r2;
    //std::cout << r1 << r2; // test
    std::cout << "Arithmetic results:" << std::endl;
    std::cout << "x + y = " << r1 + r2 << std::endl;
    std::cout << "x - y = " << r1 - r2 << std::endl;
    std::cout << "x * y = " << r1 * r2 << std::endl;
    std::cout << "x / y = " << r1 / r2 << std::endl;
}
/*実行結果
echo 13 30 -9 20 | ./kadai26
Enter two rational numbers x and y:
Arithmetic results:
x + y = -1/60
x - y = 53/60
x * y = -39/200
x / y = -26/27
[21D8101016K@ISE46c 08]$ echo 3 12 1 12 | ./kadai26
Enter two rational numbers x and y:
Arithmetic results:
x + y = 1/3
x - y = 1/6
x * y = 1/48
x / y = 3/1
[21D8101016K@ISE46c 08]$ echo 3 100 3 100 | ./kadai26
Enter two rational numbers x and y:
Arithmetic results:
x + y = 3/50
x - y = 0/1
x * y = 9/10000
x / y = 1/1
*/