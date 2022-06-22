// 課題32, 2022-06-20, 21D8101016K, 田代達彦
#include<iostream>
#include<string>

std::string file_extension(std::string& filename) {
    int index = 0;
    bool flag = false;
    if (filename == "." || filename == "..")    return "";
    for(int i = 0;i < filename.size();i++) {
        if(filename[i] == '.' && i == 0)    continue;
        else if(filename[i] == '.'){
            index = i;
            flag = true;
        }
    }
    if(flag)    return filename.substr(index);
    else return "";
}

int main(){
    std::string filename;
    std::cout << "Enter a filename:" << "\n";
    std::getline(std::cin, filename);
    std::cout << "File extension: " << "\"" << file_extension(filename) << "\"" << '\n';
}

/*
./kadai32
Enter a filename:
kadai99.cpp
File extention: ".cpp"

$ ./kadai32
Enter a filename:
cxx_programming.tar.gz
File extention: ".gz"
$ ./kadai32
Enter a filename:
.emacs.d
File extention: ".d"
$ ./kadai32
Enter a filename:
It's a fine day.
File extention: "."
$ ./kadai32
Enter a filename:
kadai99
File extention: ""
$ ./kadai32
Enter a filename:
.bash_history
File extention: ""
$ ./kadai32
Enter a filename:
.
File extention: ""
$ ./kadai32
Enter a filename:
..
File extention: ""
$ 
*/