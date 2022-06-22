#include<iostream>

struct RandomNumberGenerator {
    int val;
    int next_random_value(){
        val = (val * 16807LL) % 2147483647LL;
        return val;
    }
    void seed(int seed_val){
        val = seed_val;
    }
};

int main(){
    RandomNumberGenerator random;
    int seed_val;
    std::cout << "Enter a seed value:\n";
    std::cin >> seed_val;
    random.seed(seed_val);
    std::cout << "Random numbers:\n";
    for(int i;i<5;i++){
        std::cout << random.next_random_value() <<"\n";
    }
}
/*実行結果
./kadai22
Enter a seed value:
1
Random numbers:
16807
282475249
1622650073
984943658
1144108930

./kadai22
Enter a seed value:
16807
Random numbers:
282475249
1622650073
984943658
1144108930
470211272

./kadai22
Enter a seed value:
5489
Random numbers:
92253623
23448627
1111566588
1139399263
771732942
*/