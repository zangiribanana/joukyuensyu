#include <iostream>
#include <cmath>

void yen_to_euro(int yen, int *ptr_to_euro, int *ptr_to_cent){
    double yen2 = (double)yen;
    *ptr_to_euro = 0;
    while (yen2 - 134.692 > 0) {
        yen2 -= 134.692;
        (*ptr_to_euro)++;
    }
    *ptr_to_cent = std::round(yen2 / 1.34692);
}
int main() {
    int yen;
    int ptr_to_euro, ptr_to_cent;
    std::cout << "Enter the amount in JPY:\n";
    std::cin >> yen;
    yen_to_euro(yen, &ptr_to_euro, &ptr_to_cent);
    std::cout << ptr_to_euro << " euros " << ptr_to_cent << " cents\n";

    return 0;
}
/*入出力例
Enter the amount in JPY:
1346
9 euros 99 cents

Enter the amount in JPY:
1347
10 euros 0 cents

Enter the amount in JPY:
1348
10 euros 1 cents
*/