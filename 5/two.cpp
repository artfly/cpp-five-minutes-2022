// что напечатает программа?
#include <iostream>

class Foo {
 public:
  int bar() const {
    int i = baz();
    return i + m();
  }

  int baz() const { return i_++; }

  int m() const { return 2; }

 private:
  int i_ = 42;
};

int main(int argc, char** argv) {
  Foo foo;
  std::cout << foo.bar() << std::endl;
  return 0;
}