#include <iostream>
long long datetime_to_unixtime(int year, int month, int day, int hour, int minute, int second)
{
    long long result = 0;
    // month_array[i]にi-1月の日数が格納
    int month_array[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    result += second + minute * 60 + (hour - 9) * 3600 + (day - 1) * 86400;

    for (int i = 1970; i < year; ++i)
    {
        //  1年の秒数
        for (int j = 0; j < 12; ++j)
        {
            result += month_array[j] * 86400;
        }

        if (i % 400 == 0)
            result += 86400;
        else if (i % 100 != 0 && i % 4 == 0)
        result += 86400;
    }

    for (int j = 0; j < month - 1; ++j)
    {
        result += month_array[j] * 86400;
    }
    if (month > 2)
    {
        if (year % 400 == 0)
        {
            result += 86400;
        }
        else if (year % 100 != 0 && year % 4 == 0)
        {
            result += 86400;
        }
    }
    return result;
}

int main()
{
    int year, month, day, hour, minute, second;
    std::cout << "Enter a datename:\n";
    std::cin >> year >> month >> day >> hour >> minute >> second;
    datetime_to_unixtime(year, month, day, hour, minute, second);
    std::cout << "Unix time: " << datetime_to_unixtime(year, month, day, hour, minute, second) << '\n';
}

/*実行結果
Enter a datename:
1970 01 01 09 00 00
Unix time: 0

Enter a datename:
2001 09 09 10 46 40
Unix time: 1000000000
*/