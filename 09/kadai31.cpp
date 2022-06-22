#include <iostream>
#include <vector>

void first_min_first_max_index(std::vector<double> reals, int &min_idx, int &max_idx)
{
    int cnt = 0;
    auto first = reals.begin();
    auto last = reals.end();
    // 初期値は0
    min_idx = 0;
    max_idx = 0;
    // 範囲の要素数が 0 か 1 だったら、そのまま idx を返す
    if (first != last && ++first != last)
    {
        // 最初の 2 個を比較して、小さい方を min_idx に、大きい方を max_idx に設定
        if (*reals.begin() > *first)
            min_idx = first - reals.begin();
        else if (*reals.begin() < *first)
            max_idx = first - reals.begin();
        cnt++;
        // 残りの要素を 2 個ずつ繰り返し
        while (++first != last)
        {
            std::vector<double>::iterator prev = first;

            // 残りの要素が 1 個しか無かったら、min_idx と max_idx の両方の要素と比較して、
            // 必要に応じで結果を更新後、ループを抜ける
            if (++first == last)
            {
                if (*prev < reals.at(min_idx))
                    min_idx = prev - reals.begin();
                else if (*prev > reals.at(max_idx))
                    max_idx = prev - reals.begin();
                cnt++;
                break;
            }

            // 残りの要素が 2 個以上あれば、まずその 2 個を比較してから、小さい方を min_idx と、
            // 大きい方を max_idx と比較して、必要に応じて結果を更新
            if (*first < *prev)
            {
                ++cnt;
                if (*first < reals.at(min_idx)){
                    min_idx = first - reals.begin();
                    ++cnt;
                }
                if (*prev > reals.at(max_idx)){
                    max_idx = prev - reals.begin();
                    ++cnt;
                }
            }
            else if (*first > *prev)
            {
                ++cnt;
                if (*prev < reals.at(min_idx)){
                    min_idx = prev - reals.begin();
                    ++cnt;
                }
                if (*first > reals.at(max_idx)){
                    max_idx = first - reals.begin();
                    ++cnt;
                }
            }
            else
            {
                ++cnt;
                if (*prev < reals.at(min_idx)){
                    min_idx = prev - reals.begin();
                    ++cnt;
                }
                else if (*prev > reals.at(max_idx)){
                    max_idx = prev - reals.begin();
                    ++cnt;
                }
            }
        }
    }
}

int main()
{
    int n;
    std::vector<double> values;
    int min_idx, max_idx;
    std::cout << "Enter the number of elements:\n";
    std::cin >> n;
    values.resize(n);
    std::cout << "Enter real numbers:\n";
    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i];
    }
    first_min_first_max_index(values, min_idx, max_idx);
    std::cout << "min index: " << min_idx << '\n';
    std::cout << "max index: " << max_idx << '\n';
    return 0;
}
/*入出力例
echo 1 1234.5 | ./kadai31
Enter the number of elements:
Enter real numbers:
min index: 0
max index: 0

echo 3 -0.3 0.3 0.9 | ./kadai31
Enter the number of elements:
Enter real numbers:
min index: 0
max index: 2

echo 5 0.1 0.2 0.2 0.1 0.2 | ./kadai31
Enter the number of elements:
Enter real numbers:
min index: 0
max index: 1

echo 6 20 20 10 10 30 30 | ./kadai31
Enter the number of elements:
Enter real numbers:
min index: 2
max index: 4

echo 6 20 10 10 30 30 30 | ./kadai31
Enter the number of elements:
Enter real numbers:
min index: 1
max index: 3

echo 6 20 20 20 20 20 20 | ./kadai31
Enter the number of elements:
Enter real numbers:
min index: 0
max index: 0
*/