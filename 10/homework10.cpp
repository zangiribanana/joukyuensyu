#include <iostream>
#include <random>
void random1() {
    std::cout << "サイコロを5回振ります:\n";
    std::random_device random;
    for (int i = 0; i < 5; ++i) {
        double r01 = random() / (random.max() + 1.0);
        int x = 1 + 6 * r01;
        std::cout << x << "\n";
    }
}
void random2() {
    std::cout << "サイコロを5回振ります:\n";
    std::mt19937 random;
    for (int i = 0; i < 5; ++i) {
        double r01 = random() / (random.max() + 1.0);
        int x = 1 + 6 * r01;
        std::cout << x << "\n";
    }
}
int main() {
    random1();
    random2();
}
/*
$ ./homework10
サイコロを5回振ります:
2
2
4
6
2
サイコロを5回振ります:
5
1
6
6
1
*/