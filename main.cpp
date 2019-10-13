#include <iostream>
#include "fraction.h"

int main() {
  fractions f;
  fractions f1;
  std::cout << "Введите первую дробь\n";
  std::cin >> f;
  std::cout << "Введите вторую дробь\n";
  std::cin >> f1;
  std::cout << "Первая дробь\n";
  std::cout << f << std::endl;
  std::cout << "Вторая дробь\n";
  std::cout << f1 << std::endl;
  std::cout << "Сумма\n";
  std::cout << f + f1 << std::endl;
  std::cout << "Разность\n";
  std::cout << f - f1 << std::endl;
  std::cout << "Произведение\n";
  std::cout << f * f1 << std::endl;
  std::cout << "Частное\n";
  std::cout << f / f1 << std::endl;
  if(f > f1)
    std::cout << "Первая дробь больше\n";
  if(f < f1)
    std::cout << "Первая дробь меньше\n";
  if(f == f1)
    std::cout << "Дроби равны\n";
  fractions f3;
  f3 = "[5:9]"_d;
  std::cout << f3 << std::endl;
  return 0;
}
