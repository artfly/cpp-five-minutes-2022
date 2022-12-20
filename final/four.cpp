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

struct Parent {
    Parent(A & a): a(a) {
        std::cout << "Parent" << std::endl;
    }
    ~Parent() {
        std::cout << "~Parent" << std::endl;
    }
private:
    A a = A(1);
};

struct Child: public Parent {

    Child(): Child(A(12)) {
        std::cout << "Child" << std::endl;
    }
    Child(A a): Parent(a), a(A(42)) {
        std::cout << "ChildA" << std::endl;
    }
    ~Child() {
        std::cout << "~Child" << std::endl;
    }
private:
    A a = A(1337);
};

int main() {
    Child child;
}
