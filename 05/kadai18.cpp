#include<iostream>
#include<vector>
#include<utility>

void merge(std::vector<double>& values, int beg, int mid, int end)
{
    // 1. 一時作業用のコンテナ
    std::vector<double> buffer;

    // 2. 要素を小さい順に一時作業用コンテナに挿入する
    int itr_left = beg;    // ソート済みの左側グループの最小値のindex
    int itr_right = mid;   // ソート済みの右側グループの最小値のindex
    while (itr_left < mid && itr_right <end) {
        // 左側採用
        if (values[itr_left] <= values[itr_right]) {
            buffer.push_back(values[itr_left]);
            ++itr_left;
        }
        // 右側採用
        else {
            buffer.push_back(values[itr_right]);
            ++itr_right;
        }
    }
    // 右側を選択し終わったとき、左側採用
    while (itr_left < mid) {
        buffer.push_back(values[itr_left]);
        ++itr_left;
    }
    // 左側を選択し終わったとき、右側採用
    while (itr_right < end) {
        buffer.push_back(values[itr_right]);
        ++itr_right;
    }

    // 3. ソートされた要素を元のコンテナに戻す
    int size = end - beg;
    for (int k = 0; k < size; ++k) {
        values[beg + k] = buffer[k];
    }

}

void merge_sort_impl(std::vector<double>& values, int beg, int end)
{
    int size = end - beg;

    // 個数が1個以下なら、既にソート済みとみなせるので何もする必要ない
    if (size <= 1) {
        return;
    }

    int mid = beg + size / 2;
    merge_sort_impl(values, beg, mid);
    merge_sort_impl(values, mid, end);
    merge(values, beg, mid, end);
}

void merge_sort(std::vector<double>& values)
{
    merge_sort_impl(values, 0, values.size());
}

int main()
{
    int n;
    std::vector<double> values;
    std::cout << "Enter the number of elements:\n";
    std::cin >> n;
    std::cout << "Enter the elements:\n";
    for(int i = 0;i < n;++i){
        double val;
        std::cin >> val;
        values.push_back(val);
    }
    merge_sort(values);
    std::cout << "Sorted elements: ";
    for (auto i =0u;i < values.size(); ++i){
        std::cout << (i > 0 ? " " : "") << values[i];
    }
    std::cout << "\n";
}
/*
./kadai18
Enter the number of elements:
3
Enter the elements:
-0.1 0.1 -0.3
Sorted elements: -0.3 -0.1 0.1

./kadai18
Enter the number of elements:
4
Enter the elements:
3 2 4 1
Sorted elements: 1 2 3 4

./kadai18
Enter the number of elements:
5
Enter the elements:
20 30 10 30 20
Sorted elements: 10 20 20 30 30
*/