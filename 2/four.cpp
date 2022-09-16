// что выведет эта программа?
#include <iostream>

class A {
  public:
    A() {
      std::cout << "hello" << std::endl;
    }
    ~A() {
      std::cout << "bye" << std::endl;
    }
};

int main(int argc, char ** argv) {
  std::cout << "1" << std::endl;
  A a;
  std::cout << "2" << std::endl;
  return 0;
}



