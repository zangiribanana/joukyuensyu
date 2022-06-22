#include <iostream>
#include <vector>
void print_container(std::vector<int>& values) { //参照渡しされるので関数内からvalues本体を操作できる
    int n = values.size();
    for (int i = 0; i < n; ++i) {
        std::cout << (i > 0 ? " " : "") << values[i];
    }
    std::cout << "\n";
}
int main() {
    std::cout << "データ数を入力してください:\n";
    int n;
    std::cin >> n;
    std::cout << "整数データを入力してください:\n";
    std::vector<int> vals = {};
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        vals.push_back(val);
    }
    std::cout << "入力されたデータ:\n";
    print_container(vals);
}