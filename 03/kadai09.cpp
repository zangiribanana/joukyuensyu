#include <iostream>

void sort3(double& x1, double& x2, double& x3){
    double tmp;
    if(x2 > x3){
        tmp = x2;
        x2 = x3;
        x3 = tmp;
    }
    if(x1 > x2){
        tmp = x1;
        x1 = x2;
        x2 = tmp;
    }
    if(x2 > x3){
        tmp = x2;
        x2 = x3;
        x3 = tmp;
    }
    std::cout << "Sorted elements: " << x1 << " "<< x2 << " "<< x3 << std::endl;
}

int main(){
    double x1, x2, x3;
    std::cout << "Enter three elements:" << std::endl;
    std::cin >> x1 >> x2 >> x3;
    sort3(x1, x2, x3);
}

/*
Enter three elements:
-0.1 0.1 -0.3
Sorted elements: -0.3 -0.1 0.1

Enter three elements:
3 2 1
Sorted elements: 1 2 3

Enter three elements:
1000 500 1000
Sorted elements: 500 1000 1000
*/