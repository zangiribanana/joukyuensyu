#include <iostream>

int yen_to_euro(int yen) {
    return (int)((double)yen / 134.692 + 0.5);
}

int main() {
    int yen;
    std::cout <<"金額を日本円で入力してください" << std::endl;
    std::cin >> yen;
    std::cout << yen_to_euro(yen) << "ユーロ" << std::endl;
}

/*
金額を日本円で入力してください
1346
10ユーロ

金額を日本円で入力してください
1400
10ユーロ

金額を日本円で入力してください
1415
11ユーロ
*/