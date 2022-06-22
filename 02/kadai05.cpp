#include <iostream>
#include <cmath>

bool is_prime(int x) {
    int xsqrt = std::sqrt(x);
    if (x == 1)  return false;
    for(int i = 2; i <= (int)xsqrt; i++) {
        if(x % i == 0)  return false;
    }
    return true;
}

int main() {
    int x;
    std::cout << "Enter a positive integer:\n";
    std::cin >> x;
    if (is_prime(x)) {
        std::cout << x << " is a prime number.\n";
    }
    else {
        std::cout << x << " is not a prime number.\n";
    }
    return 0;
}
/*入出力例
Enter a positive integer:
11
11 is a prime number.

Enter a positive integer:
2
2 is a prime number.

Enter a positive integer:
1
1 is not a prime number.

Enter a positive integer:
397483969
397483969 is not a prime number.
*/