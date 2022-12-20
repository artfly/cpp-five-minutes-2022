#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmismatched-new-delete"
class Foo {
public:
    Foo(): data(new int[10]) {
        std::cout << "ctor" << std::endl;
    }

    ~Foo() {
        delete data;
        std::cout << "dtor" << std::endl;
    }

private:
    int * data;
};

int main() {
    Foo foo;
}
#pragma clang diagnostic pop