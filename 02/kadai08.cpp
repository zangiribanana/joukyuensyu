#include <iostream>

void minmax_index(double a[], int n, int *ptr_to_min_idx, int *ptr_to_max_idx)
{
    int cnt = 0;
    int first = 0;
    int last = n;
    // 初期値は0
    *ptr_to_min_idx = 0;
    *ptr_to_max_idx = 0;
    // 範囲の要素数が 0 か 1 だったら、そのまま idx を返す
    if (first != last && ++first != last)
    {
        // 最初の 2 個を比較して、小さい方を min_idx に、大きい方を max_idx に設定
        if (a[0] > a[first])
            *ptr_to_min_idx = first;
        else if (a[0] < a[first])
            *ptr_to_max_idx = first;
        cnt++;
        // 残りの要素を 2 個ずつ繰り返し
        while (++first != last)
        {
            int prev = first;

            // 残りの要素が 1 個しか無かったら、min_idx と max_idx の両方の要素と比較して、
            // 必要に応じで結果を更新後、ループを抜ける
            if (++first == last)
            {
                if (a[prev] < a[*ptr_to_min_idx])
                    *ptr_to_min_idx = prev;
                else
                    *ptr_to_max_idx = prev;
                cnt++;
                break;
            }

            // 残りの要素が 2 個以上あれば、まずその 2 個を比較してから、小さい方を min_idx と、
            // 大きい方を max_idx と比較して、必要に応じて結果を更新
            if (first < prev)
            {
                ++cnt;
                if (a[first] < a[*ptr_to_min_idx]){
                    *ptr_to_min_idx = first;
                    ++cnt;
                }
                if (a[prev] >= a[*ptr_to_max_idx]){
                    *ptr_to_max_idx = prev;
                    ++cnt;
                }
            }
            else
            {
                ++cnt;
                if (a[prev] < a[*ptr_to_min_idx]){
                    *ptr_to_min_idx = prev;
                    ++cnt;
                }
                if (a[first] >= a[*ptr_to_max_idx]){
                    *ptr_to_max_idx = first;
                    ++cnt;
                }
            }
        }
    }
}

int main()
{
    int n;
    double values[1000];
    int min_idx, max_idx;
    std::cout << "Enter the number of elements:\n";
    std::cin >> n;
    std::cout << "Enter real numbers:\n";
    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i];
    }
    minmax_index(values, n, &min_idx, &max_idx);
    std::cout << "min index: " << min_idx << '\n';
    std::cout << "max index: " << max_idx << '\n';
    return 0;
}
/*入出力例
./kadai08
Enter the number of elements:
3
Enter real numbers:
-0.1 0.1 -0.5
min index: 2
max index: 1
wsltatsuhiko@DESKTOP-240C7JS:/mnt/c/Users/tatsuhiko/OneDrive - 中央大学/ChuoUniv/B201/プログラ
ミング上級演習/02$ ./kadai08
Enter the number of elements:
5
Enter real numbers:
10 20 20 10 20
min index: 0
max index: 4
wsltatsuhiko@DESKTOP-240C7JS:/mnt/c/Users/tatsuhiko/OneDrive - 中央大学/ChuoUniv/B201/プログラ
ミング上級演習/02$ ./kadai08
Enter the number of elements:
1
Enter real numbers:
1234.5
min index: 0
max index: 0
*/