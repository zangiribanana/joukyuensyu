#include <iostream>
#include <string>
int main() {
    std::cout << std::boolalpha;

    char c_str1[] = "string";
    char c_str2[] = "strong";
    c_str2[3] = 'i';
    std::cout << (c_str1 == c_str2) << '\n'; // ポインタの比較になる

    std::string str1 = "string";
    std::string str2 = "strong";
    str2[3] = 'i';
    std::cout << (str1 == str2) << '\n';

    std::string str3 = "strong";
    std::string str4 = str3 + "er";
    std::string str5 = str3;
    str5 += "est";
    if (str4 < str5) {
        std::cout << str4 << " < " << str5 << '\n';
    }
}
