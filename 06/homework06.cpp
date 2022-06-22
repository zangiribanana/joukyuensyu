#include<iostream>
#include<vector>
int main() {
    std::vector<int> values{1, 2, 3, 4, 5};
    std::cout << "コンテナの要素数:" << values.size() << "\n";
    std::cout << "コンテナの中身:";
    for (auto x : values) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    values.resize(10);
    std::cout << "コンテナの要素数:" << values.size() << "\n";
    std::cout << "コンテナの中身:";
    for (auto x : values) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}
/*実行結果
./homework06
コンテナの要素数:5
コンテナの中身:1 2 3 4 5
コンテナの要素数:10
コンテナの中身:1 2 3 4 5 0 0 0 0 0
*/