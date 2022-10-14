// определите оператор== и оператор!= как внешние функции

#include <iostream>

class Wrapper {
 public:
  explicit Wrapper(int i) : data_(i) {}

 private:
  int data_;
};

int main () {
  Wrapper w1(1);
  Wrapper w2(2);
  std::cout << (w1 == w2) << std::endl;
}