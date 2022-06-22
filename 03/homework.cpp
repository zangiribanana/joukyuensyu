#include <iostream>

/*
受け取ったコマンドライン引数は*argv[]に格納される
index0にはコマンドラインの初めの相対パスが格納される
*/

int main(int argc, char *argv[])  // コマンドライン引数の数argc コマンドライン引数をchar型
{
    std::cout << "プログラム名 argv[0]:" << argv[0] << "\n";
    for(int i = 0; i < argc; ++i){
        std::cout << i << "個目のコマンドライン引数 argv[" << i << "]: ";
        std::cout << argv[i] << "\n";
    }
    std::cout << "(コマンドライン引数の個数:" << argc - 1 << ") \n";

}