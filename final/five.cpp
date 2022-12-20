#include <iostream>

class A;

namespace B {
    int bar(const A & a);
}

class A {
private:
    int foo(int i) const;

    mutable int i_ = 42;

    friend int B::bar(const A &a);
};

int A::foo(const int i) const {
    i_ = i;
    return i_;
}

int B::bar(const A &a) {
    return a.foo(43);
}

int main() {
    std::cout << (B::bar(A())) << std::endl;
    return 0;
}
