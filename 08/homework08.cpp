#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::vector<int> values = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    auto iter_max = std::max_element(values.begin(), values.end());
    std::cout << "最大値：" << *iter_max << "\n";
    std::sort(values.begin(), values.end());
    std::cout << "ソート済み：\n";
    for (auto x : values)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    auto iter_median = values.begin() + values.size() / 2;
    std::cout << "中央値：" << *iter_median << "\n";
}