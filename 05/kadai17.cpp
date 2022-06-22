#include<iostream>
#include<vector>
#include<utility>

std::vector<int> prime_factors(int n){
    std::vector<int> fcts;
    int tmp = n;
    for(int i = 2;i <=n;++i){
        while(tmp % i == 0){
            fcts.push_back(i);
            tmp /= i;
        }
    }
    return fcts;
}

int main(){
    int n;
    std::vector<int> fcts;
    std::cout << "Enter an integer:\n";
    std::cin >> n;
    std::cout << "Prime factors: ";
    fcts = prime_factors(n);
    for (auto i = 0u;i < fcts.size();++i){
        std::cout << (i > 0 ? " × " : "") << fcts[i];
    }
    std::cout << "\n";
}

/*
./kadai17
Enter an integer:
300
Prime factors: 2 × 2 × 3 × 5 × 5

./kadai17
Enter an integer:
1234
Prime factors: 2 × 617

./kadai17
Enter an integer:
19937
Prime factors: 19937
*/