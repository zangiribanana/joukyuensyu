#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<random>
struct Point {
    double x;
    double y;
};
double distance(Point a, Point b) {
    return std::hypot(a.x-b.x, a.y-b.y);
}
Point generate_random_point(std::mt19937& random) {
    Point a;
    std::uniform_real_distribution<double> distrib{0, 1};
    a.x = distrib(random);
    a.y = distrib(random);
    return a;
}
int main(int argc, char* argv[]){
    unsigned int seed_val;
    if (argc == 2) {
        seed_val = std::stoul(argv[1]);
    }
    else {
        std::random_device seeder;
        seed_val = seeder();
    }
    std::mt19937 random;
    random.seed(seed_val);
    
    std::cout << "Enter the number of points:\n";
    int n;
    std::cin >> n;
    std::vector<Point> pnts;
    for (int i = 0; i < n; i++) {
        Point tmp = generate_random_point(random);
        pnts.push_back(tmp);
    }

    // for (int i = 0; i < n; i++) {
    //         std::cout << pnts[i].x << ',' << pnts[i].y << std::endl;
    //     }
    // std::cout << std::endl;

    std::vector<double> dist;
    for (int i = 0; i < n; i++) {
        double min;
        bool is_first = true;
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            if (is_first){ 
                min = distance(pnts[i],pnts[j]);
                is_first = false;
            }
            min = distance(pnts[i],pnts[j]) < min ? distance(pnts[i],pnts[j]) : min;
        }
        dist.push_back(min);
    }

    // for (int i = 0; i < n; i++) {
    //     std::cout << dist[i] << std::endl;
    // }

    double min_dist, max_dist, sum_dist = 0;
    for (int i = 0; i < n; i++) {
        sum_dist += dist[i];
        if (i == 0) {
            min_dist = dist[i];
            max_dist = dist[i];
            continue;
        }
        if (min_dist > dist[i]) min_dist = dist[i];
        if (max_dist < dist[i]) max_dist = dist[i];
    }
    std::cout << "min: " << min_dist << std::endl;
    std::cout << "avg: " << sum_dist / dist.size() << std::endl;
    std::cout << "max: " << max_dist << std::endl;
}

/*
$ ./kadai34 5489
Enter the number of points:
2    
min: 1.03514
avg: 1.03514
max: 1.03514

$ ./kadai34 5489
Enter the number of points:
3
min: 0.335624
avg: 0.469361
max: 0.736833

$ ./kadai34 
Enter the number of points:
5
min: 0.322293
avg: 0.382681
max: 0.598604

*/