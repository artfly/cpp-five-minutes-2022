#include <iostream>

class A {
 public:
  A() { std::cout << "A" << std::endl; }

  A(A &a) { std::cout << "CopyA" << std::endl; }

  ~A() { std::cout << "Dtor" << std::endl; }
};

void f(A a) { std::cout << "f" << std::endl; }

int main(int argc, char const *argv[]) {
  // A
  A a;
  // CopyA f Dtor 
  f(a);
  // main
  std::cout << "main" << std::endl;
  return 0;
  // Dtor
}
