// что выведет эта программа?
#include <iostream>

class Base {
 public:
    virtual void doSmth() {
        std::cout << "Base#doSmth" << std::endl;
    }
    virtual void doOther() {
        std::cout << "Base#doOther" << std::endl;
    }
};

class Child: public Base {
 public:
    virtual void doSmth() {
       std::cout << "Child#doSmth" << std::endl; 
    };
};

int main(int argc, char const *argv[]) {
    Base * base = new Child();
    // Child#doSmth
    base->doSmth();
    // Base#doOther
    base->doOther();
    return 0;
}
