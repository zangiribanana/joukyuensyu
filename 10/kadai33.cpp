#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<cctype>
// 二つの文字列を自然な順番で比較する関数
bool natural_string_compare(std::string& str1, std::string& str2) {
    int n1 = str1.size();
    int n2 = str2.size();
    int i1 = 0;
    int i2 = 0;
    // 注目添字が末尾以下
    while (i1 < n1 && i2 < n2) {
        // 比べる桁がどちらも数字の時その添字以降の文字列をtmp1, tmp2に格納し、それぞれの先頭の数字をx, yに格納後、yが大きければtrueを返す
        // 比べる桁を数字の分だけ進める
        if (std::isdigit(str1[i1]) && std::isdigit(str2[i2])) {
            std::string tmp1 = str1.substr(i1);
            std::string tmp2 = str2.substr(i2);

            std::size_t num_digits1;
            std::size_t num_digits2;
            int x = std::stoi(tmp1, &num_digits1);        
            int y = std::stoi(tmp2, &num_digits2);
            if ( x < y ) return true;
            if ( x > y ) return false;
            i1 += (int)num_digits1;
            i2 += (int)num_digits2;
        }
        if ( str1[i1] < str2[i2]) return true;
        if ( str1[i1] > str2[i2]) return false;
        ++i1;
        ++i2;
    }
    return n1 - i1 < n2 - i2; // str2の方が注目添字以降の文字列が長ければtrue

}

int main(){
    std::cout << "Enter the number of filenames:\n";
    std::vector<std::string> name;
    int num;
    std::cin >> num;
    std::cout << "Enter the filenames:\n";
    for (int i = 0; i < num;++i) {
        std::string tmp;
        std::cin >> tmp;
        name.push_back(tmp);
    }
    std::sort(name.begin(), name.end(), natural_string_compare);
    std::cout << "Natural sort results:\n";
    for (std::string x : name) {
        std::cout << x << std::endl;
    }
}

/*
$ echo 7 kadai1.cpp kadai10.cpp kadai12.cpp kadai2.cpp homework09.cpp homework100.cpp homework11.cpp | ./kadai33
Enter the number of filenames:
Enter the filenames:
Natural sort results:
homework09.cpp
homework11.cpp
homework100.cpp
kadai1.cpp
kadai2.cpp
kadai10.cpp
kadai12.cpp

$ echo 18 1abca 12a 1a1 1abc 12a1 123ab 123abc 1ab 12ab 1ab 123a 12abc1 1a 123a 123ab1 12abc 12aba 123abc | ./kadai33
Enter the number of filenames:
Enter the filenames:
Natural sort results:
1a
1a1
1ab
1ab
1abc
1abca
12a
12a1
12ab
12aba
12abc
12abc1
123a
123a
123ab
123ab1
123abc
123abc

*/