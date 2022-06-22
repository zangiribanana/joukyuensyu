#include <iostream>

void swap(int& x, int& y){
    double tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void insertion_sort(int values[], int n){
    for(int i = 0;i < n;++i){
        int j = i;
        while(j >= 1 && values[j-1] > values[j]){
            swap(values[j-1], values[j]);
            j--;
        }
    }
}

bool num_to_array(int& n, int value[]){
    int i = 0;
    int cnt = 0;
    while(n != 0){
        value[i] = n % 10;
        n /= 10;
        i++;
        cnt++;
    }
    insertion_sort(value, cnt);
    for(int k = 0;k < cnt - 1;k++){
        if(value[k] == value[k+1]){
            return true;
        }
    }
    return false;
}


int main(){
    std::cout << "Enter a non-negative integer:\n";
    int n;
    int value[10000];
    std::cin >> n;
    bool a = num_to_array(n, value);
    std::cout<<std::boolalpha;
    std::cout << "has duplicate_digits: " << a << '\n';
}

/*実行結果
./kadai11
Enter a non-negative integer:
2022
has duplicate_digits: true

./kadai11
Enter a non-negative integer:
19937
has duplicate_digits: true

./kadai11
Enter a non-negative integer:
1234567890
has duplicate_digits: false

./kadai11
Enter a non-negative integer:
0
has duplicate_digits: false
*/