#include<cstdlib>
#include<iostream>
#include <chrono>
#include <thread>
void sleep(double t)
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(t * 1s);
}

int main(int argc, char* argv[])
{
    if(argc != 2){
        std::cout << "usage: " << argv[0] << " seconds\n";
        std::exit(1);
    }
    double time = std::atof(argv[1]);
    std::cout << "0%  10   20   30   40   50   60   70   80   90   100\n";
    std::cout << "|----|----|----|----|----|----|----|----|----|----|\n";
    std::cout << "^" << std::flush;
    for(int i = 0;i < 50;++i){
        sleep(time/50);
        std::cout << "\b" << "~" << "^" << std::flush;
    }
    std::cout << "\n" << time << " seconds have elapsed.\n";
}

/*実行結果
./kadai13 5.0
0%  10   20   30   40   50   60   70   80   90   100
|----|----|----|----|----|----|----|----|----|----|
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^
5 seconds have elapsed.

./kadai13 2.5 10.0
usage: ./kadai13 seconds

./kadai13
usage: ./kadai13 seconds
*/