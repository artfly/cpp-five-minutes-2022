#include <iostream>

class A {
 public:
  A() { 
    std::cout << "A" << std::endl;
    i_ = 0;
  }
  A(int i) { 
    std::cout << "A" << i << std::endl;
    i_ = i;
  }
  A(const A &other) {
    i_ = other.i_;
    std::cout << "copy" << std::endl;
  }
  A &operator=(const A &other) {
    std::cout << "assign" << std::endl;
    i_ = other.i_;
    return *this;
  }
  ~A() { std::cout << "dtor" << i_ << std::endl; }

 private:
  int i_;
};

class B {
 public:
  B(const A &x, A y, A *z) {
    // assign 
    a1 = y;
    // B
    std::cout << "B" << std::endl;
    A &tmp = y;
    // dtor0
  }
  ~B() { std::cout << "dtor" << std::endl; }

 private:
  A a2 = A(42);
  A a1 = A(11);
};

int main(int argc, char const *argv[]) {
  // A
  A a1;
  // A42 copy или copy A42
  // A42 A11
  B b(A(42), a1, &a1);
  // dtor42
  return 0;
  // dtor dtor11 dtor42
  // dtor0
}