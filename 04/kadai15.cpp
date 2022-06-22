#include<iostream>
#include<chrono>
#include<cmath>
#include<iomanip>
int days_since_1900_01_01(int y, int m, int d)
{
    if (m <= 2)  { m += 9; --y; }
    else         { m -= 3;      }
    int e = (y >= 0 ? y : y -399) / 400;
    int f = y - 400 * e;
    int g = (153 * m + 2) / 5 + d - 1;
    int h = f * 365 + f / 4 - f / 100 + g;
    return e * 146097 + h - 693901;
}

int main(int argc, char* argv[])
{
    int num_days;
    if(argc == 2){
        int y = std::atoi(&(argv[1][0]));
        int m = std::atoi(&(argv[1][5]));
        int d = std::atoi(&(argv[1][8]));
        num_days = days_since_1900_01_01(y, m, d);
    }
    else if( argc > 2){
        std::cout << "usage: ./kadai15 [YYYY-MM-DD]\n";
        exit(1);
    }
    else{
        using namespace std::chrono_literals;
        auto now = std::chrono::system_clock::now();
        auto unix_time = now.time_since_epoch() / 1s;
        num_days = (unix_time + 9 * 60 * 60) / (24 * 60 * 60);
        num_days += days_since_1900_01_01(1970, 1, 1);
    }

    double moon_age = std::fmod(num_days, 29.530589);
    if (moon_age < 0.0) { moon_age += 29.530589; }

    char moon_emojis[8][5] = {"\U0001F311", "\U0001F312", "\U0001F313", "\U0001F314",
                              "\U0001F315", "\U0001F316", "\U0001F317", "\U0001F318"
                              };
    int moon_age2 = (int)(moon_age / (29.530589 / 8.0) + 0.5);
    if(moon_age2 == 8)  moon_age2 = 0;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << moon_emojis[moon_age2] << " (" << moon_age << " / 29.5)\n";
}

/*実行結果
./kadai15
🌔 (11.2 / 29.5)
./kadai15 2022-05-16
🌕 (15.2 / 29.5)
./kadai15 2038-01-19
🌕 (13.3 / 29.5)
./kadai15 1900-01-01
🌑 (0.0 / 29.5)
./kadai15 9999 12 31
usage: ./kadai15 [YYYY-MM-DD]
*/