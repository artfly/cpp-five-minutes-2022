#pragma clang diagnostic push
#pragma ide diagnostic ignored "HidingNonVirtualFunction"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#pragma ide diagnostic ignored "modernize-use-override"
#include <iostream>

class Parent {
public:
    virtual void doSmth() {

    }
};

class Child: public Parent {
public:
    virtual void doSmth() {
        this->doOther();
    }

    void doOther() {
        std::cout << "hello";
    }
};

class GrandChild: public Child {
public:
    virtual void doSmth() {
        this->doOther();
    }

    void doOther () {
        std::cout << "hello";
    }
};

int main() {
    Child * child = new GrandChild();
    child->doSmth();
    return 0;
}
#pragma clang diagnostic pop