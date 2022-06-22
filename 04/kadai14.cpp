#include<cstdlib>
#include<iostream>
#include<cstring>

int main(int argc, char* argv[])
{
    bool flag = true;
    bool space = false;
    for(int i = 1;i < argc;++i){
        if (i == 1 && std::strcmp(argv[1], "-n") == 0){
            flag = false;
        }
        else{
            std::cout << (space?" ":"") << argv[i];
            space = true;
        }
    }
    if(flag)    std::cout << '\n';
}

/*実行結果
wsltatsuhiko@DESKTOP-240C7JS:/mnt/c/Users/tatsuhiko/OneDrive - 中央大学/ChuoUniv/B201/プログラミング上級演習/04$ ./kadai14 Clang GCC MSVC
Clang GCC MSVC
wsltatsuhiko@DESKTOP-240C7JS:/mnt/c/Users/tatsuhiko/OneDrive - 中央大学/ChuoUniv/B201/プログラミング上級演習/04$ ./kadai14 -n
wsltatsuhiko@DESKTOP-240C7JS:/mnt/c/Users/tatsuhiko/OneDrive - 中央大学/ChuoUniv/B201/プログラミング上級演習/04$ ./kadai14 -n Clang GCC MSVC
Clang GCC MSVCwsltatsuhiko@DESKTOP-240C7JS:/mnt/c/Users/tatsuhiko/OneDrive - 中央大学/ChuoUniv/B201/プログラミング上級演習/04$ ./kadai14 -no errors
-no errors
wsltatsuhiko@DESKTOP-240C7JS:/mnt/c/Users/tatsuhiko/OneDrive - 中央大学/ChuoUniv/B201/プログラミング上級演習/04$ ./kadai14 -n -n
-nwsltatsuhiko@DESKTOP-240C7JS:/mnt/c/Users/tatsuhiko/OneDrive - 中央大学/ChuoUniv/B201/プログラミング上級演習/04$ ./kadai14

wsltatsuhiko@DESKTOP-240C7JS:/mnt/c/Users/tatsuhiko/OneDrive - 中央大学/ChuoUniv/B201/プログラミング上級演習/04$
*/