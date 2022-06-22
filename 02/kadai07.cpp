#include <iostream>
#include <cmath>

void minmax_index(double a[], int n, int *ptr_to_min_idx, int *ptr_to_max_idx){
    double max = a[0];
    int min_idx, max_idx;
    double min = a[0];
    for (int i = 0; i < n; i++) {
        if(max <= a[i]) {
            max = a[i];
            max_idx = i;
        }
        if(min > a[i]) {
            min = a[i];
            min_idx = i;
        }
    }
    *ptr_to_max_idx = max_idx;
    *ptr_to_min_idx = min_idx;
}
int main() {
    int n;
    double values[1000];
    int min_idx, max_idx;
    std::cout << "Enter the number of elements:\n";
    std::cin >> n;
    std::cout << "Enter real numbers:\n";
    for (int i = 0; i < n; i++){
        std::cin >> values[i];
    }
    minmax_index(values, n, &min_idx, &max_idx);
    std::cout << "min index: " << min_idx << '\n';
    std::cout << "max index: " << max_idx << '\n';
    return 0;
}
/*入出力例
Enter the number of elements:
5
Enter real numbers:
10 20 20 10 20
min index:0
max index:4

Enter the number of elements:
1
Enter real numbers:
1234.5
min index:0
max index:0

Enter the number of elements:
3
Enter real numbers:
-0.1 0.1 -0.5
min index:2
max index:1
*/