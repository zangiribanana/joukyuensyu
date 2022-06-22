#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

void mean_and_sigma(std::vector<int>& scores, double& mean, double& sigma){
    double sum = 0;
    for(int val : scores){
        sum += val;
    }
    mean = sum / scores.size();
    sum = 0;
    for(int val : scores){
        sum += pow(val - mean, 2);
    }
    sigma = sqrt(sum / scores.size());
}

double div_value(int score, double mean, double sigma){
    if(sigma == 0) return 50;
    return 50 + 10 * (score - mean) / sigma;
}

int main(){
    int num_of_scores;
    std::cout << "Enter the number of scores:\n";
    std::cin >> num_of_scores;
    std::vector<int> scores;
    scores.resize(num_of_scores);

    std::cout << "Enter the scores:\n";
    for(int& val : scores){
        std::cin >> val;
    }
    double mean, sigma;
    mean_and_sigma(scores, mean, sigma);
    std::cout << "Conversion results:\n";
    for(int val : scores){
        std::cout << "score " << val << " => T-score " << div_value(val, mean, sigma) << "\n";
    }
}
/*実行結果
./kadai23
Enter the number of scores:
3
Enter the scores:
90 85 95
Conversion results:
score 90 => T-score 50
score 85 => T-score 37.7526
score 95 => T-score 62.2474

./kadai23
Enter the number of scores:
4
Enter the scores:
50 90 80 70
Conversion results:
score 50 => T-score 34.7872
score 90 => T-score 61.8322
score 80 => T-score 55.0709
score 70 => T-score 48.3097

./kadai23
Enter the number of scores:
5
Enter the scores:
100 100 100 100 100
Conversion results:
score 100 => T-score 50
score 100 => T-score 50
score 100 => T-score 50
score 100 => T-score 50
score 100 => T-score 50
*/