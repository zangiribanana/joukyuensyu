#include <iostream>

void return_wareki(int seireki) {
    if (seireki >= 1868 && seireki <= 1912) {
        std::cout << "明治" << seireki - 1868 + 1 << "年です" << std::endl;
    }
    if (seireki >= 1912 && seireki <= 1926) {
        std::cout << "大正" << seireki - 1912 + 1 << "年です" << std::endl;
    }
    if (seireki >= 1926 && seireki <= 1989) {
        std::cout << "昭和" << seireki - 1926 + 1 << "年です" << std::endl;
    }
    if (seireki >= 1989 && seireki <= 2019) {
        std::cout << "平成" << seireki - 1989 + 1 << "年です" << std::endl;
    }
    if (seireki >= 2019) {
        std::cout << "令和" << seireki - 2019 + 1 << "年です" << std::endl;
    }
}

int main() {
    int year;
    std::cout <<"年を西暦で入力してください" << std::endl;
    std::cin >> year;
    return_wareki(year);
    return 0;
}
/*
年を西暦で入力してください
1900
明治33年です

年を西暦で入力してください
2019
平成31年です
令和1年です

年を西暦で入力してください
2022
令和4年です
*/