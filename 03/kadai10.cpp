#include <iostream>

void swap(double& x, double& y){
    double tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void insertion_sort(double values[], int n){
    for(int i = 0;i < n;++i){
        int j = i;
        while(j >= 1 && values[j-1] > values[j]){
            swap(values[j-1], values[j]);
            j--;
        }
    }
    std::cout << "Sorted elements: ";
    for(int i = 0;i<n;++i){
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::cout << "Enter the number of elements:\n";
    int n;
    double value[10000];
    std::cin >> n;
    std::cout << "Enter the elements:\n";
    for(int i = 0;i<n;i++){
        std::cin >> value[i];
    }
    insertion_sort(value, n);
}

/*実行結果

Enter the number of elements:
3
Enter the elements:
-0.1 0.1 -0.3
Sorted elements: -0.3 -0.1 0.1 

Enter the number of elements:
4
Enter the elements:
3 2 4 1
Sorted elements: 1 2 3 4 

Enter the number of elements:
5
Enter the elements:
20 30 10 30 20
Sorted elements: 10 20 20 30 30
*/