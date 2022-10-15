// определите оператор== и оператор!= как внешние функции

#include <iostream>

class Wrapper {
 public:
  explicit Wrapper(int i) : data_(i) {}
  friend bool operator==(const Wrapper&, const Wrapper&);
 private:
  int data_;
};

bool operator==(const Wrapper& w1, const Wrapper& w2) {
  return w1.data_ == w2.data_;
}

bool operator!=(const Wrapper& w1, const Wrapper& w2) {
  return !(w1 == w2);
}

int main () {
  Wrapper w1(1);
  Wrapper w2(2);
  std::cout << (w1 == w2) << std::endl;
}