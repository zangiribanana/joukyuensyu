#include<iostream>
#include<vector>
#include<cmath>

void mean_and_sigma(std::vector<int> a, double& mean, double& sigma){
    double sum = 0;
    for (int x : a) {
        sum += x;
    }
    mean = sum / a.size();
    double s = 0;
    for (int x : a) {
        s += pow(mean - x, 2);
    }

    sigma = sqrt(s/a.size());
}

void minmax_index(std::vector<double>& values, int& min_idx, int& max_idx){
    double max = values[0];
    double min = values[0];
    min_idx = 0;
    max_idx = 0;
    for (int i = 0;i < values.size();i++){
        if ( max <= values[i]){
            max_idx = i;
            max = values[i];
        }
        if ( min > values[i]){
            min_idx = i;
            min = values[i];
        }
    }
}
int main(){
    int n, min_idx, max_idx;
    std::cin >> n;
    std::vector<double> a;
    for (int i = 0;i<n;i++){
        double tmp;
        std::cin >> tmp;
        a.push_back(tmp);
    }
    minmax_index(a, min_idx, max_idx);
    std::cout <<"min_idx:"<< min_idx << '\n';
    std::cout <<"max_idx:"<< max_idx << '\n';
}