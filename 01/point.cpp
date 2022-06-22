#include <iostream>
void average(int x, int y, double *ptr) {
  double result = (double)(x + y) / 2;
  *ptr = result;  //ptrが指す変数の実態にresultの値を代入
}
int main() {
  int x, y;
  std::cout << "二つの整数を入力して下さい\n";
  std::cin >> x >> y;
  double avg;
  average(x, y, &avg);
  std::cout << "平均値は" << avg << '\n';
  return 0;
}