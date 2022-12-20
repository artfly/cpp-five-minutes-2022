#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-override"
#include <iostream>

class Foo {
public:
    virtual ~Foo() {
        std::cout << "~Foo" << std::endl;
    }
};

class Bar: public Foo {
public:
    virtual ~Bar() = 0;
};

class Baz: public Bar {
public:
    ~Baz() {
        std::cout << "~Baz" << std::endl;
    }
};

int main() {
    Bar * foo = new Baz();
    delete foo;
    return 0;
}

#pragma clang diagnostic pop