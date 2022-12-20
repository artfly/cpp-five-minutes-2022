#pragma clang diagnostic push
#pragma ide diagnostic ignored "performance-unnecessary-value-param"
// порядок вызова кторов

#include <iostream>

struct A {
    A() { std::cout << "A!" << std::endl; }
    ~A() { std::cout << "~A!" << std::endl; }
    A(const A & other) { std::cout << "Acopy!" << std::endl; }
    A(int a) { std::cout << "Aint" << a << "!" << std::endl; }
    A & operator=(const A & other) {
        std::cout << "A=!" << std::endl;
        return *this;
    }
};

struct B {
    B(A & a, A a1): a2(a1) {
        std::cout << "B!" << std::endl;
        a = a1;
    }

    ~B() {
        std::cout << "~B!" << std::endl;
    }

private:
    A a = A(42);
    A a2 = A(1337);
};

int main() {
    A a = 42;
    B b(a, A());
}

#pragma clang diagnostic pop