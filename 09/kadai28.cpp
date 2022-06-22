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
    std::sort(values.begin(), values.end());
    std::reverse(values.begin(), values.end());
    std::cout << "Sorted elements (in descending order):\n";
    for (auto x : values) {
        std::cout << x << std::endl;
    }
}

/*実行結果
echo 5 0.9 0.9 0.7 0.3 0.1 | ./kadai28
Enter th number of elements:
Enter the elements:
Sorted elements (in descending order):
0.9
0.9
0.7
0.3
0.1

echo 7 `seq -3 3 | sort -R` | ./kadai28
Enter th number of elements:
Enter the elements:
Sorted elements (in descending order):
3
2
1
0
-1
-2
-3
*/