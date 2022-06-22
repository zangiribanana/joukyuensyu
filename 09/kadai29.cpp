#include<iostream>
#include<vector>
#include<algorithm>
int main(){
    std::cout << "Enter th number of elements:\n";
    int n;
    std::cin >> n;
    std::cout << "Enter the elements:\n";
    std::vector<double> values;
    for (int i = 0; i < n; ++i)  {
        double val;
        std::cin >> val;
        values.push_back(val);
    }
    auto it_beg = values.begin();
    auto it_end = values.end();
    for (int i = 0;i < 5;i++) {
        auto it_min = std::min_element(it_beg, it_end);
        std::swap(values[i], *it_min);
        ++it_beg;
    }
    it_beg = values.begin();
    it_end = values.end();
    for (int i = n-1;i >= n-5;i--) {
        auto it_max = std::max_element(it_beg, it_end);
        std::swap(values[i], *it_max);
        --it_end;
    }
    std::cout << "Sorted elements:\n";
    for (int i = 0;i < 5;++i) {
        std::cout << values[i] << std::endl;
    }
    std::cout << "⋮" << std::endl;
    for (int i = n-5;i < n;++i) {
        std::cout << values[i] << std::endl;
    }
}

/*実行結果
./kadai29
Enter th number of elements:
11
Enter the elements:
0.5 0.4 0.3 0.2 0.1 0.0 -0.1 -0.2 -0.3 -0.4 -0.5
Sorted elements:
-0.5
-0.4
-0.3
-0.2
-0.1
⋮
0.1
0.2
0.3
0.4
0.5

echo 1000 `seq 1000 | sort -R` | ./kadai29
Enter th number of elements:
Enter the elements:
Sorted elements:
1
2
3
4
5
⋮
996
997
998
999
1000

*/