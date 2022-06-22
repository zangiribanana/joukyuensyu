#include<iostream>
#include<vector>
#include<utility>

void reverse(std::vector<double>& values){
    for(auto i = 0u;i < values.size() / 2;++i){
        std::swap(values[i], values[values.size()-i-1]);
    }
}

int main() {
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
    reverse(values);
    std::cout << "Reversed elements:";
    for(int i = 0;i < n;++i){
        std::cout << " " << values[i];
    }
    std::cout << "\n";
}
/*
./kadai16
Enter the number of elements:
3
Enter the elements:
1.1 2.2 3.3
Reversed elements: 3.3 2.2 1.1

./kadai16
Enter the number of elements:
4
Enter the elements:
10 20 30 40
Reversed elements: 40 30 20 10

./kadai16
Enter the number of elements:
7
Enter the elements:
1 0 4 8 5 7 6
Reversed elements: 6 7 5 8 4 0 1
*/