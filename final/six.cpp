#include <iostream>

template<class T>
class Printer {

public:
    void operator()(T t) {
        std::cout << "functor!" << std::endl;
    }

private:
    void printer(T t) {
        std::cout << "printer func!" << std::endl;
    }
};

template<class T, class TPrinter>
void doSmth(T t, TPrinter & printer) {
    printer(t);
}

int main() {
    int a = 42;
    Printer<int> p;
    doSmth(a, p);
    return 0;
}
