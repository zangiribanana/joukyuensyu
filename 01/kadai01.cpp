#include <iostream>

int main() {
    int x, y;
    std::cout <<"正の整数x, yを入力してください" << std::endl;
    std::cin >> x >> y;
    std::cout << "x/y:" << (double)x / y << std::endl;
    std::cout << "切り捨て:" << x / y <<std::endl;
    std::cout << "切り上げ:" << (x + y - 1) / y << std::endl;
}

/*
正の整数x, yを入力してください
1234 5
x/y:246.8
切り捨て:246
切り上げ:247

正の整数x, yを入力してください
1010 10
x/y:101
切り捨て:101
切り上げ:101
*/